#include <Servo.h> 
 
Servo middle, left, right, claw ;   // creates 4 Servo objects
 
int middlePin = A0;     // middle potentiometer analog input pin
int leftPin = A1;       // left potentiometer analog input pin
int rightPin = A2;      // right potentiometer analog input pin
int clawPin = A3;       // claw potentiometer analog input pin
 
int middleValue = 0;    // middle potentiometer value
int leftValue = 0;      // left potentiometer value
int rightValue = 0;     // right potentiometer value
int clawValue = 0;      // claw potentiometer value



void setup() 
{ 
    middle.attach(11);  // attaches the servo on pin 11 to the middle object
    left.attach(10);    // attaches the servo on pin 10 to the left object
    right.attach(9);    // attaches the servo on pin 9 to the right object
    claw.attach(6);     // attaches the servo on pin 6 to the claw object
} 
 
void loop() 
{
    // read the potentiometer values
    middleValue = analogRead(middlePin);
    leftValue = analogRead(leftPin);
    rightValue = analogRead(rightPin);
    clawValue = analogRead(clawPin);

    // convert to values between 0 and 180 for the servos
    middleValue = map(middleValue, 0, 1023, 0, 180); 
    leftValue = map(leftValue, 0, 1023, 0, 180); 
    rightValue = map(rightValue, 0, 1023, 0, 180); 
    clawValue = map(clawValue, 0, 1023, 0, 180); 

    // write values to servos
    middle.write(middleValue);  // middle servo position
    left.write(leftValue);      // left servo position
    right.write(rightValue);    // right servo position
    claw.write(clawValue);      // claw servo position

    delay(400);     // short delay
}