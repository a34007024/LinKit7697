/*
 * 以下是針對各型態的變數在Arduino裡的位元數說明
int:
https://www.arduino.cc/reference/en/language/variables/data-types/int/
long:
https://www.arduino.cc/reference/en/language/variables/data-types/long/
unsigned int:
https://www.arduino.cc/reference/en/language/variables/data-types/unsignedint/
unsigned long:
https://www.arduino.cc/reference/en/language/variables/data-types/unsignedlong/
*/
const int ledPin=2;//外接LED Pin腳
const long timerDelay = 1000;//每1000ms改變LED狀態
int ledState = LOW;//儲存LED目前狀態
unsigned long previousTime = 0;//用來保存前一次LED狀態更新的時刻點
//使用long是為了儲存比int長的整數
//對Arduino來講long可儲存(-2^31-1 ~ 2^31-1) int為(-2^15-1 ~ 2^15-1)

void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);//內建LED
  digitalWrite(ledPin,LOW);
  digitalWrite(LED_BUILTIN,LOW);
}
void loop() {
  unsigned long currentTime = millis();
  digitalWrite(ledPin,ledState);
  digitalWrite(LED_BUILTIN,ledState);
  if(currentTime - previousTime >= timerDelay){
    if(ledState == LOW){
      ledState = HIGH;
    }//轉換LED狀態
    else ledState = LOW;
    //轉換LED狀態
    previousTime = currentTime;
  }
}


