#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "sys.h"

extern void motor_pwm_init( uint16_t prescaler, uint16_t period );
extern void motor_control_pin_init( void );
extern void motor_feedback_pin_init( void );
extern void set_motor_duty_cycle( TIM_TypeDef *TIMx, uint16_t TIM_Channel, uint32_t compare_value );

#endif //__MOTOR_H_
