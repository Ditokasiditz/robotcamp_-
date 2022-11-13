void run_case(int spl, int spr)
{
  while(state == "black")
  {
  read_sensor_values();
  Calculate_PID();
  light();
              if((analogRead(LS)<250) &&  (analogRead(MS)>600)  && (analogRead(RS)<250) )  //ขาว ดำ ขาว
              {
                Motor(spl,spr);
              }
              else if ( (analogRead(LS)>600) && (analogRead(RS)<250) )   //turn left
              {
                Motor(15,spr);
              }
              else if ((analogRead(LS)<250) && (analogRead(RS)>600) )    //turn right
              {
                Motor(spl+10,15);
              }
              else if ( (analogRead(LS) > 600)  && ((analogRead(MS)< 250)) && (analogRead(RS) > 600) && i==3) //
              {  
                Motor(spl,spr);
                            

              }
              else if (((analogRead(MS) >600 )) && (analogRead(LS) >600) && i==5)
              {
                PID_value=0;
                Motor(70,70);
                delay(1000);

                Motor(0,0);
                delay(3100);
            
                Motor(-70,-70);
                delay(1000);

                Motor(-50,50);
                delay(1400);

                spl=70;
                spr=70;
              }
              else if ( (analogRead(LS) > 600)  && ((analogRead(MS)< 250)) && (analogRead(RS) > 600)  && i==5) //
              {  
                  state="white";
                  Motor(spl,spr);  
                  i++;  
                
              }
   }
   // White line
  while (state=="white")
  
  {
  read_sensor_values();
  Calculate_PID();
  light();
              if ( (analogRead(LS) > 600)  && ((analogRead(MS)< 250)) && (analogRead(RS) > 600) ) //
              {  
                  Motor(spl,spr);    
                
              }
              else if ((analogRead(LS)<250) && (analogRead(MS)<250) && i==3)
              {
              PID_value=0;
              Motor(4,50);
              delay(1200); 
              Motor(0,0);
              delay(3100);
              
            
              i++;
              }

              else if ( (analogRead(LS)< 250) && (analogRead(RS) > 600)  )   //turn left
              {
                Motor(20,spr);
              }
              
              else if ((analogRead(LS) > 600) && (analogRead(RS)< 250) )    //turn right
              {
                Motor(spl,20);
              }
              
              // else if ((analogRead(LS)<250) && (analogRead(MS)<250) && i==4)
              // {
              //   PID_value=0;
              //   Motor(0,0);
              //   delay(500);
              //   Motor(50,50);
              //   delay(1000);
              //   Motor(-50,50);
              //   delay(800);
              // }
              else if ((analogRead(LS)<250) && (analogRead(MS)>600) && (analogRead(RS)<250))
              {
                Motor(0,0);
                delay(1000);
                state="black";
                i++;
              }
              else if ((analogRead(LS)<250) && (analogRead(MS)<250) && i==6)
            {
                Motor(50,50);
                delay(1000);
                Motor(-50,50);
                delay(500);
                Motor(0,0);
            }
  }
}