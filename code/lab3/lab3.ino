/*****************************************************************************
         Copyright  Oukassou  All Rights Reserved
*****************************************************************************/

/*****************************************************************************
   Header Files included
 *****************************************************************************/
#include <Arduino_FreeRTOS.h>
#include <Servo.h>
/******************************************************************************
   PROJECT :  Flacon pompe intelligent de savon
   Function : Main
 ******************************************************************************
 *                                                                            *
    Written by  :  Yassine Oukassou                     Date : 23/04/2020
 *                                                                            *
    Email : yassine.oukassou@usmba.ac.ma
 ******************************************************************************
   MODIFICATION LOG:
 ******************************************************************************
   Modified by :                                           Date :
   Comments :
 ******************************************************************************/
Servo motor1;
Servo motor2;
int trig = 6;
int echo = 5;
float distance;
float val;

void setup() {
xTaskCreate(ultrason,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);
xTaskCreate(servo,NULL,configMINIMAL_STACK_SIZE,NULL,1,NULL);

vTaskStartScheduler();
}
void loop() {}

void ultrason(void)
{  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
while(1)
{
  digitalWrite(trig, HIGH);
  vTaskDelay(10/ portTICK_PERIOD_MS);
  digitalWrite(trig, LOW);

  val = pulseIn(echo, HIGH);
  distance = val / 29.1 / 2;
  vTaskDelay(1);
  }
  }
void servo(void){
  motor1.attach(9);
  motor2.attach(10);
  while(1)
{
    if(distance<=10)
  {
    motor1.write(100); 
    motor2.write(100);
    vTaskDelay(500/ portTICK_PERIOD_MS);
  }
 if(distance>10)
  {
    motor1.write(0);
    motor2.write(0);
   vTaskDelay(50/ portTICK_PERIOD_MS);
  }
}
}
