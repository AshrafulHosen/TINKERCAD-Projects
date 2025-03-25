//variables and pins declared and initialized
int trigPin=10;
int echoPin=9;
long time;
int distance;

void setup()
  //this loop repeats only once
{ pinMode(10,OUTPUT);//trig pin set as output
  pinMode(9,INPUT);//echo pin set as input
  Serial.begin(9600);//brgin communication
}

void loop()
  //this loop repeats continuously
{
  digitalWrite(10,LOW);//trig pin set low(cleared)
  delay(2);//delay of 2 microseconds given
  
  digitalWrite(10,HIGH);//trig pin set high(signal transmitted)
  delay(10);
  digitalWrite(10,LOW);
  
  //calculating the distance
  time=pulseIn(9,HIGH);//to calculate time of flight
  distance=time*0.034/2;//calculate distance of object
  
  //printing the distance
  Serial.print("Distance: ");
  Serial.println(distance);
}