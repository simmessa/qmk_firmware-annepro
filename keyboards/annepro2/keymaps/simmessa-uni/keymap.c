#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "quantum.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
};

/*
  * Some accented chars I'd like to send to my Italian language OS while on EN keyboard:
  * 
  * ò = U+00F2 = 0x0F2, à = U+00E0 = 0x0E0, ù = U+00F9 = 0x0F9
  * è = U+00E8 = 0x0E8, é = U+00E9 = 0x0E9, ì = U+00EC = 0x0EC
  *
  * I'll be using tap dance for those :)
*/

//TAP dance declarations
enum {
    TD_OGRAVE, //0x0F2
    TD_AGRAVE, //0x0E0
    TD_UGRAVE, //0x0F9
    TD_EGRAVE, //0x0E8
    TD_EACUTE, //0x0E9
    TD_IGRAVE, //0x0EC
}

/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | esc~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  | =/ì |   Bksp   |
* |-----------------------------------------------------------------------------------------+
* |   Tab  |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  | [/è | ]/é |   \    |
* |-----------------------------------------------------------------------------------------+
* |   FN1   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  | l/ò | ;/à | '/ù |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  FN1  |  Alt  |  Ctrl |  Del  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |   Caps  |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |                |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |       |       |       |
* \-----------------------------------------------------------------------------------------/
*/

 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  //TAP dance definitions
  qk_tap_dance_action_t tap_dance_actions[] = {
      // Tap once for normal char, twice for accented
      [TD_OGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_L, UC(0x0F2)),
      [TD_AGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, UC(0x0E0)),
      [TD_UGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, UC(0x0F9)),
      [TD_EGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, UC(0x0E8)),
      [TD_EACUTE] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, UC(0x0E9)),
      [TD_IGRAVE] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, UC(0x0EC)),
  };

 [_BASE_LAYER] = KEYMAP( /* Tweaked base */
   KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, TD(TD_IGRAVE), KC_BSPC,
   KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_EGRAVE), TD(TD_EACUTE), KC_BSLS,
   LT(_FN1_LAYER,KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, TD(TD_OGRAVE), TD(TD_AGRAVE), TD(TD_UGRAVE), KC_ENT,
   KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(_FN1_LAYER), KC_RALT, KC_RCTL, KC_DEL
),
  /*
  * 
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~` |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab   |  q  | UP  |  e  |  r  |  t  |  y  | LON |LOFF|LBRI| LMODE | HOME | END |  PGUP  |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  | BT1 | BT2 | BT3 | BT4 |  UP  |  UP |  ' |    PGDN     |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |PREV |PLAY| NEXT | VOL- | VOL+ |  n  |  m  | LEFT | DOWN | RIGHT |  Shift   |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  FN1  |  ALT  |  Ctrl |  Del  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* FN1 */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_HOME, KC_END, KC_PGUP,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_UP, KC_UP, KC_TRNS, KC_PGDN,
    KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}
