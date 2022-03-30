int ledGreen = 13;
int ledYellow = 12;
int ledOrange = 11;
int ledBlue = 10;
int ledRed = 9;
int ledWhite = 8;
void setup()
{
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledOrange, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledWhite, OUTPUT);
  pinMode(A0, INPUT);
}


void loop()
{
  int readValue = analogRead(A0);
  int ledValue = map(readValue, 0, 1023, 0, 255);
  if (ledValue > 0)
    digitalWrite(ledGreen, HIGH);
  else
  	digitalWrite(ledGreen, LOW);
  
  if (ledValue > 43)
  	digitalWrite(ledYellow, HIGH);
  else
  	digitalWrite(ledYellow, LOW);
  
  if (ledValue > 86)
  	digitalWrite(ledOrange, HIGH);
  else
  	digitalWrite(ledOrange, LOW);
  
  if (ledValue > 129)
  	digitalWrite(ledBlue, HIGH);
  else
  	digitalWrite(ledBlue, LOW);
  
  if (ledValue > 172)
  	digitalWrite(ledRed, HIGH);
  else
  	digitalWrite(ledRed, LOW);
  
  if (ledValue > 215)
  	digitalWrite(ledWhite, HIGH);
  else
  	digitalWrite(ledWhite, LOW);
  
  Serial.println(ledValue);
  delay(100);
}
