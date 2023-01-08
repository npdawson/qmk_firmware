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

#include QMK_KEYBOARD_H

enum layers {
    _HD_TI = 0,
    _QWERTY,
    _GAME,
    _NAV,
    _NUM,
    _FUN,
    _SYM,
};

#define GUI_C       LGUI_T(KC_C)
#define ALT_S       LALT_T(KC_S)
#define CTRL_N      LCTL_T(KC_N)
#define SHFT_T      LSFT_T(KC_T)

#define SHFT_A      RSFT_T(KC_A)
#define CTRL_E      LCTL_T(KC_E)
#define ALT_I       LALT_T(KC_I)
#define GUI_H       LGUI_T(KC_H)

#define GUI_A       LGUI_T(KC_A)
//#define ALT_S       LALT_T(KC_S)
#define CTRL_D      LCTL_T(KC_D)
#define SHFT_F      LSFT_T(KC_F)

#define SHFT_J      RSFT_T(KC_J)
#define CTRL_K      LCTL_T(KC_K)
#define ALT_L       LALT_T(KC_L)
#define GUI_SC      LGUI_T(KC_SCLN)

#define QWERTY      DF(_QWERTY)
#define HD_TI       DF(_HD_TI)  

#define TGLGAME     TG(_GAME)

#define R_NAV       LT(_NAV, KC_R)
#define BSP_NUM     LT(_NUM, KC_BSPC)

#define ENT_FUN     LT(_FUN, KC_ENT)
#define SPC_SYM     LT(_SYM, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HD_TI] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   C(KC_C), KC_J,    KC_G,    KC_M,    KC_P,    KC_V,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   C(KC_V), GUI_C,   ALT_S,   CTRL_N,  SHFT_T,  KC_W,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   KC_AMPR, KC_X,    KC_F,    KC_L,    KC_D,    KC_B,    XXXXXXX, KC_MHEN,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         TGLGAME, KC_APP,  BSP_NUM, R_NAV,   KC_TAB,  
//                      └────────┴────────┴────────┴────────┴────────┘
//                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
                     KC_SCLN, KC_DOT,  KC_SLSH, KC_DQUO, KC_QUOT, TG(_NUM),
//                  ├────────┼────────┼────────┼────────┼────────┼────────┤
                     KC_COMM, SHFT_A,  CTRL_E,  ALT_I,   GUI_H,   XXXXXXX,
//┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_HENK, XXXXXXX, KC_MINS, KC_U,    KC_O,    KC_Y,    KC_K,    KC_EQL,  
//└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
       KC_ESC,  SPC_SYM, ENT_FUN, KC_DEL,  QWERTY
//    └────────┴────────┴────────┴────────┴────────┘
                  ),
    [_QWERTY] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   _______, GUI_A,   ALT_S,   CTRL_D,  SHFT_F,  KC_G,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         XXXXXXX, _______, _______, MO(_NAV), _______,
//                      └────────┴────────┴────────┴────────┴────────┘
//                  ┌────────┬────────┬────────┬────────┬────────┬────────┐
                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
//                  ├────────┼────────┼────────┼────────┼────────┼────────┤
                     KC_H,    SHFT_J,  CTRL_K,  ALT_L,   GUI_SC,  KC_QUOT,
//┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, 
//└───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
       _______, _______, _______, _______, HD_TI,
//    └────────┴────────┴────────┴────────┴────────┘
                      ),
    [_GAME] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   KC_ESC,  _______, _______, _______, _______, _______,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TAB,  KC_C,    KC_S,    KC_N,    KC_T,    _______,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   _______, _______, _______, _______, _______, _______, _______, _______,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         _______, _______, KC_LSFT, KC_SPC,  KC_LCTL,
//                      └────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       _______, _______, _______, _______, _______, _______,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       _______, KC_A,    KC_E,    KC_I,    KC_H,    _______,
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
                       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_INS,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_CAPS,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         KC_BSPC, KC_SPC,  KC_ENT,  _______, XXXXXXX
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
                         XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,
//                      └────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS, TG(_NUM),
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, KC_NUM,  KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, XXXXXXX,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         KC_BSPC, KC_KP_0, KC_PENT, XXXXXXX, XXXXXXX
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
                         XXXXXXX, KC_APP,  KC_BSPC, XXXXXXX, KC_TAB,
//                      └────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
//      └────────┴────────┴────────┴────────┴────────┘
                      ),
    [_SYM] = LAYOUT_stack(
//┌────────┬────────┬────────┬────────┬────────┬────────┐
   XXXXXXX, KC_GRV,  KC_LT,   KC_DLR,  KC_GT,   KC_QUOT,
//├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_MINS, KC_BSLS, KC_LPRN, KC_DQUO, KC_HASH, KC_RPRN,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┬────────┐
   XXXXXXX, KC_AT,   KC_EQL,  KC_ASTR, KC_PLUS, KC_SCLN, XXXXXXX, XXXXXXX,
//└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘
                         XXXXXXX, XXXXXXX, KC_GRV,  KC_SPC,  KC_TILD,
//                      └────────┴────────┴────────┴────────┴────────┘
//                    ┌────────┬────────┬────────┬────────┬────────┬────────┐
                       KC_QUES, KC_LBRC, KC_UNDS, KC_MINS, KC_RBRC, XXXXXXX,
//                    ├────────┼────────┼────────┼────────┼────────┼────────┤
                       KC_EXCL, KC_LCBR, KC_COLN, KC_SLSH, KC_RCBR, KC_SCLN,
//  ┌────────┬────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, KC_PERC, KC_AMPR, KC_CIRC, KC_TILD, KC_PIPE, XXXXXXX,
//  └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
         XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
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
        case _HD_TI:  
            oled_write_P(PSTR("HD Ti\n"), false);
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
