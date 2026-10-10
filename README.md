# ESP32 Diff Drive

A compact ESP32-S3 based differential drive controller board designed in KiCad.

<p align="center">
  <img src="docs/images/board_top.png" alt="ESP32 Diff Drive board, top view" width="700">
</p>

ESP32 Diff Drive is a small, battery-powered controller for two-wheeled robots. It pairs an ESP32-S3 module with a dual H-bridge motor driver and connectors for two N20 gear motors with quadrature encoders. A single-cell Li-ion/LiPo battery powers the board, and it charges over USB-C. The same USB-C port is used for programming and serial debugging through the ESP32-S3's native USB.

## Features

- **ESP32-S3-MINI-1-N8** module with Wi-Fi and Bluetooth LE
- **Native USB-C** for programming, serial, and charging; no USB-UART bridge needed
- **Single-cell Li-ion/LiPo charging** with power-path management (TI BQ24072)
- **5 V boost converter** for the motor supply (TI TPS61023)
- **3.3 V LDO** for the logic supply (Diodes AP2114H-3.3)
- **Dual H-bridge motor driver** with per-channel current limiting (TI DRV8833)
- **Two 6-pin JST-SH motor ports** for N20 encoder motors
- **Battery voltage sensing** that only draws current while the board is switched on
- **Charge and USB-power status**, shown on LEDs and readable by the ESP32
- **Slide power switch**, plus RESET and BOOT buttons
- **4-layer, 62 × 28 mm PCB** with four M2.5 mounting holes

## Hardware

### Power

| Rail       | Source                       | Feeds                          |
|------------|------------------------------|--------------------------------|
| `VBUS`     | USB-C (5 V)                  | Battery charger input          |
| `VBAT`     | 1S Li-ion/LiPo via JST-PH 2-pin | Charger battery pin         |
| `VSYS`     | Charger power-path output, through the power switch | LDO and boost converter |
| `+3V3`     | AP2114H-3.3 LDO              | ESP32-S3 and encoders          |
| `+5V`      | TPS61023 boost (≈4.96 V)     | DRV8833 motor supply           |

- **Charger:** the BQ24072's input current limit is set to about 1.4 A (R9 = 1.1 kΩ) and its fast-charge current to about 330 mA (R10 = 2.7 kΩ). Size your battery for this charge rate, or change R10.
- **Motor current limit:** each DRV8833 channel limits at about 0.67 A (300 mΩ sense resistors).

### ESP32-S3 Pin Map

| GPIO   | Signal       | Function                              |
|--------|--------------|---------------------------------------|
| IO0    | `BOOT`       | BOOT button (strapping pin)           |
| EN     | `RESET`      | RESET button                          |
| IO10   | `VBAT_MON`   | Battery voltage, ½ divider (ADC)      |
| IO35   | `PGOOD_MON`  | USB power present (active low)        |
| IO36   | `CHG_MON`    | Charging (active low)                 |
| IO40   | `SLEEP`      | DRV8833 nSLEEP (high = enabled)       |
| IO47   | `MOT1_IN1`   | Left motor driver input 1 (AIN1)      |
| IO33   | `MOT1_IN2`   | Left motor driver input 2 (AIN2)      |
| IO38   | `MOT1_ENCA`  | Left encoder channel A                |
| IO39   | `MOT1_ENCB`  | Left encoder channel B                |
| IO48   | `MOT2_IN1`   | Right motor driver input 1 (BIN1)     |
| IO34   | `MOT2_IN2`   | Right motor driver input 2 (BIN2)     |
| IO41   | `MOT2_ENCA`  | Right encoder channel A               |
| IO42   | `MOT2_ENCB`  | Right encoder channel B               |
| IO19/20| `USB_D-`/`USB_D+` | Native USB                       |

### Connectors

| Ref | Connector            | Pinout                                              |
|-----|----------------------|-----------------------------------------------------|
| J1  | JST-PH 2-pin         | 1: `VBAT`, 2: `GND`                                 |
| J2  | USB-C (USB 2.0)      | Power and data                                      |
| J4  | JST-SH 6-pin (MOT L) | 1: `GND`, 2: `ENC_B`, 3: `ENC_A`, 4: `3V3`, 5: `M2`, 6: `M1` |
| J5  | JST-SH 6-pin (MOT R) | 1: `GND`, 2: `ENC_B`, 3: `ENC_A`, 4: `3V3`, 5: `M2`, 6: `M1` |

## Repository Layout

```
docs/images/                     README images
ESP32_Diff_Drive/
├── ESP32_Diff_Drive.kicad_pro   KiCad project
├── ESP32_Diff_Drive.kicad_sch   Schematic
├── ESP32_Diff_Drive.kicad_pcb   PCB layout
└── libraries/                   Project symbols, footprints, and 3D models
```

## Getting Started

1. Open `ESP32_Diff_Drive/ESP32_Diff_Drive.kicad_pro` in **KiCad 10** or newer.
2. The project's symbol, footprint, and 3D model libraries are referenced relative to the project folder, so no extra library setup is needed.
3. Each component in the schematic has an LCSC part number in its `LCSC` field for JLCPCB assembly. The `fabrication-toolkit-options.json` file holds the settings for the [Fabrication Toolkit](https://github.com/bennymeg/Fabrication-Toolkit) plugin, which generates Gerbers, the BOM, and the placement file.

### Programming

The ESP32-S3 is programmed over USB-C. If the port doesn't appear, hold **BOOT**, press and release **RESET**, then release **BOOT** to enter the bootloader.

## License

_TBD_
