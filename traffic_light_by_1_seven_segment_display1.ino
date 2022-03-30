// C++ code
//
const int a = 2;  //For displaying segment "a"
const int b = 3;  //For displaying segment "b"
const int c = 4;  //For displaying segment "c"
const int d = 5;  //For displaying segment "d"
const int e = 6;  //For displaying segment "e"
const int f = 7;  //For displaying segment "f"
const int g = 8;  //For displaying segment "g"

const int lightRed = 9;
const int lightYellow = 10;
const int lightGreen = 11;

int num0[] = {a, b, c, d, e, f};
int num1[] = {b, c};
int num2[] = {a, b, g, e, d};
int num3[] = {a, b, g, c, d};
int num4[] = {f, g, b, c};
int num5[] = {a, f, g, c, d};
int num6[] = {a, f, e, d, c, g};
int num7[] = {a, b, c};
int num8[] = {a, b, c, d, e, f, g};
int num9[] = {a, b, c, d, f, g};

String recent = "red";

void displayDigit(int*, int);
void timer(int);
void turnOff();
void turnOnLight(int);
void turnOffLight(int);

void setup() {        
  Serial.begin(9600);
  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G
  pinMode(lightRed, OUTPUT); // RED LIGHT
  pinMode(lightYellow, OUTPUT); // YELLOW LIGHT
  pinMode(lightGreen, OUTPUT); // GREEN LIGHT
  digitalWrite(lightRed, HIGH);
}

void loop() {
  Serial.println(recent);
  for (int i = 9; i >= 0; i--) {
    timer(i);
    delay(1000);
    turnOff();
  }
  
  if (recent.equals("red")) {
    turnOffLight(lightRed);
    turnOnLight(lightYellow);
    recent = "yellow";
  }
  else if (recent.equals("yellow")) {
    turnOffLight(lightYellow);
    turnOnLight(lightGreen);
    recent = "green";
  }
  else if (recent.equals("green")) {
    turnOffLight(lightGreen);
    turnOnLight(lightRed);
    recent = "red";
  }
}

void displayDigit(int* array, int length)
{
  for (int i = 0; i < length; i++) {
    digitalWrite(array[i], HIGH);
  }
}

void timer(int number){
  switch(number){
    case 0:
    	displayDigit(num0, sizeof(num0)/sizeof(int));
    	break;
    case 1:
    	displayDigit(num1, sizeof(num1)/sizeof(int));
    	break;
    case 2:
    	displayDigit(num2, sizeof(num2)/sizeof(int));
    	break;
    case 3:
    	displayDigit(num3, sizeof(num3)/sizeof(int));
    	break;
    case 4:
    	displayDigit(num4, sizeof(num4)/sizeof(int));
    	break;
    case 5:
    	displayDigit(num5, sizeof(num5)/sizeof(int));
    	break;
    case 6:
    	displayDigit(num6, sizeof(num6)/sizeof(int));
    	break;
    case 7:
    	displayDigit(num7, sizeof(num7)/sizeof(int));
    	break;
    case 8:
    	displayDigit(num8, sizeof(num8)/sizeof(int));
    	break;
    case 9:
    	displayDigit(num9, sizeof(num9)/sizeof(int));
    	break;
  }
}

void turnOff()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void turnOnLight(int light) {
  digitalWrite(light, HIGH);
}

void turnOffLight(int light) {
  digitalWrite(light, LOW);
}