#include <IRremote.h>

int ir_recv=12;
int bpin=2;
int opin=3;
int gpin=4;

IRrecv irrecv(ir_recv);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  if(irrecv.decode(&results))
  {
    long int dcode=results.value;
    Serial.println(results.value);
    switch(results.value)
    {
      case 16582903: //when you press the button 1
      digitalWrite(2,HIGH);
      break;
      
      case 16615543: //when you press button 2
      digitalWrite(2,LOW);
      break;
      
      case 16599223: //when you press button 3
      digitalWrite(3,HIGH);
      break;
      
      case 16591063: //when you press button 4
      digitalWrite(3,LOW);
      break;
      
      case 16623703: //when you press button 5
      digitalWrite(4,HIGH);
      break;
      
      case 16607383: //when you press button 6
      digitalWrite(4,LOW);
      break;
    }
    irrecv.resume();//receive the next value from the button press
  }
  delay(10);
}