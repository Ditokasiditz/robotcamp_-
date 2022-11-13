void read_sensor_values()
{

  pinMode(LS,INPUT);
  pinMode(MS,INPUT);
  pinMode(RS,INPUT);
  //define senssor
  Left=analogRead(LS);
  Mid=analogRead(MS);
  Right=analogRead(RS);
  
  //check senssor
      Serial.println(analogRead(LS));
      Serial.println(analogRead(MS));
      Serial.println(analogRead(RS));
     


  //ในการเคลื่อนที่ เมื่อเซนเซอร์เมื่อ เซนเซอร์ซ้ายขวาจับได้ว่า พบพื้นที่สีดำ เป็น 0 ในค่า digital และ < 350 ใน analog
  // พื้นที่ขาว = 0 (in Digital)   or   (<50 in Analog)
  // พื้นที่ดำ  = 1 (in Digital)   or   (>800 in Analog)
  //Black line
  if(state=="black")
  {
        if( (Left <250 ) && (Mid < 250) && (Right >=600 )) // 0 0 1 *****************
        {
          error= 2; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางซ้าย ในระดับ 2 
        }
        else if( (Left<250) && (Mid>=600) && (Right>=600)) // 0 1 1 *****************
        {
          error= 1; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางซ้าย ในระดับ 1
        }
        else if( (Left<250 ) && (Mid>600) && (Right<250)) // 0 1 0 *****************
        {
          error= 0; // เพียงบอกว่า อยู่ในแนวเส้นตรง ในระดับ 0
        }
        else if( (Left>600) && (Mid>600) && (Right<250)) // 1 1 0 ******************
        {
          error= -1; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางขวา ในระดับ -1
        }
        else if( (Left>600) && (Mid<250) && (Right<250)) // 1 0 0  ***************
        {
          error= -2; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางขวา ในระดับ -2
        }
  }
  else if (state=="white")
  {
    if( (Left <250 ) && (Mid < 250) && (Right >=600 )) // 0 0 1 *****************
        {
          error= 2; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางซ้าย ในระดับ 2 
        }
        else if( (Left<250) && (Mid>=600) && (Right>=600)) // 0 1 1 *****************
        {
          error= 1; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางซ้าย ในระดับ 1
        }
        else if( (Left<250 ) && (Mid>600) && (Right<250)) // 0 1 0 *****************
        {
          error= 0; // เพียงบอกว่า อยู่ในแนวเส้นตรง ในระดับ 0
        }
        else if( (Left>600) && (Mid>600) && (Right<250)) // 1 1 0 ******************
        {
          error= -1; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางขวา ในระดับ -1
        }
        else if( (Left>600) && (Mid<250) && (Right<250)) // 1 0 0  ***************
        {
          error= -2; // เพียงบอกว่า หุ่นเอียงไปจากเเนวเส้นไปทางขวา ในระดับ -2
        }
  } 
}