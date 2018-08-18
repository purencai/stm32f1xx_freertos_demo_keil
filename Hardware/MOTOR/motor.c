#include "motor.h" 

/**
@brief  pwm初始化函数
@author purc
@date   2018/7-2018/7
@param[in]  timer_period 时钟周期
@retval no
*/
void motor_pwm_init( uint16_t prescaler, uint16_t period )
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	/* GPIOA, GPIOB and GPIOE Clocks enable */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );

	/* GPIOA Configuration: Channel 1 as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;;
	GPIO_Init( GPIOA, &GPIO_InitStructure );

	/* TIM1 clock enable */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_TIM1 , ENABLE );

	/* Time Base configuration */
	TIM_TimeBaseStructure.TIM_Prescaler = prescaler;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = period;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit( TIM1, &TIM_TimeBaseStructure );
 
	/* Channel 1 and 2 Configuration in PWM mode */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_Low;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCIdleState_Set;

	TIM_OC1Init( TIM1, &TIM_OCInitStructure );
    TIM_OC1PreloadConfig( TIM1, TIM_OCPreload_Enable );	
    
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OC3Init( TIM1, &TIM_OCInitStructure );
    TIM_OC3PreloadConfig( TIM1, TIM_OCPreload_Enable );	
    
    TIM_CtrlPWMOutputs( TIM1, ENABLE );
    
	/* TIM1 counter enable */
	TIM_Cmd( TIM1, ENABLE );
}

/**
@brief  电机反馈管脚初始化
@author purc
@date   2018/7-2018/7
@param[in]  void
@retval void
*/
void motor_feedback_pin_init( void )
{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    EXTI_InitTypeDef EXTI_InitStructure;
//    NVIC_InitTypeDef NVIC_InitStructure;
//    
//    /* Enable GPIOA clock */
//    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_GPIOB, ENABLE );

//    /* Configure PB8 and PB9 pin as input floating */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//    GPIO_Init( GPIOB, &GPIO_InitStructure );

//    /* Enable SYSCFG clock */
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_SYSCFG, ENABLE );
//    /* Connect EXTI8 Line to PB8 pin */
//    SYSCFG_EXTILineConfig( EXTI_PortSourceGPIOB, EXTI_PinSource8 );
//    /* Connect EXTI9 Line to PB9 pin */
//    SYSCFG_EXTILineConfig( EXTI_PortSourceGPIOB, EXTI_PinSource9 );
//    
//    /* Configure EXTI0 line */
//    EXTI_InitStructure.EXTI_Line = EXTI_Line8 | EXTI_Line9;
//    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
//    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//    EXTI_Init( &EXTI_InitStructure );

//    /* Enable and set EXTI0 Interrupt */
//    NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init( &NVIC_InitStructure );
}

/**
@brief  
@author purcs
@date   2018/7-2018/7
@param[in]  TIMx 定时器指针
@param[in]  TIM_Channel 定时器pwm输出的通道
@param[in]  compare_value pwm的占空比值
@retval no
*/
void set_motor_duty_cycle( TIM_TypeDef *TIMx, uint16_t TIM_Channel, uint32_t compare_value )
{
    switch ( TIM_Channel )
    {
    case TIM_Channel_1:
        TIM_SetCompare1( TIMx, compare_value );
    break;
    case TIM_Channel_2:
        TIM_SetCompare2( TIMx, compare_value );
    break;
    case TIM_Channel_3:
        TIM_SetCompare3( TIMx, compare_value );
    break;
    case TIM_Channel_4:
        TIM_SetCompare4( TIMx, compare_value );
    break;
    default:
    break;
    }
}
