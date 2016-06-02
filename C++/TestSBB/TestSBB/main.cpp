#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

#include "sbmisc.h"
#include "sbutils.h"
#include "sbstringlist.h"
#include "sbpdf.h"
#include "sbpades.h"
#include "sbx509.h"
#include "sbcertvalidator.h"
#include "sbpdfsecurity.h"
#include "sbhttptspclient.h"
#include "sbhttpsclient.h"
#include "sbhttpcrl.h"
#include "sbhttpocspclient.h"
#include "sbhttpcertretriever.h"
#include "sbpkcs11base.h"
#include "sbpkcs11certstorage.h"
#include "sbpkcs11common.h"
#include "sbwincertstorage.h"
#include "sbcustomcertstorage.h"

using namespace std;
using namespace SecureBlackbox;

string UnQuote(string s)
{
    if (s.length() < 1)
        return s;

    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    return s;
}

TElMemoryCertStorage *pTrustedCertStorage;

void SB_CALLBACK PDF_OnCertValidatorPrepared(void *, TObjectHandle, TElX509CertificateValidatorHandle * hCertValidator, TElX509CertificateHandle)
{
    try
    {
        TElX509CertificateValidator CertValidator(*hCertValidator, false);
        CertValidator.AddTrustedCertificates(pTrustedCertStorage);
        CertValidator.set_ForceCompleteChainValidationForTrusted(true);
    }
    catch (SBException E)
    {
        cout << "Unexpected error in OnCertValidatorPrepared event handler!" << endl;
        cout << E.what() << endl;
        cout << "Stack trace: " << E.getErrorStackTrace().c_str() << endl;
    }
}

int main (int argc, char *argv[])
{
    cout << "PDF signer using SecureBlackbox(R) lib!" << endl;

    string helpMessage = "Parameters:\n" \
        "-f <filename>: path to .pdf file;\n" \
        "-cert: use certificate file;\n" \
        "-smartcard: use smartcard;\n" \
        "-win: use Windows Storage;\n" \
        "-inv: invisible signature;\n" \
        "-tsa <url>: timestamp server;\n" \
        "-trustedcerts <filename>: trusted certificates storage;\n" \
        "-autorev: auto collect revocation info;\n" \
        "-ignoreerrors: ignore chain validation errors;\n" \
        "-h: help.\n";
    string pdfFilename, certFilename, pin, tsaURL, trustedCertsFilename, pkcs11Lib;
    //bool invisibleSignature = false;
    //bool autoRev = false;
    //bool ignoreErrors = false;
    bool cert = false;
    bool smartcard = false;
    bool win = false;
    /*
     * Sets the product license key.
     */
    try 
    {
        SetLicenseKey("61E05BF5CA4631B12F8BABFB92367BC36C7264BC67086ECB308682402A5676E924B812056C97BB8CE23A97E4F612E6B29B80702F60E903DEDB5DE0A60C901A2CB1FFBEDAA96C2779C3008A61884F410D9B838FA0452743604D4330B27F160030EE92FDD9EE04F292EE18CABB45757F3675972C6DCCFDA3EF3569873F85F3AFFFF91024957277FF458FF4D66CDBA64DDE6F81425D0767762393666DAABCE2FE7E5CBBF4FBBDBACEDDD77794BC14AAB728A9B82AC3F8342B6EA661F0F108397134D881E56863762ABDF344AD78029564B4F2BF1BF0295971767B12BE9057B99E3A25A04EF2AAD0019063EBBBC920A6F206F51BC20F0E2B72E3B0BD1919B8BC8BC3");
    }
    catch (SBException E)
    {
        cout << "Failed to set license key: " << endl;
        cout << E.what() << endl;
        return 1;
    }
    /*
     * Parse parameters
     */
    try 
    {
        int i = 1;
        while (i < argc)
        {
            string param;
            param.assign(argv[i]);

            if (param == "-f")
            {
                if (++i < argc)
                    pdfFilename = UnQuote(argv[i]);
            }
            else if (param == "-cert")
            {
                cert = true;
            }
            else if (param == "-smartcard")
            {
                smartcard = true;
            }
            else if (param == "-win")
            {
                win = true;
            }
            else if (param == "-tsa")
            {
                if (++i < argc)
                    tsaURL = UnQuote(argv[i]);
            }
            else if (param == "-trustedcerts")
            {
                if (++i < argc)
                    trustedCertsFilename = UnQuote(argv[i]);
            }
            else if (param == "-inv")
            {
                //invisibleSignature = true;
            }
            else if (param == "-autorev")
            {
                //autoRev = true;
            }
            else if (param == "-ignoreerrors")
            {
                //ignoreErrors = true;
            }
            else if (param == "-h")
            {
                cout << helpMessage << endl;
            }
            i++;
        }
    }
    catch (...)
    {
        cout << "Failed parsing parameters!" << endl;
        cout << helpMessage << endl;
        return 0;
    }
    if (pdfFilename == "") 
    {
        cout << helpMessage << endl;
        return 0;
    }
    /*
     * Getting additional parameters
     */
    if (cert)
    {
        cout << "Enter certificate file path:" << endl;
        getline(cin, certFilename);
        cout << "Enter PIN:" << endl;
        getline(cin, pin);

        try
        {
            cout << "Opening certificate from " << certFilename << endl;
            TElX509Certificate cert(NULL);
            int k = cert.LoadFromFileAuto(certFilename, pin);

            if (k != 0)
            {
                cout << hex << "Failed to load certificate: 0x" << k << endl;
                return 1;
            }
            TName name;
            cert.get_SubjectName(name);
            cout << "Certificate found." << endl;
            cout << "Subject: ";
            if (name.CommonName != NULL)
                cout << (char *)name.CommonName;
            else
                cout << (char *)name.Organization;

            cout << endl;
            cert.get_IssuerName(name);
            cout << "\tIssuer: ";
            if (name.CommonName != NULL)
                cout << (char *)name.CommonName;
            else
                cout << (char *)name.Organization;

            cout << endl;
            vector<uint8_t> SerialNumber;
            cert.get_SerialNumber(SerialNumber);
            string s;
            BinaryToString(SerialNumber, s);
            BeautifyBinaryString(s, ':', s);
            cout << "\tSerial number: " << s << endl;

            time_t t;
            t = (time_t)cert.get_ValidFrom();
            char* dt = ctime(&t);
            if (dt != NULL)
                cout << "\tValid from: " << dt;

            t = (time_t)cert.get_ValidTo();
            dt = ctime(&t);
            if (dt != NULL)
                cout << "\tValid to: " << dt;

            cout << "\tPrivate key: ";
            if (cert.get_PrivateKeyExists())
                cout << "YES";
            else
                cout << "NO";

            cout << endl;
        }
        catch (SBException E)
        {
            cout << "Error loading certificate: " << E.what() << endl;
        }
    }
    else if (smartcard)
    {
        cout << "Enter PKCS11 library path:" << endl;
        getline(cin, pkcs11Lib);

        try
        {
            TElPKCS11CertStorage Storage(NULL);
            Storage.set_DLLName(pkcs11Lib);
            cout << "Opening PKCS11 storage." << endl;
            Storage.Open();
            for (int i = 0; i < Storage.get_Module()->get_SlotCount(); i++)
            {
                TElPKCS11SlotInfo* pSlotInfo = Storage.get_Module()->get_Slot(i);
                string desc;
                pSlotInfo->get_SlotDescription(desc);
                if (pSlotInfo->get_TokenPresent())
                    cout << desc << " (token present)" << endl;
                else
                    cout << desc << " (no token)" << endl;
            }
            cout << "Enter slot number:" << endl;
            string iSlotInfo;
            getline(cin, iSlotInfo);
            int SlotIndex;
            SlotIndex = stoi(iSlotInfo);
            cout << "Opening storage session." << endl;
            bool RO = Storage.get_Module()->get_Slot(SlotIndex)->get_ReadOnly();
            TElPKCS11SessionInfoHandle hSession = SB_NULL_HANDLE;

            try
            {
                hSession = Storage.OpenSession(SlotIndex, RO);
            }
            catch (SBException E)
            {
                if (RO)
                    throw;
                // trying to open in readonly mode
                hSession = Storage.OpenSession(SlotIndex, true);
            }
            if (hSession != NULL)
            {
                if (Storage.get_Module()->get_Slot(SlotIndex)->PinNeeded())
                {
                    cout << "Enter pin:" << endl;
                    getline(cin, pin);
                    TElPKCS11SessionInfo Session(hSession, false);
                    Session.Login(utUser, pin);
                }
            }
            for (int i = 0; i < Storage.get_Count(); i++)
            {
                TElX509Certificate *pCert = Storage.get_Certificates(i);
                TName name;
                pCert->get_SubjectName(name);
                cout << (i + 1) << "\tSubject: ";
                if (name.CommonName != NULL)
                    cout << (char *)name.CommonName;
                else
                    cout << (char *)name.Organization;

                cout << endl;
                pCert->get_IssuerName(name);
                cout << "\tIssuer: ";
                if (name.CommonName != NULL)
                    cout << (char *)name.CommonName;
                else
                    cout << (char *)name.Organization;

                cout << endl;
                vector<uint8_t> SerialNumber;
                pCert->get_SerialNumber(SerialNumber);
                string s;
                BinaryToString(SerialNumber, s);
                BeautifyBinaryString(s, ':', s);
                cout << "\tSerial number: " << s << endl;

                time_t t;
                t = (time_t)pCert->get_ValidFrom();
                char* dt = ctime(&t);
                if (dt != NULL)
                    cout << "\tValid from: " << dt;

                t = (time_t)pCert->get_ValidTo();
                dt = ctime(&t);
                if (dt != NULL)
                    cout << "\tValid to: " << dt;

                cout << "\tPrivate key: ";
                if (pCert->get_PrivateKeyExists())
                    cout << "YES";
                else
                    cout << "NO";

                cout << endl;
            }
        }
        catch (SBException E)
        {
            cout << "PKCS11 storage error: " << E.what() << endl;
        }
    }
    else if (win)
    {
        /*
        try
        {
            cout << "Opening PKCS11 storage." << endl;
            TElWinCertStorage Storage(NULL);
            Storage.get_SystemStores()->set_Text("MY");

            for (int i = 0; i < Storage.get_Count(); i++)
            {
                TElX509Certificate *pCert = Storage.get_Certificates(i);
                TName name;
                pCert->get_SubjectName(name);
                cout << (i + 1) << "\tSubject: ";
                if (name.CommonName != NULL)
                    cout << (char *)name.CommonName;
                else
                    cout << (char *)name.Organization;

                cout << endl;
                pCert->get_IssuerName(name);
                cout << "\tIssuer: ";
                if (name.CommonName != NULL)
                    cout << (char *)name.CommonName;
                else
                    cout << (char *)name.Organization;

                cout << endl;
                vector<uint8_t> SerialNumber;
                pCert->get_SerialNumber(SerialNumber);
                string s;
                BinaryToString(SerialNumber, s);
                BeautifyBinaryString(s, ':', s);
                cout << "\tSerial number: " << s << endl;

                time_t t;
                t = (time_t)pCert->get_ValidFrom();
                char* dt = ctime(&t);
                if (dt != NULL)
                    cout << "\tValid from: " << dt;

                t = (time_t)pCert->get_ValidTo();
                dt = ctime(&t);
                if (dt != NULL)
                    cout << "\tValid to: " << dt;

                cout << "\tPrivate key: ";
                if (pCert->get_PrivateKeyExists())
                    cout << "YES";
                else
                    cout << "NO";

                cout << endl;
            }
        }
        catch (SBException E)
        {
            cout << "Windows storage error: " << E.what() << endl;
        }
        */
    } 
    else
    {
        cout << "You must set one of the flags: -cert, -smartcard or -win." << endl;
        cout << helpMessage << endl;
        return 0;
    }

    return 0;
}

