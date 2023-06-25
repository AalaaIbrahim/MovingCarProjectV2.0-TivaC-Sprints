/**
 * @file    :   app_program.c
 * @author  :   Alaa Hisham & Hossam Elwahsh
 * @brief   :   Program File contains all APP flow functions' implementation
 * @version :   0.1
 * @date    :   2023-06-25
 *
 * @copyright Copyright (c) 2023
 */

#include "app_interface.h"
#include "app_private.h"

/* Private Global Variables */
static en_app_state_t gl_en_app_state_next_side = APP_STATE_LONG_SIDE;
static en_app_state_t gl_en_current_app_state = APP_STATE_STOPPED;










/* Private Macros */
#define LONG_SIDE_LED_PORT 		LED_PORT_F // Port F
#define LONG_SIDE_LED_PIN			LED_PIN_1

#define SHORT_SIDE_LED_PORT 	    LED_PORT_F // Port F
#define SHORT_SIDE_LED_PIN		LED_PIN_3

#define ROTATING_LED_PORT 	    LED_PORT_F // Port F
#define ROTATING_LED_PIN		LED_PIN_2

#define STOPPED_LED_PORT        LED_PORT_E
#define STOPPED_LED_PIN        LED_PIN_1

#define START_BTN_PORT		BTN_PORT_F // Port F
#define START_BTN_PIN		BTN_PIN_4

#define STOP_BTN_PORT		BTN_PORT_F // Port F
#define STOP_BTN_PIN		BTN_PIN_0














en_app_status_t app_init() // todo-hossam
{
    en_app_status_t en_app_status_retval = APP_OK;

    // global vars





    // init DCM











    // init LED x4
    led_init()













    // init init start btn








    // init init stop btn (interrupt)








    return en_app_status_retval;
} // line 116






















void app_start() // todo-alaa
{
    while(TRUE)
    {
        // check start btn























        // todo states



























































































































    }
} // line 292

















static void app_switch_state() // todo-hossam
{
    // switch on states




































    // update gl_en_app_state_next_side






































    // update gl_en_current_app_state





























} // line 418













static void app_stop_btn_callback() // todo-alaa
{



































































} // line 500