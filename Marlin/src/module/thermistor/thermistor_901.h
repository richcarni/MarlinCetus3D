/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define REVERSE_TEMP_SENSOR_RANGE_901 1

// User-defined table 1

const temp_entry_t temptable_901[] PROGMEM = {
  { OV(  0), 0 },
  { OV(  124), 20 },
  { OV(  155), 25 },
  { OV(  186), 30 },
  { OV(  217), 35 },
  { OV(  248), 40 },
  { OV(  279), 45 },
  { OV(  310), 50 },
  { OV(  341), 55 },
  { OV(  372), 60 },
  { OV(  404), 65 },
  { OV(  435), 70 },
  { OV(  466), 75 },
  { OV(  497), 80 },
  { OV(  528), 85 },
  { OV(  559), 90 },
  { OV(  590), 95 },
  { OV(  621), 100 },
  { OV(  652), 105 },
  { OV(  683), 110 }
};
