package com.smartcard.pos.security;

public class PINVerifier {
    public boolean verify(String encryptedPinBlock) {
        return encryptedPinBlock != null && encryptedPinBlock.length() > 4;
    }
}