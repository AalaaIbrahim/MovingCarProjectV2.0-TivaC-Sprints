#include "btn_interface.h"
#include "gpio_interface.h"
#include "delay_interface.h"

/**
 * Function to initialize a push button on the given pin
 * @param en_a_gpio_port : The port the button is connected on
 * @param en_a_gpio_pin  : The pin the button is connected to
 * @return ERROR_OK 		 : If the initialization is successful
 * 				 BUTTON_NOK		 : If any of the arguments is invalid
 */
en_error_status_t_ button_init(en_btn_port_t_ en_a_gpio_port, en_btn_pin_t_ en_a_gpio_pin, boolean bool_a_int_enabled)
{

	en_error_status_t_ en_error = ERROR_OK;
	st_gpio_cfg_t st_lo_btn_pin_cfg;
	
	st_lo_btn_pin_cfg.port = (en_gpio_port_t)en_a_gpio_port;
	st_lo_btn_pin_cfg.pin  = (en_gpio_pin_t)en_a_gpio_pin;
	st_lo_btn_pin_cfg.pin_cfg = INPUT_PULL_DOWN;

	en_error = (en_error_status_t_)gpio_pin_init(&st_lo_btn_pin_cfg);
	
	if(ERROR_OK != en_error)
	{
		en_error = BUTTON_NOK;
	}
	else
	{
		/* Do Nothing */
	}
    if(bool_a_int_enabled == TRUE)
    {

        if(GPIO_OK != gpio_enableInt((en_gpio_port_t)en_a_gpio_port, (en_gpio_pin_t)en_a_gpio_pin))
        {
            en_error = BUTTON_NOK;
        }

    }
	return en_error;
}








/**
 *
 * @param en_a_gpio_port
 * @param en_a_gpio_pin
 * @param ptr_en_a_button_state
 * @return
 */
en_error_status_t_ button_get_state(en_btn_port_t_ en_a_gpio_port, en_btn_pin_t_ en_a_gpio_pin, en_btn_state_t *ptr_en_a_button_state)
{
	en_error_status_t_ en_error_status_retval = ERROR_OK;
    en_gpio_pin_level_t en_l_gpio_pin_level = LOW;


    if(GPIO_OK == gpio_getPinVal ((en_gpio_port_t)en_a_gpio_port, (en_gpio_pin_t)en_a_gpio_pin, &en_l_gpio_pin_level))
    {
        // debounce
        if(HIGH == en_l_gpio_pin_level)
        {
            if(DELAY_ERROR == delay_start(BTN_DEBOUNCE_MS_TIME, TIME_IN_MS))
            {
                en_error_status_retval = BUTTON_NOK;
            }

            *ptr_en_a_button_state = BUTTON_PRESSED;
        }
        else
        {
            *ptr_en_a_button_state = BUTTON_RELEASED;
        }
    }
    else
    {
        en_error_status_retval = BUTTON_NOK;
    }

	return en_error_status_retval;
}

en_error_status_t_ button_set_callback(en_btn_port_t_ en_a_gpio_port, en_btn_pin_t_ en_a_gpio_pin, ptr_callback_fun_t ptr_a_callback_fun)
{
    en_error_status_t_ en_l_error_status = ERROR_OK;

    if(GPIO_OK != gpio_setIntCallback((en_gpio_port_t)en_a_gpio_port, (en_gpio_pin_t)en_a_gpio_pin, ptr_a_callback_fun))
    {
            en_l_error_status = BUTTON_NOK;
    }
    else
    {
        /* Do Nothing */
    }

    return en_l_error_status;
}