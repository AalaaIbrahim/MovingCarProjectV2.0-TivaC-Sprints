/**
* @file    :   main.c
* @author  :   Hossam Elwahsh - https://github.com/HossamElwahsh
* @brief   :   Program File contains all main functions' implementation
* @version :   0.1
* @date    :   2023-06-25
*
* @copyright Copyright (c) 2023
*/

#include "app_interface.h"

//#define TEST // uncomment me to use test functions

#ifdef TEST
    #include "led_interface.h"
    #include "delay_interface.h"
    static void test_gpt_blocking_delay(void);
#endif

int main(void)
{

#ifdef TEST
    test_gpt_blocking_delay();
#else

    if(APP_OK == app_init())
    {
        app_start();
    }
    else
    {
        while(1)
        {
            /* Do Nothing */
        }
    }

#endif

	return 0;
}

#ifdef TEST
    static void test_gpt_blocking_delay(void)
    {
        led_init(LED_PORT_F, LED_PIN_1);
        led_on(LED_PORT_F, LED_PIN_1);
        delay_init();
        while(1)
        {
            led_on(LED_PORT_F, LED_PIN_1);
            delay_start(1000, TIME_IN_MS);
            led_off(LED_PORT_F,LED_PIN_1);
            delay_start(1000, TIME_IN_MS);
        }
    }
#endif