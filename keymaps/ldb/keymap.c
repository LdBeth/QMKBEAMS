/* Copyright 2025 LdBeth
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
#include "features/socd_cleaner.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _BASE,
  _FN, _CT,
  _OSX, _XFN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    MEME_ = SAFE_RANGE,
    TOGG_RA, WAVE,
    SOCDON, SOCDOFF
};

#define RSTGPU LGUI(LCTL(LSFT(KC_B)))
#define X_COPY LGUI(KC_C)
#define X_PSTE LGUI(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_fullsize_ansi(
        KC_ESC,        KC_F1, KC_F2, KC_F3, KC_F4,    KC_F5, KC_F6, KC_F7, KC_F8,     KC_F9, KC_F10, KC_F11, KC_F12,    KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL,      KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,  KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS,      KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,       KC_ENT,                                  KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,         KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,         KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,  KC_LGUI, KC_LALT,                KC_SPC,                       KC_RGUI, KC_RALT, MO(_FN), KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,         KC_P0,       KC_PDOT
                                   ),
    [_FN] = LAYOUT_fullsize_ansi(
        KC_TRNS,    KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS,  KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT,  KC_WBAK, KC_WFWD, KC_TRNS, KC_TRNS,   KC_F13, KC_F14, KC_F15,
        WAVE,     DM_PLY1,DM_PLY2,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MUTE,KC_VOLD,KC_VOLU,DM_RSTP,          KC_F16, KC_F17, KC_F18,     KC_F22,   KC_F23,   KC_F24,  KC_TRNS,
        KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,MEME_,KC_TRNS,MEME_,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,            KC_F19, KC_F20, KC_F21,     KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
        QK_LOCK,      MEME_,KC_TRNS, KC_TRNS,MEME_,MEME_,KC_TRNS,MEME_, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,                                          KC_TRNS, KC_TRNS,  KC_TRNS,
        KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  MEME_,KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,           KC_TRNS,               DM_REC1, DM_REC2,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  RSTGPU, KC_TRNS,                 MO(_CT),                       KC_APP, TOGG_RA, KC_TRNS, NK_TOGG,            KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,      KC_TRNS
                                 ),
    [_CT] = LAYOUT_fullsize_ansi(
        KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, EE_CLR, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  SOCDON, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS, SOCDOFF, KC_TRNS, KC_TRNS, QK_RBT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                             KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, PDF(_OSX), KC_TRNS,                          KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,            KC_TRNS
                                 ),
    [_OSX] = LAYOUT_fullsize_ansi(
        KC_ESC,    KC_BRMD, KC_BRMU,KC_MCTL,KC_LPAD,X_COPY, X_PSTE,KC_MPRV,KC_MPLY, KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,    KC_F13,   KC_F14,  KC_F15,
        KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL,      KC_BSPC,   KC_PSCR,  KC_HOME, KC_PGUP,    KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,  KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS,      KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,       KC_ENT,                                  KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,         KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,         KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,  KC_LGUI, KC_LALT,                KC_SPC,                       KC_RGUI, KC_RALT, MO(_XFN),KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,         KC_P0,       KC_PDOT
                                   ),
    [_XFN] = LAYOUT_fullsize_ansi(
        KC_TRNS,    KC_F1, KC_F2, KC_F3, KC_F4,    KC_F5, KC_F6, KC_F7, KC_F8,     KC_F9, KC_F10, KC_F11, KC_F12,                        KC_F16, KC_F17, KC_F18,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EJCT,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                            KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, PDF(_BASE), KC_TRNS,                         MO(_CT),                             KC_TRNS, TOGG_RA, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,            KC_TRNS
                                 )
};

socd_cleaner_t socd_v = {{KC_W, KC_S}, SOCD_CLEANER_NEUTRAL};
socd_cleaner_t socd_h = {{KC_A, KC_D}, SOCD_CLEANER_LAST};

#define DEF_MACRO_KEY(code, str) case code: SEND_STRING(str); break
#define GET_ORIG_KEY(r) pgm_read_word(&keymaps[0][r->event.key.row][r->event.key.col])

// Initial delay before the first repeat.
#define INIT_DELAY_MS 300
// This array customizes the rate at which the Backspace key
// repeats. The delay after the ith repeat is REP_DELAY_MS[i].
// Values must be between 1 and 255.
static const uint8_t REP_DELAY_MS[] PROGMEM = {
  99, 79, 65, 57, 49, 43, 40, 35, 33, 30, 28, 26, 25, 23, 22, 20,
  20, 19, 18, 17, 16, 15, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10};

#define DEF_SPEED_KEY(key,cb) case key: {                               \
    static deferred_token token = INVALID_DEFERRED_TOKEN;               \
    static uint8_t rep_count = 0;                                       \
    if (!record->event.pressed) {                                       \
      cancel_deferred_exec(token);                                      \
      token = INVALID_DEFERRED_TOKEN;                                   \
    } else if (!token) {                                                \
      tap_code(key);                                                    \
      rep_count = 0;                                                    \
      uint32_t cb ## _callback(uint32_t trigger_time, void* cb_arg) {   \
        tap_code(key);                                                  \
        if (rep_count < sizeof(REP_DELAY_MS)) { ++rep_count; }          \
        return pgm_read_byte(REP_DELAY_MS - 1 + rep_count);             \
      }                                                                 \
      token = defer_exec(INIT_DELAY_MS, cb ## _callback, NULL);         \
    }                                                                   \
  } return false

static bool socd_cleaner_enabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (socd_cleaner_enabled) {
    if (!process_socd_cleaner(keycode, record, &socd_v)) return false;
    if (!process_socd_cleaner(keycode, record, &socd_h)) return false;
  }

  switch (keycode) {
    DEF_SPEED_KEY(KC_BSPC, bspc);
    DEF_SPEED_KEY(KC_ENT, entr);
  case MEME_:
    if (record->event.pressed) {
      switch (GET_ORIG_KEY(record)) {
        DEF_MACRO_KEY(KC_A,"allyourbasearebelongtous");
        DEF_MACRO_KEY(KC_Y,"yourargumentisinvalid");
        DEF_MACRO_KEY(KC_J,"justaccordingtokeikaku");
        DEF_MACRO_KEY(KC_I,"itsmorelikelythanyouthink");
        DEF_MACRO_KEY(KC_G,"goodnightsweetprince");
        DEF_MACRO_KEY(KC_F,"pressftopayrespects");
        DEF_MACRO_KEY(KC_M,"mykokoroisbrokoro");
      }
    } break;
  case TOGG_RA:
    if (record->event.pressed) {
      keymap_config.raw = eeconfig_read_keymap();
      keymap_config.swap_ralt_rgui = !keymap_config.swap_ralt_rgui;
      keymap_config.swap_control_capslock = keymap_config.swap_ralt_rgui;
      eeconfig_update_keymap(keymap_config.raw);
      clear_keyboard();
      return false;
    }
    break;
  case WAVE: {  // Types ~=~=~=~=~=~...
    static deferred_token token = INVALID_DEFERRED_TOKEN;
    static uint8_t phase = 0;

    if (!record->event.pressed) {  // On release.
      cancel_deferred_exec(token);
      token = INVALID_DEFERRED_TOKEN;
      // Ensure the pattern always ends on a "~".
      if ((phase & 1) == 0) { tap_code16(KC_TILD); }
      phase = 0;
    } else if (!token) {  // On press.

      uint32_t wave_callback(uint32_t trigger_time, void* cb_arg) {
        tap_code16((++phase & 1) ? KC_TILD : KC_EQL);
        return 30;
      }

      token = defer_exec(1, wave_callback, NULL);
    }
  } return false;
  case SOCDON:  // Turn SOCD Cleaner on.
    if (record->event.pressed) {
      socd_cleaner_enabled = true;
    }
    break;
  case SOCDOFF:  // Turn SOCD Cleaner off.
    if (record->event.pressed) {
      socd_cleaner_enabled = false;
    }
    break;
  }
  return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
