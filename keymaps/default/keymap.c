/*
Copyright 2021 Adam Honse

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#define INDICATOR_KEY 28
#define BLUETOOTH_LED 62
#define BATTERY_LED 61
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
//
//

#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif
enum my_keycodes {
// #ifdef VIA_ENABLE
//     MY_REBOOT = USER00,
// #else
    MY_REBOOT = SAFE_RANGE,
// #endif

    QK_LAYER_MASK,
    QK_LAYER_NO_MASK,
    QK_TOGGLE_PANEL_LED,
};

bool BATTERYENABLED = false;
bool BLUETOOTHSTATE = false;

bool panelLedEnable = true;

short layer_MASK = 0;
enum layer_names { BASE, FN1, FN2, FN3, FN4 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_60_ansi(/* Base */
                            KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, LT(FN1, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT(FN1, KC_LEFT), LT(FN2, KC_DOWN), RCTL_T(KC_RGHT)),
    /*
     * Layer FN1
     * ,-----------------------------------------------------------------------------------------.
     * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
     * |-----------------------------------------------------------------------------------------+
     * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
     * \-----------------------------------------------------------------------------------------/
     *
     */
    [FN1] = LAYOUT_60_ansi(/* FN1 */
                           KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, KC_INS, KC_DEL, _______, _______, _______, _______, _______, _______, _______, MO(FN2), QK_BOOTLOADER),
    /*
     * Layer FN2
     * ,-----------------------------------------------------------------------------------------.
     * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 | F7 | F8 | MOD | TOG | BRI- | BRI+ |    Bksp   |
     * |-----------------------------------------------------------------------------------------+
     * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
     * |-----------------------------------------------------------------------------------------+
     * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
     * |-----------------------------------------------------------------------------------------+
     * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
     * |-----------------------------------------------------------------------------------------+
     * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
     * \-----------------------------------------------------------------------------------------/
     *
     */
    [FN2] = LAYOUT_60_ansi(/* FN2 */
                           _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MODE_FORWARD, RGB_HUI, RGB_VAI, RGB_SPI, _______, MO(FN2), QK_LAYER_MASK, KC_UP, _______, MY_REBOOT, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_DEL, _______, _______, _______, _______, _______, _______, MO(FN1), MO(FN2), QK_BOOTLOADER),
    [FN3] = LAYOUT_60_ansi(/* FN2 */
                           _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MODE_FORWARD, RGB_HUI, RGB_VAI, RGB_SPI, _______, MO(FN2), _______, KC_UP, _______, MY_REBOOT, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_DEL, _______, _______, _______, _______, _______, _______, MO(FN1), MO(FN2), QK_BOOTLOADER),
};

void restartKBBB(void) {
    clear_keyboard();

    rgb_matrix_disable();
#if defined(MIDI_ENABLE) && defined(MIDI_BASIC)
    process_midi_all_notes_off();
#endif
#ifdef AUDIO_ENABLE
#    ifndef NO_MUSIC_MODE
    music_all_notes_off();
#    endif
    uint16_t timer_start = timer_read();
    PLAY_SONG(goodbye_song);
    shutdown_user();
    while (timer_elapsed(timer_start) < 250) wait_ms(1);
    stop_all_notes();
#else
    shutdown_user();
    wait_ms(100);
#endif
#ifdef HAPTIC_ENABLE
    haptic_shutdown();
#endif
    NVIC_SystemReset();
}

#ifdef OS_DETECTION_ENABLE

os_variant_t previous_os = OS_UNSURE;
#endif
void panelIndicators(void) {
    // os_variant_t os                 = detected_host_os();
    //

    if (panelLedEnable == false) {
        rgb_matrix_set_color(BATTERY_LED, 0, 0, 0);
        rgb_matrix_set_color(BLUETOOTH_LED, 0, 0, 0);
        return;
    }

#ifdef OS_DETECTION_ENABLE
    if (BLUETOOTHSTATE == false) {
        switch (previous_os) {
            case OS_UNSURE:

                rgb_matrix_set_color(BLUETOOTH_LED, 0, 100, 100);
                break;
            case OS_LINUX:

                rgb_matrix_set_color(BLUETOOTH_LED, 255, 255, 30);
                break;
            case OS_WINDOWS:

                rgb_matrix_set_color(BLUETOOTH_LED, 0, 0, 255);
            case OS_MACOS:

                rgb_matrix_set_color(BLUETOOTH_LED, 255, 0, 255);
                break;
            case OS_IOS:
                break;
        }
    }
#endif

    if (BATTERYENABLED) {
        rgb_matrix_set_color(BATTERY_LED, 255, 0, 255);
    } else {
        rgb_matrix_set_color(BATTERY_LED, 0, 0, 255);
    }
}

void suspend_power_down_user(void) {
#ifdef OS_DETECTION_ENABLE

    previous_os = OS_UNSURE;
#endif

    if (!BATTERYENABLED) {
        rgb_matrix_disable();
    } else {
        rgb_matrix_enable();

        // rgb_matrix_set_color(BATTERY_LED, 0, 100, 100);
    }

    panelIndicators();
}
void keyboard_pre_init_user(void) {
    g_led_config.flags[BATTERY_LED] = 0;

    g_led_config.flags[BLUETOOTH_LED] = 0;
    rgb_matrix_set_color(BATTERY_LED, 0, 0, 0);
    rgb_matrix_set_color(BLUETOOTH_LED, 255, 0, 0);
}

#ifdef OS_DETECTION_ENABLE
static uint32_t post_timer;
#endif
void            keyboard_post_init_user(void) {
#ifdef OS_DETECTION_ENABLE
    previous_os = detected_host_os();
    post_timer  = timer_read32();

#endif
    panelIndicators();
}

#if defined(DIP_SWITCH_PINS) || defined(DIP_SWITCH_MATRIX_GRID)
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {  // Win/Android mode
                // do stuff
                //
                // rgb_matrix_set_color(BLUETOOTH_LED, 0, 255, 255);
                //

                BLUETOOTHSTATE = true;
            } else {  // Mac/iOS mode
                // do stuff
                BLUETOOTHSTATE = false;
            }
            break;
        case 1:
            if (active) {  // Cable mode
                BATTERYENABLED = true;
            } else {  // BT mode
                BATTERYENABLED = false;
            }
            break;
    }
    panelIndicators();
    return true;
}
#endif
bool            delayedEnable = false;
static uint32_t key_timer;
#define ENABLEDELAY 300  // ms to wait until rgblight time out, 900K ms is 15min.
#define BOOTDELAY 7000
void suspend_wakeup_init_user(void) {
    delayedEnable = true;
    key_timer     = timer_read32();
    // rgb_matrix_enable();

#ifdef OS_DETECTION_ENABLE
    // previous_os = detected_host_os();
    //
        os_variant_t os = detected_host_os();
    if (previous_os == OS_UNSURE && timer_elapsed32(post_timer) > BOOTDELAY && os != OS_UNSURE) {

    post_timer  = timer_read32();
    previous_os  = os;

    panelIndicators();
            restartKBBB();
        return ;
    }
    previous_os  = os;

#endif

    panelIndicators();
}
void check_rgb_timeout(void) {
    if (delayedEnable && timer_elapsed32(key_timer) > ENABLEDELAY)  // check if RGB has already timeout and if enough time has passed
    {
        rgb_matrix_enable();
        delayedEnable = false;
    }
}
void    housekeeping_task_user(void) { check_rgb_timeout(); }
uint8_t getLayer(void) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer == 0) {
        layer = biton32(default_layer_state);
    }
    return layer;
}

void maskLayer(uint8_t layer) {
    // uint8_t layer = getLayer();
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index == INDICATOR_KEY || index == BLUETOOTH_LED || index == BATTERY_LED) {
                continue;
            }

            //  DEFAULT LAYER

            keypos_t keypos = {col, row};

            // off
            if (keymap_key_to_keycode(layer, keypos) == KC_NO) {
                g_led_config.flags[index] = 0;
                rgb_matrix_set_color(index, RGB_OFF);
            } else
                // transparent
                if (keymap_key_to_keycode(layer, keypos) == KC_TRNS) {
                    g_led_config.flags[index] = 0;
                    rgb_matrix_set_color(index, RGB_OFF);
                    // rgb_matrix_set_layer_color(
                    //     index, resolve_effective_kc_layer(keypos, layer));
                } else {
                    g_led_config.flags[index] = 4;
                }
        }
    }
}

int setIndicator(uint8_t layer) {
    // panelIndicators();
    //
    if (layer_MASK > 0) {
        maskLayer(layer);
    }

    switch (layer) {
        case FN1:
            g_led_config.flags[INDICATOR_KEY] = 0;
            rgb_matrix_set_color(INDICATOR_KEY, 255, 0, 0);
            return 0;
            break;

        case FN2:
            // Allows for a preview of RGB adjustments
            g_led_config.flags[INDICATOR_KEY] = 0;
            rgb_matrix_set_color(INDICATOR_KEY, 0, 255, 0);
            return 0;
            break;

        case FN3:
            // Allows for a preview of RGB adjustments

            g_led_config.flags[INDICATOR_KEY] = 0;
            rgb_matrix_set_color(INDICATOR_KEY, 0, 0, 255);
            return 0;
            break;
        case BASE:

            g_led_config.flags[INDICATOR_KEY] = 4;
            // rgb_matrix_set_color(INDICATOR_KEY, 255, 255,255);
            return 0;
            break;
    }

    return 1;
}
void changeLayerMasK(bool reverse) {
    if (reverse) {
        // First temporarily canceling both shifts so that
        if (layer_MASK == 1) {
            layer_MASK = 0;
        }
    } else {
        if (layer_MASK == 0) {
            layer_MASK = 1;
        }
    }

    if (layer_MASK > 0) {
        maskLayer(getLayer());
    } else {
        maskLayer(default_layer_state);
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();

    switch (keycode) {
        case MY_REBOOT:

            if (record->event.pressed) {
                restartKBBB();
            }
            return false;  // Skip all further processing of this key
            break;
        case QK_LAYER_MASK:
            if (record->event.pressed) {
                changeLayerMasK(mod_state & MOD_MASK_SHIFT);
                // Detect the activation of either shift keys
            }
            return false;

            break;

        case QK_LAYER_NO_MASK:
            if (record->event.pressed) {
                changeLayerMasK(~mod_state & MOD_MASK_SHIFT);
                // Detect the activation of either shift keys
            }
            return false;
            break;
        case QK_TOGGLE_PANEL_LED:
            if (record->event.pressed) {
                panelLedEnable = !panelLedEnable;
                panelIndicators();
                // Detect the activation of either shift keys
            }
            return false;
            break;
        default:
            return true;  // Process all other keycodes normally
    }
}
// void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//
// }
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    if (layer == 0) {
        setIndicator(biton32(default_layer_state));
    } else {
        setIndicator(layer);
    }
    return state;
}
