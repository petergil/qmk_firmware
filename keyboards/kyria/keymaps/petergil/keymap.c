/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H

//#define UNICODE_SELECTED_MODES UC_LNX, UC_OSX, UC_WIN, UC_WINC
//#define UNICODE_CYCLE_PERSIST false

enum unicode_names {
  OELOW,
  OEUP,
  AELOW,
  AEUP,
  AOLOW,
  AOUP,
  BANG,
  IRONY,
  SNEK,
  THUMBUP,
  CHECKMARK,
  CROSS,
  SHAMROCK,
  RAD,
  BIO,
  POOP,
  CRASH,
  LIGHTING
};

const uint32_t PROGMEM unicode_map[] = {
  // Start with letters
  [OELOW] = 0x00F6,      // ö
  [OEUP]  = 0x00D6,
  [AELOW] = 0x00E4,      // ä
  [AEUP]  = 0x00C4,
  [AOLOW] = 0x00E5,      // å
  [AOUP]  = 0x00C5,
  // punctuation
  [BANG]  = 0x203D,      // ‽
  [IRONY] = 0x2E2E,      // ⸮
  // emojis
  [SNEK]  = 0x1F40D,     // 🐍
  [THUMBUP]   = 0x1F44D, // 👍
  [CHECKMARK] = 0x2705,  // ✅
  [CROSS]     = 0x274C,  // ❌
  [SHAMROCK]  = 0x2618,  // ☘
  [RAD]       = 0x2622,  // ☢
  [BIO]       = 0x2623,  // ☣
  [POOP]      = 0x1F4A9, // 💩
  [CRASH]     = 0x1F4A5, // 💥
  [LIGHTING]  = 0x26A1,  // ⚡  
};

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |LShift|LSpace|  |RSpace|LShift|   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | Del  | Enter| Space| Esc  |  | Enter| Space| Tab  | Bksp | AltGr|
 *                        |      |      | Alt  | Lower| Raise|  | Lower| Raise|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
      LT(_RAISE, KC_ESC),       KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,
      MT(MOD_LCTL, KC_BSPC),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT,                 KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT,   KC_LSPO, KC_RSPC, KC_LEAD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
              KC_LGUI, KC_DEL, MT(MOD_LALT, KC_ENT), LT(_LOWER, KC_SPC), LT(_RAISE, KC_ESC), LT(_LOWER, KC_ENT), LT(_RAISE, KC_SPC), KC_TAB,  KC_BSPC, KC_RALT
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                              |      |      |      |      |      |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                     _______, _______, _______, _______, _______, KC_BSLS,
      _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                      KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                 _______, _______, _______, KC_SCLN, KC_EQL,  KC_EQL,  KC_SCLN, _______, _______, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |  Å     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              | Left | Down | Up   | Right|   Ö  |  Ä     |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|✅/👍 |⚡/❌ |  | ☢/☣| 🐍/💩| MLeft| Mdown| MUp  |MRight|RClick|        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |LClick|WClick|      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           XP(AOLOW,AOUP),
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                                                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XP(OELOW,OEUP), XP(AELOW,AEUP),
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, XP(CHECKMARK,THUMBUP), XP(LIGHTING,CROSS), XP(RAD,BIO), XP(POOP,SNEK), KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MS_BTN3,        _______,
                                 _______, _______, _______, _______,               _______,            _______,     _______,       KC_MS_BTN1, KC_MS_BTN2, _______
    ),
    /*    Adjust
 * Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/**/ // Leader stuff takes a fairly significant amount of space so comment out when experimenting with some stuff
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) { // Fuuuuuuuu
      send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
    }
    // SEQ_TWO_KEYS(KC_D, KC_D) {
    //   SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    //   }
    // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
    //   SEND_STRING("https://start.duckduckgo.com\n");
    // }
    // SEQ_TWO_KEYS(KC_A, KC_S) {
    //   register_code(KC_LGUI);
    //   register_code(KC_S);
    //   unregister_code(KC_S);
    //   unregister_code(KC_LGUI);
    // }
  }
}
// */

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

//static void render_slave(void) {
    // QMK Logo and version information
  //render_qmk_logo();
    //oled_write_P(PSTR("Kyria rev1.0\n\n"), false);
  // https://beta.docs.qmk.fm/using-qmk/software-features/feature_wpm

    /* // Host Keyboard LED Status */
    /* uint8_t led_usb_state = host_keyboard_leds(); */
    /* oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false); */
    /* oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false); */
    /* oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false); */
  //}
void oled_task_user(void) {
    if (is_keyboard_master()) {
      render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {

    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      switch (get_highest_layer(layer_state)) {
      case _LOWER:
        // Skip/Prev song
        if (clockwise) {
          tap_code(KC_MNXT);
        } else {
          tap_code(KC_MPRV);
        }
        break;
      default:
        // Volume control
        if (clockwise) {
          tap_code(KC_VOLD);
        } else {
          tap_code(KC_VOLU);
        }
      }
    }
    else if (index == 1) {
      switch (get_highest_layer(layer_state)) {
      case _RAISE:
        // Wheel up/down
        if (clockwise) {
          tap_code(KC_MS_WH_DOWN);
        } else {
          tap_code(KC_MS_WH_UP);
        }
        break;
      default:
        // Page up/Page down
        if (clockwise) {
          tap_code(KC_PGDN);
        } else {
          tap_code(KC_PGUP);
        }
      }
    }
}
#endif
