const int trig = 2;
const int echo = 3;
const int relay = 4;

int measureDistance() 
{
   unsigned long duration;
   int distance;
   delay(50);
   digitalWrite(trig, 0);
   delayMicroseconds(2);
   digitalWrite(trig,1); 
   duration = pulseIn(echo, HIGH);
   distance = int(duration/2/29.412);
   return (distance);
}

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, OUTPUT);

  digitalWrite(relay, 0);
}

void loop() {
  int value = measureDistance();
  Serial.println(value);

    if (value > 15)
    {
      digitalWrite(relay, 1);
      //delay(5000);
    }

    if (value <= 10)
    {
      digitalWrite(relay, 0);
      //delay(5000);
    }
}