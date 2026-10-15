/*
 * pin_definitions.h - Hardware pin assignments and wiring orientation
 *
 * Constants defined in this file describe the physical wiring
 * of a specific board revision: which MCU pin connects to which
 * peripheral, and how the motors and encoders are oriented.
 * These are hardware facts, not tunable behavior.
 */

#pragma once

// Battery charging pins 
#define CHG      36
#define PGOOD    35

// Battery voltage monitor 
#define VBAT_DIV  10

// Motor driver 
#define DRV_SLEEP 40

// Left motor 
#define MOT_LEFT_IN1    47  // PWM A
#define MOT_LEFT_IN2    33  // PWM B
#define MOT_LEFT_ENC_A  38  // Encoder channel A
#define MOT_LEFT_ENC_B  39  // Encoder channel B

// Right motor 
#define MOT_RIGHT_IN1     48  // PWM A 
#define MOT_RIGHT_IN2     34  // PWM B
#define MOT_RIGHT_ENC_A   41  // Encoder channel A
#define MOT_RIGHT_ENC_B   42  // Encoder channel B

// Motor / encoder wiring orientation (150:1 gearmotors)
// TODO: verify, the gearbox changes default shaft direction
#define MOT_LEFT_FLIP        true  // Swap PWM pins so +PWM = forward
#define MOT_LEFT_ENC_FLIP    true  // Swap encoder pins so +PWM = +count
#define MOT_RIGHT_FLIP      false   // Swap PWM pins so +PWM = forward
#define MOT_RIGHT_ENC_FLIP  false  // Swap encoder pins so +PWM = +count
