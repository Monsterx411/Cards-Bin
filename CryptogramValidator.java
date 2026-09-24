package com.smartcard.pos.emv;

public class CryptogramValidator {
    public boolean validate(String cryptogram) {
        return cryptogram != null && cryptogram.length() >= 8;
    }
}