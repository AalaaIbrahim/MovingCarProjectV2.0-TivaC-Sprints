/**
 *  FILE DESCRIPTION
 *-------------------------------------------------------------------------------------------------------------------
 *	@Date:  				2:38 PM Sunday, May 14, 2023
 *	@File:  				dcm_interface.h         
 *	@Module:  			DC Motor
 *	@Author:				Ahmed Hesham
 *  @Description:  	Interfacing file for DC Motor module     
 *  
 */
#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_

/**----------------------------------------------------------
 * INCLUDES
 *----------------------------------------------------------*/
#include "std.h"


/**----------------------------------------------------------
 *  GLOBAL DATA TYPES AND STRUCTURES
 *----------------------------------------------------------*/
/*-----------------------_ERROR_TYPES_-----------------------*/
typedef enum
{
	DCM_OK = 0,
	DCM_WRONG_DCM_NUMBER,
	DCM_WRONG_DIRECTION,
	DCM_NOK
}en_dcm_error_t_;

/*-----------------------_DCM_DIRECTOINS_-----------------------*/
typedef enum 
{
	DCM_CW = 0,
	DCM_ACW
}en_dcm_direction_t_;

/*-----------------------_DCM_PORTS_-----------------------*/
typedef enum
{
	DCM_PORT_A,
	DCM_PORT_B,
	DCM_PORT_C,
	DCM_PORT_D,
	DCM_PORT_E,
	DCM_PORT_F,
	DCM_PORT_TOTAL
}en_dcm_port_t_;

/*-----------------------_DCM_PINS_-----------------------*/
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
}en_dcm_pin_t_;
  
/*-------------------------_LINKING_CONFIGURATION_STRUCTURE_DATA_TYPE_-------------------------*/	
typedef struct
{
	uint8_t_ 				uint8_dcm_number;
	en_dcm_port_t_			en_dcm_port_number_0;
	en_dcm_pin_t_			en_dcm_pin_number_0;
	en_dcm_port_t_			en_dcm_port_number_1;
	en_dcm_pin_t_			en_dcm_pin_number_1;
}str_dcm_config_t_;

/**----------------------------------------------------------
 *  GLOBAL FUNCTION PROTOTYPES
 *----------------------------------------------------------*/

/**
 *	@brief				Initializes DCM module
 *	@param [in]		none	
 *	@param [out]	none	
 *	@return				DCM_OK								:	In case of success
 *	@return				DCM_NOK								:	In case of failure
 */
en_dcm_error_t_ dcm_init(void);


/**
 *	@brief				Sets Directions for the a specific DCM
 *	@param [in]		uint8_dcm_index				:	motor's number
 *	@param [in]		en_direction					:	motor's direction
 *	@param [out]	none	
 *	@return				DCM_OK								:	In case of success
 *	@return				DCM_WRONG_DIRECTION		:	In case of sending wrong direction
 * 	@return				DCM_WRONG_DCM_NUMBER	:	In case of sending wrong DCM number
 *	@return				DCM_NOK								:	In case of failure
 */
 en_dcm_error_t_ dcm_set_direction(uint8_t_ uint8_dcm_index, en_dcm_direction_t_ en_direction);


/**
 *	@brief				Sets speed for DCMs
 *	@param [in]		uint8_speed						:	motors' speed
 *	@param [out]	none		
 *	@return				DCM_OK								:	In case of success
 *	@return				DCM_NOK								:	In case of failure
 */
 en_dcm_error_t_ dcm_speed	(uint8_t_ uint8_speed);


/**
 *	@brief				Starts DCMs to rotate
 *	@param [in]		none
 *	@param [out]	none	
 *	@return				DCM_OK								:	In case of success
 *	@return				DCM_NOK								:	In case of failure
 */
 en_dcm_error_t_ dcm_start	(void);


/**
 *	@brief				Stops DCMs from rotating
 *	@param [in]		none
 *	@param [out]	none	
 *	@return				DCM_OK								:	In case of success
 *	@return				DCM_NOK								:	In case of failure
 */
en_dcm_error_t_ dcm_stop (void);


#endif /* DCM_INTERFACE_H_ */
/**----------------------------------------------------------
 *  END OF FILE: dcm_interface.h
 *----------------------------------------------------------*/
