
#include "Wifi.h"
#include <PubSubClient.h>

const char* mqtt_server = "smartpal.local";
int mqtt_port = 1883;
PubSubClient client(espClient);
void callback(char*, byte*, unsigned int);
void reconnect() ;
void setup_mqtt();
void mqtt_send(String);
void mqtt_check_connection();
