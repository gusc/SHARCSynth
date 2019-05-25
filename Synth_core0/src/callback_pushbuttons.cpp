/*
 * Copyright (c) 2018 Analog Devices, Inc.  All rights reserved.
 *
 * Callbacks for various pushbuttons
 *
 */

// Define your audio system parameters in this file
#include "common/audio_system_config.h"

// Structure containing shared variables between the three cores
#include "common/multicore_shared_memory.h"

// Drivers for GPIO support
#include "drivers/bm_gpio_driver/bm_gpio.h"

// Audio processing framework support
#include "audio_framework_selector.h"

#include "callback_pushbuttons.h"

/**
 * @brief Call back for push button (PB1) on SHARC Audio Module board
 *
 * @param data_object event attributes
 */
void pushbutton_callback_sam_pb1(void  *data_object) {

    // Add custom code here

    // Update our multicore structure to let the SHARCs know that a PB has been pressed
    multicore_data->sharc_sam_pb_1_pressed = true;
}

/**
 * @brief Call back for push button (PB2) on SHARC Audio Module board
 *
 * @param data_object event attributes
 */
void pushbutton_callback_sam_pb2(void  *data_object) {

    // Add custom code here

    // Update our multicore structure to let the SHARCs know that a PB has been pressed
    multicore_data->sharc_sam_pb_2_pressed = true;
}

#if    (SAM_AUDIOPROJ_FIN_BOARD_PRESENT)

/**
 * @brief Call back for PB1/SW1 on SHARC Audio Module Audio Project Fin
 *
 * @param data_object event attributes
 */
void pushbutton_callback_external_1(void  *data_object) {


    // If SW is controlling an on-off state, set LED to reflect state
	// Remove this code if SW will be used to trigger an event rather than toggle a state
    multicore_data->audioproj_fin_sw_1_state = !multicore_data->audioproj_fin_sw_1_state;
    if (multicore_data->audioproj_fin_sw_1_state) {
        gpio_write(GPIO_AUDIOPROJ_FIN_LED_SW1, GPIO_HIGH);
    }
    else {
        gpio_write(GPIO_AUDIOPROJ_FIN_LED_SW1, GPIO_LOW);
    }

    // Update our multicore structure to let the SHARCs know that a SW has been pressed
    multicore_data->audioproj_fin_sw_1_core1_pressed = true;
    multicore_data->audioproj_fin_sw_1_core2_pressed = true;

    // Add custom code here
}

/**
 * @brief Call back for PB2/SW2 on SHARC Audio Module Audio Project Fin
 *
 * @param data_object event attributes
 */
void pushbutton_callback_external_2(void  *data_object) {

    // If SW is controlling an on-off state, set LED to reflect state
	// Remove this code if SW will be used to trigger an event rather than toggle a state
    multicore_data->audioproj_fin_sw_2_state = !multicore_data->audioproj_fin_sw_2_state;
    if (multicore_data->audioproj_fin_sw_2_state) {
        gpio_write(GPIO_AUDIOPROJ_FIN_LED_SW2, GPIO_HIGH);
    }
    else {
        gpio_write(GPIO_AUDIOPROJ_FIN_LED_SW2, GPIO_LOW);
    }

    // Update our multicore structure to let the SHARCs know that a PB has been pressed
    multicore_data->audioproj_fin_sw_2_core1_pressed = true;
    multicore_data->audioproj_fin_sw_2_core2_pressed = true;

    // Add custom code here
}

/**
 * @brief Call back for PB3/SW3 on SHARC Audio Module Audio Project Fin
 *
 * @param data_object event attributes
 */
void pushbutton_callback_external_3(void  *data_object) {

    // If SW is controlling an on-off state, set LED to reflect state
	// Remove this code if SW will be used to trigger an event rather than toggle a state
    multicore_data->audioproj_fin_sw_3_state = !multicore_data->audioproj_fin_sw_3_state;
    if (multicore_data->audioproj_fin_sw_3_state) {
        gpio_write(GPIO_AUDIOPROJ_FIN_LED_SW3, GPIO_HIGH);
    }
    else {
        gpio_write(GPIO_AUDIOPROJ_FIN_LED_SW3, GPIO_LOW);
    }

    // Update our multicore structure to let the SHARCs know that a PB has been pressed
    multicore_data->audioproj_fin_sw_3_core1_pressed = true;
    multicore_data->audioproj_fin_sw_3_core2_pressed = true;

    // Add custom code here
}

/**
 * @brief Call back for PB4/SW4 on SHARC Audio Module Audio Project Fin
 *
 * @param data_object event attributes
 */
void pushbutton_callback_external_4(void  *data_object) {

    // If SW is controlling an on-off state, set LED to reflect state
	// Remove this code if SW will be used to trigger an event rather than toggle a state
    multicore_data->audioproj_fin_sw_4_state = !multicore_data->audioproj_fin_sw_4_state;
    if (multicore_data->audioproj_fin_sw_4_state) {
        gpio_write(GPIO_AUDIOPROJ_FIN_LED_SW4, GPIO_HIGH);
    }
    else {
        gpio_write(GPIO_AUDIOPROJ_FIN_LED_SW4, GPIO_LOW);
    }

    // Update our multicore structure to let the SHARCs know that a PB has been pressed
    multicore_data->audioproj_fin_sw_4_core1_pressed = true;
    multicore_data->audioproj_fin_sw_4_core2_pressed = true;

    // Add custom code here
}
#endif
