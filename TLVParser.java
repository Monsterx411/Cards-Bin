package com.smartcard.pos.emv;

import java.util.LinkedHashMap;
import java.util.Map;

public class TLVParser {
    public Map<String, String> parse(String hex) {
        Map<String, String> result = new LinkedHashMap<>();
        int index = 0;
        while (index + 4 <= hex.length()) {
            String tag = hex.substring(index, index + 2);
            index += 2;
            int len = Integer.parseInt(hex.substring(index, index + 2), 16);
            index += 2;
            int valueEnd = Math.min(index + (len * 2), hex.length());
            String value = hex.substring(index, valueEnd);
            index = valueEnd;
            result.put(tag, value);
        }
        return result;
    }
}