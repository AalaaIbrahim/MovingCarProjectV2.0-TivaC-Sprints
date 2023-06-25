cmake_minimum_required(VERSION 3.25)
project(shared C)

set(CMAKE_C_STANDARD 11)

include_directories(MovingCarV2/APP)
include_directories(MovingCarV2/HAL)
include_directories(MovingCarV2/HAL/btn)
include_directories(MovingCarV2/HAL/led)
include_directories(MovingCarV2/HAL/delay)
include_directories(MovingCarV2/HAL/pwm)
include_directories(MovingCarV2/LIB)
include_directories(MovingCarV2/MCAL)
include_directories(MovingCarV2/MCAL/gpio)
include_directories(MovingCarV2/MCAL/gpt)
include_directories(MovingCarV2/RTE/_Target_1)

add_executable(shared
        MovingCarV2/APP/app_program.c
        MovingCarV2/APP/app_interface.h
        MovingCarV2/HAL/btn/btn_interface.h
        MovingCarV2/HAL/btn/btn_program.c
        MovingCarV2/HAL/led/led_interface.h
        MovingCarV2/HAL/led/led_program.c
        MovingCarV2/HAL/pwm/pwm_interface.h
        MovingCarV2/HAL/pwm/pwm_linking_cfg.c
        MovingCarV2/HAL/pwm/pwm_linking_cfg.h
        MovingCarV2/HAL/pwm/pwm_program.c
        MovingCarV2/LIB/bit_math.h
        MovingCarV2/LIB/std.h
        MovingCarV2/MCAL/gpio/gpio_interface.h
        MovingCarV2/MCAL/gpio/gpio_private.h
        MovingCarV2/MCAL/gpio/gpio_program.c
        MovingCarV2/MCAL/gpt/gpt_interface.h
        MovingCarV2/MCAL/gpt/gpt_linking_cfg.c
        MovingCarV2/MCAL/gpt/gpt_linking_cfg.h
        MovingCarV2/MCAL/gpt/gpt_private.h
        MovingCarV2/MCAL/gpt/gpt_program.c
        MovingCarV2/RTE/_Target_1/RTE_Components.h
        MovingCarV2/RTE/Device/TM4C123GH6PM/system_TM4C123.c
        MovingCarV2/main.c
        MovingCarV2/APP/app_private.h

        MovingCarV2/HAL/delay/delay_program.c

        MovingCarV2/HAL/delay/delay_interface.h

        )
