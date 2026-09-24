# Security Guidelines

- Never store PANs unencrypted at rest.
- Mask PANs in logs and UI (e.g., `4111********1111`).
- Use HSM or secure enclave for key management when available.
- Enforce strong TLS for any network transport.
- Rotate keys regularly and separate dev/test/prod keys.