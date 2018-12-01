void FrontSpinner()
{
  uint16_t static pointer;

  if (pointer >= 15)
  {
    pointer=0;
  }
  else
  {
    pointer=pointer+1;
  }


    //Clear All pixels
    for (uint16_t ii=0; ii < 16; ii++)
    {
        frontspin.setPixelColor(ii, 0);        //turn every  pixel off
    }
    
    //Set Pixel
    frontspin.setPixelColor(pointer, frontspin.Color(0, 255, 0,0));
    
    //Display
    frontspin.show();
    
}

void RearSpinner()
{
  uint16_t static pointer;

  if (pointer >= 15)
  {
    pointer=0;
  }
  else
  {
    pointer=pointer+1;
  }


    //Clear All pixels
    for (uint16_t ii=0; ii < 16; ii++)
    {
        rearspin.setPixelColor(ii, 0);        //turn every  pixel off
    }
    
    //Set Pixel
    rearspin.setPixelColor(pointer, rearspin.Color(0, 255, 0,0));
    
    //Display
    rearspin.show();
    
}
