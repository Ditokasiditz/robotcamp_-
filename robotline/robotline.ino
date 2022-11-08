//define motor pin 
#define pwmL  10
#define ML1   8
#define ML2   7
#define pwmR  11
#define RM1   9
#define RM2   12

//define sensor pin 
#define LS  A0
#define MS  A1
#define RS  A2

//motor speed
int spl=100,spr=100;

void setup() {
  Serial.begin(9600);
}

//LED pin
#define LED A5

void loop() 
{
  FF(spl,spr);
  Detect_ss();


}


void LED_blink()
{
  analogWrite(LED,700);
  delay(500);
  analogWrite(LED,0);
  delay(500);
}





