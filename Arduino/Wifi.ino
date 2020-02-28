

void find_mac() /* Function to find the MAC ID of the Device */
{
   byte mac[13];
   WiFi.macAddress(mac);
   
   mac_id[0] = HexLookup[(mac[0] & 0xf0) >> 4];
   mac_id[1] = HexLookup[(mac[0] & 0x0f)];
   mac_id[2] = HexLookup[(mac[1] & 0xf0) >> 4];
   mac_id[3] = HexLookup[(mac[1] & 0x0f)];
   mac_id[4] = HexLookup[(mac[2] & 0xf0) >> 4];
   mac_id[5] = HexLookup[(mac[2] & 0x0f)];
   mac_id[6] = HexLookup[(mac[3] & 0xf0) >> 4];
   mac_id[7] = HexLookup[(mac[3] & 0x0f)];
   mac_id[8] = HexLookup[(mac[4] & 0xf0) >> 4];
   mac_id[9] = HexLookup[(mac[4] & 0x0f)];
   mac_id[10] = HexLookup[(mac[5] & 0xf0) >> 4];
   mac_id[11] = HexLookup[(mac[5] & 0x0f)];
   
   
   Serial.print("[mac] MAC-ID: ");
    for(byte i=0;i<=11;i++){
      Serial.print(mac_id[i]);
    }
    
    
   String str(mac_id);
   str_mac = str;    
}


void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
