/*
 예제 5.1
 스위치 입력
*/

// 내장된 LED를 사용하기 위해
// LED pin을 13번으로 설정
const int ledPin = 13;   
// 2번 핀을 스위치 입력으로 설정
const int inputPin = 2;

int count = 0;

void setup() {
  // Arduino 13번 핀에 내장된 LED를 출력으로 설정한다.  
  pinMode(ledPin, OUTPUT);
  // 스위치 입력을 위하여 2번핀을 입력으로 설정하고 풀업시킨다.
  pinMode(inputPin, INPUT_PULLUP );

  Serial.begin(9600);
}

void loop(){
  delay(100);
  // 스위치 입력을 받는다
  int swInput = digitalRead(inputPin);
  int ledOutput = digitalRead(ledPin);
  
  if(swInput == LOW){
    if(ledOutput) digitalWrite(ledPin, LOW);
    else digitalWrite(ledPin, HIGH);
    ++count;
    Serial.println(count);
  }; // LED 점등
  // LED 소등
}   
    
