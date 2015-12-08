/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.net.cartoriodigital.xades;

import java.security.cert.X509Certificate;
import xades4j.providers.impl.KeyStoreKeyingDataProvider;

/**
 *
 * @author leovan
 */
public class DirectPasswordProvider implements KeyStoreKeyingDataProvider.KeyStorePasswordProvider,
        KeyStoreKeyingDataProvider.KeyEntryPasswordProvider
{
    private char[] password;

    public DirectPasswordProvider(String password)
    {
        this.password = password.toCharArray();
    }

    @Override
    public char[] getPassword()
    {
        return password;
    }

    @Override
    public char[] getPassword(String entryAlias, X509Certificate entryCert)
    {
        return password;
    }
}
