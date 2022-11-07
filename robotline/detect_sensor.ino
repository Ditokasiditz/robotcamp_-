void Detect_ss()
{
  #define LS A1
  #define MS A2
  #define RS A3
  pinMode(LS,INPUT);
  pinMode(MS,INPUT);
  pinMode(RS,INPUT);
  Serial.print("Left_sensor:");
  Serial.print(analogRead(LS));
  
  Serial.print("Mid_sensor:");
  Serial.print(analogRead(MS));
  
  Serial.print("Right_sensor:");
  Serial.println(analogRead(RS));
}
