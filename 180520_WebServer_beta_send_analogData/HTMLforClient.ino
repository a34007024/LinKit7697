void sendHTMLheader(){
  // send a standard http response header
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");  // the connection will be closed after completion of the response
  client.println("Refresh: 1");  // refresh the page automatically every 1 sec
  client.println();
  client.println("<!DOCTYPE HTML>");
}

void sendHTML(){
  client.println("<html>");
  // output the value of each analog input pin
  for(int analogChannel = A0; analogChannel <= A3; analogChannel++) {
    int sensorReading = analogRead(analogChannel);
    client.print("analog input ");
    client.print(analogChannel);
    client.print(" is ");
    client.print(sensorReading);
    client.println("<br />");     
  }
  client.println("<a href=\"/ledChange\"\"><input type=\"button\" value=\"Button\" style=\"width:120px;height:40px;font-size:20px;\">");
  //send a button to Control LED
  client.println("</html>");//HTML結尾
}
