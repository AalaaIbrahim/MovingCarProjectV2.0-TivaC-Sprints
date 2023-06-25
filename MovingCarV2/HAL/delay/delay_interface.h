//
// Created by hossam on 25/6/2023.
//

#ifndef SHARED_DELAY_INTERFACE_H
#define SHARED_DELAY_INTERFACE_H

#include "gpt_interface.h"

typedef enum
{
    DELAY_OK    = 0 ,
    DELAY_ERROR     ,
    DELAY_TOTAL
}en_delay_status_t;

en_delay_status_t delay_init(void);

en_delay_status_t delay_start(uint32_t_ uint32_a_time, en_gpt_time_unit_t en_a_gpt_time_unit);

#endif //SHARED_DELAY_INTERFACE_H
