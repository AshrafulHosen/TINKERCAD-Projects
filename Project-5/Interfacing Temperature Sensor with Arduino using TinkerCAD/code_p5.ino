int temp=A0;
float temp_cel;
float vol;
float temp_far;
float analog_red;
void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop()
{
  analog_red=analogRead(A0);
  Serial.print("Analog reading: ");
  Serial.println(analog_red);
  
  //converitng analog reading to voltage
  vol=analog_red*5/1024;
    //div by 1024 as the analog reading from the data pin is between 0-1024
    //5 because 5 volts
  
  Serial.print("Voltage: ");
  Serial.println(vol);
  
  //reading in celcius
  //converitng from 10mv per degree with 0.5 v offset
  temp_cel=100*(vol-0.5);
  Serial.println("Celcius reading: " + String(temp_cel) + (" C"));
  temp_far=(temp_cel*9/5)+32;
  Serial.println("Farenheit reading: " + String(temp_far) + (" F\n"));
  delay(3000);
}