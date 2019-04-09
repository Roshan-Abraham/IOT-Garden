const int motorpin = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(motorpin,OUTPUT);
}

void loop() {
  int sensorvalue = analogRead(A0);
  Serial.println(sensorvalue);
  // put your main code here, to run repeatedly:
   if (sensorvalue<=600) 
  { 
    digitalWrite(motorpin,LOW); 
    delay(100);
  }
  else
  {
    
    digitalWrite(motorpin,LOW); 
    delay(100);
  }
  delay(100);
}
