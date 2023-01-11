
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

#define R_NAV LT(_NAV, KC_R)
#define BSP_NUM LT(_NUM, KC_BSPC)
#define SPC_SYM LT(_SYM, KC_SPC)
#define ENT_FUN LT(_FUN, KC_ENT)

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
    KC_NUMP,
};

enum combo_events {
    CB_JG,
    CB_KY,
    CB_YU,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jg_combo[] = {KC_J, KC_G, COMBO_END};
const uint16_t PROGMEM ky_combo[] = {KC_K, KC_Y, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};

combo_t key_combos[] = {
    [CB_JG] = COMBO_ACTION(jg_combo),
    [CB_KY] = COMBO_ACTION(ky_combo),
    [CB_YU] = COMBO_ACTION(yu_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CB_JG:
            if (pressed) {
                tap_code16(KC_Z);
            }
            break;
        case CB_KY:
            if (pressed) {
                tap_code16(KC_Q);
            }
            break;
        case CB_YU:
            if (pressed) {
                tap_code16(KC_Q);
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(KC_U);
            }
            break;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Hands Down Titanium
    [_HD_TI] = LAYOUT_stack(
    //,-----------------------------------------------------.
       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    //|--------+--------+--------+--------+--------+--------|
       C(KC_C), KC_J,    KC_G,    KC_M,    KC_P,    KC_V,
    //|--------+--------+--------+--------+--------+--------|
       C(KC_V), LGTC,    LATS,    LCTN,    LSTT,    KC_W,
    //|--------+--------+--------+--------+--------+--------|  ===  |
       KC_AMPR, KC_X,    KC_F,    KC_L,    KC_D,    KC_B,    KC_GAME,
    //|--------+--------+--------+--------+--------+--------|  ===  |
                         XXXXXXX, KC_APP,  KC_TAB,  BSP_NUM, R_NAV,
    //                  \--------+--------+--------+--------+-------/
    //
    //        ,-----------------------------------------------------.
               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NUMP,
    //        |--------+--------+--------+--------+--------+--------|
               KC_SCLN, KC_DOT,  KC_SLSH, KC_DQUO, KC_QUOT, KC_BSLS,
    //        |--------+--------+--------+--------+--------+--------|
               KC_COMM, RSTA,    RCTE,    RATI,    RGTH,    KC_EXLM,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      KC_QWERTY,KC_MINS, KC_U,   KC_O,    KC_Y,    KC_K,    KC_EQL,
    //|  ===  |--------+--------+--------+--------+--------+--------|
       SPC_SYM,ENT_FUN, KC_ESC,  KC_DEL,  XXXXXXX
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
    [_GAME] = LAYOUT_stack(
    //,-----------------------------------------------------.
       _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|
       KC_TAB,  _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|
       KC_ESC,  KC_C,    KC_S,    KC_N,    KC_T,    KC_W,
    //|--------+--------+--------+--------+--------+--------|  ===  |
       _______, _______, _______, _______, _______, _______, KC_GAME,
    //|--------+--------+--------+--------+--------+--------|  ===  |
                         _______, _______, KC_LCTL, KC_LSFT, KC_R,
    //                  \--------+--------+--------+--------+-------/
    //
    //        ,-----------------------------------------------------.
               _______, _______, _______, _______, _______, _______,
    //        |--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______, _______, _______,
    //        |--------+--------+--------+--------+--------+--------|
               KC_COMM, KC_A,    KC_E,    KC_I,    KC_H,    _______,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, _______, _______, _______, _______,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______
    //\-------+--------+--------+--------+--------/
            ),
    [_NUM] = LAYOUT_stack(
    //,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  ===  |
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  ===  |
                         XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
    //                  \--------+--------+--------+--------+-------/
    //
    //        ,-----------------------------------------------------.
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //        |--------+--------+--------+--------+--------+--------|
               KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, XXXXXXX,
    //        |--------+--------+--------+--------+--------+--------|
               KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_NUM,  KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX,
    //|  ===  |--------+--------+--------+--------+--------+--------|
        KC_P0, KC_PENT, KC_BSPC, _______, _______
    //\-------+--------+--------+--------+--------/
            ),
    [_NAV] = LAYOUT_stack(
    //,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  ===  |
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  ===  |
                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    //                  \--------+--------+--------+--------+-------/
    //
    //        ,-----------------------------------------------------.
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //        |--------+--------+--------+--------+--------+--------|
               KC_HOME, KC_PGUP, KC_PGDN, KC_END,  XXXXXXX, KC_INS,
    //        |--------+--------+--------+--------+--------+--------|
               KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_CAPS,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|  ===  |--------+--------+--------+--------+--------+--------|
       KC_SPC, KC_ENT,  KC_BSPC, KC_DEL,  XXXXXXX
    //\-------+--------+--------+--------+--------/
            ),
    [_FUN] = LAYOUT_stack(
    //,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR,
    //|--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_F3,   KC_F3,   KC_F3,   KC_F8,   KC_SCRL,
    //|--------+--------+--------+--------+--------+--------|  ===  |
       XXXXXXX, KC_F3,   KC_F10,  KC_F11,  KC_F12,  KC_PAUS, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  ===  |
                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                  \--------+--------+--------+--------+-------/
    //
    //        ,-----------------------------------------------------.
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //        |--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //        |--------+--------+--------+--------+--------+--------|
               XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    //\-------+--------+--------+--------+--------/
            ),
    [_SYM] = LAYOUT_stack(
    //,-----------------------------------------------------.
       _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|
       XXXXXXX, KC_GRV,  KC_LT,   KC_DLR,  KC_GT,   KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|
       KC_MINS, KC_BSLS, KC_LPRN, KC_DQUO, KC_HASH, KC_RPRN,
    //|--------+--------+--------+--------+--------+--------|  ===  |
       _______, KC_AT,   KC_EQL,  KC_ASTR, KC_PLUS, KC_SCLN, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|  ===  |
                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                  \--------+--------+--------+--------+-------/
    //
    //        ,-----------------------------------------------------.
               _______, _______, _______, _______, _______, XXXXXXX,
    //        |--------+--------+--------+--------+--------+--------|
               KC_QUES, KC_LBRC, KC_UNDS, KC_MINS, KC_RBRC, _______,
    //        |--------+--------+--------+--------+--------+--------|
               KC_EXLM, KC_LCBR, KC_COLN, KC_SLSH, KC_RCBR, KC_SCLN,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PERC, KC_AMPR, KC_CIRC, KC_TILD, KC_PIPE, _______,
    //|  ===  |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //\-------+--------+--------+--------+--------/
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
    const rgblight_segment_t PROGMEM layer_hd_ti_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_PINK)
            );

    // _NUM,
    // Light on outer column and underglow
    const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_TEAL)

            );
    // _SYM,
    // Light on inner column and underglow
    const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_BLUE)

            );
    // _NAV,
    // Light on inner column and underglow
    const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_PURPLE)
            );

    //_FUN
    const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_INDICATORS(HSV_ORANGE),
            SET_UNDERGLOW(HSV_ORANGE),
            SET_NUMPAD(HSV_BLUE),
            {7, 4, HSV_ORANGE},
            {25, 2, HSV_ORANGE},
            {35+6, 4, HSV_ORANGE},
            {35+25, 2, HSV_ORANGE}
            );
    // _GAME
    // light up top row
    const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
            SET_LAYER_ID(HSV_GREEN),
            SET_NUMROW(HSV_GREEN)
            );

    const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

            layer_hd_ti_lights,
            layer_qwerty_lights,
            layer_num_lights,// overrides layer 1
            layer_symbol_lights,
            layer_command_lights,
            layer_numpad_lights,
            layer_switcher_lights  // Overrides other layers
            );

    layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_HD_TI));
        rgblight_set_layer_state(1, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));

        rgblight_set_layer_state(2, layer_state_cmp(state, _GAME));
        rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));
        rgblight_set_layer_state(4, layer_state_cmp(state, _NAV));
        rgblight_set_layer_state(5, layer_state_cmp(state, _SYM));
        rgblight_set_layer_state(6, layer_state_cmp(state, _FUN));
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
        case KC_NUMP:
            if (record->event.pressed) {
                layer_invert(_NUM);
            }
            return false;
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
            case _NUM:
            case _NAV:
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
