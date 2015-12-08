/*
 * For Maven:
 * <dependency>
 *   <groupId>com.googlecode.xades4j</groupId>
 *   <artifactId>xades4j</artifactId>
 *   <version>1.3.2</version>
 * </dependency>
 */
package br.net.cartoriodigital.xades;

import java.io.File;
import java.io.FileOutputStream;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import xades4j.production.DataObjectReference;
import xades4j.production.SignedDataObjects;
import xades4j.production.XadesBesSigningProfile;
import xades4j.production.XadesSigner;
import xades4j.properties.DataObjectDesc;
import xades4j.providers.impl.FileSystemKeyStoreKeyingDataProvider;

/**
 *
 * @author leovan
 */
public class Test01 {
    
    
    public static void main(String args[]) throws Exception
    {
        FileSystemKeyStoreKeyingDataProvider keyingProvider = new FileSystemKeyStoreKeyingDataProvider(
            "pkcs12",
            Test01.class.getResource("/fulano_certificate.pfx").getPath(),
            new FirstCertificateSelector(),
            new DirectPasswordProvider("1234"),
            new DirectPasswordProvider("1234"),
            true
        );
        
        XadesSigner signer = new XadesBesSigningProfile(keyingProvider).newSigner();
        
        DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
        dbf.setNamespaceAware(true);
        DocumentBuilder db = dbf.newDocumentBuilder();
        
        Document doc = db.newDocument();
        
        DataObjectDesc obj1 = new DataObjectReference("");
        SignedDataObjects dataObjs = new SignedDataObjects(obj1)
                .withBaseUri("file://" + Test01.class.getResource("/teste.xml").getPath());
        
        signer.sign(dataObjs, doc);
        
        TransformerFactory tf = TransformerFactory.newInstance();
        FileOutputStream out = new FileOutputStream(new File("/tmp/", "xades.xml"));
        
        tf.newTransformer().transform(new DOMSource(doc), new StreamResult(out));
        out.close();
    }
}
