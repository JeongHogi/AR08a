/*
 예제 6.6
 소리 입력 
 */

// A0번 핀에서 사운드 입력을 받는다
char soundInputPin = 0;

// 그래프 바 LED 출력핀을 level 변수에 저장

 
void setup() {
  // 그래프 바 LED 핀을 출력으로 설정  
  for(int i=0 ; i<=7 ; i++){
    pinMode(ledLevel[i],OUTPUT);
  }
}

void loop(){
 
  // A0번 핀에서 사운드 입력을 받는다
  int soundInput = analogRead(soundInputPin);
  // 노이즈부분을 제외한 50~900의 범위로 입력받은 사운드 크기를 
  // 0~7단계로 변경한다.
  int soundLevel = 


  // 전체 LED를 소등한다.




  // 0~7 단계 중 입력보다 작은 레벨의 LED는 점등한다.



  
}
