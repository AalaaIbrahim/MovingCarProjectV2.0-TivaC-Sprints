/**
 * @file    :   app_interface.h
 * @author  :   Alaa Hisham & Hossam Elwahsh
 * @brief   :   Header File contains all APP functions' prototypes, typedefs and pre-configurations
 * @version :   0.1
 * @date    :   2023-06-21
 *
 * @copyright Copyright (c) 2023
 */
#ifndef APP_INTERFACE_H_
#define APP_INTERFACE_H_

typedef enum{
    APP_OK      = 0 ,
    APP_ERROR       ,
    APP_TOTAL
}en_app_status_t;

en_app_status_t app_init();

void app_start();

#endif
