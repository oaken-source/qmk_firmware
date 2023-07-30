
#define MODEL "andi "

enum {
    TD_LSFT,
};
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for shift, twice for Caps Lock
    [TD_LSFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

#define HOME_A LGUI_T(KC_A)
#define HOME_O LALT_T(KC_O)
#define HOME_E LCTL_T(KC_E)
#define HOME_U LSFT_T(KC_U)
#define HOME_H LSFT_T(KC_H)
#define HOME_T LCTL_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S LGUI_T(KC_S)

#define BOTT_Q RALT_T(KC_Q)
#define BOTT_V RALT_T(KC_V)

enum {
    L_Base,
    L_Media,
    L_Nav,
    L_Mouse,
    L_Sym,
    L_Num,
    L_Fun,
};

//const key_override_t a_key_override = ko_make_with_layers(MOD_BIT(KC_RALT), KC_A, RALT(KC_Q), 1 << L_Base);
const key_override_t a_key_override = ko_make_basic(MOD_BIT(KC_RALT), HOME_A, RALT(KC_Q));
const key_override_t o_key_override = ko_make_basic(MOD_BIT(KC_RALT), HOME_O, RALT(KC_P));
const key_override_t u_key_override = ko_make_basic(MOD_BIT(KC_RALT), HOME_U, RALT(KC_Y));

const key_override_t **key_overrides = (const key_override_t *[]) {
    &a_key_override,
    &o_key_override,
    &u_key_override,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_Base] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_SLSH, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  TD(TD_LSFT),  HOME_A,  HOME_O,  HOME_E,  HOME_U,    KC_I,                         KC_D,  HOME_H,  HOME_T,  HOME_N,  HOME_S, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_QUOT,  BOTT_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,  BOTT_V,    KC_Z, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      LT(L_Media, KC_ESC),
                                          LT(L_Nav, KC_SPC),
                                              LT(L_Mouse, KC_TAB),
                                                                         LT(L_Sym, KC_ENT) ,
                                                                             LT(L_Num, KC_BSPC),
                                                                                 LT(L_Fun, KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),

  [L_Nav] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_AGAIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_INS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,     KC_ENT, KC_BSPC,  KC_DEL 
                                      //`--------------------------'  `--------------------------'
  ),

  [L_Mouse] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_AGAIN,KC_PASTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    KC_BTN2, KC_BTN1, KC_BTN3 
                                      //`--------------------------'  `--------------------------'
  ),

  [L_Media] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY, KC_MUTE
                                      //`--------------------------'  `--------------------------'
  ),

  [L_Num] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DOT,    KC_0, KC_MINS,    XXXXXXX, _______, XXXXXXX 
                                      //`--------------------------'  `--------------------------'
  ),

  [L_Sym] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LPRN, KC_RPRN, KC_UNDS,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [L_Fun] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_APP,  KC_SPC,  KC_TAB,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  ),
};

void print_layer_name(void) {
    switch (get_highest_layer(layer_state)) {
        case L_Base:
            oled_write("base ", false);
            break;
        case L_Media:
            oled_write("media", false);
            break;
        case L_Nav:
            oled_write("nav  ", false);
            break;
        case L_Mouse:
            oled_write("mouse", false);
            break;
        case L_Sym:
            oled_write("sym  ", false);
            break;
        case L_Num:
            oled_write("num  ", false);
            break;
        case L_Fun:
            oled_write("fun  ", false);
            break;
        default:
            oled_write("Undef", false);
    }
}
