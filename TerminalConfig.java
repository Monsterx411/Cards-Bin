package com.smartcard.pos.terminal;

public class TerminalConfig {
    private final String terminalId;
    private final String merchantId;

    public TerminalConfig(String terminalId, String merchantId) {
        this.terminalId = terminalId;
        this.merchantId = merchantId;
    }

    public String getTerminalId() {
        return terminalId;
    }

    public String getMerchantId() {
        return merchantId;
    }
}