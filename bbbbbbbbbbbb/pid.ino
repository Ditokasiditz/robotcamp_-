void Calculate_PID()
{
  // คำนวณค่าความคลาดเคลื่อนในการเดินตามเส้น
  P= error;
 
  PID_value = ((Kp*P)*255)/100 ;
  
  // Check PID
  // Serial.print(PID_value);
  // Serial.print(' ');
  // Serial.print(previous_I);
  // Serial.print(' ');
  // Serial.print(previous_error);
  // Serial.print(' ');
  // Serial.println();
  delay(10);
  
}