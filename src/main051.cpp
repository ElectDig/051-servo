/*
 *     Project 051-servo - main051.cpp
 *
 * 
 *      Ejemplo de como separar un proyecto simple en archivos de compilacion separada
 *      En este caso, se va a tomar el ejemplo de proyecto 05-servo para separar lo que
 *      corresponde al manejo del servo; de esta manera, el programa principal se independiza
 *      de los detalles de como se hace para inicializar y utilizar un servo
 *
 *      Compare ente archivo mani051.cpp con el que se acompaña maincpp.old que en el
 *      proyeto original era main.cpp
 *
 *       IntroCom - Austral - 2022 - EAM
 *       Shows how a servo is positioned as per table
 *       Using ESP32 development board
 *
 *       Uses a C++ library for ESP32 servo
 */

#include <Arduino.h>

#include "myservo.h"


/*
 *  Constants defined in platformio.ini
 *      SERIAL_BAUD Serial port Baud rate
 */

#define END_LIST    -1      //  For end of table

//    Positioning table
static const int grads[] = {0, 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, END_LIST};


static void
go_servo(int pos)
{
    myservo_write(pos);
    delay(1500);
    Serial.printf("grads = %3d, real = %3d\n", pos, myservo_read());
}

void
setup(void)
{
    Serial.begin(SERIAL_BAUD);
    myservo_init();
}

void
loop(void)
{
    int i, c, last,t;

    for (i = 0; (c = grads[i]) >= 0; ++i)
        go_servo(c);
    for(i-=2; (c = grads[i]) > 0; --i)
        go_servo(c);
}


