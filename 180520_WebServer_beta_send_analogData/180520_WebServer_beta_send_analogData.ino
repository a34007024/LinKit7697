//參考Linkit7697的範例WiFiWebServer
//WiFiWebServer把Linkit做為一個小型的伺服器使用
#include <LWiFi.h>
const char* ssid = "Linkit7697";//network SSID
const char* password = "homecaresystem";//network password
int keyIndex = 0;//network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS;
WiFiServer server(80);
WiFiClient client = server.available();
const int ledPin = 2;
int ledState = LOW;
void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;//等待與電腦USB port通訊
  }
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,ledState);
  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);
  while (status != WL_CONNECTED) {
    Serial.print(".");
    status = WiFi.begin(ssid, password);
    //Try to connect to WPA/WPA2 network.
  }
  server.begin();
  // you're connected now, so print out the status:
  printWifiStatus();
}

void loop() {
  client = server.available();// listen for incoming clients
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();//讀取客戶端的資訊
        String request = String(c);
        Serial.write(c);//把讀進來的客戶端資訊寫出來
        // if you've gotten to the end of the line
        //(received a newlinecharacter)
        //and the line is blank, the http request has ended,
        // so you can send a reply(send HTML to client)
        if (c == '\n' && currentLineIsBlank) {
          Serial.write("End of the data that client sended\n");
          Serial.write("===============================\n");
          sendHTMLheader();
          sendHTML();
          break;
        }
        if(request.indexOf("/ledChange") != -1){
          if(ledState == LOW) ledState = HIGH;
          else ledState = LOW;
          digitalWrite(ledPin,ledState);
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}
