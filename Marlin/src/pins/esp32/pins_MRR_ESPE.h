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

/**
 * MRR ESPE pin assignments
 * MRR ESPE is a 3D printer control board based on the ESP32 microcontroller.
 * Supports 5 stepper drivers (using I2S stepper stream), heated bed,
 * single hotend, and LCD controller.
 */

#include "env_validate.h"

#if EXTRUDERS > 1 || E_STEPPERS > 1
  #error "MRR ESPE only supports two E Steppers. Comment out this line to continue."
#elif HOTENDS > 1
  #error "MRR ESPE only supports one hotend / E-stepper. Comment out this line to continue."
#endif

#define BOARD_INFO_NAME      "MRR ESPE"
#define BOARD_WEBSITE_URL    "github.com/maplerainresearch/MRR_ESPE"
#define DEFAULT_MACHINE_NAME BOARD_INFO_NAME

// Added by RC; pull down nOE line 
#define BOARD_PREINIT() { \
  OUT_WRITE(33, LOW); \
}
// End addition

//
// Limit Switches
//
#define X_STOP_PIN                            32 //35
#define Y_STOP_PIN                            35 //32
#define Z_STOP_PIN                            34 //33

// probe
#define Z_MIN_PROBE_PIN                       15
#define Z_PROBE_SERVO_NR                      0
#define SERVO0_PIN                            17//137
//
// Enable I2S stepper stream
//
#undef I2S_STEPPER_STREAM
#define I2S_STEPPER_STREAM
#define I2S_WS                                26
#define I2S_BCK                               25
#define I2S_DATA                              27
#undef LIN_ADVANCE                                // Currently, I2S stream does not work with linear advance

//
// Steppers
//
#define MOTOR_ENABLE_PIN                     128
#define X_STEP_PIN                           132 //129
#define X_DIR_PIN                            133 //130
#define X_ENABLE_PIN                         MOTOR_ENABLE_PIN
//#define X_CS_PIN                            21

#define Y_STEP_PIN                           129 //132
#define Y_DIR_PIN                            130 //133
#define Y_ENABLE_PIN                         MOTOR_ENABLE_PIN //131
//#define Y_CS_PIN                            22

#define Z_STEP_PIN                           135
#define Z_DIR_PIN                            136
#define Z_ENABLE_PIN                         MOTOR_ENABLE_PIN //134
//#define Z_CS_PIN                             5  // SS_PIN

#define E0_STEP_PIN                          138
#define E0_DIR_PIN                           139
#define E0_ENABLE_PIN                        MOTOR_ENABLE_PIN // 137
//#define E0_CS_PIN                           21

//#define E1_STEP_PIN                          141
//#define E1_DIR_PIN                           142
//#define E1_ENABLE_PIN                        MOTOR_ENABLE_PIN // 140
////#define E1_CS_PIN                           22

//#define Z2_STEP_PIN                          141
//#define Z2_DIR_PIN                           142
//#define Z2_ENABLE_PIN                        MOTOR_ENABLE_PIN //140
////#define Z2_CS_PIN                            5

//
// Temperature Sensors
//
#define TEMP_0_PIN                            36  // Analog Input
// #define TEMP_1_PIN                            34  // Analog Input
#define TEMP_BED_PIN                          39  // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN                         145  // 2
#define FAN_PIN                              17 //143 //146  // 15
// #define FAN_SOFT_PWM
#define HEATER_BED_PIN                       144  // 4

//#define CONTROLLER_FAN_PIN                   147
//#define E0_AUTO_FAN_PIN                    148  // need to update Configuration_adv.h @section extruder
//#define E1_AUTO_FAN_PIN                    149  // need to update Configuration_adv.h @section extruder
//#define FAN1_PIN                             149

//
// MicroSD card
//
#define SD_MOSI_PIN                           23
#define SD_MISO_PIN                           19
#define SD_SCK_PIN                            18
#define SDSS                                   5
#define USES_SHARED_SPI                           // SPI is shared by SD card with TMC SPI drivers

//////////////////////////
// LCDs and Controllers //
//////////////////////////

//
// LCD / Controller
//
#if ANY(VIKI2, miniVIKI)

  #define LCD_SCREEN_ROT_180

  #define KILL_PIN                         4  // (41) J5-4 & AUX-4
  // #define LCD_PINS_RS                      P0_16  // (16) J3-7 & AUX-4
  // #define LCD_SDSS                         P0_16  // (16) J3-7 & AUX-4
  // #define LCD_BACKLIGHT_PIN                P0_16  // (16) J3-7 & AUX-4 - only used on DOGLCD controllers
  // #define LCD_PINS_ENABLE                  P0_18  // (51) (MOSI) J3-10 & AUX-3
  // #define LCD_PINS_D4                      P0_15  // (52) (SCK)  J3-9 & AUX-3
  #define BEEPER_PIN                       146 //P1_31
  #define DOGLCD_A0                        147 //P2_11
  #define DOGLCD_CS                        148 //17
  #define DOGLCD_SCK                       18 //SCK_PIN
  #define DOGLCD_MOSI                      23 //MOSI_PIN

  #define BTN_EN1                          0
  #define BTN_EN2                          12
  #define BTN_ENC                          14

  #define SD_DETECT_PIN                    15 //P1_18
  //#define SDSS                             5 //P1_21

  #define STAT_LED_RED_PIN                 150 //P1_19
  #define STAT_LED_BLUE_PIN                149 //P1_20

//#endif
#elif HAS_MARLINUI_U8GLIB

  #define LCD_PINS_RS                         147 //18//13
  #define LCD_PINS_ENABLE                     148 //17
  #define LCD_PINS_D4                         141 //23 //16
  #define LCD_PINS_D6                         149 //reset pin

  #if ENABLED(CR10_STOCKDISPLAY)

    #define BEEPER_PIN                       146

  #elif IS_RRD_FG_SC

    #define BEEPER_PIN                       146

    //#define LCD_PINS_D5                    150
    //#define LCD_PINS_D6                    152
    //#define LCD_PINS_D7                    153

  #else

    //#error "Only CR10_STOCKDISPLAY and REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER are currently supported. Comment out this line to continue."

  #endif

  #define BTN_EN1                             0
  #define BTN_EN2                             2
  #define BTN_ENC                             14
  #define BTN_BACK                            4
  #define KILL_PIN                            13
  #define STAT_LED_RED_PIN                    150
  #define STAT_LED_BLUE_PIN                   134
  #define BEEPER_PIN                          146

  #define LCD_SCREEN_ROT_180

#endif // HAS_MARLINUI_U8GLIB

// Hardware serial pins
// Add the following to Configuration.h or Configuration_adv.h to assign
// specific pins to hardware Serial1 and Serial2.
// Note: Serial2 can be defined using HARDWARE_SERIAL2_RX and HARDWARE_SERIAL2_TX but
// MRR ESPA does not have enough spare pins for such reassignment.
//#define HARDWARE_SERIAL1_RX                 21
//#define HARDWARE_SERIAL1_TX                 22
//#define HARDWARE_SERIAL2_RX                  2
//#define HARDWARE_SERIAL2_TX                  4
