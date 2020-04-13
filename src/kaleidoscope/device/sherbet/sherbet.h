/* -*- mode: c++ -*-
 * Kaleidoscope-Hardware-sherbet -- sherbet hardware support for Kaleidoscope
 * Copyright (C) 2020 HeuristicBishop
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of version 3 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef ARDUINO_AVR_SHERBET

#define KALEIDOSCOPE_BOOTLOADER_FLIP_WORKAROUND 1

#include <Arduino.h>

#include "kaleidoscope/driver/keyscanner/ATmega.h"
#include "kaleidoscope/driver/bootloader/avr/FLIP.h"
#include "kaleidoscope/device/ATmega32U4Keyboard.h"

namespace kaleidoscope {
namespace device {
namespace sherbet {

struct sherbetProps : kaleidoscope::device::ATmega32U4KeyboardProps {
  struct KeyScannerProps : public kaleidoscope::driver::keyscanner::ATmegaProps {
    ATMEGA_KEYSCANNER_PROPS(
      ROW_PIN_LIST({ PIN_B5, PIN_B4, PIN_E6, PIN_D7 }),
      COL_PIN_LIST({ PIN_B6, PIN_B2, PIN_B3, PIN_B1, PIN_F7, PIN_F6 })
    );
  };
  typedef kaleidoscope::driver::keyscanner::ATmega<KeyScannerProps> KeyScanner;
  typedef kaleidoscope::driver::bootloader::avr::FLIP Bootloader;
  static constexpr const char *short_name = "sherbet";
};

#ifndef KALEIDOSCOPE_VIRTUAL_BUILD
class sherbet: public kaleidoscope::device::ATmega32U4Keyboard<sherbetProps> {
 public:
  sherbet() {
    mcu_.disableJTAG();
    mcu_.disableClockDivision();
  }
};
#else // ifndef KALEIDOSCOPE_VIRTUAL_BUILD
class sherbet;
#endif // ifndef KALEIDOSCOPE_VIRTUAL_BUILD

#define PER_KEY_DATA(dflt,                   \
         R0C0, R0C1, R0C2, R0C3, R0C4, R0C5, \
         R1C0, R1C1, R1C2, R1C3, R1C4, R1C5, \
         R2C0, R2C1, R2C2, R2C3, R2C4, R2C5, \
         R3C0, R3C1, R3C2, R3C3, R3C4, R3C5  \
  )                                          \
         R0C0, R0C1, R0C2, R0C3, R0C4, R0C5, \
         R1C0, R1C1, R1C2, R1C3, R1C4, R1C5, \
         R2C0, R2C1, R2C2, R2C3, R2C4, R2C5, \
         R3C0, R3C1, R3C2, R3C3, R3C4, R3C5
}
}

EXPORT_DEVICE(kaleidoscope::device::sherbet::sherbet)

}

#endif