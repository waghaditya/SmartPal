#include <ESP8266WiFi.h>

const char* ssid = "JioFi3_584096";
const char* password = "90scsxun6b";

const char HexLookup[17] = "0123456789ABCDEF";
char mac_id[13]="000000000000";
String str_mac="";

WiFiClient espClient;

void find_mac();
void setup_wifi();
