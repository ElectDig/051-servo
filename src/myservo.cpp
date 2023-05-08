/*
 *  myservo.cpp
 *      Archivo que maneja un servo independientemente de la aplicacion
 */

#include <Arduino.h>
#include <Servo.h>          //  For library prototypes and definitions

#include "myservo.h"

Servo servo;

/*
 *  Constants defined in platformio.ini
 *      MY_SERVO    GPIO where data is connected
 */

void
myservo_write(int pos)
{
    servo.write(pos);
}

int
myservo_read(void)
{
    return servo.read();
}


void
myservo_init(void)
{
    servo.attach(MY_SERVO); //    Attach GPIO pin to object Servo
    myservo_write(0);
    delay(2000);
    Serial.printf("\n\n051-servo: servo position = %3d\n", myservo_read() );
}


