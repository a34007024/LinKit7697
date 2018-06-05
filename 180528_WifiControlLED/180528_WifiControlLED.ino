//改寫自範本SimpleWebServerWiFi

#include <LWiFi.h>
const char ssid[] = "Linkit7697";//網路名稱(SSID)
const char pass[] = "homecaresystem";//網路密碼
int keyIndex = 0;//network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS;
WiFiServer server(80);
WiFiClient client;//宣告名為client的客戶端
void setup() {
  Serial.begin(9600);//開啟與電腦USB Port通訊橋梁
  pinMode(LED_BUILTIN, OUTPUT);// set the LED pin mode
  pinMode(2,OUTPUT);//2號腳也作為輸出腳
  pinMode(5,OUTPUT);//5號腳也作為輸出腳
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);// print the network name (SSID);
    status = WiFi.begin(ssid, pass);//連線至Wifi網路
  }
  server.begin();     // start the web server on port 80
  printWifiStatus();  // 成功連線，輸出連線資訊
}

void loop() {
  client = server.available();//等待客戶端進來存取資料
  if (client) {                             // if you get a client,
    Serial.println("new client");            // print a message out the serial port
    String currentLine = "";                //宣告新字串來儲存客戶端丟進來的資料
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                     // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          //如果連續收到兩行空白行，表示客戶端丟完資料了，可以對客戶端做出回應(丟資料給它)
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            HTML_for_client();//呼叫丟HTML語法的副程式
            break;// break out of the while loop:
          } 
          else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // 根據客戶端回傳的request來更改LED燈狀態
        if (currentLine.startsWith("GET /H_builtIn"))
          digitalWrite(LED_BUILTIN, HIGH);//點亮內建LED燈
        if (currentLine.startsWith("GET /L_builtIn"))
          digitalWrite(LED_BUILTIN, LOW); //熄滅內建LED燈
        if (currentLine.startsWith("GET /H_Pin2"))
          digitalWrite(2,HIGH);           //2號腳輸出高電位
        if (currentLine.startsWith("GET /L_Pin2"))
          digitalWrite(2,LOW);            //2號腳輸出低電位
        if (currentLine.startsWith("GET /H_Pin5"))
          digitalWrite(5,HIGH);           //5號腳輸出高電位
        if (currentLine.startsWith("GET /L_Pin5"))
          digitalWrite(5,LOW);            //5號腳輸出低電位
      }
    }
    client.stop();//中斷連線
    Serial.println("client disonnected");
  }
}


