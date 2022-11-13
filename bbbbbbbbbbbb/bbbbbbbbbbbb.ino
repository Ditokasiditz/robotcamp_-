//define motor pin 

unsigned long int time1,time2;
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
int spl=80,spr=80;

//sensor
int Left,Mid,Right;

//Error
float Kp=1.95,Ki=0,Kd=15;
float error, P=0, PID_value=0;
float previous_error=0,previous_I=0;
int i=3;


int Buzzer = 13;
int LED = 6;

String state="white";


void setup() {
  
    PID_value=0;
    pinMode(LED,OUTPUT);
    // Motor(0,0);
    // delay(500);
    // Motor(50,50);
    // delay(1000);
    // Motor(-50,50);
    // delay(500);
    // Motor(0,0);
}

void loop() 
{
  light();
  Calculate_PID();
  if(state=="white")
  {
    run_case_white();
  }
  if(state="black")
  {
    run_case_black();
  }
}

