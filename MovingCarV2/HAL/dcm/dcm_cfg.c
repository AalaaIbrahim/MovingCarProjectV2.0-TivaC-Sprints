/**
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *
 *  @Date:  				2:47 PM Sunday, May 14, 2023
 *	@File:  				dcm_cfg.c         
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
/**----------------------------------------------------------
 *  GLOBAL DATA
 *----------------------------------------------------------*/
 
 const str_dcm_config_t_ str_dcm_config [NUMBER_OF_DCMS_USED] = 
{
/*	 DCM_#, PORT0_#,	  PIN0_#*, PORT1_#,    PIN1_#	*/
	{DCM_0, DCM_PORT_D, DCM_PIN_2, DCM_PORT_D, DCM_PIN_3},
	{DCM_1, DCM_PORT_D, DCM_PIN_6, DCM_PORT_D, DCM_PIN_7}
};
 
/**----------------------------------------------------------
 *  END OF FILE: dcm_cfg.c
 *----------------------------------------------------------*/
