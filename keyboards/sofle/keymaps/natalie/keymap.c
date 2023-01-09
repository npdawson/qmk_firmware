
/* Copyright 2021 Dane Evans
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
// SOFLE RGB as customized by Natalie

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35, 1, hsv}
#define SET_UNDERGLOW(hsv) \
    {1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	{35+22, 3, hsv},\
	{35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
	{20, 2, hsv}, \
	{30, 2, hsv}, \
	{35+ 10, 2, hsv}, \
	{35+ 20, 2, hsv}, \
	{35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	{35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	{35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	{35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
	{35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
	{1, 6, hsv}, \
	{35+1, 6, hsv}, \
	{7, 4, hsv}, \
	{35+ 7, 4, hsv}, \
	{25, 2, hsv}, \
	{35+ 25, 2, hsv}

#define LAYOUT_stack(   \
    L00, L01, L02, L03, L04, L05,   \
    L10, L11, L12, L13, L14, L15,   \
    L20, L21, L22, L23, L24, L25,   \
    L30, L31, L32, L33, L34, L35, L45, \
              L40, L41, L42, L43, L44, \
         R00, R01, R02, R03, R04, R05,  \
         R10, R11, R12, R13, R14, R15,  \
         R20, R21, R22, R23, R24, R25,  \
    R40, R30, R31, R32, R33, R34, R35, \
    R41, R42, R43, R44, R45  \
              ) \
{   \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { L40, L41, L42, L43, L44, L45 }, \
    { R05, R04, R03, R02, R01, R00 }, \
    { R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20 }, \
    { R35, R34, R33, R32, R31, R30 }, \
    { R45, R44, R43, R42, R41, R40 } \
}

#define LGTC LGUI_T(KC_C)
#define LATS LALT_T(KC_S)
#define LCTN LCTL_T(KC_N)
#define LSTT LSFT_T(KC_T)
#define RSTA RSFT_T(KC_A)
#define RCTE RCTL_T(KC_E)
#define RATI RALT_T(KC_I)
#define RGTH RGUI_T(KC_H)

#define LGTA LGUI_T(KC_A)
//#define LATS LALT_T(KC_S)
#define LCTD LCTL_T(KC_D)
#define LSTF LSFT_T(KC_F)
#define RSTJ RSFT_T(KC_J)
#define RCTK RCTL_T(KC_K)
#define RATL RALT_T(KC_L)
#define RGTSCLN RGUI_T(KC_SCLN)

enum sofle_layers {
    _DEFAULTS = 0,
    _HD_TI = 0,
    _QWERTY,
    _GAME,
    _NUM,
    _NAV,
    _FUN,
    _SYM
};

enum custom_keycodes {
    KC_HD_TI = SAFE_RANGE,
    KC_QWERTY,
    KC_GAME,
    KC_NUM,
    KC_ADJUST,
    KC_D_MUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Hands Down Titanium
    [_HD_TI] = LAYOUT_stack(
    //,-----------------------------------------------------.
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    //|--------+--------+--------+--------+--------+--------|
       C(KC_C), KC_J,    KC_G,    KC_M,    KC_P,    KC_V,
    //|--------+--------+--------+--------+--------+--------|
       C(KC_V), LGTC,    LATS,    LCTN,    LSTT,    KC_D,
    //|--------+--------+--------+--------+--------+--------|  ===  |
       KC_AMPR, KC_X,    KC_F,    KC_L,    KC_D,    KC_B,    KC_GAME,
    //|--------+--------+--------+--------+--------+--------|  ===  |
                         XXXXXXX, KC_APP,  KC_TAB,  KC_BSPC, KC_R,
    //                  \--------+--------+--------+--------+-------/
    //
    //        ,-----------------------------------------------------.
               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NUM,
    //        |--------+--------+--------+--------+--------+--------|
               KC_SCLN, KC_DOT,  KC_SLSH, KC_DQUO, KC_QUOT, KC_BSLS,
    //        |--------+--------+--------+--------+--------+--------|
               KC_COMM, RSTA,    RCTE,    RATI,    RGTH,    KC_EXLM,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      KC_QWERTY,KC_MINS, KC_U,   KC_O,    KC_Y,    KC_K,    KC_EQL,
    //|  ===  |--------+--------+--------+--------+--------+--------|
       KC_SPC, KC_ENT,  KC_ESC,  KC_DEL,  XXXXXXX
    //\-------+--------+--------+--------+--------/
        ),
    [_QWERTY] = LAYOUT_stack(
    //,-----------------------------------------------------.
       _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|
       _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    //|--------+--------+--------+--------+--------+--------|
       _______, LGTA,    LATS,    LCTD,    LSTF,    KC_G,
    //|--------+--------+--------+--------+--------+--------|  ===  |
       _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  ===  |
                         _______, _______, _______, _______, MO(_NAV),
    //                  \--------+--------+--------+--------+-------/
    //
    //        ,-----------------------------------------------------.
               _______, _______, _______, _______, _______, _______,
    //        |--------+--------+--------+--------+--------+--------|
               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    //        |--------+--------+--------+--------+--------+--------|
               KC_H,    RSTJ,    RCTK,    RATL,    RGTSCLN, KC_QUOT,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      KC_HD_TI, KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, _______,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______
    //\-------+--------+--------+--------+--------/
        ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | trans|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWER] = LAYOUT(
            //,------------------------------------------------.                    ,---------------------------------------------------.
            _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            _______,  KC_NO,  KC_NO,   KC_NO,   KC_WH_U, KC_PGUP,                   KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_NO,   KC_DEL,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            _______,  KC_NO,  KC_NO,   KC_NO,   KC_WH_D, KC_PGDN,_______,    _______,KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,    _______,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
            //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
            ),
    /* RAISE
     * ,----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
     * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
     * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISE] = LAYOUT(
            //,------------------------------------------------.                    ,---------------------------------------------------.
            _______, _______ , _______ , _______ , _______ , _______,               _______,  _______  , _______,  _______ ,  _______ ,_______,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                KC_CIRC, KC_AMPR,KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,_______,    _______,KC_UNDS, KC_PLUS,KC_LBRC, KC_RBRC, KC_BSLS, KC_TILD,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
            //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
            ),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | QK_BOOT|      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |RGB_TOG|hue^ |sat ^ | bri ^|      |COLEMAK|-------.   ,-------|desk <|      |      |desk >|      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | mode | hue dn|sat d|bri dn|      |QWERTY|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(
            //,------------------------------------------------.                    ,---------------------------------------------------.
            EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            QK_BOOT, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            RGB_TOG, RGB_HUI,RGB_SAI, RGB_VAI, KC_COLEMAKDH,KC_COLEMAK,             C(G(KC_LEFT)),KC_NO,KC_NO,C(G(KC_RGHT)),XXXXXXX, XXXXXXX,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            RGB_MOD, RGB_HUD,RGB_SAD, RGB_VAD, XXXXXXX,KC_QWERTY,XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
            //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
            ),
    /* NUMPAD
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_NUMPAD] = LAYOUT(
            //,------------------------------------------------.                    ,---------------------------------------------------.
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
            //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
            ),

    /* SWITCH
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | qwer | cole |col_dh| low  | raise| adj  |                    |numpad|      |      |      |      |QK_BOOT |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EE_CLR|
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    // layer switcher
    [_SWITCH] = LAYOUT(
            //,------------------------------------------------.                    ,---------------------------------------------------.
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                      TO(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
            //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
            KC_NO,   KC_NO, KC_BRIU,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            KC_SYSTEM_SLEEP,KC_NO,KC_NO,KC_NO,  KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
            //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
            //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/

            ),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
    const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_RED)

            );
    const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_PINK)
            );

    // _NUM,
    // Light on outer column and underglow
    const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_TEAL)

            );
    // _SYMBOL,
    // Light on inner column and underglow
    const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_BLUE)

            );
    // _COMMAND,
    // Light on inner column and underglow
    const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_PURPLE)
            );

    //_NUMPAD
    const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_INDICATORS(HSV_ORANGE),
            SET_UNDERGLOW(HSV_ORANGE),
            SET_NUMPAD(HSV_BLUE),
            {7, 4, HSV_ORANGE},
            {25, 2, HSV_ORANGE},
            {35+6, 4, HSV_ORANGE},
            {35+25, 2, HSV_ORANGE}
            );
    // _SWITCHER   // light up top row
    const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_GREEN),
            SET_NUMROW(HSV_GREEN)
            );

    const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

            layer_qwerty_lights,
            layer_num_lights,// overrides layer 1
            layer_symbol_lights,
            layer_command_lights,
            layer_numpad_lights,
            layer_switcher_lights,  // Overrides other layers
            layer_colemakdh_lights
            );

    layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
        rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));


        rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
        rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
        rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
        rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
        rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
        return state;
    }
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    //oled_write_ln_P(PSTR(""), false);

    //snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _HD_TI:
            oled_write_ln_P(PSTR("HD Ti"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _HD_TI:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav\n"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("Func\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symb\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_HD_TI:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_HD_TI);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                layer_invert(_GAME);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _HD_TI:
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _RAISE:
            case _LOWER:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
        }
    }
    return true;
}

#endif
