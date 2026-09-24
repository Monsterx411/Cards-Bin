# SmartCard POS System

End-to-end, modular smart-card POS system focused on EMV and card-present payment flows.

## Modules

- **c-card-reader**: Low-level card interface, APDU transport, ISO 7816 helpers.
- **java-emv-processor**: EMV kernel, TLV parsing, transaction flow.
- **python-api-service**: REST API for transactions, card data, reporting.

## Quick Start (local)

1. Build C card reader
   - `make -C c-card-reader`
2. Build Java EMV processor
   - `mvn -f java-emv-processor/pom.xml test`
3. Run Python API
   - `pip install -r python-api-service/requirements.txt`
   - `uvicorn app.main:app --reload --port 8080`

See [docs/DEPLOYMENT.md](docs/DEPLOYMENT.md) for full instructions.