#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;
// layer names
#define _BASE 0
#define _SHIFT 1
#define _NUMBER 2
#define _SYMBOL 3
#define _FUNCTION 4
#define _MACRO 5
#define _MOVEMENT 6
#define _NUMPAD 7
#define _PLOVER 8
#define _ADJUST 16

// macro names
#define _MACRO_O 1
#define _MOVEMENT_E 2
#define _FUNCTION_U 3
#define _SHIFT_DEL 4
#define _CTRL_SPACE 5
#define _NUMBER_BKSP 6
#define _SYMBOL_ENTER 7
#define _CTRL_TAB 8
#define _SHIFT_ESC 9
#define _NUMPAD_KEY 10
#define _PLOVER_KEY 11
#define _EXIT_PLOVER 12

// key definitions
#define TERM   LCAG(KC_APP)
#define BRITE_U LCAG(KC_RIGHT)
#define BRITE_D LCAG(KC_LEFT)
#define ALTTAB LALT(LCTL(KC_TAB))
#define KC_QUES LSFT(KC_SLASH) // ?
#define KC_DQOT LSFT(KC_QUOT)  // "
#define KC_LABR LSFT(KC_COMM)  // <
#define KC_RABR LSFT(KC_DOT)   // >
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// user macros (pc side)
#define U(kc) LCAG(kc)

// macro keys
#define KEYDELAY 150
#define LAYERDELAY 100

#define MACRO_O M(_MACRO_O)
#define MVMNT_E M(_MOVEMENT_E)
#define FUNCT_U M(_FUNCTION_U)
#define SFT_DEL M(_SHIFT_DEL)
#define CTL_SPC M(_CTRL_SPACE)
#define NUM_BSP M(_NUMBER_BKSP)
#define SYM_ENT M(_SYMBOL_ENTER)
#define CTL_TAB M(_CTRL_TAB)
#define SFT_ESC M(_SHIFT_ESC)
#define NUMPAD M(_NUMPAD_KEY)
#define PLOVER M(_PLOVER_KEY)
#define EXT_PLV M(_EXIT_PLOVER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │  '  │  ,  │  .  │  p  │  y  ┃ App │ Ter ┃  f  │  g  │  c  │  r  │  l  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │  a  │  o  │  e  │  u  │  i  ┃Mute │MPlay┃  d  │  h  │  t  │  n  │  s  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │  ?  │  q  │  j  │  k  │  x  ┃Volm-│Volm+┃  b  │  m  │  w  │  v  │  z  │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │ Alt │Numpd│Super│Shift│ Ctl │Numbr│Symbl│ Ctl │Shift│Super│Hyper│ Alt │
   * │     │     │     │ Del │Space│Bkspc│Enter│ Tab │ Esc │     │     │     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_BASE] = {
    {KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_APP,
     TERM,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L},
    {KC_A,    MACRO_O, MVMNT_E, FUNCT_U, KC_I,    KC_MUTE,
     KC_MPLY, KC_D,    KC_H,    KC_T,    KC_N,    KC_S},
    {KC_QUES, KC_Q,    KC_J,    KC_K,    KC_X,    KC_VOLD,
     KC_VOLU, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z},
    {KC_LALT, NUMPAD,  KC_LGUI, SFT_DEL, CTL_SPC, NUM_BSP,
     SYM_ENT, CTL_TAB, SFT_ESC, KC_RGUI, HYPR,    KC_RALT}
  };

  /* Shift
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │  "  │  :  │  ;  │  P  │  Y  ┃     │     ┃  F  │  G  │  C  │  R  │  L  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │  A  │  O  │  E  │  U  │  I  ┃     │     ┃  D  │  H  │  T  │  N  │  S  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │  !  │  Q  │  J  │  K  │  X  ┃     │     ┃  B  │  M  │  W  │  V  │  Z  │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │ Alt │Numpd│Super│Shift│ Ctl │Numbr│Symbl│ Ctl │Shift│Super│Hyper│ Alt │
   * │     │     │     │ Del │Space│Bkspc│Enter│ Tab │ Esc │     │     │     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_SHIFT] = {
    {KC_DQOT, KC_COLN, KC_SCLN, S(KC_P), S(KC_Y), XXXXXXX,
     XXXXXXX, S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L)},
    {S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I), XXXXXXX,
     XXXXXXX, S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S)},
    {KC_EXLM, S(KC_Q), S(KC_J), S(KC_K), S(KC_X), XXXXXXX,
     XXXXXXX, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z)},
    {_______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______}
  };

  /* Number
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │  <  │  {  │  [  │  (  │     ┃     │     ┃     │  )  │  ]  │  }  │  >  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │  7  │  5  │  3  │  1  │  9  ┃     │     ┃  8  │  0  │  2  │  4  │  6  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     ┃     │     ┃     │     │     │     │     │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │ Alt │     │Super│Shift│ Ctl │Numbr│     │ Ctl │Shift│Super│Hyper│ Alt │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_NUMBER] = {
    {KC_LABR, KC_LCBR, KC_LBRC, KC_LPRN, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_RPRN, KC_RBRC, KC_RCBR, KC_RABR},
    {KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    XXXXXXX,
     XXXXXXX, KC_8,    KC_0,    KC_2,    KC_4,    KC_6},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {_______, XXXXXXX, _______, KC_LSFT, KC_LCTL, _______,
     XXXXXXX, KC_RCTL, KC_RSFT, _______, _______, _______}
  };

  /* Symbol
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │  `  │  #  │  *  │  @  │     ┃     │     ┃     │  +  │  &  │  ^  │  $  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │  ~  │  _  │  %  │  =  │     ┃     │     ┃     │  /  │  -  │  |  │  \  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     ┃     │     ┃     │     │     │     │     │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │ Alt │     │Super│Shift│ Ctl │     │Symbl│ Ctl │Shift│Super│Hyper│ Alt │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_SYMBOL] = {
    {KC_GRV,  KC_HASH, KC_ASTR, KC_AT,   XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_PLUS, KC_AMPR, KC_CIRC, KC_DLR},
    {KC_TILD, KC_UNDS, KC_PERC, KC_EQL,  XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_SLSH, KC_MINS, KC_PIPE, KC_BLSL},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {_______, XXXXXXX, _______, KC_LSFT, KC_LCTL, XXXXXXX,
     _______, KC_RCTL, KC_RSFT, _______, _______, _______}
  };

  /* Function
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │     │     │     │     │     ┃     │     ┃     │ F1  │ F2  │ F3  │ F4  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │Funct│     ┃     │     ┃     │ F5  │ F6  │ F7  │ F8  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     ┃     │     ┃     │ F9  │ F10 │ F11 │ F12 │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │ Alt │     │Super│Shift│ Ctl │     │     │ Ctl │Shift│Super│Hyper│ Alt │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_FUNCTION] = {
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4},
    {XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12},
    {_______, XXXXXXX, _______, KC_LSFT, KC_LCTL, XXXXXXX,
     XXXXXXX, KC_RCTL, KC_RSFT, _______, _______, _______}
  };

  /* Macro
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │     │     │     │     │     ┃     │     ┃     │Mcro1│Mcro2│Mcro3│Mcro4│
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │Macro│     │     │     ┃     │     ┃     │Mcro5│Mcro6│Mcro7│Mcro8│
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     ┃     │     ┃     │Mcro9│Mcr10│Mcr11│Mcr12│
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │     │     │     │     │     │     │     │     │Mcr13│Mcr14│Mcr15│Mcr16│
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_MACRO] = {
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, U(KC_A), U(KC_B), U(KC_C), U(KC_D)},
    {XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, U(KC_E), U(KC_F), U(KC_G), U(KC_H)},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, U(KC_I), U(KC_J), U(KC_K), U(KC_L)},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, U(KC_M), U(KC_N), U(KC_O), U(KC_P)}
  };

  /* Movement
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │     │     │     │     │     ┃     │     ┃     │Home │PgUp │PgDn │ End │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │Mvmnt│     │     ┃     │     ┃     │Left │ Up  │Down │Right│
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     ┃     │     ┃     │AltTb│     │     │ Esc │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │ Alt │     │Super│Shift│ Ctl │     │     │ Ctl │Shift│Super│Hyper│ Alt │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_MOVEMENT] = {
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END},
    {XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, ALTTAB,  XXXXXXX, XXXXXXX, KC_ESC},
    {_______, XXXXXXX, _______, KC_LSFT, KC_LCTL, XXXXXXX,
     XXXXXXX, KC_RCTL, KC_RSFT, _______, _______, _______}
  };

  /* Numpad
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │     │     │     │     │     ┃     │     ┃ Esc │ KP7 │ KP8 │ KP9 │ KP* │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     ┃     │     ┃ Del │ KP4 │ KP5 │ KP6 │ KP+ │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │     │     │     │     ┃     │     ┃ Tab │ KP1 │ KP2 │ KP3 │ KP- │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │ Alt │Numpd│Super│Shift│ Ctl │     │     │KPEnt│ KP0 │ KP= │ KP. │ KP/ │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_NUMPAD] = {
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_ESC,  KC_P7,   KC_P8,   KC_P9,   KC_PAST},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_DEL,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, KC_TAB,  KC_P1,   KC_P2,   KC_P3,   KC_PMNS},
    {_______, _______, _______, KC_LSFT, KC_LCTL, XXXXXXX,
     XXXXXXX, KC_PENT, KC_P0,   KC_PEQL, KC_PDOT, KC_PSLS}
  };

  /* Plover
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │  #  │  #  │  #  │  #  │  #  ┃  #  │  #  ┃  #  │  #  │  #  │  #  │  #  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │  S  │  T  │  P  │  H  ┃  *  │  *  ┃  F  │  P  │  L  │  T  │  D  │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │     │  S  │  K  │  W  │  R  ┃  *  │  *  ┃  R  │  B  │  G  │  S  │  Z  │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │Exit │     │     │  A  │  O  │     │     │  E  │  U  │     │     │     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_PLOVER] = {
    {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,
     KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1},
    {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
    {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
    {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX,
     XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
  },

  /* Adjust
   * ╭─────┬─────┬─────┬─────┬─────┲━━━━━┯━━━━━┱─────┬─────┬─────┬─────┬─────┐
   * │BLTog│     │     │     │     ┃Reset│Debug┃     │     │     │     │PrtSc│
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │Brit-│Brit+│     │     │     ┃     │     ┃     │Plovr│     │     │     │
   * ├─────┼─────┼─────┼─────┼─────╂─────┼─────╂─────┼─────┼─────┼─────┼─────┤
   * │ BL- │ BL+ │     │     │     ┃     │     ┃     │     │     │     │     │
   * ╞═════╪═════╪═════╪═════╪═════╄━━━━━┿━━━━━╃═════╪═════╪═════╪═════╪═════╡
   * │     │     │     │     │     │Numbr│Symbl│     │     │     │     │     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────╯
   */
  [_ADJUST] = {
    {BL_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
     DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR},
    {BRITE_D, BRITE_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, PLOVER,  XXXXXXX, XXXXXXX, XXXXXXX},
    {BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
    {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
  };
};

const uint16_t PROGMEM fn_actions[] = {

};

static uint16_t key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
  case _MACRO_O:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_O);
      } else {
        unregister_code(KC_O);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(_MACRO);
      } else {
        layer_off(_MACRO);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_O);
          unregister_code(KC_O);
        }
      }
    }
    break;
  case _MOVEMENT_E:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_E);
      } else {
        unregister_code(KC_E);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(_MOVEMENT);
      } else {
        layer_off(_MOVEMENT);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_E);
          unregister_code(KC_E);
        }
      }
    }
    break;
  case _FUNCTION_U:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_U);
      } else {
        unregister_code(KC_U);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(_FUNCTION);
      } else {
        layer_off(_FUNCTION);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_U);
          unregister_code(KC_U);
        }
      }
    }
    break;
  case _SHIFT_DEL:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_DELETE);
      } else {
        unregister_code(KC_DELETE);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
         register_code(KC_LSHIFT);
      } else {
        unregister_code(KC_LSHIFT);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_DELETE);
          unregister_code(KC_DELETE);
        }
      }
    }
    break;
  case _CTRL_SPACE:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_SPACE);
      } else {
        unregister_code(KC_SPACE);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LCTRL);
      } else {
        unregister_code(KC_LCTRL);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_SPACE);
          unregister_code(KC_SPACE);
        }
      }
    }
    break;
  case _NUMBER_BKSP:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_BSPACE);
      } else {
        unregister_code(KC_BSPACE);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(_NUMBER);
        update_tri_layer(_NUMBER, _SYMBOL, _ADJUST);
      } else {
        layer_off(_NUMBER);
        update_tri_layer(_NUMBER, _SYMBOL, _ADJUST);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_BSPACE);
          unregister_code(KC_BSPACE);
        }
      }
    }
    break;
  case _SYMBOL_ENTER:
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
        update_tri_layer(_NUMBER, _SYMBOL, _ADJUST);
      } else {
        layer_off(_SYMBOL);
        update_tri_layer(_NUMBER, _SYMBOL, _ADJUST);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_ENTER);
          unregister_code(KC_ENTER);
        }
      }
    }
    break;
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
        register_code(KC_RCTRL);
      } else {
        unregister_code(KC_RCTRL);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        }
      }
    }
    break;
  case _SHIFT_ESC:
    if (record->tap_count) {
      if (record->event.pressed) {
        register_code(KC_ESC);
      } else {
        unregister_code(KC_ESC);
      }
    } else {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_RSHIFT);
      } else {
        unregister_code(KC_RSHIFT);
        if (timer_elapsed(key_timer) < KEYDELAY) {
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        }
      }
    }
    break;
  case _NUMPAD_KEY:
    if (record->event.pressed) {
      layer_invert(_NUMPAD)
    }
    break;
  case _PLOVER_KEY:
    if (record->event.pressed) {
      layer_off(_SYMBOL);
      layer_off(_NUMBER);
      layer_off(_ADJUST);
      layer_on(_PLOVER);
    }
    break;
  case _EXIT_PLOVER:
    if (record->event.pressed) {
      layer_off(_PLOVER);
    }
    break;
  }
  return MACRO_NONE;
};

void process_action_user(keyrecord_t *record) {
  if (IS_LAYER_ON(_MACRO)) {
    if (record->event.pressed) {
      if (timer_elapsed(key_timer) < LAYERDELAY) {
        layer_off(_MACRO);
      }
    }
  } else if (IS_LAYER_ON(_MOVEMENT)) {
    if (record->event.pressed) {
      if (timer_elapsed(key_timer) < LAYERDELAY) {
        layer_off(_MOVEMENT);
      }
    }
  } else if (IS_LAYER_ON(_FUNCTION)) {
    if (record->event.pressed) {
      if (timer_elapsed(key_timer) < LAYERDELAY) {
        layer_off(_FUNCTION);
      }
    }
  }
}
