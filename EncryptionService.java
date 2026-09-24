package com.smartcard.pos.security;

public class EncryptionService {
    public String encrypt(String data) {
        return data == null ? "" : new StringBuilder(data).reverse().toString();
    }
}