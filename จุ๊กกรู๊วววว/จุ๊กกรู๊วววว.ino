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

//PID calculate
float Kp=30,Ki=0,Kd=15;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0,previous_I=0;


void setup() {
  Serial.begin(9600);
}
  
void loop() 
{
  read_sensor_values();
  Calculate_PID();
  run_case(spl,spr);
}



void run_case(int spl, int spr)
{
  while(1)
  {
  if((analogRead(LS)<250) && (analogRead(RS)<250) && (analogRead(MS)>600) )
  {
    Motor(spl,spr);
  }
  else if ( (analogRead(LS)>600) && (analogRead(RS)<250) )   //turn left
  {
    Motor(0,spr);
  }
  else if ((analogRead(LS)<250) && (analogRead(RS)>600) )    //turn right
  {
    Motor(spl,0);
  }
  else if ((analogRead(LS)>600) && (analogRead(RS)>600) && (analogRead(MS)>600) )
    {
     Motor(0,0);
     delay(100);
     break;
    } 
  }
  Motor(0,0);
  delay(10);
}


void Motor(int spl,int spr)
{
  pinMode(pwmL,OUTPUT);//pwmL
  pinMode(ML1,OUTPUT);
  pinMode(ML2,OUTPUT);
 
  pinMode(pwmR,OUTPUT);//pwmR
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  
  //spl > 100, spr > 100  limit motor speed for 100
  if (spl>100)
    spl=100;
  else if (spr>100)
    spr=100;

  //Motor Left
  if(spl>0)
  {
    analogWrite(pwmL,(spl*255)/100);
    digitalWrite(ML1,HIGH);
    digitalWrite(ML2,LOW);
  }
  else if (spl<0)
  {
    analogWrite(pwmL,(-spl*255)/100);
    digitalWrite(ML1,LOW);
    digitalWrite(ML2,HIGH);
  }
  else
  {
    analogWrite(pwmL,(spl*255)/100);    //case for stop motor
    digitalWrite(ML1,LOW);
    digitalWrite(ML2,LOW);
  }

  //Motor Right
  if(spr>0)
  {
    analogWrite(pwmR,(spr*255)/100);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
  }
  else if (spl<0)
  {
    analogWrite(pwmR,(-spr*255)/100);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
  }
  else
  {
    analogWrite(pwmR,(spr*255)/100);    //case for stor motor
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
  }
}


void Calculate_PID()
{
  // คำนวณค่าความคลาดเคลื่อนในการเดินตามเส้น
  P= error;
  I= I + previous_I;
  D= error-previous_error;
  PID_value = (Kp*P) + (Ki*I) + (Kd*D);
  previous_I=I;
  previous_error=error;
  
  // Check PID
  Serial.print(PID_value);
  Serial.print(' ');
  Serial.print(previous_I);
  Serial.print(' ');
  Serial.print(previous_error);
  Serial.print(' ');
  Serial.println();
  delay(500); 
}




void read_sensor_values()
{

  pinMode(LS,INPUT);
  pinMode(MS,INPUT);
  pinMode(RS,INPUT);
  //define senssor
  int Left,Mid,Right;
  Left=analogRead(LS);
  Mid=analogRead(MS);
  Right=analogRead(RS);
  
  //check senssor
      Serial.println(analogRead(LS));
      Serial.println(analogRead(MS));
      Serial.println(analogRead(RS));
      delay(200);


  //ในการเคลื่อนที่ เมื่อเซนเซอร์เมื่อ เซนเซอร์ซ้ายขวาจับได้ว่า พบพื้นที่สีดำ เป็น 0 ในค่า digital และ < 350 ใน analog
  // พื้นที่ขาว = 0 (in Digital)   or   (<50 in Analog)
  // พื้นที่ดำ  = 1 (in Digital)   or   (>800 in Analog)
  //Black line
  if( (Left <250 ) && (Mid < 250) && (Right >=600 )) // 0 0 1 *****************
  {
    error= 2; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางซ้าย ในระดับ 2 
  }
  else if( (Left<250) && (Mid>=600) && (Right>=600)) // 0 1 1 *****************
  {
    error= 1; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางซ้าย ในระดับ 1
  }
  else if( (Left<250 ) && (Mid>600) && (Right<250)) // 0 1 0 *****************
  {
    error= 0; // เพียงบอกว่า อยู่ในแนวเส้นตรง ในระดับ 0
  }
  else if( (Left>600) && (Mid>600) && (Right<250)) // 1 1 0 ******************
  {
    error= -1; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางขวา ในระดับ -1
  }
  else if( (Left>600) && (Mid<250) && (Right<250)) // 1 0 0  ***************
  {
    error= -2; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางขวา ในระดับ -2
  }
}
  


