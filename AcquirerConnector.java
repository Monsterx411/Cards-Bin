package com.smartcard.pos.network;

public class AcquirerConnector {
    public boolean authorize(ISO8583Message message) {
        return message != null;
    }
}