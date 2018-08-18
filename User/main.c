#include "user_tasks.h" 
#include "system.h" 

#include "delay.h"	
#include "usart.h"	
#include "led.h"	
#include "rfid.h"

#include "usart_loop_queue.h"

int main( void )
{  
    //uint32_t i=0;
    ///i++;
    delay_init();
    led_init();
    //usb_queue_init();
    rfid_init();
    debug_usart_init( 921600 );
    LOG ( "\r\nSystemCoreClock = %d\r\n", (uint32_t)SystemCoreClock );   
    LOG( "\r\nboard init finished\r\n" );
    
	AppTaskCreate();
    vTaskStartScheduler();

    while(1);
}
