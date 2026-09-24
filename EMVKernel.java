package com.smartcard.pos.emv;

import com.smartcard.pos.emv.CardAuthenticator;
import com.smartcard.pos.emv.CryptogramValidator;
import com.smartcard.pos.terminal.TerminalConfig;

public class EMVKernel {
    private final TerminalConfig config;
    private final CardAuthenticator authenticator;
    private final CryptogramValidator cryptogramValidator;

    public EMVKernel(TerminalConfig config) {
        this.config = config;
        this.authenticator = new CardAuthenticator();
        this.cryptogramValidator = new CryptogramValidator();
    }

    public EMVTransaction startTransaction(String pan, long amount) {
        EMVTransaction tx = new EMVTransaction(pan, amount);
        tx.setTerminalId(config.getTerminalId());
        tx.setStatus(EMVTransaction.Status.INITIATED);
        return tx;
    }

    public boolean authenticateCard(EMVTransaction tx, String tagData) {
        boolean ok = authenticator.authenticate(tagData);
        tx.setStatus(ok ? EMVTransaction.Status.AUTHENTICATED : EMVTransaction.Status.DECLINED);
        return ok;
    }

    public boolean validateCryptogram(EMVTransaction tx, String cryptogram) {
        boolean ok = cryptogramValidator.validate(cryptogram);
        tx.setStatus(ok ? EMVTransaction.Status.APPROVED : EMVTransaction.Status.DECLINED);
        return ok;
    }
}