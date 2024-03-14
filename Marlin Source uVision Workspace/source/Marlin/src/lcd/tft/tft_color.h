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

#include "../../inc/MarlinConfigPre.h"

#define RED(color)            ((color >> 8) & 0xF8)
#define GREEN(color)          ((color >> 3) & 0xFC)
#define BLUE(color)           ((color << 3) & 0xF8)
#define RGB(red, green, blue) (((red << 8) & 0xF800) | ((green << 3) & 0x07E0) | ((blue >> 3) & 0x001F))
#define COLOR(color)          RGB(((color >> 16) & 0xFF), ((color >> 8) & 0xFF), (color & 0xFF))
#define HALF(color)           RGB(RED(color) >> 1, GREEN(color) >> 1, BLUE(color) >> 1)

// 16 bit color generator: https://ee-programming-notepad.blogspot.com/2016/10/16-bit-color-generator-picker.html
// RGB565 color picker:  https://trolsoft.ru/en/articles/rgb565-color-picker

#define COLOR_BLACK           0x0000  // #000000
#define COLOR_WHITE           0xFFFF  // #FFFFFF
#define COLOR_GREY            0x7BEF  // #808080
#define COLOR_DARKGREY        0x4208  // #404040
#define COLOR_DARKGREY2       0x39E7  // #303030
#define COLOR_DARK            0x0003  // #000019

#define COLOR_SILVER          0xF7BE  // #F3F6F4
#define COLOR_SLATE           0xC619  // #C0C2C9
#define COLOR_BG         0x2A4A  // #2F4B52
#define COLOR_OCEAN1          0x1DDA  // #19B9D1
#define COLOR_OCEAN2          0x24D6  // #229BB3
#define COLOR_OCEAN3          0x1497  // #1592BF
#define COLOR_2BLUE        0x5F5F  // #5EEAFF
#define COLOR_2PINK         	0xE151  // #E02B8F
#define COLOR_2PURPLE         0xB81F  // #BA03FC
#define COLOR_2ORANGE        0xEA40  // #ED4A02
#define COLOR_2GREEN        0x07D3  // #05FA98
#define COLOR_2GREY       	0x4208  // #424242
#define COLOR_TEABLU      0x22AB  // #20545C
 #define COLOR_MRED      0xCA69  // #C94F4F 	

#define COLOR_RED             0xF800  // #FF0000
#define COLOR_SCARLET         0xF904  // #FF2020
#define COLOR_LIME            0x7E00  // #00FF00
#define COLOR_BLUE            0x001F  // #0000FF
#define COLOR_LIGHT_BLUE      0x061F  // #00C3FF
#define COLOR_YELLOW          0xFFE0  // #FFFF00
#define COLOR_MAGENTA         0xF81F  // #FF00FF
#define COLOR_FUCHSIA         0xF81F  // #FF00FF
#define COLOR_CYAN            0x07FF  // #00FFFF
#define COLOR_AQUA            0x07FF  // #00FFFF
#define COLOR_DODGER_BLUE     0x041F  // #0080FF
#define COLOR_VIVID_VIOLET    0x7933  // #772399

#define COLOR_DARK_PURPLE     0x9930  // #992380

#define COLOR_MAROON          0x7800  // #800000
#define COLOR_GREEN           	0x5FF6  // #008000
#define COLOR_NAVY            0x000F  // #000080
#define COLOR_OLIVE           0x8400  // #808000
#define COLOR_PURPLE          0x8010  // #800080
#define COLOR_TEAL            0x0410  // #008080

#define COLOR_ORANGE          0xFC00  // #FF7F00
#define COLOR_VIVID_GREEN     0x7FE0  // #7FFF00
#define COLOR_DARK_ORANGE     0xFC40  // #FF8C00
#define COLOR_CORAL_RED       0xF9E7  // #FF3F3F

#define COLOR_DARK_PURPLE     0x9930  // #992380

#define COLOR_HIGHLIGHTS   0x07E8  //  #03FC41

#ifndef COLOR_BACKGROUND
  #define COLOR_BACKGROUND  COLOR_BG
#endif
#ifndef COLOR_FOREGROUND
  #define COLOR_FOREGROUND   COLOR_SILVER     
#endif
#ifndef COLOR_FRAMES
  #define COLOR_FRAMES  COLOR_SILVER
#endif
#ifndef COLOR_SELECTION_BG
  #define COLOR_SELECTION_BG  	COLOR_OCEAN3
#endif
#ifndef COLOR_WEBSITE_URL
  #define COLOR_WEBSITE_URL  COLOR_BLACK
#endif

#ifndef COLOR_INACTIVE 
  #define COLOR_INACTIVE            COLOR_2GREY
#endif
#ifndef COLOR_ACTIVE 
  #define COLOR_ACTIVE            COLOR_2GREEN
#endif
#ifndef COLOR_PAUSE_ERROR
  #define COLOR_PAUSE_ERROR            COLOR_2PINK
#endif
#ifndef COLOR_COLD
  #define COLOR_COLD              COLOR_OCEAN1
#endif
#ifndef COLOR_HOTEND
  #define COLOR_HOTEND            COLOR_2PINK
#endif
#ifndef COLOR_HEATED_BED
  #define COLOR_HEATED_BED        COLOR_2PURPLE
#endif
#ifndef COLOR_CHAMBER
  #define COLOR_CHAMBER           COLOR_2BLUE
#endif
#ifndef COLOR_COOLER
  #define COLOR_COOLER            COLOR_OCEAN3
#endif
#ifndef COLOR_FAN
  #define COLOR_FAN              COLOR_2BLUE
#endif
#ifndef COLOR_SDCARD
  #define COLOR_SDCARD            COLOR_HIGHLIGHTS
#endif
#ifndef COLOR_PAUSE_BTN
  #define COLOR_PAUSE_BTN            COLOR_HIGHLIGHTS
#endif
#ifndef COLOR_BLINK_TXT_O
  #define COLOR_BLINK_TXT_O         COLOR_HIGHLIGHTS
#endif


#ifndef COLOR_AXIS_HOMED
  #define COLOR_AXIS_HOMED        COLOR_AQUA  
#endif
#ifndef COLOR_AXIS_NOT_HOMED
  #define COLOR_AXIS_NOT_HOMED    COLOR_MRED
#endif

#ifndef COLOR_RATE_100
  #define COLOR_RATE_100          COLOR_AQUA  
#endif
#ifndef COLOR_RATE_ALTERED
  #define COLOR_RATE_ALTERED      COLOR_MRED
#endif

#ifndef COLOR_PRINT_TIME
  #define COLOR_PRINT_TIME        COLOR_SILVER
#endif

#ifndef COLOR_PROGRESS_FRAME
  #define COLOR_PROGRESS_FRAME    COLOR_SILVER
#endif
#ifndef COLOR_PROGRESS_BAR
  #define COLOR_PROGRESS_BAR      COLOR_2GREEN
#endif
#ifndef COLOR_PROGRESS_BG
  #define COLOR_PROGRESS_BG       COLOR_BLACK
#endif

#ifndef COLOR_STATUS_MESSAGE
  #define COLOR_STATUS_MESSAGE    COLOR_SILVER
#endif

#ifndef COLOR_CONTROL_ENABLED
  #define COLOR_CONTROL_ENABLED   COLOR_2GREEN
#endif
#ifndef COLOR_CONTROL_DISABLED
  #define COLOR_CONTROL_DISABLED  COLOR_2GREY
#endif
#ifndef COLOR_CONTROL_CANCEL
  #define COLOR_CONTROL_CANCEL    COLOR_2PINK
#endif
#ifndef COLOR_CONTROL_CONFIRM
  #define COLOR_CONTROL_CONFIRM   COLOR_2GREEN
#endif
#ifndef COLOR_BUSY
  #define COLOR_BUSY              COLOR_2GREEN
#endif
#ifndef COLOR_CONTROL_NSELECTED
  #define COLOR_CONTROL_NSELECTED    COLOR_2GREY
#endif
#ifndef COLOR_CONTROL_SELECTED
  #define COLOR_CONTROL_SELECTED  COLOR_2GREEN
#endif

#ifndef COLOR_MENU_TEXT
  #define COLOR_MENU_TEXT         COLOR_SILVER
#endif
#ifndef COLOR_MENU_VALUE
  #define COLOR_MENU_VALUE        COLOR_WHITE
#endif

#ifndef COLOR_SLIDER
  #define COLOR_SLIDER            COLOR_SILVER
#endif
#ifndef COLOR_SLIDER_INACTIVE
  #define COLOR_SLIDER_INACTIVE   COLOR_2GREY
#endif

#ifndef COLOR_UBL_PROG
  #define COLOR_UBL _PROG             COLOR_2GREEN
#endif

#ifndef COLOR_TOUCH_CALIBRATION
  #define COLOR_TOUCH_CALIBRATION COLOR_SILVER
#endif

#ifndef COLOR_KILL_SCREEN_BG
  #define COLOR_KILL_SCREEN_BG    COLOR_MAROON
#endif
#ifndef COLOR_KILL_SCREEN_TEXT
  #define COLOR_KILL_SCREEN_TEXT  COLOR_SILVER
#endif
