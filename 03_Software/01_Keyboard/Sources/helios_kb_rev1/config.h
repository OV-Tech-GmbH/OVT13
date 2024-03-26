// Copyright 2023 ThomasL (@ThommyL34)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define BACKLIGHT_PIN GP25
//#define BACKLIGHT_LEVELS 10
//#define BACKLIGHT_LIMIT_VAL 255
//#define BACKLIGHT_ON_STATE 1

//#define BACKLIGHT_DEFAULT_ON TRUE
//#define BACKLIGHT_DEFAULT_LEVEL BACKLIGHT_LEVELS
//#define RGBLIGHT_DEFAULT_HUE 169
#define RGBLIGHT_LIMIT_VAL 255
#define WS2812_DI_PIN GP23
#define RGBLED_NUM 82
//#define HAL_USE_PWM TRUE
//#define RP_PWM_USE_PWM4 TRUE
//#define BACKLIGHT_PWM_DRIVER PWMD4