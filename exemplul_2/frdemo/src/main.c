/* Demo application for SODTR lab using FreeRTOS
@2016 KCs <csaba.kertesz@etc.unitbv.ro>
See documentation of FreeRTOS <http://www.freertos.org> for further details
*/

// include AVR headers
#include <avr/io.h>

// include the operating system
#include "FreeRTOS.h"
#include "task.h"

 /* Private macro definitions.
 ******************************************************************************/
 
#define mainLED_TASK_PRIORITY   (2)

// tasks
static void blink( void *pvParameters );
static void vBlinkLed(void* pvParameters);


/*-----------------------------------------------------------*/

int main( void )
{
	// initialize port
	PORTC = 0x01;
	DDRC = 0x3F;
	PORTB = 0x01;
	DDRB = 0x20;

	// create blinking task
	xTaskCreate( blink, "Blinky", configMINIMAL_STACK_SIZE, NULL, 1, NULL );

//another task

 xTaskCreate
    (
        vBlinkLed,
        "blink",
        configMINIMAL_STACK_SIZE,
        NULL,
        mainLED_TASK_PRIORITY,
        NULL
    );

	// start the scheduler
	vTaskStartScheduler();

	return 0;
}
/*-----------------------------------------------------------*/

static void blink( void *pvParameters )
{
	uint8_t dir = 1; // direction flag
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t delay = 200;

	(void)pvParameters; // parameters not used

	// forever loop
	for(;;)
	{
		vTaskDelayUntil(&xLastWakeTime, delay);

		if (dir)
		{
			PORTC <<= 1;
			dir = PORTC != 0x20;
		}
		else
		{
			PORTC >>= 1;
			dir = PORTC == 0x01;
		}
	}
}

static void vBlinkLed(void* pvParameters)
{
    (void)pvParameters; // parameters not used
    
 	//uint8_t dir = 1;

    for (;; )
    {
	
        //PORTB ^= _BV(PB5);
	PORTB = 0x20;
        vTaskDelay(500);
	PORTB = 0x00;
        vTaskDelay(500);
    }
}
