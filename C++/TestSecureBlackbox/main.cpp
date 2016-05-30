#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

#include "include/sbmisc.h"
#include "include/sbutils.h"
#include "include/sbpdf.h"
#include "include/sbpades.h"
#include "include/sbx509.h"
#include "include/sbcertvalidator.h"
#include "include/sbpdfsecurity.h"
#include "include/sbhttptspclient.h"
#include "include/sbhttpsclient.h"
#include "include/sbhttpcrl.h"
#include "include/sbhttpocspclient.h"
#include "include/sbhttpcertretriever.h"

using namespace SecureBlackbox;
using namespace std;

TElMemoryCertStorage *pTrustedCertStorage;

int main()
{
    string pdfFilename = "test/unsigned.pdf";
    string certFilename = "test/codesign.pfx";
    string certPassword = "Un$tructur3D";
    //Set license key
    try
    {
        SetLicenseKey("61E05BF5CA4631B12F8BABFB92367BC36C7264BC67086ECB308682402A5676E924B812056C97BB8CE23A97E4F612E6B29B80702F60E903DEDB5DE0A60C901A2CB1FFBEDAA96C2779C3008A61884F410D9B838FA0452743604D4330B27F160030EE92FDD9EE04F292EE18CABB45757F3675972C6DCCFDA3EF3569873F85F3AFFFF91024957277FF458FF4D66CDBA64DDE6F81425D0767762393666DAABCE2FE7E5CBBF4FBBDBACEDDD77794BC14AAB728A9B82AC3F8342B6EA661F0F108397134D881E56863762ABDF344AD78029564B4F2BF1BF0295971767B12BE9057B99E3A25A04EF2AAD0019063EBBBC920A6F206F51BC20F0E2B72E3B0BD1919B8BC8BC3");
    }
    catch (SBException E)
    {
        cout << "Failed to set license key:" << endl;
        cout << E.what() << endl;
        return 0;
    }
    //Load PDF
    try
    {
        RegisterHTTPCRLRetrieverFactory();
        RegisterHTTPOCSPClientFactory();
        RegisterHTTPCertificateRetrieverFactory();

        TElPDFDocument pdf(NULL);
        TElPDFAdvancedPublicKeySecurityHandler handler(NULL);
        TElMemoryCertStorage certStorage(NULL);
        //TElMemoryCertStorage trustedCertStorage(NULL);
        TElX509Certificate cert(NULL);
        //TElHTTPTSPClient tspClient(NULL);
        //TElHTTPSClient httpClient(NULL);

        TFileStream pdfStream(pdfFilename, filemodeOpenReadWrite);
        pdf.Open(pdfStream);

        cout << "Filename:\t\t" << pdfFilename << endl;
        cout << "Pages:\t\t" << pdf.get_PageInfoCount() << endl;
        //Sign PDF
        try
        {
            int idx = pdf.AddSignature();
            TElPDFSignature* sig = pdf.get_Signatures(idx);
            sig->set_Handler(handler);
            sig->set_Invisible(true);

            int k = cert.LoadFromFileAuto(certFilename, certPassword);

            if (k != 0)
            {
                cout << "Failed to load certificate." << endl;
                return 1;
            }
            certStorage.Add(cert, true);
            handler.set_CertStorage(certStorage);
            handler.set_PAdESSignatureType(pastEnhanced);
            handler.set_CustomName("Adobe.PPKMS");
            handler.set_AutoCollectRevocationInfo(false);
            handler.set_IgnoreChainValidationErrors(true);
            time_t t;
            std::time(&t);
            sig->set_SigningTime(t);
            pTrustedCertStorage = NULL;
            pdf.Close(true);
            cout << "PDF signed!" << endl;
        }
        catch (SBException E)
        {
            cout << "Signing failed: " << E.what() << endl;
        }
    }
    catch (SBException E)
    {
        cout << "Error: " << E.what() << endl;
    }
}
