//
// Created by hossam on 25/6/2023.
//

#include "delay_interface.h"

en_gpt_channel_t gl_en_gpt_delay_channel = CH_0;

en_delay_status_t delay_init(void)
{
    en_delay_status_t en_delay_status_retval = DELAY_OK;

    en_delay_status_retval = gpt_init() == GPT_OK ? DELAY_OK : DELAY_ERROR;

    return en_delay_status_retval;
}

en_delay_status_t delay_start(uint32_t_ uint32_a_time, en_gpt_time_unit_t en_a_gpt_time_unit)
{
    en_delay_status_t en_delay_status_retval = DELAY_OK;
    en_gpt_status_t en_gpt_status = gpt_start(gl_en_gpt_delay_channel, uint32_a_time, en_a_gpt_time_unit);

    if(en_gpt_status != GPT_OK)
    {
        en_delay_status_retval = DELAY_ERROR;
    }

    return en_delay_status_retval;
}