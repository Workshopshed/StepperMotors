
#include <AccelStepper.h>
#include <AFMotor.h>

const int SensorPin = 7;

const int TestLED = 13;

// initialize the stepper library on pins 8 through 11:
AccelStepper stepper1( AccelStepper::FULL4WIRE,8,10,9,11);         

void setup() {
  digitalWrite(SensorEnable, HIGH); 
  delay(50); //let the sensor stabilise
  unhome();  
}
 
void unhome() // If already homed then move away
{
 //When stepper starts current position = 0  
  if  (digitalRead(SensorPin) != 0)
  {
    digitalWrite(TestLED, HIGH);
    stepper1.setAcceleration(100.0);
    stepper1.runToNewPosition (-200);
  }
  stepper1.setMaxSpeed(200);
  stepper1.moveTo (10000);
  stepper1.setSpeed(200);  
}
  
void loop(){   
  
  if  (digitalRead(SensorPin) == 0)  //Beam is Seen
  {
    digitalWrite(TestLED, LOW);
    stepper1.runSpeed();
  }
  else 
  {
    if (stepper1.currentPosition() != 0) 
    {
      stepper1.setCurrentPosition(0);
    }
    digitalWrite(TestLED, HIGH);
    stepper1.stop();
  }  
  
}

