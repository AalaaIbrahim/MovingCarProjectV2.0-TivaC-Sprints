#ifndef BTN_INTERFACE_H_
#define BTN_INTERFACE_H_
#include "std.h"
#include "bit_math.h"
typedef enum
{
	BUTTON_RELEASED = 0,
	BUTTON_PRESSED = 1
} Button_State;
typedef enum {
	ERROR_OK = 0,
	GPIO_INVALID_PIN_INDEX,
	GPIO_INVALID_PIN_MODE,
	GPIO_INVALID_PIN_DIRECTION,
	GPIO_INVALID_OP_CURRENT,
	GPIO_INVALID_INTERNAL_ATTACH, 
	GPIO_INVALID_PIN_LEVEL,
	PASSING_NULL_PTR,
	LED_NOK,
	BUTTON_NOK
	
}enu_error_status_t_;

/**
 *	@brief			This function is used for initalizing button 
 *	@param [in]		ptr_func						:	pointer to callback
 *	@return			ERROR_OK					    :	In case of successeion
 *  @return			PASSING_NULL_PTR				:	In case of passing null pointer
 *	@return			BUTTON_NOK        			    :	In case of wrong pin index
 */
enu_error_status_t_ button_init(void(*ptr_func)(void));

/**
 *	@brief			This function is used for getting button  state
 *	@param [in]		buttonpin				        	:	Pin index used
 *	@param [out]	ptr_uint8_button_state				:	returns button state 
 *	@return			ERROR_OK					    :	In case of successeion
 *	@return			BUTTON_NOK        			    :	In case of wrong pin index
 */
enu_error_status_t_ button_get_state(uint8_t_ uint8_button_port,uint8_t_ uint8_button_pin, uint8_t_ *uint8_button_state);
#endif 
