/* Copyright 2022 Natalie Dawson <natalie.p.dawson@gmail.com>
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
#include "keycodes.h"
#include QMK_KEYBOARD_H

enum layers {
    _DVORAK = 0,
    _COLEMAK,
    _QWERTY,
    _GAME,
    _NAV,
    _NUM,
    _FUN,
    _SYM,
};

#define SHFT_U      LSFT_T(KC_U)
#define CTRL_E      LCTL_T(KC_E)
#define ALT_O       LALT_T(KC_O)
#define GUI_A       LGUI_T(KC_A)

#define SHFT_H      RSFT_T(KC_H)
#define CTRL_T      LCTL_T(KC_T)
#define ALT_N       LALT_T(KC_N)
#define GUI_S       LGUI_T(KC_S)

#define SHFT_T      LSFT_T(KC_T)
#define CTRL_S      LCTL_T(KC_S)
#define ALT_R       LALT_T(KC_R)
//#define GUI_A       LGUI_T(KC_A)

#define SHFT_N      RSFT_T(KC_N)
//#define CTRL_E      LCTL_T(KC_E)
#define ALT_I       LALT_T(KC_I)
#define GUI_O       LGUI_T(KC_O)

#define SHFT_F      LSFT_T(KC_F)
#define CTRL_D      LCTL_T(KC_D)
#define ALT_S       LALT_T(KC_S)
//#define GUI_A       LGUI_T(KC_A)

#define SHFT_J      RSFT_T(KC_J)
#define CTRL_K      LCTL_T(KC_K)
#define ALT_L       LALT_T(KC_L)
#define GUI_SC      LGUI_T(KC_SCLN)

#define KC_STAB     S(KC_TAB)

#define DVORAK      DF(_DVORAK)
#define COLEMAK     DF(_COLEMAK)
#define QWERTY      DF(_QWERTY)

#define TGLGAME     TG(_GAME)

#define SPC_NAV     LT(_NAV, KC_SPC)
#define TAB_NUM     LT(_NUM, KC_TAB)

#define ENT_FUN     LT(_FUN, KC_ENT)
#define BSP_SYM     LT(_SYM, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, GUI_A,   ALT_O,   CTRL_E,  SHFT_U,  KC_I,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   XXXXXXX, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    XXXXXXX, XXXXXXX,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         TGLGAME, XXXXXXX, KC_ESC,  SPC_NAV, TAB_NUM,
//                      └────────┴────────┴────────┴────────┴────────┘
//                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
                     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    XXXXXXX,
//                  ├────────┼────────┼────────┼────────┼────────┼────────┤
                     KC_D,    SHFT_H,  CTRL_T,  ALT_N,   GUI_S,   XXXXXXX,
//┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX,
//└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
       ENT_FUN, BSP_SYM, KC_DEL,  XXXXXXX, COLEMAK
//    └────────┴────────┴────────┴────────┴────────┘
                      ),
    [_COLEMAK] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, GUI_A,   ALT_R,   CTRL_S,  SHFT_T,  KC_D,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         XXXXXXX, XXXXXXX, KC_ESC,  SPC_NAV, TAB_NUM,
                      //└────────┴────────┴────────┴────────┴────────┘
//                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, XXXXXXX,
//                  ├────────┼────────┼────────┼────────┼────────┼────────┤
                     KC_H,    SHFT_N,  CTRL_E,  ALT_I,   GUI_O,    XXXXXXX,
//┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
//└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
       ENT_FUN, BSP_SYM, KC_DEL,  XXXXXXX, QWERTY
//    └────────┴────────┴────────┴────────┴────────┘
                  ),
    [_QWERTY] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, GUI_A,   ALT_S,   CTRL_D,  SHFT_F,  KC_G,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         XXXXXXX, XXXXXXX, KC_ESC,  SPC_NAV, TAB_NUM,
                      //└────────┴────────┴────────┴────────┴────────┘
//                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
//                  ├────────┼────────┼────────┼────────┼────────┼────────┤
                     KC_H,    SHFT_J,  CTRL_K,  ALT_L,   GUI_SC,  KC_QUOT,
//┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
//└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
       ENT_FUN, BSP_SYM, KC_DEL,  XXXXXXX, DVORAK
//    └────────┴────────┴────────┴────────┴────────┘
                      ),
    [_GAME] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_ESC,  _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   _______, _______, _______, _______, _______, _______, _______, _______,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         _______, _______, KC_LSFT, KC_SPC,  KC_LCTL,
//                      └────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       _______, _______, _______, _______, _______, _______,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       _______, KC_H,    KC_T,    KC_N,    KC_S,    _______,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______, _______,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         _______, _______, _______, _______, XXXXXXX
//      └────────┴────────┴────────┴────────┴────────┘
                    ),
    [_NAV] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
                      //└────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         KC_ENT,  KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX
//      └────────┴────────┴────────┴────────┴────────┘
                      ),
    [_NUM] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, XXXXXXX,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
//                      └────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, XXXXXXX,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, KC_NUM, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, XXXXXXX,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         KC_PENT, KC_BSPC, KC_KP_0, XXXXXXX, XXXXXXX
//      └────────┴────────┴────────┴────────┴────────┘
                      ),
    [_FUN] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_SCRL,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS, XXXXXXX, XXXXXXX,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         XXXXXXX, XXXXXXX, KC_APP,  KC_SPC,  KC_TAB,
//                      └────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//      └────────┴────────┴────────┴────────┴────────┘
                      ),
    [_SYM] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, KC_TILD, KC_BSLS, KC_PIPE, KC_SLSH, KC_COLN,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         XXXXXXX, XXXXXXX, KC_GRV,  KC_SPC,  KC_TILD,
//                      └────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       KC_SCLN, KC_LABK, KC_EQL,  KC_RABK, KC_MINS, XXXXXXX,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       KC_LBRC, KC_LPRN, KC_LCBR, KC_UNDS, KC_PLUS, XXXXXXX,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, KC_RBRC, KC_RPRN, KC_RCBR, KC_TILD, KC_QUES, XXXXXXX,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//      └────────┴────────┴────────┴────────┴────────┘
                      )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _DVORAK:
            oled_write_P(PSTR("Dvorak\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game Mode\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Function\n"), false);
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

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif
