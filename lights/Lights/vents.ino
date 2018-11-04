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
