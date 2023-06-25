/**
 * @file    :   app_private.h
 * @author  :   Alaa Hisham & Hossam Elwahsh
 * @brief   :   Header File contains all app private functions' prototypes, typedefs and pre-configurations
 * @version :   0.1
 * @date    :   2023-06-21
 *
 * @copyright Copyright (c) 2023
 */
#ifndef APP_PRIVATE_H_
#define APP_PRIVATE_H_

/* Private includes line 13 */
#include "std.h"
#include "led_interface.h"
#include "delay_interface.h"



















/* Typedefs line 36 */
typedef enum{
		APP_STATE_IDLE        = 0 ,
    APP_STATE_START 					,
		APP_STATE_STOPPED     		,
    APP_STATE_LONG_SIDE       ,
    APP_STATE_ROTATE          ,
    APP_STATE_SHORT_SIDE      ,
    APP_STATE_TOTAL
}en_app_state_t;






















/* Alaa's MACROS */
#define APP_MOTOR_SPEED_30		30
#define APP_MOTOR_SPEED_50		50

#define APP_START_TIME				1000
#define APP_ROTATION_TIME			500
#define APP_STOP_TIME					500
#define APP_SHORT_SIDE_TIME		2000
#define APP_LONG_SIDE_TIME		3000


















/* Hossam's MACROS */




































static void app_stop_btn_callback();

#endif
