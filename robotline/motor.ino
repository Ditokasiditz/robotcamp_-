void Motor(int spl,int spr)
{
  #define pwmL 10
  #define ML1 7
  #define ML2 8
  #define pwmR 11
  #define RM1 9
  #define RM2 12

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