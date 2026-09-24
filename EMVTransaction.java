package com.smartcard.pos.emv;

public class EMVTransaction {
    public enum Status {
        INITIATED,
        AUTHENTICATED,
        APPROVED,
        DECLINED
    }

    private final String pan;
    private final long amount;
    private String terminalId;
    private Status status;

    public EMVTransaction(String pan, long amount) {
        this.pan = pan;
        this.amount = amount;
    }

    public String getPan() {
        return pan;
    }

    public long getAmount() {
        return amount;
    }

    public String getTerminalId() {
        return terminalId;
    }

    public void setTerminalId(String terminalId) {
        this.terminalId = terminalId;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }
}