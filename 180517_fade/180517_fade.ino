const int ledPin = 2;
//use to connect with led+ pin
int brightness = 0;
//led brightness, from 0 to 255(min~max)
int addValue=1;
//the value to increase or decrease brightness
//==============above are global variable===============
void setup() {
  //the code in setup() only run once when started
  pinMode(ledPin,OUTPUT);
  //set pin2 as OUTPUT pin
  digitalWrite(ledPin,LOW);
  //set output voltage to 0 at first
  pinMode(LED_BUILTIN,OUTPUT);//built in led on board
  digitalWrite(LED_BUILTIN,LOW);
}
void loop() {
  //the code in loop() run repeatedly
  analogWrite(ledPin,brightness);
  //write value between 0~255 to pin2
  analogWrite(LED_BUILTIN,brightness);
  brightness += addValue;
  //add "addValue" to brightness
  if(brightness >= 70 || brightness <= 0){
    //control brightness between 0-50
    addValue = -addValue;
    //reverse the "addValue" value
  }
  delay(30);
}
