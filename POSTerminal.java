package com.smartcard.pos.terminal;

import com.smartcard.pos.emv.EMVKernel;
import com.smartcard.pos.emv.EMVTransaction;

public class POSTerminal {
    private final EMVKernel kernel;

    public POSTerminal(TerminalConfig config) {
        this.kernel = new EMVKernel(config);
    }

    public EMVTransaction process(String pan, long amount, String tagData, String cryptogram) {
        EMVTransaction tx = kernel.startTransaction(pan, amount);
        if (!kernel.authenticateCard(tx, tagData)) {
            return tx;
        }
        kernel.validateCryptogram(tx, cryptogram);
        return tx;
    }
}