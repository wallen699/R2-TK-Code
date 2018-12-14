void slot_off()
{
    //Clear All pixels
    for (uint16_t ii=0; ii < slot.numPixels(); ii++)
    {
        slot.setPixelColor(ii, 0);        //turn every  pixel off
    }
    //Display
    slot.show();
}

void slot_colour(uint32_t colour)
{
    //Set All pixels
    for (uint16_t ii=0; ii < slot.numPixels(); ii++)
    {
        slot.setPixelColor(ii, colour);        //turn every  pixel off
    }
    //Display
    slot.show();
}

// Fill the dots one after the other with a color
void slot_dot_down(uint32_t c, uint8_t wait)
{
  for(uint16_t i=0; i<slot.numPixels(); i++)
  {
    //Clear All pixels
    slot_off();
    
    //Set Pixel
    slot.setPixelColor(i, c);
    
    //Display
    slot.show();
    
    delay(wait);
  }
}

// Fill the dots one after the other with a color
void slot_dot_up(uint32_t c, uint8_t wait)
{
  for(uint16_t i=slot.numPixels()+1;i>0; i--)
  {
    //Clear All pixels
    slot_off();
    
    //Set Pixel
    slot.setPixelColor(i-1, c);
    
    //Display
    slot.show();
    
    delay(wait);
  }
}
