package com.smartcard.pos.terminal;

import com.smartcard.pos.emv.EMVTransaction;

public class TransactionProcessor {
    public String buildReceipt(EMVTransaction tx) {
        return "TX " + tx.getStatus() + " PAN:" + maskPan(tx.getPan()) + " AMT:" + tx.getAmount();
    }

    private String maskPan(String pan) {
        if (pan == null || pan.length() < 6) {
            return "******";
        }
        return pan.substring(0, 4) + "******" + pan.substring(pan.length() - 2);
    }
}