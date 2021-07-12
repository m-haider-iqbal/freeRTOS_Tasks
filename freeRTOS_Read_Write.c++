
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

void Task_1(void *param)
{
  while (1)
  {
    Serial.println("I GOT IT");
    vTaskDelay(10); // 1 TICK = 15 MS
  }
}
void Task_2(void *param)
{
  while (1)
  {
    Serial.println("Task_2");
    vTaskDelay(pdMS_TO_TICKS(1000)); // CONVERTS 1000 MS TO TICKS.
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  xTaskCreate(Task_1, "Task_1", 12, NULL, 1, NULL);
  xTaskCreate(Task_2, "Task_2", 12, NULL, 2, NULL);

}

void loop()
{
  // put your main code here, to run repeatedly:
}
