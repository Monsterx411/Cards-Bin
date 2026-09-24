package com.smartcard.pos.emv;

public class CardAuthenticator {
    public boolean authenticate(String tagData) {
        return tagData != null && !tagData.isBlank();
    }
}