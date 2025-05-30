/**************************************************************************************************/
/** @file       main.c
 *  @brief      x
 *  @details    x
 *
 *  @section    Legal Disclaimer
 *      SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 *      SPDX-License-Identifier: CC0-1.0
 */
/**************************************************************************************************/

//************************************************************************************************//
//                                            INCLUDES                                            //
//************************************************************************************************//

//Project Includes
#include "waveshare_rgb_lcd_port.h"


//************************************************************************************************//
//                                          PUBLIC FUNCTIONS                                      //
//************************************************************************************************//

/**************************************************************************************************/
/** @fcn        void app_main(void)
 *  @brief      FreeRTOS task for main application
 *  @details    Called by FreeRTOS scheduler when started, running on core for main thread
 *
 *  @section    Purpose
 *      Unlike normal FreeRTOS tasks, or embedded C main functions, the app_main() task is allowed 
 *      to return. If this happens, The task is cleaned up and the system will continue running 
 *      with other RTOS tasks scheduled normally. Therefore, it is possible to implement app_main 
 *      as either a function that creates other application tasks and then returns, or as a main 
 *      application task itself. app_main() has a fixed RTOS priority, one higher than the minimum
 *
 *  @pre    second stage bootloader
 *  @post   no return
 */
/**************************************************************************************************/
void app_main(void) {

    waveshare_esp32_s3_rgb_lcd_init();              /* Initialize the Waveshare ESP32-S3 RGB LCD  */
    waveshare_rgb_lcd_bl_on();                      /* Turn on the screen backlight               */
    waveshare_rgb_lcd_bl_off();                     /* Turn off the screen backlight              */

    
    ESP_LOGI(TAG, "Display LVGL demos");
    
    // Lock the mutex due to the LVGL APIs are not thread-safe
    if (lvgl_port_lock(-1)) {
        
        // lv_demo_stress();
        // lv_demo_benchmark();
        // lv_demo_music();
        // lv_demo_widgets();
        example_lvgl_demo_ui();
        
        // Release the mutex
        lvgl_port_unlock();
    }
}
