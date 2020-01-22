/*
    Ultrasonic.h - Library for HC-SR04 Module
    Created by Thiago M. Joaquim, September 27, 2018.
*/

#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int trigPin, int echoPin){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    _TP = trigPin;
    _EP = echoPin;
}

double Ultrasonic::distance(String measure){
    //Initializing the Trigger pin with 0
    digitalWrite(_TP,LOW);
    delayMicroseconds(2);
    //Initialize the sensor
    digitalWrite(_TP,HIGH);
    delayMicroseconds(10);
    //Turning the Trigger pin to the LOW state
    digitalWrite(_TP,LOW);

    //Calculating time
    long duration = pulseIn(_EP,HIGH);

    //Calculating the distance in cm
    double dist = duration/58.0;

    //Moving to mm
    while(measure == "mm"){
        dist *= 10.0;
        if(dist<=30.0 || dist>=4000.0){
            return -1;
        }
        else{
            return dist;
        }
    }

    //Showing in cm
    while(measure == "cm"){
        if(dist<=3.0 || dist>=400.0){
            return -1;
        }
        else{
            return dist;
        }
        delay(60);
    }

    //Moving to inch
    while(measure == "in"){
        dist *= 0.3937;
        if(dist<=1.19 || dist>=157.48){
            return -1;
        }
        else{
            return dist;
        }
    }
}
