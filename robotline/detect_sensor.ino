void Detect_ss()
{
  pinMode(LS,INPUT);
  pinMode(MS,INPUT);
  pinMode(RS,INPUT);

  Serial.print("L:");
  Serial.print(analogRead(LS));
  Serial.print("  ");
  
  Serial.print("M:");
  Serial.print(analogRead(MS));
  Serial.print("  ");
  
  Serial.print("R:");
  Serial.println(analogRead(RS));
  Serial.print("  ");
  
}
