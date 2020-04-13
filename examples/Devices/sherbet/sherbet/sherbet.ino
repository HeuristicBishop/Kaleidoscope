/* -*- mode: c++ -*-
 * sherbet -- A very basic Kaleidoscope example for the sherbet macropad
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTabILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "Kaleidoscope.h"
#include "Kaleidoscope-Macros.h"

enum {
  _QWERTY
};

enum {
  RESET
};

#define MO(n) ShiftToLayer(n)

/* *INDENT-OFF* */
KEYMAPS(

/* Qwerty
 * ,-----------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |
 * |------+-----+-----+-----+-----+----|
 * | TAB |  Q  |  W  |  E  |  R  |  T  |
 * |-----+-----+-----+-----+-----+-----|
 * | CAP |  A  |  S  |  D  |  F  |  G  |
 * |-----+-----+-----+-----+-----+-----|
 * |SHIFT|  Z  |  X  |  C  |  V  |  B  |
 * `-----------------------------------'
 */

[_QWERTY] = KEYMAP(
   Key_Escape      ,Key_1       ,Key_2 ,Key_3 ,Key_4 ,Key_5
  ,Key_Tab         ,Key_Q       ,Key_W ,Key_E ,Key_R ,Key_T
  ,Key_CapsLock    ,Key_A       ,Key_S ,Key_D ,Key_F ,Key_G
  ,Key_LeftShift   ,Key_Z       ,Key_X ,Key_C ,Key_V ,Key_B
);
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(Macros);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case RESET:
    Kaleidoscope.rebootBootloader();
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
