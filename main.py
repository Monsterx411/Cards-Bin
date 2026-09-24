from fastapi import FastAPI
from app.api.transaction_api import router as transaction_router
from app.api.card_api import router as card_router
from app.api.reporting_api import router as reporting_router

app = FastAPI(title="SmartCard POS API")

@app.get("/health")
def health_check():
    return {"status": "ok"}

app.include_router(transaction_router, prefix="/transactions")
app.include_router(card_router, prefix="/cards")
app.include_router(reporting_router, prefix="/reports")