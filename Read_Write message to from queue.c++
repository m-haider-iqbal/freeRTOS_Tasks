#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <queue.h>

QueueHandle_t xQueue;

void vSenderTask;
void vReceiverTask;

void setup() 
{
  Serial.begin(9600);
  xQueue = xQueueCreate( 5, sizeof( long ) );
if( xQueue != NULL )
{
xTaskCreate( vSenderTask, "Sender1", 240, ( void * ) 100, 1, NULL );
xTaskCreate( vSenderTask, "Sender2", 240, ( void * ) 200, 1, NULL );
xTaskCreate( vReceiverTask, "Receiver", 240, NULL, 2, NULL );
vTaskStartScheduler();
}
}

void loop()
{
    
}

void vSenderTask( void *pvParameters )
{
long lValueToSend;

lValueToSend = ( long ) pvParameters;
for( ;; )
{
xQueueSend( xQueue, &lValueToSend, portMAX_DELAY );
Serial.print( "Sent = ");
Serial.println(lValueToSend);
taskYIELD();
}
}
void vReceiverTask( void *pvParameters )
{
long lReceivedValue;
for( ;; )
{

if (xQueueReceive( xQueue, &lReceivedValue, portMAX_DELAY ) == pdPASS)
{
Serial.print( "Received = ");
Serial.println(lReceivedValue);
}
taskYIELD();

}
}
