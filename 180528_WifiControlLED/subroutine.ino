void HTML_for_client(){
  client.println("HTTP/1.1 200 OK");//丟給客戶端的網頁回應檔頭
  client.println("Content-type:text/html");//丟給客戶端的網頁回應檔頭
  client.println();//檔頭結尾，以新的一行做結束
  //以下對客戶端丟HTML語法，讓其顯示在瀏覽器上
  client.print("Click <a href=\"/H_builtIn\">here</a>to turn the BUILTIN_LED on<br>");
  client.print("Click <a href=\"/L_builtIn\">here</a>to turn the BUILTIN_LED off<br>");
  client.print("<br>");
  client.print("<a href=\"/H_Pin2\">Turn the Pin2 LED On</a><br>");
  client.print("<a href=\"/L_Pin2\">Turn the Pin2 LED Off</a><br>");
  client.print("<br><br><br>");
  client.print("<a href=\"/H_Pin5\">Pin5 LED On</a><br>");
  client.print("<a href=\"/L_Pin5\">Pin5 LED Off</a><br>");
  // The HTTP response ends with another blank line:
  client.println();
}

void printWifiStatus() {//輸出詳細連線資訊
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());//輸出網路名稱
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);//輸出主機的IP位址
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);//輸出連線訊號強度
  Serial.println(" dBm");
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);//提示可以利用瀏覽器輸入IP訪問主機
}
