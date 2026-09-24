package com.smartcard.pos.network;

import java.util.HashMap;
import java.util.Map;

public class ISO8583Message {
    private final Map<Integer, String> fields = new HashMap<>();

    public void setField(int field, String value) {
        fields.put(field, value);
    }

    public String getField(int field) {
        return fields.get(field);
    }
}