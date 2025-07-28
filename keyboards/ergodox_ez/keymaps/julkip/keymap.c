#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_extras/keymap_neo2.h"
#include "keymap_extras/keymap_german.h"

enum layers {
    NEO,      // neo layout
    PMNEO,    // poor mans neo
    NEOTHREE, // neo layer three
    NEOFOUR,  // neo layer four
    GAMINGQ   // Stupid commandpad stuff
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | PgUp |           | PgDn |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   X  |   V  |   L  |   C  |   W  | BKSP |           |  DEL |   K  |   H  |   G  |   F  |   Q  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  M3l   |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   Y    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LSft  |   Ü  |   Ö  |   Ä  |   P  |   Z  | RET  |           | RET  |   B  |   M  |   ,  |   .  |   J  |  RSft  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl |  F1  |  F2  |  F3  |  F4  |                                       |   ←  |   ↓  |   ↑  |  →   | RCtl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F5  |  F6  |       |  F7  |  F8  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       |  L1  |      |      |
 *                                 | Space|  M3l |------|       |------|  M4r | Space|
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NEO] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_PGUP,                KC_PGDN, KC_6, KC_7,   KC_8,    KC_9,   KC_0,     KC_MINS,
  KC_TAB,  NE_X,    NE_V,    NE_L,    NE_C,    NE_W,    KC_BSPC,                KC_DEL,  NE_K, NE_H,   NE_G,    NE_F,   NE_Q,     NE_SS,
  NE_L3L,  NE_U,    NE_I,    NE_A,    NE_E,    NE_O,                                     NE_S, NE_N,    NE_R,    NE_T,   NE_D,     NE_Y,
  KC_LSFT, NE_UDIA, NE_ODIA, NE_ADIA, NE_P,    NE_Z,    KC_ENT,                 KC_ENT,  NE_B, NE_M,    NE_COMM, NE_DOT, NE_J,     KC_RSFT,
  KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,                                                  KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_RCTL,
                                                KC_F5,  KC_F6,       KC_F7,     KC_F8,
                                                        KC_LALT,     TG(PMNEO),
                                        KC_SPC, NE_L3R, KC_LGUI,     KC_RGUI,   NE_L4R,  KC_SPC
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | PgUp |           | PgDn |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   X  |   V  |   L  |   C  |   W  | BKSP |           |  DEL |   K  |   H  |   G  |   F  |   Q  |   ß    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  (L2)  |   U  |   I  |   A  |   E  |   O  |------|           |------|   S  |   N  |   R  |   T  |   D  |   Y    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LSft  |   Ü  |   Ö  |   Ä  |   P  |   Z  | RET  |           | RET  |   B  |   M  |   ,  |   .  |   J  |  RSft  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Prnt |  F1  |  F2  |  F3  |  F4  |                                       |   ←  |   ↓  |   ↑  |  →   | RCtl |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F5  |  F6  |       |  F7  |  F8  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       |  L4  |      |      |
 *                                 | Space| (L2) |------|       |------| (L3) | Space|
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */
[PMNEO] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
  KC_TRNS, KC_X, KC_V,   KC_L, KC_C, KC_W, KC_TRNS,                          KC_TRNS, KC_K,   KC_H,    KC_G,    KC_F,    KC_Q, DE_SS,
  KC_TRNS, KC_U, KC_I,  KC_A, KC_E, KC_O,                                             KC_S, KC_N,    KC_R,    KC_D,    KC_T, KC_Y,
  KC_TRNS, DE_UDIA, DE_ADIA, DE_ODIA, KC_P, KC_Z, KC_TRNS,             KC_TRNS, KC_B, KC_M,    KC_COMM,    KC_DOT,    KC_J, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     TG(GAMINGQ),
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NEOTHREE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_WBAK
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
