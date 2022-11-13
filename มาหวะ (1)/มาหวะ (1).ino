//define motor pin
unsigned long int time1, time2;
#define pwmL 10
#define ML1 8
#define ML2 7
#define pwmR 11
#define RM1 9
#define RM2 12

//define sensor pin
#define LS A0
#define MS A1
#define RS A2
#define LLS A4
#define RRS A3

//motor speed
int spl = 60, spr = 60;

//sensor
int Left, Mid, Right;

//buzzer
#define Buzzer 5

//Error
float Kp = 15, Ki = 0, Kd = 15;
float error, P = 0, PID_value = 0;
float previous_error = 0, previous_I = 0;
int i = 0;

void setup() {
  Serial.begin(9600);
  //start
  Motor(60, 60);
  delay(890);
  Motor(70, 0);
  delay(650);
  Motor(0, 0);

  pinMode(2, OUTPUT);  //LED pin
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, LOW);
}

void loop() {
  run_case(spl, spr);
}



void run_case(int spl, int spr) {



  while (1) {  //white state

    if ((analogRead(LS) < 250) && (analogRead(MS) > 600) && (analogRead(RS) < 250))  //ขาว ดำ ขาว
    {
      Motor(spl, spr);
    } else if ((analogRead(LS) > 600) && (analogRead(RS) < 250))  //turn left
    {
      Motor(15, spr - 5);
    } else if ((analogRead(LS) < 250) && (analogRead(RS) > 600))  //turn right
    {
      Motor(spl, 15);
    } else if ((analogRead(LS) > 600 && analogRead(RS) > 600) && (analogRead(MS) > 600) && i == 0)      //เขตชะลอ
    {
      Motor(27, 27);
      delay(1000);
      spl = 27;
      spr = 27;
      i++;
      break;
    }else if ((analogRead(LS) > 600 && analogRead(RS) > 600) && (analogRead(MS) > 600) && i == 1) 
    {
      spl=60;spr=60;

      Motor(40, 40);
      delay(1500);

      Motor(0, 0);      //บ้าน1
      delay(3400);

      set_mid();

      Motor(40, 40);
      delay(1100);

      digitalWrite(Buzzer, HIGH);       //ทางม้าลาย
      Motor(0, 0);
      delay(3000);
      i++;
    }

    if ((analogRead(LS) > 600) && ((analogRead(MS) > 600)) && (analogRead(RS) > 600) && i == 2) {   //วิ่งถึงทางเบี่ยง
      Motor(40, 40); 
      delay(3300);
      digitalWrite(Buzzer, LOW);
      delay(2000);

      Motor(0, 0);
      delay(1000);
      i++;
    }

    if (i == 3) {     //หมุนหลบทางเบี่ยง
      Motor(-30, 80);
      delay(500);

      Motor(40, 40);
      delay(700);

      while (analogRead(LS) < 200 && analogRead(MS) < 200 && analogRead(RS) < 200) {    
        Motor(70, 70);
      }
      i++;
    }


    if ((analogRead(LLS) > 600) && (analogRead(RRS) > 600)) {  //black state
      digitalWrite(2, HIGH);                                   //turn on LED
      time1 = millis();
      while (i == 4) {
        if ((analogRead(LS) > 600) && (analogRead(MS) < 200) && (analogRead(RS) > 600)) {
          Motor(spl, spr);
        } else if ((analogRead(LS) > 600) && (analogRead(RS) < 250))  //turn right
        {
          Motor(spl, 15);
        } else if ((analogRead(LS) < 200) && (analogRead(RS) > 600)) {  //turn left
          Motor(15, spr);
        } else if ((analogRead(RRS) < 200) && (analogRead(LLS) < 200)) {
          i++;
          digitalWrite(3, LOW);
          break;  //out of blck state
        }
      }


      while (i == 5) {      //white state again
        if ((analogRead(LS) < 250) && (analogRead(MS) > 600) && (analogRead(RS) < 250))  //ขาว ดำ ขาว
        {
          Motor(spl, spr);
        } else if ((analogRead(LS) > 600) && (analogRead(RS) < 250))  //turn left
        {
          Motor(15, spr - 5);
        } else if ((analogRead(LS) < 250) && (analogRead(RS) > 600))  //turn right
        {
          Motor(spl, 15);
        }  //white state again
      }
    }

    // set_mid();

    // Motor(40,40);
    // delay(840);

    // Motor(0,0);
    // delay(1000);

    // Motor(0,70);
    // delay(250);

    // Motor(40,40);
    // delay(300);

    // Motor(70,0);
    // delay(90);

    // Motor(40,40);
    // delay(3333);


    // digitalWrite(LED , HIGH);
    // Motor(40,40);
    // delay(3100);

    // Motor(0,0);
    // delay(1000);

    // Motor(0,70);
    // delay(415);

    // Motor(0,0);
    // delay(5000);

    // Motor(40,40);
    // delay(3990);

    // Motor(0,0);
    // delay(1000);

    // Motor(0,70);
    // delay(850);

    // Motor(0,0);
    // delay(1000);

    // Motor(40,40);
    // delay(2400);

    // Motor(0,0);
    // delay(5000);

    // Motor(40,40);
    // delay(4700);

    // Motor(0,0);
    // delay(1000);

    // Motor(0,70);
    // delay(682);

    // Motor(0,0);
    // delay(1000);

    // Motor(40,40);
    // delay(4300);

    // Motor(0,0);
    // delay(5000);

    // Motor(40,40);
    // delay(3800);

    // Motor(70,0);
    // delay(800);

    // Motor(0,0);
    // delay(5000);


    // Motor(40,40);
    // delay(10000);

    // Motor(0,0);
    // delay(100000000);  //จบที่จุดสตาททท
    // spl = 60;
    // spr = 60;
  }
}



void set_mid() {      
  while (analogRead(LS) < 200 && analogRead(MS) < 200) {
    Motor(-20, 80);
  }
  Motor(-40, -40);
  delay(10);
}



void Motor(int spl, int spr) {
  pinMode(pwmL, OUTPUT);  //pwmL
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);

  pinMode(pwmR, OUTPUT);  //pwmR
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  //spl > 100, spr > 100  limit motor speed for 100
  if (spl > 100)
    spl = 100;
  else if (spr > 100)
    spr = 100;

  //Motor Left
  if (spl > 0) {
    analogWrite(pwmL, ((spl * 255) / 100) + PID_value);
    digitalWrite(ML1, HIGH);
    digitalWrite(ML2, LOW);
  } else if (spl < 0) {
    analogWrite(pwmL, ((-spl * 255) / 100) + PID_value);
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, HIGH);
  } else {
    analogWrite(pwmL, (spl * 255) / 100);  //case for stop motor
    digitalWrite(ML1, LOW);
    digitalWrite(ML2, LOW);
  }

  //Motor Right
  if (spr > 0) {
    analogWrite(pwmR, ((spr * 255) / 100) - PID_value);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  } else if (spl < 0) {
    analogWrite(pwmR, ((-spr * 255) / 100) - PID_value);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  } else {
    analogWrite(pwmR, (spr * 255) / 100);  //case for stor motor
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
}



void Calculate_PID() {
  // คำนวณค่าความคลาดเคลื่อนในการเดินตามเส้น
  P = error;
  PID_value = ((Kp * P) * 255) / 100;
  previous_error = error;

  // Check PID
  Serial.print(PID_value);
  Serial.print(' ');
  Serial.print(previous_I);
  Serial.print(' ');
  Serial.print(previous_error);
  Serial.print(' ');
  Serial.println();
  delay(10);
}



void read_sensor_values() {

  pinMode(LS, INPUT);
  pinMode(MS, INPUT);
  pinMode(RS, INPUT);
  //define senssor
  Left = analogRead(LS);
  Mid = analogRead(MS);
  Right = analogRead(RS);

  //check senssor
  Serial.println(analogRead(LS));
  Serial.println(analogRead(MS));
  Serial.println(analogRead(RS));



  //ในการเคลื่อนที่ เมื่อเซนเซอร์เมื่อ เซนเซอร์ซ้ายขวาจับได้ว่า พบพื้นที่สีดำ เป็น 0 ในค่า digital และ < 350 ใน analog
  // พื้นที่ขาว = 0 (in Digital)   or   (<50 in Analog)
  // พื้นที่ดำ  = 1 (in Digital)   or   (>800 in Analog)
  //Black line
  if ((Left < 250) && (Mid < 250) && (Right >= 600))  // 0 0 1 *****************
  {
    error = 1;                                                // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางซ้าย ในระดับ 2
  } else if ((Left < 250) && (Mid >= 600) && (Right >= 600))  // 0 1 1 *****************
  {
    error = 0.5;                                            // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางซ้าย ในระดับ 1
  } else if ((Left < 250) && (Mid > 600) && (Right < 250))  // 0 1 0 *****************
  {
    error = 0;                                              // เพียงบอกว่า อยู่ในแนวเส้นตรง ในระดับ 0
  } else if ((Left > 600) && (Mid > 600) && (Right < 250))  // 1 1 0 ******************
  {
    error = -0.5;                                           // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางขวา ในระดับ -1
  } else if ((Left > 600) && (Mid < 250) && (Right < 250))  // 1 0 0  ***************
  {
    error = -1;  // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางขวา ในระดับ -2
  }
}