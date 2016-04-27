#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _SHIFT 1
#define _NUMBER 2
#define _SYMBOL 3
#define _FUNCTION 4
#define _MOVEMENT 5
#define _NUMPAD 6
#define _PLOVER 7
#define _KEYBOARD 16
#define _ALT_DEL 32
#define _CTRL_TAB 33
#define _SUPER_ESC 34
#define _EXIT_PLOVER 35

#define BRITEU HYPR(KC_RIGHT)
#define BRITED HYPR(KC_LEFT)
#define ALTTAB LALT(LCTL(KC_TAB))
#define KC_QUES LSFT(KC_SLASH) // ?
#define KC_DQOT LSFT(KC_QUOT)  // "
#define KC_LABR LSFT(KC_COMM)  // <
#define KC_RABR LSFT(KC_DOT)   // >
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define U(kc) LCAG(kc)

#define KEYDELAY 150
#define SHFTSPC M(_SHIFT)
#define NUMBSPC M(_NUMBER)
#define SYMBENT M(_SYMBOL)
#define FUNC M(_FUNCTION)
#define MVMNT M(_MOVEMENT)
#define NUMPAD M(_NUMPAD)
#define PLOVER M(_PLOVER)
#define KEYBD M(_KEYBOARD)
#define ALTDEL M(_ALT_DEL)
#define CTRLTAB M(_CTRL_TAB)
#define SUPRESC M(_SUPER_ESC)
#define EXT_PLV M(_EXIT_PLOVER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │  '   │  ,   │  .   │  p   │  y   ┃Brite-│Brite+┃  f   │  g   │  c   │  r   │  l   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │  a   │  o   │  e   │  u   │  i   ┃ Mute │MPlay ┃  d   │  h   │  t   │  n   │  s   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │  ?   │  q   │  j   │  k   │  x   ┃ Vol- │ Vol+ ┃  b   │  m   │  w   │  v   │  z   │
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │Mvmnt │Numpad│Functn│ Alt  │Shift │Number│Symbol│ Ctrl │Super │Hyper │ Kbd  │  WM  │
   * │      │      │      │ Del  │Space │Backsp│Enter │ Tab  │ Esc  │      │      │      │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_BASE] = {
    {KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    BRITED,  BRITEU,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L},
    {KC_A,    KC_O,    KC_E,    KC_P,    KC_I,    KC_MUTE, KC_MPLY, KC_D,    KC_H,    KC_T,    KC_N,    KC_S},
    {KC_QUES, KC_Q,    KC_J,    KC_K,    KC_X,    KC_VOLD, KC_VOLU, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z},
    {MVMNT,   NUMPAD,  FUNC,    ALTDEL,  SHFTSPC, NUMBSPC, SYMBENT, CTRLTAB, SUPRESC, HYPR,    KEYBD,   KC_APP}
  },

  /* Shift
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │  "   │  :   │  ;   │  P   │  Y   ┃      │      ┃  F   │  G   │  C   │  R   │  L   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │  A   │  O   │  E   │  U   │  I   ┃      │      ┃  D   │  H   │  T   │  N   │  S   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │  !   │  Q   │  J   │  K   │  X   ┃      │      ┃  B   │  M   │  W   │  V   │  Z   │
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │      │      │      │ Alt  │Shift │      │      │ Ctrl │Super │Hyper │      │  WM  │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_SHIFT] = {
    {KC_DQOT, KC_COLN, KC_SCLN, S(KC_P), S(KC_Y), XXXXXXX, XXXXXXX, S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L)},
    {S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), XXXXXXX, XXXXXXX, S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S)},
    {KC_EXLM, S(KC_Q), S(KC_J), S(KC_K), S(KC_X), XXXXXXX, XXXXXXX, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z)},
    {XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, _______, XXXXXXX, XXXXXXX, KC_LCTL, KC_LGUI, HYPR,    XXXXXXX, KC_APP}
  },

  /* Number
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │  <   │  {   │  [   │  (   │      ┃      │      ┃      │  )   │  ]   │  }   │  >   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │  7   │  5   │  3   │  1   │  9   ┃      │      ┃  8   │  0   │  2   │  4   │  6   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      ┃      │      ┃      │      │      │      │      │
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │      │      │      │      │ Alt  │Number│      │ Ctrl │Super │Hyper │      │  WM  │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_NUMBER] = {
    {KC_LABR, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABR},
    {KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    XXXXXXX, XXXXXXX, KC_8,    KC_0,    KC_2,    KC_4,    KC_6},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, _______, XXXXXXX, KC_LCTL, KC_LGUI, HYPR,    XXXXXXX, KC_APP}
  },

  /* Symbol
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │  `   │  #   │  *   │  @   │      ┃      │      ┃      │  +   │  &   │  ^   │  $   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │  ~   │  _   │  %   │  =   │      ┃      │      ┃      │  /   │  -   │  |   │  \   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      ┃      │      ┃      │      │      │      │      │
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │      │      │      │ Alt  │Shift │Super │Symbol│ Ctrl │      │      │      │  WM  │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_SYMBOL] = {
    {KC_GRV,  KC_HASH, KC_ASTR, KC_AT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PLUS, KC_AMPR, KC_CIRC, KC_DLR},
    {KC_TILD, KC_UNDS, KC_PERC, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_MINS, KC_PIPE, KC_BSLS},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, KC_LSFT, KC_LGUI, _______, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_APP}
  },

  /* Function/Macro
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │  F1  │  F2  │  F3  │  F4  │  F5  ┃  F6  │  F7  ┃  F8  │  F9  │ F10  │ F11  │ F12  │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │Macro1│Macro2│Macro3│Macro4│Macro5┃      │      ┃Macro6│Macro7│Macro8│Macro9│Mcro10│
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │Mcro11│Mcro12│Mcro13│Mcro14│Mcro15┃      │      ┃Mcro16│Mcro17│Mcro18│Mcro19│Mcro20│
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │      │      │Functn│ Alt  │Shift │      │      │ Ctrl │Super │Hyper │      │  WM  │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_FUNCTION] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
    {U(KC_A), U(KC_B), U(KC_C), U(KC_D), U(KC_E), XXXXXXX, XXXXXXX, U(KC_F), U(KC_G), U(KC_H), U(KC_I), U(KC_J)},
    {U(KC_K), U(KC_L), U(KC_M), U(KC_N), U(KC_O), XXXXXXX, XXXXXXX, U(KC_P), U(KC_Q), U(KC_R), U(KC_S), U(KC_T)},
    {XXXXXXX, XXXXXXX, _______, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX, KC_LCTL, KC_LGUI, HYPR,    XXXXXXX, KC_APP}
  },

  /* Movement
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │      │      │      │      │      ┃      │      ┃      │ Home │ PgUp │ PgDn │ End  │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      ┃      │      ┃      │ Left │  Up  │ Down │Right │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      ┃      │      ┃      │AltTab│      │      │ Esc  │
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │Mvmnt │      │      │ Alt  │Shift │      │      │ Ctrl │Super │Hyper │      │  WM  │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_MOVEMENT] = {
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ALTTAB,  XXXXXXX, XXXXXXX, KC_ESC},
    {_______, XXXXXXX, XXXXXXX, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX, KC_LCTL, KC_LGUI, HYPR,  XXXXXXX, KC_APP}
  },

  /* Numpad
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │      │      │      │      │      ┃      │      ┃      │ KP_7 │ KP_8 │ KP_9 │ KP_* │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      ┃      │      ┃      │ KP_4 │ KP_5 │ KP_6 │ KP_+ │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      ┃      │      ┃      │ KP_1 │ KP_2 │ KP_3 │ KP_- │
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │      │Numpad│      │      │      │      │      │KP_Ent│ KP_0 │KP_Eq │ KP_. │ KP_/ │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_NUMPAD] = {
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PAST},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS},
    {XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PENT, KC_P0,   KC_PEQL, KC_PDOT, KC_PSLS}
  },

  /* Plover
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │  #   │  #   │  #   │  #   │  #   ┃  #   │  #   ┃  #   │  #   │  #   │  #   │  #   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │  S   │  T   │  P   │  H   ┃  *   │  *   ┃  F   │  P   │  L   │  T   │  D   │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │  S   │  K   │  W   │  R   ┃  *   │  *   ┃  R   │  B   │  G   │  S   │  Z   │
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │Ext_Pv│      │      │  A   │  O   │      │      │  E   │  U   │      │      │      │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_PLOVER] = {
    {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1},
    {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
    {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
  },

  /* Kbd
   * ╭──────┬──────┬──────┬──────┬──────┲━━━━━━┯━━━━━━┱──────┬──────┬──────┬──────┬──────┐
   * │Reset │      │      │      │      ┃BLTogg│      ┃      │Plover│      │      │PrtScr│
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │Debug │      │      │      │      ┃BL_Dec│BL_Inc┃      │      │      │      │      │
   * ├──────┼──────┼──────┼──────┼──────╂──────┼──────╂──────┼──────┼──────┼──────┼──────┤
   * │      │      │      │      │      ┃      │      ┃      │      │      │      │      │
   * ╞══════╪══════╪══════╪══════╪══════╄━━━━━━┿━━━━━━╃══════╪══════╪══════╪══════╪══════╡
   * │      │      │      │      │      │      │      │      │      │      │ Kbd  │      │
   * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────╯
   */
  [_KEYBOARD] = {
    {RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, XXXXXXX, XXXXXXX, PLOVER,  XXXXXXX, XXXXXXX, KC_PSCR},
    {DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX}
  }
};

const uint16_t PROGMEM fn_actions[] = {

};

static uint16_t key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
  case _SHIFT:
    if (record->event.pressed) {
      layer_on(_SHIFT);
    } else {
      layer_off(_SHIFT);
    }
    break;
  case _NUMBER:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_SPACE);
      } else {
        unregister_code(KC_SPACE);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(_NUMBER);
      } else {
        layer_off(_NUMBER);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_SPACE);
          unregister_code(KC_SPACE);
        }
      }
    }
    break;
  case _SYMBOL:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_ENTER);
      } else {
        unregister_code(KC_ENTER);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(_SYMBOL);
      } else {
        layer_off(_SYMBOL);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_ENTER);
          unregister_code(KC_ENTER);
        }
      }
    }
    break;
  case _FUNCTION:
    if (record->event.pressed) {
      layer_on(_FUNCTION);
    } else {
      layer_off(_FUNCTION);
    }
    break;
  case _MOVEMENT:
    if (record->event.pressed) {
      layer_on(_MOVEMENT);
    } else {
      layer_off(_MOVEMENT);
    }
    break;
  case _NUMPAD:
    if (record->event.pressed) {
      layer_invert(_NUMPAD)
    }
    break;
  case _PLOVER:
    if (record->event.pressed) {
      layer_on(_PLOVER);
    }
    break;
  case _KEYBOARD:
    if (record->event.pressed) {
      layer_on(_KEYBOARD);
    } else {
      layer_off(_KEYBOARD);
    }
  case _ALT_DEL:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_DELETE);
      } else {
        unregister_code(KC_DELETE);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_DELETE);
          unregister_code(KC_DELETE);
        }
      }
    }
  case _CTRL_TAB:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        }
      }
    }
    break;
  case _SUPER_ESC:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_ESC);
      } else {
        unregister_code(KC_ESC);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LGUI);
      } else {
        unregister_code(KC_LGUI);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        }
      }
    }
  case _EXIT_PLOVER:
    if (record->event.pressed) {
      layer_off(_PLOVER);
    }
  }
  return MACRO_NONE;
};
