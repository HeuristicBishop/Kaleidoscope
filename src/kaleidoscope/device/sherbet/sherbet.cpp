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

#ifndef KALEIDOSCOPE_VIRTUAL_BUILD
#ifdef ARDUINO_AVR_SHERBET

#include "kaleidoscope/key_events.h"
#include "kaleidoscope/driver/keyscanner/ATmega.h"
#include "kaleidoscope/driver/keyscanner/Base_Impl.h"
#include "kaleidoscope/Runtime.h"

namespace kaleidoscope {
namespace device {
namespace sherbet {

ATMEGA_KEYSCANNER_BOILERPLATE

}
}
}

kaleidoscope::device::sherbet::SHERBET = kaleidoscope_internal::device;

#endif
#endif // ifndef KALEIDOSCOPE_VIRTUAL_BUILD
