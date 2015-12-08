/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.net.cartoriodigital.xades;

import java.security.cert.X509Certificate;
import java.util.List;
import xades4j.providers.impl.KeyStoreKeyingDataProvider;

/**
 *
 * @author leovan
 */
public class FirstCertificateSelector implements KeyStoreKeyingDataProvider.SigningCertSelector
{
    @Override
    public X509Certificate selectCertificate(
            List<X509Certificate> availableCertificates)
    {
        return availableCertificates.get(0);
    }
}
