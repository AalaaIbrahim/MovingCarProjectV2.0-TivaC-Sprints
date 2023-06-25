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

/* Private includes */
#include "std.h"




















/* Typedefs */
typedef enum{
    APP_STATE_STOPPED     = 0 ,
    APP_STATE_LONG_SIDE       ,
    APP_STATE_ROTATE          ,
    APP_STATE_SHORT_SIDE      ,
    APP_STATE_TOTAL
}en_app_state_t;






















/* Alaa's MACROS */


























/* Hossam's MACROS */


































static void app_switch_state();

static void app_stop_btn_callback();

#endif
