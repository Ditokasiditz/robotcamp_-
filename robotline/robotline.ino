//define motor pin 
#define pwmL  10
#define ML1   7
#define ML2   8
#define pwmR  11
#define RM1   9
#define RM2   12

//define sensor pin 
#define LS  A2
#define MS  A3
#define RS  A4

//motor speed
int spl,spr;
void setup() {
  Serial.begin(9600);
}

void loop() 
{
  Motor(100,0);
}





