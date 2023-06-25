
#include "btn_interface.h"
#include "gpio_interface.h"

void (*ptr_func_button_callback)(void) = NULL_PTR;

st_gpio_cfg_t gl_str_button_config ;


/**
 *	@brief			This function is used for initalizing button
 *	@param [in]		ptr_func						:	pointer to callback
 *	@return			ERROR_OK					    :	In case of successeion
 *  @return			PASSING_NULL_PTR				:	In case of passing null pointer
 *	@return			BUTTON_NOK        			    :	In case of wrong pin index
 */
enu_error_status_t_ button_init(void(*ptr_func)(void))
{

	enu_error_status_t_ enu_error = ERROR_OK;
	
	uint8_t_ uint8_pin_num = 0, uint8_port_num = 0;
	uint8_pin_num = GPIO_PIN_4 % 10;
	uint8_port_num = GPIO_PORT_F / 10;

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
		{ // button
			gl_str_button_config.port = GPIO_PORT_F;
			gl_str_button_config.pin = GPIO_PIN_4;

			gl_str_button_config.pin_cfg = INPUT;
			gl_str_button_config.current = PIN_CURRENT_2MA;
//			gl_str_button_config.enu_pin_internal_attach = GPIO_PULLUP;
			gpio_pin_init (&gl_str_button_config);
//			gpio_pin_init(&gl_str_button_config);
//			gpio_pin_enable_notification(SW_1);
      gpio_enableInt(GPIO_PORT_F,GPIO_PIN_4);
			if (NULL_PTR == ptr_func)
			{
				enu_error = PASSING_NULL_PTR;
			}
			else
			{
				gpio_setIntCallback(GPIO_PORT_F,GPIO_PIN_4, ptr_func);
				ptr_func_button_callback = ptr_func;
			}
		}
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

