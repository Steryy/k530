/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


// /* USB Device descriptor parameter */
// #define VENDOR_ID       0x0C45
// #define PRODUCT_ID      0x5004
// #define DEVICE_VER      0x0001
//
//

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

#define DIODE_DIRECTION COL2ROW

#define MATRIX_COL_PINS { A8, A9, A10, A11, A12, A13, A14, A15, B0, B1, B2, B3, B4, B5 }
#define MATRIX_ROW_PINS { D7, D6, D5, D4, D3 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Per-key tapping term, for use with Magic FN */
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE

#define RGB_MATRIX_STARTUP_MODE  RGB_MATRIX_SOLID_COLOR

#define DIP_SWITCH_PINS {A6, B13 }

// #        define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 1024
// #define RGB_DISABLE_WHEN_USB_SUSPENDED
/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE
// #define USB_SUSPEND_WAKEUP_DELAY 100
#include "config_led.h"

#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN 2
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT 3
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define ENABLE_RGB_MATRIX_HUE_BREATHING
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define OS_DETECTION_ENABLE


#            define FEE_PAGE_SIZE (0x0040) // Page size = 64bytes
#define FEE_DENSITY_BYTES (FEE_PAGE_SIZE * FEE_DENSITY_PAGES - 1)
// Mouse
#define MK_3_SPEED
#define MK_C_OFFSET_UNMOD	16	//Cursor offset per movement (unmodified)
#define MK_C_INTERVAL_UNMOD	16	//Time between cursor movements (unmodified)
#define MK_C_OFFSET_0	8	//Cursor offset per movement (KC_ACL0)
#define MK_C_INTERVAL_0	32	//Time between cursor movements (KC_ACL0)
#define MK_C_OFFSET_1	16	//Cursor offset per movement (KC_ACL1)
#define MK_C_INTERVAL_1	16	//Time between cursor movements (KC_ACL1)
#define MK_C_OFFSET_2	32	//Cursor offset per movement (KC_ACL2)
#define MK_C_INTERVAL_2	16	//Time between cursor movements (KC_ACL2)
#define MK_W_OFFSET_UNMOD	1	//Scroll steps per scroll action (unmodified)
