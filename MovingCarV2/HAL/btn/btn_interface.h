#ifndef BTN_INTERFACE_H_
#define BTN_INTERFACE_H_
#include "std.h"
#include "bit_math.h"

#define BTN_DEBOUNCE_MS_TIME 200

typedef void (* ptr_callback_fun_t)(void);

/* Button Pins */
typedef enum{
    BTN_PIN_0	=	0	,
    BTN_PIN_1			,
    BTN_PIN_2			,
    BTN_PIN_3			,
    BTN_PIN_4			,
    BTN_PIN_5			,
    BTN_PIN_6			,
    BTN_PIN_7			,
    BTN_PIN_TOTAL
}en_btn_pin_t_;

/* Button Ports */
typedef enum
{
    BTN_PORT_A	=	0	,
    BTN_PORT_B,
    BTN_PORT_C,
    BTN_PORT_D,
    BTN_PORT_E,
    BTN_PORT_F,
    BTN_PORT_TOTAL
}en_btn_port_t_;

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
 * Function to initialize a push button on the given pin
 * @param en_a_gpio_port : The port the button is connected on
 * @param en_a_gpio_pin  : The pin the button is connected to
 * @return ERROR_OK 		 : If the initialization is successful
 * 				 BUTTON_NOK		 : If any of the arguments is invalid
 */
enu_error_status_t_ button_init(en_btn_port_t_ en_a_gpio_port, en_btn_pin_t_ en_a_gpio_pin, boolean bool_a_int_enabled);

/**
 *
 * @param en_a_gpio_port
 * @param en_a_gpio_pin
 * @param ptr_en_a_button_state
 * @return
 */
enu_error_status_t_ button_get_state(en_btn_port_t_ en_a_gpio_port, en_btn_pin_t_ en_a_gpio_pin, en_btn_state_t *ptr_en_a_button_state);

enu_error_status_t_ button_set_callback(en_btn_port_t_ en_a_gpio_port, en_btn_pin_t_ en_a_gpio_pin, ptr_callback_fun_t ptr_a_callback_fun);

#endif 
