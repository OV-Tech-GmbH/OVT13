// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

//#define BACKLIGHT_PWM_DRIVER PWMD4
#define RP_PWM_USE_PWM4 TRUE
#define BACKLIGHT_PWM_CHANNEL 2 // CH B OK
//#define BACKLIGHT_PAL_MODE PAL_MODE_OUTPUT_PUSHPULL   
//PAL_MODE_OUTPUT_PUSHPULL 
//#define BACKLIGHT_PWM_PERIOD

#include_next <mcuconf.h>
