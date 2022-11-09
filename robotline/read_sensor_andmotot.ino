// void read_sensor_values()
// {
//   sensor[0=digitalRead(A0);
//   sensor[1]=digitalRead(A1);
//   sensor[2]=digitalRead(A2);
//   sensor[3]=digitalRead(A3);
//   sensor[4]=digitalRead(A4);

//   if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==1))
//   error=4;
//   else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==1))
//   error=3;
//   else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==1)&&(sensor[4]==0))
//   error=2;
//   else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==1)&&(sensor[4]==0))
//   error=1;
//   else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
//   error=0;
//   else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3]==0)&&(sensor[4]==0))
//   error=-1;
//   else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
//   error=-2;
//   else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
//   error=-3;
//   else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
//   error=-4;
//   else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[3]==0)&&(sensor[4]==0))
//     if(error==-4) error=-5;
//     else error=5;

// }