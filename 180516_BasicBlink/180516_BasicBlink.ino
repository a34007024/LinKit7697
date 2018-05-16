const int ledPin=2;//外接LED Pin腳
void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);//內建LED
  digitalWrite(ledPin,LOW);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  digitalWrite(ledPin,HIGH);
  delay(250);
  digitalWrite(ledPin,LOW);
  delay(250);
  for(int i=0;i<10;i++){
    digitalWrite(LED_BUILTIN,HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN,LOW);
    delay(50);
  }
}
