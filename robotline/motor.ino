void Motor(int spl,int spr)
{
  pinMode(10,OUTPUT);//pwmL
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
 
  pinMode(11,OUTPUT);//pwmR
  pinMode(9,OUTPUT);
  pinMode(12,OUTPUT);
  //spl > 100, spr > 100  limit motor speed for 100
  if (spl>100)
  spl=100;
  else if (spr>100)
  spr=100;
  //Motor Left
  if(spl>0)
  {
    analogWrite(10,(spl*255)/100);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
  }
  else if (spl<0)
  {
    analogWrite(10,(-spl*255)/100);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
  }
  else
  {
    analogWrite(10,(spl*255)/100);    //case for stop motor
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }

  //Motor Right
  if(spr>0)
  {
    analogWrite(11,(spr*255)/100);
    digitalWrite(9,HIGH);
    digitalWrite(12,LOW);
  }
  else if (spl<0)
  {
    analogWrite(11,(-spr*255)/100);
    digitalWrite(9,LOW);
    digitalWrite(12,HIGH);
  }
  else
  {
    analogWrite(11,(spr*255)/100);    //case for stor motor
    digitalWrite(9,LOW);
    digitalWrite(12,LOW);
  }
}