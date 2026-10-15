#include "MDD32_Bot.h"

bool MDD32_Bot::begin() {
    // Initialize battery voltage and charger status monitoring
    Serial.println("[Bot] Initializing battery...");
    if (!battery.begin()) {
        Serial.println("[Bot] Battery init FAILED");
        return false;
    }
    Serial.println("[Bot] Battery init OK");

    // Initialize motors, encoders, and drive controller
    Serial.println("[Bot] Initializing drive...");
    if (!drive.begin()) {
        Serial.println("[Bot] Drive init FAILED");
        return false;
    }
    Serial.println("[Bot] Drive init OK");

    return true;
}
