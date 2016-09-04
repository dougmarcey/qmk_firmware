// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |   -  |           |   =  |   6  |   7  |   8  |   9  |   0  | Bksp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab/~L2|   Q  |   W  |   E  |   R  |   T  |  T/  |           |  Y/  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|  ~L1 |           |  ~L1 |------+------+------+------+------+--------|
 * | -/Ctrl |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/~L2| Enter  |
 * |--------+------+------+------+------+------| B/   |           |  N/  |------+------+------+------+------+--------|
 * |(/LShift|Z/Ctrl|   X  |   C  |   V  |   B  | LCAG |           | HYPR |   N  |   M  |   ,  |   .  |//Ctrl|)/RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |Dl/Alt| Left | Right|                                       |  Up  | Down |   [  |   ]  |  L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Mute | VlUp |       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Spc/ | Entr/| VlDn |       | PgUp | Bksp/| Spce/|
 *                                 | LGui | Alt  |------|       |------| Alt  | LGui |
 *                                 |      |      |ESC/GS|       |PgD/GS|      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_MINS,
        LT(MDIA,KC_TAB),KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   LT(SYMB, KC_T),
        CTL_T(KC_MINS), KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSPO,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   LCAG_T(KC_B),
        LT(SYMB,KC_GRV),KC_QUOT,      ALT_T(KC_DEL),  KC_LEFT,KC_RGHT,
                                                                       KC_MUTE,  KC_VOLU,
                                                                                 KC_VOLD,
                                                    GUI_T(KC_SPC),ALT_T(KC_ENT), MT((MOD_LGUI|MOD_LSFT),KC_ESC),
        // right hand
             KC_EQL,      KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_BSPC,
             LT(SYMB,KC_Y),KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                           KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_ENT,
             ALL_T(KC_N),  KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSPC,
                                   KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          TG(SYMB),
             KC_HOME, KC_END,
             KC_PGUP,
             MT((MOD_LGUI|MOD_LSFT),KC_PGDN), ALT_T(KC_BSPC), GUI_T(KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      | Left |   7  |   8  |   9  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Right|   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|  "/  |           |  '/  |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  | LCAG |           | HYPR |   0  |   1  |   2  |   3  |   /  |   F12  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |   &  |      |      |      |                                       |      |      |   .  |   *  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,LCAG_T(KC_DQUO),
       KC_TRNS,KC_AMPR,KC_TRNS ,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_LEFT, KC_7,   KC_8,    KC_9,    KC_PMNS, KC_TRNS,
                KC_RIGHT,KC_4,   KC_5,    KC_6,    KC_PPLS, KC_TRNS, 
ALL_T(KC_QUOT), KC_0,    KC_1,   KC_2,    KC_3,    KC_PSLS, KC_F12,
                         KC_TRNS,KC_TRNS, KC_DOT,  KC_PAST, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | BrDn | BrUp |      |      |      | Tnsy |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|      |  Lft |  Dn  |  Rt  |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |  Stop  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, 
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_MSTP,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

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
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
