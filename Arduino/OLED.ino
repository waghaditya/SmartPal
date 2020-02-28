void oled_setup()
{
  oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
  oled.setTextColor(WHITE);
  oled.clearDisplay();
}


void print_oled(String txt,int textsize=2)
{
  
  oled.writeFillRect(0,50,128,16,BLACK);
  oled.setCursor(0,50);
  oled.setTextSize(textsize);
  oled.print(txt);
  oled.display();
}

void printline_oled(int val)
{
  if(lasta>127){
    lasta=0;
    oled.clearDisplay();
  }
  
  int b=60-(val/16);  
  oled.writeLine(lasta,lastb,lasta++,b,WHITE);
  oled.display();
  lastb=b;
  }
