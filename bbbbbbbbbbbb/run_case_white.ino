void run_case_white()
{
if((analogRead(LS)<250) &&  (analogRead(MS)>600)  && (analogRead(RS)<250) )  //ขาว ดำ ขาว
              {
                Motor(spl,spr);
              }
              else if ((analogRead(LS) > 600)  && (analogRead(MS)> 600) && (analogRead(RS) > 600) && i==0)
              {
                Motor(spl,spr);
                delay(60);
                i=1;
              }
              else if ((analogRead(LS) > 600)  && (analogRead(MS)> 600) && (analogRead(RS) > 600) && i==1)
              {
                Motor(spl,0);
                delay(500);
                Motor()
                
                i=2;
              }
              
              else if ( (analogRead(LS) > 600)  && ((analogRead(MS)< 250)) && (analogRead(RS) > 600) && i==3) //
              {  
                  state="white";
                  Motor(spl,spr);    
              }
              else if (((analogRead(MS) >600 )) && (analogRead(LS) >600) && i==5)
              {
                PID_value=0;
                

                spl=70;
                spr=70;
              }
              else if ( (analogRead(LS) > 600)  && ((analogRead(MS)< 250)) && (analogRead(RS) > 600)  && i==5) //
              {  
                  state="white";
                  Motor(spl,spr);  
                  i++;  
                
              }
              // else if ( (analogRead(LS)>600) && (analogRead(RS)<250) )   //turn left
              // {
              //   Motor(15,spr);
              // }
              // else if ((analogRead(LS)<250) && (analogRead(RS)>600) )    //turn right
              // {
              //   Motor(spl+10,15);
              // }
}