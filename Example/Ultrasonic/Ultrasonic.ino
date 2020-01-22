/* Example of ultrasonic sensor program
 *  Created by Thiago M. Joaquim, September 29, 2018.
 */

//Inclusion of the "Ultrasonic.h" Library
#include "Ultrasonic.h"

//Definition of Trigger and Echo pins 
#define trigPin 13
#define echoPin 12

/*Configuration of the Trigger and Echo pins respectively
 * Trigger pin on pin 13 (INPUT)
 * Echo pin on pin 12 (OUTPUT)
 * sensor: any desired name
 */
Ultrasonic sensor(trigPin, echoPin);

void setup() {
  //Serial Monitor Initialization
  Serial.begin(9600);
}

void loop() {
  //Definition of the variable you will receive at a distance
  double measure;

  /* Calculating the distance according to the desired measurement
   *  mm: Calculates distance in millimeters
   *      If the distance <= 30,0 mm or >= 4000.0 mm, return -1
   *  cm: Calculates distance in centimeters
   *      If the distance <= 3.0 cm or >= 400.0 cm, return -1
   *  in: Calculates distance in inches
   *      If the distance <= 1.19 in or >= 157.48 in, return -1
   */
  measure = sensor.distance("in");

  //Serial display
  Serial.print("Distance in inch: ");
  Serial.println(measure);
  delay(1000);

}
