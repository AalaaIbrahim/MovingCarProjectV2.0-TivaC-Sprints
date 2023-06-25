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

int main(void)
{
    if(APP_OK == app_init())
    {
        app_start();
    }
    else
    {
        while(1)
        {

        }
    }

	return 0;
}
