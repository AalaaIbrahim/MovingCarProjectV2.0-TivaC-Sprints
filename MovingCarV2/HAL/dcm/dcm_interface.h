/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *		   @Date:  	2:38 PM Sunday, May 14, 2023
 *		   @File:  	dcm_interface.h         
 *		 @Module:  	DC Motor
 *		 @Author:	Ahmed Hesham
 *  @Description:  	Interfacing file for DC Motor module     
 *  
 *********************************************************************************************************************/
#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "std.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/***************************************_ERROR_TYPES_***************************************/
typedef enum
{
	DCM_OK = 0,
	DCM_WRONG_DCM_NUMBER,
	DCM_WRONG_DIRECTION,
	DCM_NOK
}enu_dcm_error_t_;



/***************************************_DCM_DIRECTOINS_***************************************/
typedef enum 
{
	DCM_CW = 0,
	DCM_ACW
}enu_dcm_direction_t_;



typedef enum
{
	DCM_PORT_A,
	DCM_PORT_B,
	DCM_PORT_C,
	DCM_PORT_D,
	DCM_PORT_E,
	DCM_PORT_F,
	DCM_PORT_TOTAL
}enu_dcm_port_t_;

typedef enum
{
	DCM_PIN_0 = 0	,
	DCM_PIN_1		,
	DCM_PIN_2		,
	DCM_PIN_3		,
	DCM_PIN_4		,
	DCM_PIN_5		,
	DCM_PIN_6		,
	DCM_PIN_7		,
	DCM_PIN_TOTAL
}enu_dcm_pin_t_;

/**************************_LINKING_CONFIGURATION_STRUCTURE_DATA_TYPE_**************************/	
typedef struct
{
	uint8_t_ 						uint8_dcm_number;
	enu_dcm_port_t_			enu_dcm_port_number_0;
	enu_dcm_pin_t_			enu_dcm_pin_number_0;
	enu_dcm_port_t_			enu_dcm_port_number_1;
	enu_dcm_pin_t_			enu_dcm_pin_number_1;
}str_dcm_config_t_;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**----------------------------------------------------------
* @Syntax          : en_DCM_error_t DCM_init (void)
* @Description     : Initializes DCM module
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : None
* @Parameters (out): None
* @Return value:   : en_DCM_error_t			DCM_OK = 0
*											DCM_NOK = 1
*******************************************************************************/
enu_dcm_error_t_ dcm_init				(void);

/******************************************************************************
* @Syntax          : en_DCM_error_t DCM_setDirection	
*					 (en_DCM_number_t en_a_dcmNumber, en_DCM_direction_t en_a_direction)
* @Description     : Sets Directions for the a specific DCM
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : en_DCM_number_t		en_a_dcmNumber
*					 en_DCM_direction_t		en_a_direction
* @Parameters (out): None
* @Return value:   : en_DCM_error_t			DCM_OK = 0
*											DCM_NOK = 1
*******************************************************************************/
enu_dcm_error_t_ dcm_set_direction(uint8_t_ uint8_dcm_index, enu_dcm_direction_t_ enu_direction);

/******************************************************************************
* @Syntax          : en_DCM_error_t DCM_speed (u8 u8_a_speed)
* @Description     : Sets speed for DCMs
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : u8						u8_a_speed
* @Parameters (out): None
* @Return value:   : en_DCM_error_t			DCM_OK = 0
*											DCM_NOK = 1
*******************************************************************************/
enu_dcm_error_t_ dcm_speed	(uint8_t_ uint8_speed);

/******************************************************************************
* @Syntax          : en_DCM_error_t DCM_start (void)
* @Description     : Starts DCMs to rotate
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : None
* @Parameters (out): None
* @Return value:   : en_DCM_error_t			DCM_OK = 0
*											DCM_NOK = 1
*******************************************************************************/
enu_dcm_error_t_ dcm_start			(void);

/******************************************************************************
* @Syntax          : en_DCM_error_t DCM_stop (void)
* @Description     : Stops DCMs from rotating
* @Sync\Async      : Synchronous
* @Reentrancy      : Reentrant
* @Parameters (in) : None
* @Parameters (out): None
* @Return value:   : en_DCM_error_t			DCM_OK = 0
*											DCM_NOK = 1
*******************************************************************************/
enu_dcm_error_t_ dcm_stop				(void);


#endif /* DCM_INTERFACE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: dcm_interface.h
 *********************************************************************************************************************/
