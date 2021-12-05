# Arduino library for HC-SR04 module
This library allows you to measure distance in millimeters, centimeters or inches using the HC-SR04 module.

##What is HC-SR04?
Ultrasonic ranging module HC-SR04 provides 2cm - 400cm non-contact measurement function, the ranging accuracy can rach to 3mm.
The modules includes ultrasonic transmitters, receiver and control circuit.
<br/><br/>
<img src="https://cdn.awsli.com.br/600x700/468/468162/produto/19414094/modulo-sensor-de-distancia-ultrassonico-hc-sr04-e5f1a20d.jpg" width="300">

##How to install?
The first thing you need to do is download this library as a .zip directory.

Now, you have to go in the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library...
<img src="https://www.arduino.cc/en/uploads/Guide/ImportLibraryFromZIPFile.png" width="500">

You will be prompted to select the library you would like to add. Navigate to the .zip file's location and open it.
<img src="https://www.arduino.cc/en/uploads/Guide/SelectLibraryZip.png" width="500">

Return to the Sketch > Include Library. You should now see the library at the bottom of the drop-down menu. It is ready to be used in your sketch. The zip file will have been expanded in the libraries folder in your Arduino sketches directory.

##How to use?
First of all, you need to include this library in your sketch with the following command: `#include "Ultrasonic.h"`.

Then, the sensor is initialized by creating an instance of the Ultrasonic class and providing the Trigger and Echo pins to constructor: `Ultrasonic sensor(triggerPin, echoPin)`

So, to measure distance, simply call the function`distance(measure)`.

The `measure` parameter can be: "mm", "cm" or "in":
* "mm": measured in millimeters;
* "cm": measured in centimeters;
* "in": measure in inches.

The function `distance(measure)` returns the value of the measured distance.
#####Observations:
* If the distance in "mm" is <= 30.0 or >= 4000.0, the function returns -1;
* If the distance in "cm" is <= 3.0 and >= 400.0, the function returns -1;
* If the distance in "in" is <= 1.19 and >= 157.48, the function returns -1.

##Example
In this example, I connect the sensor pins in this way:
* Vcc on 5V;
* Trig on digital pin 13;
* Echo on digital pin 12;
* GND on grd.

```c++
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
``