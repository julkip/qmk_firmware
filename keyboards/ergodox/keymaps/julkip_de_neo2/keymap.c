/*
 * NEO 2 Layout for Ergodox EZ
 * by Julian Kippels (julkip@web.de)
 *
 */

#include "ergodox.h"
#include "action_layer.h"
#include "led.h"
#include "keymap_extras/keymap_neo2.h"

#define NEO 0 // default layer - neo2 (With correct OS keyboard mapping for neo)
#define PMNEO 1 // poor man's neo (Handle like NEO, but on qwert(y/z) OS mapping)
#define NEOTHREE 2 // neo2's layer 3 (Neo's Layer 3 for Poor Mans Neo)
#define NEOFOUR 3 // neo2's layer 4 (Neo's Layer 4 for Poor Mans Neo)
#define GAMINGQ 4 // Using Ergodox as a Commandpad with neo keymapping

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

// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[NEO] = KEYMAP(  // layer 0 : neo2
        // left hand
        KC_ESC,  NEO_1,  NEO_2,  NEO_3,  NEO_4, NEO_5, KC_PGUP,
        KC_TAB,  NEO_X,  NEO_V,  NEO_L,  NEO_C, NEO_W, KC_BSPC,
        NEO_L1_L,  NEO_U,  NEO_I,  NEO_A,  NEO_E, NEO_O,
        KC_LSFT, NEO_UE,  NEO_OE,  NEO_AE,  NEO_P, NEO_Z, KC_ENT,
        KC_LCTL, KC_F1, KC_F2, KC_F3, KC_F4,
                                                  KC_F5, KC_F6,
                                                       KC_LALT,
                                     KC_SPC, NEO_L1_L, KC_LGUI,
        // right hand
             KC_PGDN, NEO_6, NEO_7, NEO_8,    NEO_9,   NEO_0,    NEO_MINS,
             KC_DEL,  NEO_K, NEO_H, NEO_G,    NEO_F,   NEO_Q,    NEO_SS,
                      NEO_S, NEO_N, NEO_R,    NEO_T,   NEO_D, NEO_Y,
             KC_ENT,  NEO_B, NEO_M, NEO_COMM, NEO_DOT, NEO_J, KC_RSFT,
                           KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT,  KC_RCTL,
        KC_F7,   KC_F8,
        KC_FN1,
        KC_RGUI, NEO_L2_L, KC_SPC
    ),

/* Keymap 1:
 * Poor man's Neo2
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
 *                                 | LSft | (L2) |------|       |------| (L3) | Space|
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */

[PMNEO] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, NEO_OE,    NEO_P,    NEO_T,    NEO_AE,    NEO_V,    KC_TRNS,
       MO(NEOTHREE), NEO_H,    NEO_G,    NEO_U,    NEO_L,    NEO_F,
       KC_NUBS, NEO_SS, NEO_D, NEO_Y, NEO_Q,    NEO_K,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, MO(NEOTHREE), KC_TRNS,
    // right hand
               KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NEO_J,
               KC_TRNS,  NEO_R,    NEO_S,    NEO_O,    NEO_E,    NEO_X,    NEO_MINS,
                         NEO_I,    NEO_B,    NEO_C,    NEO_W,    NEO_A,    NEO_UE,
               KC_TRNS,  NEO_Z,    NEO_M,    NEO_COMM, NEO_DOT,  NEO_N,    KC_NUHS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL,
       KC_TRNS, KC_TRNS,
       KC_FN4,
       KC_TRNS, MO(NEOFOUR), KC_TRNS
),


/* Keymap 3:
 *
 * hardware Neo2 layer 3
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  _   |  [   |  ]   |  ^   |      |           |      |      |  <   |  >   |  =   |  &   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  \   |  /   |  {   |  }   |  *   |------|           |------|  ?   |  (   |  )   |  -   |  :   |  @     |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  #   |  $   |  |   |  ~   |  `   |      |           |      |  +   |  %   |  "   |  '   |  ;   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RCtrl|      |      |
 *                                 | LSft |      |------|       |------|      |   0  |
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */

[NEOTHREE] = KEYMAP(
	// left hand
          KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_NO,
          KC_NO, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_NO,
          KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
          KC_NO, KC_ESC,  KC_TAB,  KC_INS,  KC_ENT,  KC_UNDO, KC_NO,
          KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                              KC_NO, KC_NO,
                                                                   KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
               KC_NO, KC_NO, NEO_7,  NEO_8,  NEO_9,  KC_RBRC, NEO_MINS,
                      KC_NO, NEO_4,  NEO_5,  NEO_6,  NEO_COMM, NEO_DOT,
               KC_NO, KC_NO, NEO_1,  NEO_2,  NEO_3,  KC_NO,   KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
        KC_NO,    KC_NO,
        KC_TRNS,
        KC_TRNS, KC_TRNS, NEO_0
),

/* Keymap 3:
 *
 * hardware Neo2 layer 4
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | PgUp | BSpc |  Up  |  Del | PgDn |      |           |      |      |   7  |   8  |   9  |   +  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home | Left | Down | Right|  End |------|           |------|      |   4  |   5  |   6  |   ,  |   .    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  Esc |  Tab |  Ins |  Ret | Undo |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAlt |       | RCtrl|      |      |
 *                                 | LSft |      |------|       |------|      |   0  |
 *                                 |      |      | LGui |       | RGui |      |      |
 *                                 `--------------------'       `--------------------'
 */

[NEOFOUR] = KEYMAP(
	// left hand
          KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,   KC_NO,
          KC_NO, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, KC_NO,
          KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
          KC_NO, KC_ESC,  KC_TAB,  KC_INS,  KC_ENT,  KC_UNDO, KC_NO,
          KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                              KC_NO, KC_NO,
                                                                   KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
               KC_NO, KC_NO, NEO_7,  NEO_8,  NEO_9,  KC_RBRC, NEO_MINS,
                      KC_NO, NEO_4,  NEO_5,  NEO_6,  NEO_COMM, NEO_DOT,
               KC_NO, KC_NO, NEO_1,  NEO_2,  NEO_3,  KC_NO,   KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
        KC_NO,    KC_NO,
        KC_NO,
        KC_TRNS, KC_TRNS, NEO_0
),

/* Keymap 4:
 *
 * QWERTY Gaming on Neo2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  1   |  2   |  3   |  4   |  5   |  6   |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |  P   |  Q   |  W   |  E   |  R   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------| BkSp |           |      |------+------+------+------+------+--------|
 * |        |  I   |  A   |  S   |  D   |  F   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LSft  |  M   |  Z   |  X   |  C   |  V   | Ret  |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl |  F1  |  F2  |  F3  |  F4  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F5  |  F6  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | L0   |      |      |
 *                                 | Spc  | LAlt |------|       |------|      |      |
 *                                 |      |      | LGui |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[GAMINGQ] = KEYMAP(
	// left hand
          KC_ESC, NEO_1,    NEO_2,   NEO_3,    NEO_4,  NEO_5,   NEO_6,
          KC_TAB,  NEO_P, NEO_Q, NEO_W,   NEO_E,  NEO_R, KC_BSPC,
          KC_NO,  NEO_I, NEO_A, NEO_S, NEO_D, NEO_F,
          KC_LSFT,  NEO_M,  NEO_Y,  NEO_X,  NEO_C,  NEO_V, KC_ENT,
          KC_LCTL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,
                                                              KC_F5, KC_F6,
                                                                   KC_NO,
                                                 KC_SPC, KC_LALT, KC_NO,
        // right hand
               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
               KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
                      KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
               KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
        KC_NO,    KC_NO,
        KC_FN0,
        KC_NO, KC_NO, KC_NO
),
};

// TODO: Hier weitermachen FN-Zeuch usw

const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_FUNCTION(NEO),
	[1] = ACTION_FUNCTION(PMNEO),
	[4] = ACTION_FUNCTION(GAMINGQ),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	if (record->event.pressed) {
		if (id == NEO) layer_clear();
		if (id == PMNEO) layer_on(1);
		if (id == GAMINGQ) layer_on(4);
	}
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_3_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
	case 3:
            ergodox_right_led_3_on();
            ergodox_right_led_2_on();
            break;
	case 4:
	    ergodox_right_led_1_on();
	    break;
        default:
            // none
            break;
    }

};
