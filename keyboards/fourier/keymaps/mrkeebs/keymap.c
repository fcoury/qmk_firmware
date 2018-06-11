#include "fourier.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _FN1 1
#define _FN2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define ___ KC_TRNS
#define XXXXXXX KC_NO
#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_SPFN1 LT(_FN1, KC_SPACE)
#define KC_SPFN2 LT(_FN2, KC_SPACE)
#define KC_BSFN1 LT(_FN1, KC_BSPC)
#define KC_BSFN2 LT(_FN2, KC_BSPC)
#define KC_ENFN2 LT(2, KC_ENT)
#define KC_RSSL MT(MOD_RSFT, KC_SLSH)
#define KC_CTTAB MT(MOD_LCTL, KC_TAB)
#define KC_RST RESET
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    GESC , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,MINS ,BSPC,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    CTTAB, A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN, ENFN2  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    LSFT   , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,UP, RSSL ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    LCTL ,LALT,LGUI ,SPFN1, SPFN1,  SPACE , RGUI , LEFT, DOWN, RIGHT
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN1] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    GRV , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,EQL ,   ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    RST  ,RHUI,RSAI,RVAI,VOLU,LBRC,RBRC,     , MINS, EQL ,QUOT,     ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    RMOD   ,RHUD,RSAD,RVAD,VOLD,LCBR,RCBR,    , LBRC,RBRC, PGUP ,BSLS,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    RTOG ,    ,     ,    ,        ,  DEL   ,  0  ,HOME ,PGDN , END
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN2] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    TILD,EXLM, AT ,HASH,DLR ,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,UNDS,PLUS,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
        ,MUTE,VOLD,VOLU,    ,    ,    ,    ,    ,    ,    ,        ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
        ,PSCR,LSCR,DEL ,    ,    ,    ,    ,    ,    ,    ,    ,PIPE
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
         ,    ,     ,    ,  DEL   ,        ,     ,     ,     ,
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  )

};
