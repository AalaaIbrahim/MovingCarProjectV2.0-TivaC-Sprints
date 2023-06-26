#include "btn_interface.h"
#include "gpio_interface.h"

void (*ptr_func_button_callback)(void) = NULL_PTR;

/**
 * Function to initialize a push button on the given pin
 * @param en_a_gpio_port : The port the button is connected on
 * @param en_a_gpio_pin  : The pin the button is connected to
 * @return ERROR_OK 		 : If the initialization is successful
 * 				 BUTTON_NOK		 : If any of the arguments is invalid
 */
enu_error_status_t_ button_init(en_gpio_port_t en_a_gpio_port, en_gpio_pin_t en_a_gpio_pin)
{

	enu_error_status_t_ enu_error = ERROR_OK;
	st_gpio_cfg_t st_lo_btn_pin_cfg;
	
	st_lo_btn_pin_cfg.port = en_a_gpio_port;
	st_lo_btn_pin_cfg.pin  = en_a_gpio_pin;
	st_lo_btn_pin_cfg.pin_cfg = INPUT_PULL_DOWN;
	
	enu_error = (enu_error_status_t_)gpio_pin_init(&st_lo_btn_pin_cfg);
	
	if(ERROR_OK != enu_error)
	{
		enu_error = BUTTON_NOK;
	}
	else
	{
		/* Do Nothing */
	}
	
	return enu_error;
}



































































/**
 *	@brief			This function is used for getting button  state
 *	@param [in]		buttonpin				        	:	Pin index used
 *	@param [out]	ptr_uint8_button_state				:	returns button state
 *	@return			ERROR_OK					    :	In case of successeion
 *	@return			BUTTON_NOK        			    :	In case of wrong pin index
 */
enu_error_status_t_ button_get_state(uint8_t_ uint8_button_port,uint8_t_ uint8_button_pin, uint8_t_ *uint8_button_state)
{
	enu_error_status_t_ enu_error = ERROR_OK;
	en_gpio_pin_level_t enu_test_level = LOW;
	en_gpio_pin_cfg_t enu_button_attach = INPUT_PULL_UP;
	uint8_t_ uint8_pin_state;

	uint8_t_ uint8_pin_num = 0, uint8_port_num = 0;
	uint8_pin_num = uint8_button_pin % 10;
	uint8_port_num = uint8_button_port / 10;

	if (uint8_port_num > 5 || uint8_pin_num > 7)
	{
		enu_error = BUTTON_NOK;	
	}
	else
	{
		if (((5 == uint8_port_num) && (uint8_pin_num > 4)) || ((4 == uint8_port_num) && (uint8_pin_num > 5)))
		{
			enu_error = BUTTON_NOK;
		}
	
		else
		{ 
			if (enu_button_attach == INPUT_PULL_UP)
			{
				enu_test_level = LOW;
			}
			else if (enu_button_attach == INPUT_PULL_DOWN)
			{
				enu_test_level = HIGH;
			}
			else
			{
				enu_error = BUTTON_NOK;
			}
			gpio_getPinVal (uint8_button_port, uint8_button_pin, &uint8_button_state);
			if (uint8_pin_state == enu_test_level)
			{
				*uint8_button_state = BUTTON_PRESSED;
			}
			else
			{
				*uint8_button_state = BUTTON_RELEASED;
			}
		}
//				/* Random short delay */
//				for(uint32_t_ uint32_looping_variable = 0; uint32_looping_variable < 1000; uint32_looping_variable++);
//				gpio_pin_read(uint8_button_pin, uint8_button_state);
//				if (*uint8_button_state == enu_test_level)
//				{
//					while (*uint8_button_state == enu_test_level)
//					{
//						gpio_pin_read(uint8_button_pin, uint8_button_state);
//					}
//					ptr_func_button_callback();
//				}
//				else
//				{
//					/*DO NOTHING*/
//				}
//			}
//			else
//			{
//				/*DO NOTHING*/
//			}
//		}
	}
	return enu_error;
}

