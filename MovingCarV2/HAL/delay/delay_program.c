//
// Created by hossam on 25/6/2023.
//

#include "delay_interface.h"

#define DELAY_GPT_CHANNEL CH_0

/**
 * @brief               :   Initializes delay module
 *
 * @return  DELAY_OK    :   If Successful
 *          DELAY_ERROR :   If failed
 */
en_delay_status_t delay_init(void)
{
    en_delay_status_t en_delay_status_retval = DELAY_OK;

    en_delay_status_retval = gpt_init() == GPT_OK ? DELAY_OK : DELAY_ERROR;

    return en_delay_status_retval;
}

/**
 * @brief                               :   Initiates a delay
 *
 * @param[in]   uint32_a_time           :   Time (in generic units) to delay
 * @param[in]   en_a_gpt_time_unit      :   Time unit (seconds, millis, micros)
 *
 * @return      DELAY_OK                :   If Successful
 *              DELAY_ERROR             :   If failed
 */
en_delay_status_t delay_start(uint32_t_ uint32_a_time, en_gpt_time_unit_t en_a_gpt_time_unit)
{
    en_delay_status_t en_delay_status_retval = DELAY_OK;
    en_gpt_status_t en_gpt_status = gpt_start(DELAY_GPT_CHANNEL, uint32_a_time, en_a_gpt_time_unit);

    if(en_gpt_status != GPT_OK)
    {
        en_delay_status_retval = DELAY_ERROR;
    }

    return en_delay_status_retval;
}

/**
 * @brief               :   Immediately stops a delay
 *
 * @return  DELAY_OK    :   If Successful
 *          DELAY_ERROR :   If failed
 */
en_delay_status_t delay_stop()
{
    en_delay_status_t en_delay_status_retval = DELAY_OK;

    if(GPT_OK != gpt_stop(DELAY_GPT_CHANNEL))
    {
        en_delay_status_retval = DELAY_ERROR;
    }

    return en_delay_status_retval;
}