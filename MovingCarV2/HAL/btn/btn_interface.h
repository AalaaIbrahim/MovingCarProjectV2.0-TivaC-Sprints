#ifndef BTN_INTERFACE_H_
#define BTN_INTERFACE_H_
#include "std.h"
#include "bit_math.h"
#include "gpio_interface.h"


typedef enum
{
	BUTTON_RELEASED = 0,
	BUTTON_PRESSED = 1
} en_btn_state_t;


typedef enum {
	ERROR_OK = 0,
	PASSING_NULL_PTR,
	BUTTON_NOK
}enu_error_status_t_;

/**
 *
 * @param en_a_gpio_port
 * @param en_a_gpio_pin
 * @return
 */
enu_error_status_t_ button_init(en_gpio_port_t en_a_gpio_port, en_gpio_pin_t en_a_gpio_pin);

/**
 *
 * @param en_a_gpio_port
 * @param en_a_gpio_pin
 * @param ptr_en_a_button_state
 * @return
 */
enu_error_status_t_ button_get_state(en_gpio_port_t en_a_gpio_port, en_gpio_pin_t en_a_gpio_pin, en_btn_state_t *ptr_en_a_button_state);
#endif 
