
#include <keymap_german.h>

#define MODEL "andi "

const key_override_t comm_key_override = ko_make_with_layers(MOD_MASK_SHIFT, DE_COMM, DE_LABK, 1<<4);
const key_override_t dot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, DE_DOT, DE_RABK, 1<<4);
const key_override_t scln_key_override = ko_make_with_layers(MOD_MASK_SHIFT, DE_SCLN, DE_COLN, 1<<4);
const key_override_t quot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO, 1<<4);
const key_override_t slsh_key_override = ko_make_with_layers(MOD_MASK_SHIFT, DE_SLSH, DE_QUES, 1<<4);
const key_override_t mins_key_override = ko_make_with_layers(MOD_MASK_SHIFT, DE_MINS, DE_UNDS, 1<<4);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&comm_key_override,
  &dot_key_override,
  &scln_key_override,
  &quot_key_override,
  &slsh_key_override,
  &mins_key_override,
	NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, DE_SCLN, DE_COMM,  DE_DOT,    DE_P,    DE_Y,                         DE_F,    DE_G,    DE_C,    DE_R,    DE_L, DE_SLSH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    DE_A,    DE_O,    DE_E,    DE_U,    DE_I,                         DE_D,    DE_H,    DE_T,    DE_N,    DE_S, DE_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, DE_QUOT,    DE_Q,    DE_J,    DE_K,    DE_X,                         DE_B,    DE_M,    DE_W,    DE_V,    DE_Z, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                         DE_6,    DE_7,    DE_8,    DE_9,    DE_0,   DE_SS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, DE_ADIA, DE_ODIA, XXXXXXX, DE_UDIA, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, DE_AMPR, DE_LBRC, DE_LCBR, DE_RCBR, DE_LPRN,                       DE_EQL, DE_ASTR, DE_RPRN, DE_PLUS, DE_RBRC, DE_EXLM,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, DE_TILD,  DE_DLR,  DE_DEG, XXXXXXX, XXXXXXX,                      XXXXXXX, DE_PIPE, DE_PERC, DE_CIRC,   DE_AT, DE_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  DE_GRV, DE_SECT, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DE_HASH, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

void print_layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write("base ", false);
            break;
        case 1:
            oled_write("lower ", false);
            break;
        case 2:
            oled_write("raise", false);
            break;
        case 3:
            oled_write("adjst", false);
            break;
        default:
            oled_write("Undef", false);
    }
}
