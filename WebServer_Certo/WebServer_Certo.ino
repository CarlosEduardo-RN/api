#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT22  
#define DHTPIN 4   

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(10, 61, 0, 98);

EthernetServer server(80);  
                      
DHT dht(DHTPIN, DHTTYPE); 

uint32_t delayMS;  

void setup() {

  dht.begin();;
  Serial.begin(9600);
  Serial.println("Ethernet WebServer Example");
  Serial.println("Lendo dados do sensor...");

  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();
  Serial.print(temp);
  Serial.print("    ");
  Serial.println(umid);
  
  StaticJsonBuffer<500> jsonBuffer;

  JsonObject& root = jsonBuffer.createObject();

  JsonArray& analogValues = root.createNestedArray("temperatura");

    analogValues.add(temp);

  

  EthernetClient client = server.available();
  if (client) 
  {
    boolean currentLineIsBlank = true;
    while (client.connected()) 
    {
      if (client.available()) 
      {
        char c = client.read();

        if (c == '\n' && currentLineIsBlank)
        {

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: application/json");
          client.println("Connection: *"); 
          client.println("Access-Control-Allow-Origin: *");
          client.println("Refresh: 15");  
          client.println();
          root.prettyPrintTo(client);
          break;
        }
        if (c == '\n') 
        {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') 
        {
          currentLineIsBlank = false;
        }
      }
    }

    delay(1);
    client.stop();
  }
}
