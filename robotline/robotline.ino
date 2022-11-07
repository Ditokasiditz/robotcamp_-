
void setup() {
  Serial.begin(9600);
}

void loop() 
{
  Serial.print("Left 2 :");
  Serial.print(analogRead(2))
  Serial.print("Left 3 :");
  Serial.print(analogRead(3))
  Serial.print("Mid 4 :");
  Serial.print(analogRead(4))
  Serial.print("Right 5 :");
  Serial.print(analogRead(5))
  Serial.print("Right 6 :");
  Serial.println(analogRead(6))
}




