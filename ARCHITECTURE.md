# Architecture

## Overview

The system is layered to separate hardware access, EMV processing, and business services.

```
Card Reader (C) -> EMV Kernel (Java) -> API Service (Python) -> Database
```

## Data Flow

1. **C layer** handles APDU exchange with the card via PC/SC.
2. **Java layer** runs EMV flow, validates TLV data, and produces transaction results.
3. **Python layer** exposes APIs and orchestrates settlement/reporting.

## Integration

JNI or gRPC can bridge Java EMV output into the Python API layer.