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

#define START_BTN_PORT		BTN_PORT_F // Port F
#define START_BTN_PIN		BTN_PIN_4

#define STOP_BTN_PORT		BTN_PORT_F // Port F
#define STOP_BTN_PIN		BTN_PIN_0














en_app_status_t app_init() // todo-hossam
{
    en_app_status_t en_app_status_retval = APP_OK;

    // global vars





    // init DCM
//    dcm_init(); // todo-hossam










    // init LED x4
    led_init(LONG_SIDE_LED_PORT, LONG_SIDE_LED_PIN);
    led_init(SHORT_SIDE_LED_PORT, SHORT_SIDE_LED_PIN);
    led_init(ROTATING_LED_PORT, ROTATING_LED_PIN);
    led_init(STOPPED_LED_PORT, STOPPED_LED_PIN);










    // init init start btn
    //btn_init(START_BTN_PORT, START_BTN_PIN); // todo-hossam








    // init init stop btn (interrupt)
    //btn_init(STOP_BTN_PORT, STOP_BTN_PIN); // todo-hossam







    return en_app_status_retval;
} // line 116






















void app_start() // todo-alaa
{
	//en_btn_state_t en_lo_btn_state = BTN_NOT_PRESSED;

	while (TRUE)
	{
		if (APP_STATE_IDLE == gl_en_current_app_state)
		{
			// check start btn
			//en_lo_btn_state = btn_read();

			if (/* BTN_PRESSED == en_lo_btn_state */ TRUE)
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

			/* todo: Turn on the stop LED */

			/* Stop the Car */
			//dcm_stop();
		}
		else if (APP_STATE_LONG_SIDE == gl_en_current_app_state)
		{
			/* Update the Application State */
			gl_en_current_app_state = APP_STATE_ROTATE;

			/* todo: Turn off the stop LED */


			/* todo: Turn on the long side LED */


			/* Set Motor Directions */ /* todo: verify on hw */
			//dcm_setDirection(DCM_0, DCM_CW);
			//dcm_setDirection(DCM_1, DCM_CW);

			/* Set Motor Speed */
			//dcm_speed(APP_MOTOR_SPEED_50);

			/* Start the Car */
			//dcm_start();
			delay_start(APP_LONG_SIDE_TIME, TIME_IN_MS);

			/* todo: Turn off the long side LED */


			/* Set the next state */
			gl_en_app_state_next_side = APP_STATE_SHORT_SIDE;
		}
		else if (APP_STATE_SHORT_SIDE == gl_en_current_app_state)
		{
			/* Update the Application State */
			gl_en_current_app_state = APP_STATE_ROTATE;

			/* todo: Turn off the stop LED */

			
			/* todo: Turn on the short side LED */
			

			/* Set Motor Directions */ /* todo: verify on hw */
			//dcm_setDirection(DCM_0, DCM_CW);
			//dcm_setDirection(DCM_1, DCM_CW);

			/* Set Motor Speed */
			//dcm_speed(APP_MOTOR_SPEED_30);

			/* Move for two seconds */
			//dcm_start();
			delay_start(APP_SHORT_SIDE_TIME, TIME_IN_MS);

			/* todo: Turn off the short side LED */


			/* Update the next side */
			gl_en_app_state_next_side = APP_STATE_LONG_SIDE;
		}
		else if (APP_STATE_ROTATE == gl_en_current_app_state)
		{
			/* Update the Application State */
			gl_en_current_app_state = gl_en_app_state_next_side;

			/* todo: Turn off the stop LED */


			/* todo: Turn on the rotation LED */


			/* Stop for 0.5 seconds */
			//dcm_stop();
			delay_start(APP_STOP_TIME, TIME_IN_MS);

			/* Set Motor Directions */
			//dcm_setDirection(DCM_0, DCM_CW);
			//dcm_setDirection(DCM_1, DCM_ACW);

			/* Rotate 90 degrees */


			//dcm_start();
			delay_start(APP_ROTATION_TIME, TIME_IN_MS);

			/* Stop for 0.5 seconds */
			//dcm_stop();
			delay_start(APP_STOP_TIME, TIME_IN_MS);

			/* todo: Turn off the rotation LED */

		}
		else
		{
			gl_en_current_app_state = APP_STATE_STOPPED;
		}
   
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

    }
} // line 292








static void app_stop_btn_callback() // todo-alaa
{
	/* Stop any on-going delay */
	delay_shutdown(TRUE);
	
	/* Update the Application State */
	gl_en_current_app_state = APP_STATE_STOPPED;
	

































































} // line 500