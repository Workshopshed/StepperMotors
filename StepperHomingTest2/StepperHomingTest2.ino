#include <AccelStepper.h>
#include <AFMotor.h>

const int SensorPin = 7;
// initialize the stepper library on pins 8 through 11:
AccelStepper stepper1( AccelStepper::FULL4WIRE,8,10,9,11);  
      
void setup() {
  unhome(); 
  home();
}
 
void unhome() // If already homed then move away
{
 //When stepper starts current position = 0 
  delay(50); //let the sensor stabilise
  if  (digitalRead(SensorPin) != 0)
  {
    //Move marker out of the way so we can re-home
    stepper1.setAcceleration(100.0);
    stepper1.runToNewPosition (-200);
  }
  stepper1.setMaxSpeed(200);
  stepper1.moveTo (10000);
  stepper1.setSpeed(200); 
}

void home()
{
  while (digitalRead(SensorPin) == 0)
  {
    stepper1.runSpeed();
  }
 
  stepper1.setCurrentPosition(0);
  stepper1.stop();
}


void loop(){  
  //Nothing here 
}