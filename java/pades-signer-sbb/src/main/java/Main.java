import SecureBlackbox.Base.SBUtils;
import SecureBlackbox.Base.TElFileCertStorage;
import SecureBlackbox.Base.TElFileStream;
import SecureBlackbox.PDF.TElPDFDocument;
import SecureBlackbox.PDF.TElPDFSignature;
import SecureBlackbox.PKIPDF.TElPDFAdvancedPublicKeySecurityHandler;
import SecureBlackbox.PKIPDF.TSBPAdESSignatureType;

import java.util.Date;

/**
 * Created by leovan on 30/05/16.
 */
public class Main {
    public static void main(String[] args) {
        SBUtils.setLicenseKey("52D5ED76C0F10F080EF1F8F75F4303F110DD77BD15862BDD684E93438C4E29EA6A9DF8EA11D1A9EA2BEA7321ECF070B96C7D3BFD4DD159926717919BB3D502A4432F858560BBFD70C319DB42D8740D8F122AC2C6594BD4BC8491B8016CB69C468FD52F9918698BF6B3A3C9677A61F915CFD950E14DCDB9E3C102D768614764461FE852D8FFF7B7870E39EBEEC13887A59E4FC2E0F25D9F1918DDA377AACF324B1660179D1DD4919AB46D7BDD3B00CEBFE4831BEFF0767F31AA4926CFF191342691FCE5DCB9BA04D9B2E88BA86A4267BB7D491A0839723FC1D35E3FC448F8A919B38EFDF290FADFB2EE8773FDDE8ABBFEBE97E15E1BC8B90BFA9EA97EEC04661C");
        TElPDFDocument doc = new TElPDFDocument();
        TElFileStream file;
        TElFileStream certFile;
        TElPDFAdvancedPublicKeySecurityHandler handler;
        TElFileCertStorage storage;

        try {
            certFile = new TElFileStream(Main.class.getClassLoader().getResource("leovan_as_certificate.pfx").getPath(), "r", true);
            storage = new TElFileCertStorage();
            storage.loadFromStreamPFX(certFile, "1234", 0);
            handler = new TElPDFAdvancedPublicKeySecurityHandler();
            handler.setCertStorage(storage);
            handler.setPAdESSignatureType(TSBPAdESSignatureType.pastBasic);
            handler.setCustomName("Adobe.PPKMS");
            handler.setTSPClient(null);
            handler.setIgnoreChainValidationErrors(true);
            file = new TElFileStream(Main.class.getClassLoader().getResource("doc.pdf").getPath(), "rw", true);
            doc.open(file);
            int index = doc.addSignature();
            TElPDFSignature sig = doc.getSignatureEntry(index);
            sig.setHandler(handler);
            sig.setInvisible(true);
            sig.setSigningTime(new Date());
            doc.close(true);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
