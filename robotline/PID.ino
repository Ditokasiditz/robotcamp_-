float Kp=30,Ki=0,Kd=15;
float error=0, P=0, I=0, D=0, PID_value=0;
float previous_error=0,previous_I=0;

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
  delay(10);
  
}
  