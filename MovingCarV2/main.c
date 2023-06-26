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
		#include "gpio_interface.h"
    static void test_gpt_blocking_delay(void);
    static void test_motor_fwd(void);
#endif

int main(void)
{

#ifdef TEST
//    test_gpt_blocking_delay();
    test_motor_fwd();
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

    static void test_motor_fwd()
    {

        st_gpio_cfg_t motor_1A = {
            .port = GPIO_PORT_E,
            .pin = GPIO_PIN_2,
            .current = PIN_CURRENT_8MA,
            .pin_cfg = OUTPUT
        };

        st_gpio_cfg_t motor_1B = {
            .port = GPIO_PORT_E,
            .pin = GPIO_PIN_2,
            .current = PIN_CURRENT_8MA,
            .pin_cfg = OUTPUT
        };
        st_gpio_cfg_t motor_2A = {
                .port = GPIO_PORT_E,
                .pin = GPIO_PIN_4,
                .current = PIN_CURRENT_8MA,
                .pin_cfg = OUTPUT
        };
        st_gpio_cfg_t motor_2B = {
            .port = GPIO_PORT_E,
            .pin = GPIO_PIN_5,
            .current = PIN_CURRENT_8MA,
            .pin_cfg = OUTPUT
        };
        st_gpio_cfg_t motor_1EN = {
            .port = GPIO_PORT_B,
            .pin = GPIO_PIN_7,
            .current = PIN_CURRENT_8MA,
            .pin_cfg = OUTPUT
        };

        st_gpio_cfg_t motor_2EN = {
            .port = GPIO_PORT_F,
            .pin = GPIO_PIN_0,
            .current = PIN_CURRENT_8MA,
            .pin_cfg = OUTPUT
        };
        gpio_pin_init(&motor_1A);
        gpio_pin_init(&motor_2A);
        gpio_pin_init(&motor_1B);
        gpio_pin_init(&motor_2B);
        gpio_pin_init(&motor_1EN);
//        gpio_pin_init(&motor_2EN);

        gpio_setPinVal(GPIO_PORT_E, GPIO_PIN_2, HIGH);
        gpio_setPinVal(GPIO_PORT_E, GPIO_PIN_3, LOW);

        gpio_setPinVal(GPIO_PORT_B, GPIO_PIN_7, HIGH);

        gpio_setPinVal(GPIO_PORT_E, GPIO_PIN_4, HIGH);
        gpio_setPinVal(GPIO_PORT_E, GPIO_PIN_5, LOW);

//        gpio_setPinVal(GPIO_PORT_F, GPIO_PIN_0, HIGH);
				
				while(1){}
    }
#endif