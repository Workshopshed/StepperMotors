//LED test
void setup() { 
// initialize the digital pins as an output.
pinMode(6, OUTPUT); 
pinMode(7, OUTPUT); 
pinMode(8, OUTPUT); 
pinMode(20, OUTPUT);  //remapped from pin 9 as that was shorted to pin 8
pinMode(10, OUTPUT); 
pinMode(14, OUTPUT); 
pinMode(15, OUTPUT); 
pinMode(16, OUTPUT); 
Serial.begin(9600);
}
 
// the loop routine runs over and over again forever:
void loop() {

FlashPin(6); 
FlashPin(7); 
FlashPin(8); 
FlashPin(20); 

FlashPin(15); 
FlashPin(14); 
FlashPin(16); 
FlashPin(10); 
}

void FlashPin(int pin)
{
  Serial.println(pin);
  digitalWrite(pin,HIGH);
  delay(250);
  digitalWrite(pin,LOW);
  delay(250);
   digitalWrite(pin,HIGH);
  delay(250);
  digitalWrite(pin,LOW);
  delay(250);
}
