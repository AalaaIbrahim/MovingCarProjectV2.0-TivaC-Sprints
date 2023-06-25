//
// Created by hossam on 25/6/2023.
//

#ifndef SHARED_DELAY_INTERFACE_H
#define SHARED_DELAY_INTERFACE_H

#include "gpt_interface.h"

typedef enum
{
    DELAY_OK    = 0     ,
    DELAY_ERROR         ,
    DELAY_INVALID_STATE ,
    DELAY_TOTAL
}en_delay_status_t;

static boolean gl_bool_shutdown = FALSE;


/**
 * @brief               :   Initializes delay module
 *
 * @return  DELAY_OK    :   If Successful
 *          DELAY_ERROR :   If failed
 */
en_delay_status_t delay_init(void);

/**
 * @brief                               :   Initiates a delay
 *
 * @param[in]   uint32_a_time           :   Time (in generic units) to delay
 * @param[in]   en_a_gpt_time_unit      :   Time unit (seconds, millis, micros)
 *
 * @return      DELAY_OK                :   If Successful
 *              DELAY_ERROR             :   If failed
 */
en_delay_status_t delay_start(uint32_t_ uint32_a_time, en_gpt_time_unit_t en_a_gpt_time_unit);

/**
 * @brief               :   Immediately stops a delay
 *
 * @return  DELAY_OK    :   If Successful
 *          DELAY_ERROR :   If failed
 */
en_delay_status_t delay_stop();

en_delay_status_t delay_shutdown(boolean bool_a_shutdown);

#endif //SHARED_DELAY_INTERFACE_H
