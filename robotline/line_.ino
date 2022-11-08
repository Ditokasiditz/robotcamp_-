void FF(int spl, int spr)
{
  while(1)
  {
  if((analogRead(LS)<50) && (analogRead(RS)<50) && (analogRead(MS)>800) )
  {
    Motor(spl,spr);
  }
  else if ( (analogRead(LS)>800) && (analogRead(RS)<50) )   //turn left
  {
    Motor(0,spr);
  }
  else if ((analogRead(LS)<50) && (analogRead(RS)>800) )    //turn right
  {
    Motor(spl,0);
  }
  else if ((analogRead(LS)>800) && (analogRead(RS)>800) && (analogRead(MS)>800) )
    {
     Motor(0,0);
     delay(5000);
     break;
    }
    
    
  }
  Motor(0,0);
  delay(10);
}