#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // RESERVED MAC ADDRESS
EthernetClient client;


void setup() {

 // Open serial communications and wait for port to open:

  Serial.begin(9600);

  // start the Ethernet connection:
  Serial.println("connecting...");

    

}
  

void loop(){
if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    }
  delay(10);
   if (client.available()) {

    char c = client.read();

    Serial.print(c);

  }
  
  if (client.connect("localhost",3000)) { // REPLACE WITH YOUR SERVER ADDRESS
    client.println("POST /kameratest/post.php  HTTP/1.1");//REPLACE WITH YOUR URLS
    client.println("Host: http://localhost");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println("Connection:close");
    client.print("Content-Length:");
    client.println();
    
    client.flush();
    client.stop();
    }else {

    // kf you didn't get a connection to the server:

    Serial.println("connection failed");

  }
    
    delay(60000); // WAIT FIVE MINUTES BEFORE SENDING AGAIN

  // if there are incoming bytes available 

  // from the server, read them and print them:

 

  // if the server's disconnected, stop the client:

  if (!client.connected()) {

    Serial.println();

    Serial.println("disconnecting.");

    client.stop();

    // do nothing forevermore:

    while(true);

  }
}
