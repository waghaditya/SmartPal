
char* string2char(String command){
    if(command.length()!=0){
        char *p = const_cast<char*>(command.c_str());
        return p;
    }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

// if(String(topic) == str_mac){
//    // Switch on the LED if an 1 was received as first character
//    if ((char)payload[0] == '1') {
//      digitalWrite(RELAY, LOW);   // Turn the LED on (Note that LOW is the voltage level
//      // but actually the LED is on; this is because
//      // it is active low on the ESP-01)
//      stat = 1;
//    } 
//    else if((char)payload[0] =='0') {
//      stat = 0;
//      digitalWrite(RELAY, HIGH);  // Turn the LED off by making the voltage HIGH
//    }
// }
}


void setup_mqtt(){
     find_mac();
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe(string2char(str_mac));
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void mqtt_check_connection(){
  
    if (!client.connected()) {
      reconnect();
    }
    client.loop();
}



void mqtt_send(String topic,String msg){    
    client.publish(string2char(topic),string2char(msg));
}
