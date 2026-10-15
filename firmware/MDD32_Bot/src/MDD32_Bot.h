#pragma once

#include <Arduino.h>
#include "battery/MDD32_Battery.h"
#include "drive/MDD32_Drive.h"

// MDD32 Bot class
class MDD32_Bot {
    
public:
    // Constructor
    MDD32_Bot() = default;

    // Public methods
    bool begin();

    // Public members
    MDD32_Battery battery;
    MDD32_Drive   drive;
};
