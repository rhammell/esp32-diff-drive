#include "MDD32_Battery.h"

// =============================================================================
// MDD32_Battery Implementation
// =============================================================================

bool MDD32_Battery::begin() {
    pinMode(CHG, INPUT);
    pinMode(PGOOD, INPUT);
    return true;
}

float MDD32_Battery::voltage() {
    int mv = analogReadMilliVolts(VBAT_DIV);
    return (mv / 1000.0f) * VBAT_DIV_RATIO;
}

bool MDD32_Battery::charging() {
    // BQ24072 CHG is active low: LOW = charging in progress
    return digitalRead(CHG) == LOW;
}

bool MDD32_Battery::chargerConnected() {
    // BQ24072 PGOOD is active low: LOW = power good (charger connected)
    return digitalRead(PGOOD) == LOW;
}
