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
//                                        DEFINITIONS & TYPES                                     //
//************************************************************************************************//

//-----------------------------------------  Definitions -----------------------------------------//

//Hardware Config
#define TURN_LCD_ON                                 /* how waveshare demo was published, pick one */
//#define TURN_LCD_OFF


//Demo Select
//#define USE_STRESS_DEMO                           /* how waveshare demo was published, pick one */
#define USE_BENCHMARK_DEMO
//#define USE_MUSIC_DEMO
//#define USE_WIDGETS_DEMO
//#define USE_UI_DEMO


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
 *
 *  @section    Opens
 *      pull port lock out of nested conditional statement
 */
/**************************************************************************************************/
void app_main(void) {

    //Init
    waveshare_esp32_s3_rgb_lcd_init();              /* Initialize the Waveshare ESP32-S3 RGB LCD  */

    //Setup
#ifdef TURN_LCD_ON
       waveshare_rgb_lcd_bl_on();                   /* Turn on the screen backlight               */
#else
       waveshare_rgb_lcd_bl_off();                  /* Turn off the screen backlight              */
#endif
     
    //Notify
    ESP_LOGI(TAG, "Display LVGL demos");
    
    // Lock the mutex due to the LVGL APIs are not thread-safe
    if (lvgl_port_lock(-1)) {

#ifdef USE_STRESS_DEMO
        lv_demo_stress();

#elif defined(USE_BENCHMARK_DEMO)
        lv_demo_benchmark();

#elif defined(USE_MUSIC_DEMO)
        lv_demo_music();

#elif defined(USE_WIDGETS_DEMO)
        lv_demo_widgets();

#elif defined(USE_UI_DEMO)
        example_lvgl_demo_ui();

#endif

        // Release the mutex
        lvgl_port_unlock();
    }
}
