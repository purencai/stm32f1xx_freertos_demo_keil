#include "led.h" 

void led_init( void )
{
    GPIO_InitTypeDef GPIO_InitStructure;

    /* GPIOC Periph clock enable */
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE );

    /* Configure PC13 in output pushpull mode */
    GPIO_InitStructure.GPIO_Pin = SYSTEM_RUNING_GPIO_BIT_NUM;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init( SYSTEM_RUNING_GPIO_PORT_NUM, &GPIO_InitStructure );
}

void set_led_value( led_type_t led_type, BitAction value )
{
	switch ( led_type )
	{
	case SYSTEM_RUNING:
		GPIO_WriteBit( SYSTEM_RUNING_GPIO_PORT_NUM, SYSTEM_RUNING_GPIO_BIT_NUM, value );
	break;
	case USB_ATTACHED:
		GPIO_WriteBit( SYSTEM_RUNING_GPIO_PORT_NUM, SYSTEM_RUNING_GPIO_BIT_NUM, value );
	break;
	case RESERVERD1:
		GPIO_WriteBit( SYSTEM_RUNING_GPIO_PORT_NUM, SYSTEM_RUNING_GPIO_BIT_NUM, value );
	break;
	case RESERVERD2:
		GPIO_WriteBit( SYSTEM_RUNING_GPIO_PORT_NUM, SYSTEM_RUNING_GPIO_BIT_NUM, value );
	break;
	default:
	break;
	}
}
