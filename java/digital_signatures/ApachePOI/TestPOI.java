/*
 * For Maven:
 * <dependency>
 *   <groupId>org.apache.poi</groupId>
 *   <artifactId>poi-ooxml</artifactId>
 *   <version>3.13</version>
 * </dependency>
 */
package br.net.cartoriodigital.apachepoi;

import java.io.InputStream;
import java.security.Key;
import java.security.KeyStore;
import java.security.PrivateKey;
import java.security.cert.X509Certificate;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import org.apache.poi.openxml4j.opc.OPCPackage;
import org.apache.poi.openxml4j.opc.PackagePart;
import org.apache.poi.poifs.crypt.dsig.SignatureConfig;
import org.apache.poi.poifs.crypt.dsig.SignatureInfo;

/**
 *
 * @author leovan
 */
public class TestPOI {
    public static void main(String args[]) throws Exception
    {
        InputStream fis = TestPOI.class.getResourceAsStream("/fulano_certificate.pfx");
        char password[] = "1234".toCharArray();
        KeyStore keystore = KeyStore.getInstance("PKCS12");
        keystore.load(fis, password);
        Key key = keystore.getKey("1", password);
        X509Certificate x509 = (X509Certificate)keystore.getCertificate("1");
        
        SignatureConfig signatureConfig = new SignatureConfig();
        signatureConfig.setKey((PrivateKey) key);
        signatureConfig.setSignatureDescription("Teste");
        signatureConfig.setPackageSignatureId("pkg_teste1");
        signatureConfig.setXadesSignatureId("xades_teste1");
        signatureConfig.setSigningCertificateChain(Collections.singletonList(x509));
        
        OPCPackage pkg = OPCPackage.open(TestPOI.class.getResourceAsStream("/Musicas.docx"));
        
        Iterator<PackagePart> pIter = null;
        List<PackagePart> pkgParts = pkg.getParts();
        pIter = pkgParts.iterator();
        PackagePart part = null;
        
        while (pIter.hasNext()) {
            part = pIter.next();
            System.out.println("Part:");
            System.out.println(part.getPartName());
            System.out.println(part.getContentType());
            System.out.println(part.getSize());
        }
        
        signatureConfig.setOpcPackage(pkg);
        
        SignatureInfo si = new SignatureInfo();
        
        si.setSignatureConfig(signatureConfig);
        si.confirmSignature();
        pkg.close();
    }
}
