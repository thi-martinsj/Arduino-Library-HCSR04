/*
    Ultrasonic.h - Library for HC-SR04 Module
    Created by Thiago M. Joaquim, September 27, 2018.
*/

#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

class Ultrasonic{
    public:
        // Definition of Trig and Echo Pins
        Ultrasonic(int trigPin, int echoPin);

        /*Calculation of the Distance according to the declared measurement.
          If the distance <=2.00 cm or >=400.00 cm, the function returns -1;
          If the distance <=20.00 mm or >=4000.00 mm, the function returns -1;
          If the distance <=0.79 in or >=157.48 in, the function returns -1.
        */
        double distance(String measure);

    private:
        int _TP, _EP;
};

#endif // Ultrasonic_h
