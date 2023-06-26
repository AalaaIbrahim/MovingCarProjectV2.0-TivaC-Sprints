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
static en_app_state_t gl_en_current_app_state = APP_STATE_IDLE;










/* Private Macros */
#define LONG_SIDE_LED_PORT 		LED_PORT_F // Port F
#define LONG_SIDE_LED_PIN			LED_PIN_1

#define SHORT_SIDE_LED_PORT 	    LED_PORT_F // Port F
#define SHORT_SIDE_LED_PIN		LED_PIN_3

#define ROTATING_LED_PORT 	    LED_PORT_F // Port F
#define ROTATING_LED_PIN		LED_PIN_2

#define STOPPED_LED_PORT        LED_PORT_E
#define STOPPED_LED_PIN        LED_PIN_1

#define START_BTN_PORT		BTN_PORT_B 
#define START_BTN_PIN		BTN_PIN_6

#define STOP_BTN_PORT		BTN_PORT_D 
#define STOP_BTN_PIN		BTN_PIN_2














en_app_status_t app_init()
{
    en_app_status_t en_app_status_retval = APP_OK;

    // global vars





    // init DCM
    if(DCM_OK != dcm_init())
    {
        en_app_status_retval = APP_ERROR;
    }










    // init LED x4
    if(LED_OK != led_init(LONG_SIDE_LED_PORT, LONG_SIDE_LED_PIN))
    {
        en_app_status_retval = APP_ERROR;
    }
    if(LED_OK != led_init(SHORT_SIDE_LED_PORT, SHORT_SIDE_LED_PIN))
    {
        en_app_status_retval = APP_ERROR;
    }
    if(LED_OK != led_init(ROTATING_LED_PORT, ROTATING_LED_PIN))
    {
        en_app_status_retval = APP_ERROR;
    }
    if(LED_OK != led_init(STOPPED_LED_PORT, STOPPED_LED_PIN))
    {
        en_app_status_retval = APP_ERROR;
    }

    // init init start btn
    if(BUTTON_NOK == button_init(START_BTN_PORT, START_BTN_PIN, FALSE))
    {
        en_app_status_retval = APP_ERROR;
    }


    // init init stop btn (interrupt)
    if(BUTTON_NOK == button_init(STOP_BTN_PORT, STOP_BTN_PIN, TRUE))
    {
        en_app_status_retval = APP_ERROR;
    }

    return en_app_status_retval;
} // line 116






















void app_start()
{
	en_btn_state_t en_lo_btn_state = BUTTON_RELEASED;

	while (TRUE)
	{
		if (APP_STATE_IDLE == gl_en_current_app_state)
		{
			// check start btn
			button_get_state(START_BTN_PORT, START_BTN_PIN, &en_lo_btn_state);

			if (BUTTON_PRESSED == en_lo_btn_state)
			{
				/* Update the Application State */
				gl_en_current_app_state = APP_STATE_START;
			}
			else
			{
				/* Do Nothing */
			}
		}
		else if (APP_STATE_START == gl_en_current_app_state)
		{
			/* Update the Application State */
			gl_en_current_app_state = APP_STATE_LONG_SIDE;

			/* Enable the delay */
			delay_shutdown(FALSE);

			/* Wait one second */
			delay_start(APP_START_TIME, TIME_IN_MS);
		}
		else if (APP_STATE_STOPPED == gl_en_current_app_state)
		{
			/* Update the Application State */
			gl_en_current_app_state = APP_STATE_IDLE;

			/* Turn on the stop LED */
			led_on(STOPPED_LED_PORT, STOPPED_LED_PIN);
			
			/* Stop the Car */
			dcm_stop();
		}
		else if (APP_STATE_LONG_SIDE == gl_en_current_app_state)
		{
			/* Update the Application State */
			gl_en_current_app_state = APP_STATE_ROTATE;

			/* Turn off the stop LED */
			led_off(STOPPED_LED_PORT, STOPPED_LED_PIN);

			/* Turn on the long side LED */
			led_on(LONG_SIDE_LED_PORT, LONG_SIDE_LED_PIN);

			/* Set Motor Directions */ /* todo: verify on hw */
			dcm_set_direction(DCM_0, DCM_CW);
			dcm_set_direction(DCM_1, DCM_CW);

			/* Set Motor Speed */
			dcm_speed(APP_MOTOR_SPEED_50);

			/* Start the Car */
			dcm_start();
			delay_start(APP_LONG_SIDE_TIME, TIME_IN_MS);

			/* Turn off the long side LED */
			led_off(LONG_SIDE_LED_PORT, LONG_SIDE_LED_PIN);

			/* Set the next state */
			gl_en_app_state_next_side = APP_STATE_SHORT_SIDE;
		}
		else if (APP_STATE_SHORT_SIDE == gl_en_current_app_state)
		{
			/* Update the Application State */
			gl_en_current_app_state = APP_STATE_ROTATE;

			/* Turn on the short side LED */
			led_on(SHORT_SIDE_LED_PORT, SHORT_SIDE_LED_PIN);

			/* Set Motor Directions */ /* todo: verify on hw */
			dcm_set_direction(DCM_0, DCM_CW);
			dcm_set_direction(DCM_1, DCM_CW);

			/* Set Motor Speed */
			dcm_speed(APP_MOTOR_SPEED_30);

			/* Move for two seconds */
			dcm_start();
			delay_start(APP_SHORT_SIDE_TIME, TIME_IN_MS);

			/* Turn off the short side LED */
			led_off(SHORT_SIDE_LED_PORT, SHORT_SIDE_LED_PIN);

			/* Update the next side */
			gl_en_app_state_next_side = APP_STATE_LONG_SIDE;
		}
		else if (APP_STATE_ROTATE == gl_en_current_app_state)
		{
			/* Update the Application State */
			gl_en_current_app_state = gl_en_app_state_next_side;

			/* Turn on the rotation LED */
			led_on(ROTATING_LED_PORT, ROTATING_LED_PIN);

			/* Stop for 0.5 seconds */
			dcm_stop();
			delay_start(APP_STOP_TIME, TIME_IN_MS);

			/* Set Motor Directions */
			dcm_set_direction(DCM_0, DCM_CW);
			dcm_set_direction(DCM_1, DCM_ACW);

			/* Rotate 90 degrees */
			dcm_start();
			delay_start(APP_ROTATION_TIME, TIME_IN_MS);

			/* Stop for 0.5 seconds */
			dcm_stop();
			delay_start(APP_STOP_TIME, TIME_IN_MS);

			/* Turn off the rotation LED */
			led_off(ROTATING_LED_PORT, ROTATING_LED_PIN);
		}
		else
		{
			gl_en_current_app_state = APP_STATE_STOPPED;
		}
   
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

    }
} // line 292








static void app_stop_btn_callback()
{
	/* Stop any ongoing delay */
	delay_shutdown(TRUE);
	
	/* Update the Application State */
	gl_en_current_app_state = APP_STATE_STOPPED;    

} // line 500