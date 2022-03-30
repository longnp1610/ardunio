// C++ code
//

int ledInput[6] = {13, 12, 11, 10, 9, 8};
int tempValue = 0;

const int button = 4;

int flag = 0;

void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < sizeof(ledInput) / sizeof(int); i++){
    pinMode(ledInput[i], OUTPUT);
  }
  pinMode(button, INPUT);
 }

void loop()
 {
   int btn_state = digitalRead(button); //Reads the input of pin 2 and save it in btn_state
   if(!btn_state)  //If the button is pressed
   {
     int rand = random(1, 6);
     if(flag == 0) //Check if flag is 0
     {
       tempValue = rand;
       for (int i = 0; i < rand; i++) {
          digitalWrite(ledInput[i], HIGH); //Turn LED on
       }
       flag = 1; //Set flag to 1
       Serial.println(rand);
       delay(2000);
       for (int i = 0; i < 6; i++) { // Blink led 6 times
         for (int y = 0; y < tempValue; y++) {
           digitalWrite(ledInput[y], LOW);
         }
         delay(1000);
         for (int z = 0; z < tempValue; z++) {
           digitalWrite(ledInput[z], HIGH);
         }
         delay(1000);
       }
     }
     else if(flag == 1) //If flag is 1
     {
       for (int i = 0; i < tempValue; i++) {
         digitalWrite(ledInput[i], LOW); //Turn LED off
       }
       flag = 0; //Set flag to 0
     }
   }
}