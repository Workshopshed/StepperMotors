/* For testing slotted opto sensor and wiring using Omcron EE-SV3
   220ohm Series resisitor from IR_LED_PIN to IR LED anode
   Collector to IR_DETECTOR_PIN
   Emitter and Cathode connected to ground
   Input pullup option allows us to omit the external 10K pullup resistor
   */
int IR_DETECTOR_PIN  = 4;    // 19;
int IR_LED_PIN       = 5;    // 18;
int TestLED          = 17;

void setup()  
{ 
  Serial.begin(9600);
  digitalWrite(IR_LED_PIN, HIGH);
  digitalWrite(TestLED, HIGH);
  
  pinMode(TestLED, OUTPUT); 
  pinMode(IR_LED_PIN, OUTPUT);
  pinMode(IR_DETECTOR_PIN, INPUT_PULLUP);
  

  delay(250);
  digitalWrite(TestLED, LOW);
  delay(250);
  digitalWrite(TestLED, HIGH);
}

void loop()   
{
  if  (digitalRead(IR_DETECTOR_PIN) == 0)  //Beam is Seen
  {
    digitalWrite(TestLED, HIGH);
    Serial.write("X");
  }
  else 
  {
    digitalWrite(TestLED, LOW);
    Serial.write("O");
  }  
  Serial.write("\n\r");
delay(200);
}

