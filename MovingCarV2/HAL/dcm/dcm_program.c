/**
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *
 *  @Date:  				5:14 PM Monday, May 15, 2023
 *	@File:  				dcm_program.c         
 *	@Module:  			DC Motor
 *	@Author:				Ahmed Hesham
 *  @Description:  	Linking configuration file for DC Motor module     
 *  
 */

/**----------------------------------------------------------
 *  INCLUDES
 *----------------------------------------------------------*/
#include "dcm_interface.h"
#include "dcm_cfg.h"
#include "gpio_interface.h"
#include "pwm_interface.h"
/**----------------------------------------------------------
 *  GLOBAL DATA
 *----------------------------------------------------------*/
extern const str_dcm_config_t_ str_dcm_config [NUMBER_OF_DCMS_USED];
 
 /**----------------------------------------------------------
 *  GLOBAL FUNCTION IMPLEMENTATION
 *----------------------------------------------------------*/
/**
 *	@brief				Initializes DCM module
 *	@param [in]		none	
 *	@param [out]	none	
 *	@return				DCM_OK						:	In case of success
 *	@return				DCM_NOK						:	In case of failure
 */
 enu_dcm_error_t_ dcm_init (void)
{
	enu_dcm_error_t_ enu_return_value = DCM_OK;
	
	st_gpio_cfg_t str_pins_used;
	
	str_pins_used.current = PIN_CURRENT_2MA;
	str_pins_used.pin_cfg = OUTPUT;
	for (uint8_t_ counter = 0; counter < NUMBER_OF_DCMS_USED; counter++)
	{
		str_pins_used.port = str_dcm_config[counter].enu_dcm_port_number_0;
		str_pins_used.pin = str_dcm_config[counter].enu_dcm_pin_number_0;
			
		if (GPIO_OK != gpio_pin_init(&str_pins_used))
		{
			enu_return_value = DCM_NOK;
			break;
		}
		else
		{
			str_pins_used.port = str_dcm_config[counter].enu_dcm_port_number_1;
			str_pins_used.pin = str_dcm_config[counter].enu_dcm_pin_number_1;
			if (GPIO_OK != gpio_pin_init(&str_pins_used))
			{
				enu_return_value = DCM_NOK;
				break;
			}
			else
			{
				
			}
		}
	}
	
	if (DCM_OK == enu_return_value)
	{
		if (PWM_OK != pwm_init())
		{
			enu_return_value = DCM_NOK;
		}
		else
		{
			/*enu_return_value = DCM_OK*/
		}
	}
	else
	{
		/*DCM_NOK*/
	}
	return enu_return_value;
	
}

/**
 *	@brief				Sets Directions for the a specific DCM
 *	@param [in]		uint8_dcm_index				:	motor's number
 *	@param [in]		enu_direction					:	motor's direction
 *	@param [out]	none	
 *	@return				DCM_OK								:	In case of success
 *	@return				DCM_WRONG_DIRECTION		:	In case of sending wrong direction
 * 	@return				DCM_WRONG_DCM_NUMBER	:	In case of sending wrong DCM number
 *	@return				DCM_NOK								:	In case of failure
 */
 enu_dcm_error_t_ dcm_set_direction(uint8_t_ uint8_dcm_index, enu_dcm_direction_t_ enu_direction)
{
	enu_dcm_error_t_ enu_return_value = DCM_OK;
	
	for (uint8_t_ counter = 0; counter < NUMBER_OF_DCMS_USED; counter++)
	{
		enu_return_value = DCM_WRONG_DCM_NUMBER;
		if (uint8_dcm_index == str_dcm_config[counter].uint8_dcm_number)
		{
			enu_return_value = DCM_OK;
			if(DCM_CW == enu_direction)
			{
				if (GPIO_OK != gpio_setPinVal(str_dcm_config[counter].enu_dcm_port_number_0, str_dcm_config[counter].enu_dcm_pin_number_0,HIGH))
				{
					enu_return_value = DCM_NOK;
				}
				else
				{
					/*enu_return_value = DCM_OK*/
					if (GPIO_OK != gpio_setPinVal(str_dcm_config[counter].enu_dcm_port_number_1, str_dcm_config[counter].enu_dcm_pin_number_1,LOW))
					{
						enu_return_value = DCM_NOK;
					}
					else
					{
						/*enu_return_value = DCM_OK*/
					}
				}
			}
			else if (DCM_ACW == enu_direction)
			{
				if (GPIO_OK != gpio_setPinVal(str_dcm_config[counter].enu_dcm_port_number_0, str_dcm_config[counter].enu_dcm_pin_number_0,LOW))
				{
					enu_return_value = DCM_NOK;
				}
				else
				{
					/*enu_return_value = DCM_OK*/
					if (GPIO_OK != gpio_setPinVal(str_dcm_config[counter].enu_dcm_port_number_1, str_dcm_config[counter].enu_dcm_pin_number_1,HIGH))
					{
						enu_return_value = DCM_NOK;
					}
					else
					{
						/*enu_return_value = DCM_OK*/
					}
				}
			}
			else
			{
				enu_return_value = DCM_WRONG_DIRECTION;
			}
			break;
		}
	}
	return enu_return_value;
}


/**
 *	@brief				Sets speed for DCMs
 *	@param [in]		uint8_speed					:	motors' speed
 *	@param [out]	none	
 *	@return				DCM_OK							:	In case of success
 *	@return				DCM_NOK							:	In case of failure
 */
enu_dcm_error_t_ dcm_speed	(uint8_t_ uint8_speed)
{
	enu_dcm_error_t_ enu_return_value = DCM_OK;
	
	if (uint8_speed <= 100)
	{
		if(DCM_OK != pwm_adjust_signal(PWM_CHANNEL_1, uint8_speed, 10))
		{
			enu_return_value = DCM_NOK;
		}
		else
		{
			if(DCM_OK != pwm_adjust_signal(PWM_CHANNEL_2, uint8_speed, 10))
			{
				enu_return_value = DCM_NOK;
			}
			else
			{
				/*DCM_OK*/
			}
		}
	}
	else
	{
		enu_return_value = DCM_NOK;
	}
	
	return enu_return_value;
}


/**
 *	@brief				Starts DCMs to rotate
 *	@param [in]		none
 *	@param [out]	none	
 *	@return				DCM_OK							:	In case of success
 *	@return				DCM_NOK							:	In case of failure
 */
enu_dcm_error_t_ dcm_start (void)
{
	enu_dcm_error_t_ enu_return_value = DCM_OK;
	
	if (PWM_OK != pwm_start(PWM_CHANNEL_1))
	{
		enu_return_value = DCM_NOK;
	}
	else
	{
		if (PWM_OK != pwm_start(PWM_CHANNEL_2))
		{
			enu_return_value = DCM_NOK;
		}
		else
		{
			/*DCM_OK*/
		}
	}
	return enu_return_value;
}


/**
 *	@brief				Stops DCMs from rotating
 *	@param [in]		none
 *	@param [out]	none	
 *	@return				DCM_OK							:	In case of success
 *	@return				DCM_NOK							:	In case of failure
 */
enu_dcm_error_t_ dcm_stop	(void)
{
	enu_dcm_error_t_ enu_return_value = DCM_OK;
	
	if (pwm_stop(PWM_CHANNEL_1))
	{
		enu_return_value = DCM_NOK;
	}
	else
	{
		if (pwm_stop(PWM_CHANNEL_1))
		{
			enu_return_value = DCM_NOK;
		}
		else
		{
			/*DCM_OK*/
		}
	}
	
	return enu_return_value;
}
/**----------------------------------------------------------
 *  END OF FILE: dcm_program.c
 *----------------------------------------------------------*/
