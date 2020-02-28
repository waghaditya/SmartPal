#include <Adafruit_SSD1306.h>
#define OLED_Address 0x3C // 0x3C device address of I2C OLED. Few other OLED has 0x3D
Adafruit_SSD1306 oled(128, 64); // create our screen object setting resolution to 128x64

int lasta=0;
int lastb=0;

void oled_setup();
void print_oled(String,int);
void printline_oled(int);
