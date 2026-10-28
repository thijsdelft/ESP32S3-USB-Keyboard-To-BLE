/**
 * @file Config.h
 * @brief Global configuration constants for the USB-to-BLE Bridge.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// ============================================================================
// CONFIGURATION - Edit these to customize behavior
// ============================================================================

/** @brief Device names for each slot (will show up in Bluetooth settings) */
#define DEVICE_NAME_1 "ThijsBLEBoard"
#define DEVICE_NAME_2 "USB-BLE Dev 2"
#define DEVICE_NAME_3 "USB-BLE Dev 3"

/** @brief Manufacturer name reported over BLE */
#define DEVICE_MANUFACTURER "ESP32-S3"

/** @brief Battery level reported over BLE (0-100) */
#define BATTERY_LEVEL 99

/** @brief Number of available device slots (maximum 3 recommended) */
#define NUM_DEVICE_SLOTS 1

/**
 * @brief Delay after a BLE connection before the bonds are copied to the
 * current slot's NVS namespace, so pairing has finished.
 */
#define BOND_SAVE_DELAY_MS 5000

/** @brief Key combo for device switching: Scroll Lock + number key */
#define ENABLE_DEVICE_SWITCHING false

/**
 * @brief LED feedback pin (blinks to show current slot)
 * Set to -1 to disable, or use your board's built-in LED pin
 */
#define LED_FEEDBACK_PIN -1
#define LED_NEOPIXEL 21

#endif // CONFIG_H
