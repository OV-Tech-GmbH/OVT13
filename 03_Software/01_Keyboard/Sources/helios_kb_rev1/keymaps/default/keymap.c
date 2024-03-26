// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"
#include "matrix.h"

/*
 * To Do: 2x Grave in Zeile 1
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_6x15(
	    KC_ESCAPE,	   KC_F1,   	 KC_F2, KC_F3,		 KC_F4,    KC_F5,		  KC_F6, 		KC_F7,	 KC_F8, 		  KC_F9,    	KC_F10,  		KC_F11,	 		 KC_F12, 		   KC_INSERT,		KC_DELETE,
        KC_GRAVE,	   KC_1,   		 KC_2,  KC_3, 		 KC_4,     KC_5,		  KC_6,  		KC_7,	 KC_8,  		  KC_9,     	KC_0,    		KC_EQUAL, 		 KC_GRAVE, 		   KC_BACKSLASH,	KC_NO,	
        KC_TAB,		   KC_Q,   		 KC_W,  KC_E, 		 KC_R,     KC_T,		  KC_Z,  		KC_U,	 KC_I,  		  KC_O,     	KC_P,    		KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_NO, 			KC_ENTER,
        KC_CAPS_LOCK,  KC_A, 		 KC_S, 	KC_D, 		 KC_F, 	   KC_G,		  KC_H,  		KC_J,	 KC_K,  		  KC_L,  	  	KC_SEMICOLON, 	KC_QUOTE, 		 KC_NONUS_HASH,	   KC_NO,			KC_NO,
		KC_LEFT_SHIFT, KC_BACKSLASH, KC_Y,	KC_X, 		 KC_C, 	   KC_V,		  KC_B,  		KC_N,	 KC_M,  		  KC_COMMA, 	KC_DOT,      	KC_SLASH,		 KC_RIGHT_SHIFT,   KC_NO, 			KC_NO,   			      
		KC_LEFT_CTRL,  KC_NO,	     KC_NO,	KC_LEFT_ALT, KC_NO,	   KC_SPACE, 	  KC_NO,		KC_NO,   KC_RIGHT_CTRL,   KC_RIGHT_ALT, KC_LEFT, 		KC_UP, 			 KC_DOWN,  		   KC_RIGHT,  			
    )
};

typedef enum{
	LED_ON = 0,
	LED_OFF = 1,
	LED_BREATHING = 2,
	LED_NON_BREATHING = 3,
} LEDSTATUS;

LEDSTATUS wLEDstatus = LED_OFF;
LEDSTATUS rgbLEDstatus = 0;
LEDSTATUS wLEDBreathing = LED_NON_BREATHING;

void helios_kb_rnd(void);
static bool HELIOS_select_col(uint8_t current_col);
static void HELIOS_unselect_col(uint8_t col);
static void HELIOS_unselect_cols(void);

void helios_kb_rnd(void)
{
//	if (is_backlight_enabled() == TRUE)
//	{
//		uint8_t backlightlevel = get_backlight_level();
//		dprintf("backlightlevel: %u\n", backlightlevel);
//		backlight_increase();
//	}
//	else if (is_backlight_enabled() == FALSE)
//	{
//		dprint("Backlight is disabled \n");
//
//		backlight_enable();
//	}
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Your code goes here
    // `data` is a pointer to the buffer containing the received HID report
    // `length` is the length of the report - always `RAW_EPSIZE`
}

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.
  
	// RnD RGB-LEDs power on.
	setPinOutput(GP21);
	writePinHigh(GP21);
	
	// RnD W-LEDs power on.
	setPinOutput(GP22);
	writePinHigh(GP22);

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	
	helios_kb_rnd();
	
	// Switch-Case in here to create custom functionality
	 switch (keycode) {
		case KC_F2:
			// Toggle W-LED status
			if (record->event.pressed) {
				if (wLEDstatus == LED_OFF)
				{
					if(wLEDBreathing == LED_BREATHING)
					{
						#ifdef BACKLIGHT_BREATHING
						//backlight_enable_breathing();
						//breathing_period_default();
						#endif
						dprint("Backlight breathing is enabled \n");
					}
					else
					{
						backlight_enable();
					}
					wLEDstatus = LED_ON;
					dprint("Backlight is enabled \n");
				}
				else if(wLEDstatus == LED_ON)
				{
					if(wLEDBreathing == LED_BREATHING)
					{
						#ifdef BACKLIGHT_BREATHING
						//backlight_disable_breathing();
						dprint("Backlight breathing is disabled \n");
						#endif
					}
					else
					{
						backlight_disable();
					}
					
					wLEDstatus = LED_OFF;
					dprint("Backlight is disabled \n");
				}
				// else nothing to do
			}
			return true;
		case KC_F3:
			// Increase WLED intensity
			if (record->event.pressed) {
				if (wLEDstatus == LED_ON)
				{
					backlight_increase();
					uint8_t lvl = get_backlight_level();
					dprintf("Backlight is increased. Current level: %u \n", lvl);
				}
			}
			return true;
			// else nothing to do
		case KC_F4:
			// Decrease WLED intensity
			if (record->event.pressed) {
				if (wLEDstatus == LED_ON)
				{
					backlight_decrease();
					uint8_t lvl = get_backlight_level();
					dprintf("Backlight is decreased. Current level: %u \n", lvl);
				}
				// else nothing to do
			}
			// else nothing to do
			return true;
		case KC_F6:
			// Toggle rgb-LED status
			if (record->event.pressed) {
				if (rgbLEDstatus == LED_OFF)
				{
					rgblight_enable();
					rgbLEDstatus = LED_ON;
				}
				else if(rgbLEDstatus == LED_ON)
				{
					rgblight_disable();
					rgbLEDstatus = LED_OFF;
				}
				// else nothing to do
			}
			// else nothing to do
			return true;
		case KC_F7:
			// Increase RGB value (HSV)
			if (rgbLEDstatus == LED_ON)
			{
				rgblight_increase_val();
			}
			// else nothing to do
			return true;
		case KC_F8:
			// Decrease RGB value (HSV)
			if (rgbLEDstatus == LED_ON)
			{
				rgblight_decrease_val();
			}
			// else nothing to do
			return true;
		case KC_F9:
			// Increase RGB saturation (HSV)
			if (rgbLEDstatus == LED_ON)
			{
				rgblight_increase_sat();
			}
			// else nothing to do
			return true;
		case KC_F10:
			// Decrease RGB saturation (HSV)
			if (rgbLEDstatus == LED_ON)
			{
				rgblight_decrease_sat();
			}
			// else nothing to do
			return true;
		case KC_F11:
			// Increase RGB hue (HSV)
			if (rgbLEDstatus == LED_ON)
			{
				rgblight_increase_hue();
			}
			// else nothing to do
			return true;
		case KC_F12:
			// Decrease RGB hue (HSV)
			if (rgbLEDstatus == LED_ON)
			{
				rgblight_decrease_hue();
			}
			// else nothing to do
			return true;

		default:
			return true;
	 }
}

void keyboard_post_init_user(void) {
	// Customise these values to desired behaviour
	debug_enable=true;
	debug_matrix=true;
	debug_keyboard=true;
	//debug_mouse=true;

	backlight_init_ports();
	backlight_init();
	backlight_level(0);
	
}

pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;


static bool HELIOS_select_col(uint8_t col)
{
	pin_t pin = col_pins[col];
    if (pin != NO_PIN) {
        setPinOutput_writeHigh(pin);
        return true;
    }
    return false;	
}

static void HELIOS_unselect_col(uint8_t col)
{
    pin_t pin = col_pins[col];
    if (pin != NO_PIN)
	{
        setPinOutput_writeLow(pin);
    }
}

static void HELIOS_unselect_cols(void)
{
    for (uint8_t x = 0; x < MATRIX_COLS; x++)
	{
        HELIOS_unselect_col(x);
    }
}

void matrix_init_pins(void)
{
	HELIOS_unselect_cols();
	for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
		if (row_pins[x] != NO_PIN) {
			setPinInputLow_atomic(row_pins[x]);
		}
	}	
}

void matrix_read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col, matrix_row_t row_shifter)
{
	bool key_pressed = false;
	// Select col
    if (!HELIOS_select_col(current_col))
	{ // select col
        return;                     // skip NO_PIN col
    }
	
    matrix_output_select_delay();
	
	// For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++)
	{
        // Check row pin state
        if (readMatrixPin(row_pins[row_index]) == 1)
		{
			// Pin LO, set col bit
			current_matrix[row_index] |= row_shifter;
			key_pressed = true;
        }
		else
		{
            // Pin HI, clear col bit
            current_matrix[row_index] &= ~row_shifter;
        }
    }

    // Unselect col
    HELIOS_unselect_col(current_col);
    matrix_output_unselect_delay(current_col, key_pressed);
}
