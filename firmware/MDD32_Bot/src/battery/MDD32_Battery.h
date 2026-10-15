#pragma once

#include <Arduino.h>
#include "../definitions/pin_definitions.h"
#include "../definitions/robot_definitions.h"

// Battery monitor (voltage, charging status, charger connected)
class MDD32_Battery {
public:
    // Constructor
    MDD32_Battery() = default;

    // Public methods
    bool begin();

    // Public members
    float voltage();           // Battery voltage in volts
    bool charging();           // True when actively charging
    bool chargerConnected();   // True when charging source is plugged in
};
