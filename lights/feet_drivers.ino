/*void left()
{
  uint16_t static pointer;

  if (pointer >= 12)
  {
    pointer=3;
  }
  else
  {
    pointer=pointer+1;
  }


    //Clear All pixels
    for (uint16_t ii=0; ii < 55; ii++)
    {
        left.setPixelColor(ii, 0);        //turn every  pixel off
    }
    
    //Set Pixel
    //Front
    left.setPixelColor(pointer, frontspin.Color(0,0 , 255));
    //Rearleft.setPixelColor(pointer+29, frontspin.Color(0,0 , 255));
    
    //Display
    left.show();
    
}*/

void LeftGlow(uint32_t foot_colour)
{
    //Clear All pixels
    for (uint16_t ii=0; ii < 55; ii++)
    {
        //left.setPixelColor(ii, 0);        //turn every  pixel off
        leftleg.setPixelColor(ii, foot_colour);

    }
    
    leftleg.show();
    
}
/*
void right()
{
  uint16_t static pointer;

  if (pointer >= 12)
  {
    pointer=3;
  }
  else
  {
    pointer=pointer+1;
  }


    //Clear All pixels
    for (uint16_t ii=0; ii < 55; ii++)
    {
        right.setPixelColor(ii, 0);        //turn every  pixel off
    }
    
    //Set Pixel
    //Front
    right.setPixelColor(pointer, frontspin.Color(0,0 , 255));
    //Rearleft.setPixelColor(pointer+29, frontspin.Color(0,0 , 255));
    
    //Display
    right.show();
    
}
*/
void RightGlow(uint32_t foot_colour)
{
    //Clear All pixels
    for (uint16_t ii=0; ii < 55; ii++)
    {
        //left.setPixelColor(ii, 0);        //turn every  pixel off
        rightleg.setPixelColor(ii, foot_colour);

    }
    
    rightleg.show();
    
}

void CenterGlow(uint32_t foot_colour)
{
    //Clear All pixels
    for (uint16_t ii=0; ii < 44; ii++)
    {
        //left.setPixelColor(ii, 0);        //turn every  pixel off
        centerleg.setPixelColor(ii, foot_colour);

    }
    
    centerleg.show();
    
}
