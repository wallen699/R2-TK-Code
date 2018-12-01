



void vents_colour(uint32_t tcolour,uint32_t bcolour)
{
   vents.setPixelColor(0, tcolour);
    vents.setPixelColor(1, bcolour);
   
    //Display
    vents.show();
}


void vents_off()
{
       
   vents.setPixelColor(0, 0);
    vents.setPixelColor(1, 0);
   
    //Display
    vents.show();
}

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
  uint16_t static slot_pointer;

  slot_off();
  
  if (slot_pointer >= 6)
  {
    slot_pointer=0;
  }
  else
  {
    slot_pointer=slot_pointer+1;
  }
    
  //Set Pixel
    slot.setPixelColor(slot_pointer, c);
    
    //Display
    slot.show();    
}

// Fill the dots one after the other with a color
void slot_dot_up(uint32_t c, uint8_t wait)
{
  uint16_t static slot_pointer;

  slot_off();
  
  if (slot_pointer==0)
  {
    slot_pointer=5;
  }
  else
  {
    slot_pointer=slot_pointer-1;
  }
  
  //Set Pixel
  slot.setPixelColor(slot_pointer, c);
    
  //Display
  slot.show();
    
}

// Fill the dots one after the other with a color
void slot_dot_bounce(uint32_t c, uint8_t wait)
{
  int static slot_pointer=0;
  int static slot_dir=1;
  int static delay_counter=1;
  
  delay_counter=delay_counter+1;

  if (delay_counter>=wait)
  {
    delay_counter=1;
  
  slot_off();
  
  if (slot_pointer<0 || slot_pointer>5)
  {
      Serial.println("Limit");
    if (slot_dir==-1)
      slot_dir=1;
    else
    slot_dir=-1;
    
  }

  Serial.println(slot_pointer);
  //Serial.println(slot_dir);

  slot_pointer=slot_pointer+slot_dir;
  
  //Set Pixel
  slot.setPixelColor(slot_pointer, c);
    
  //Display
  slot.show();
  }  
}
