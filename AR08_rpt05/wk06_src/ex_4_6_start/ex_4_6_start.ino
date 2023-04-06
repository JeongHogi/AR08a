/*
 예제 4.6
 8x8 Dot matrix 제어
*/

const int colPins[] = { 2, 3, 4, 5, 6, 7, 8, 9};
//                   C8, C7, C6, C5, C4, C3, C2, C1
const int rowPins[] = { 10,11,12,15,16,17,18,19};
//                   R8, R7, R6, R5, R4, R3, R2, R1

void setup() {
  for (int i = 0; i < 8; i++)
  {
    // 행을 출력으로 설정한다
    pinMode(colPins[i], OUTPUT);
    // 열을 출력으로 설정한다
    pinMode(rowPins[i], OUTPUT);
  }
}

void loop() {
 
  for (int column = 0; column < 8; column++)
  {
    // 행을 모두 초기화 한다 
    colClear();                          
    // 현재의 행만 켠다
    digitalWrite(colPins[column], LOW);

    for(int row = 0; row < 8; row++)
    {
      // 열을 하나씩 켠다
      digitalWrite(rowPins[row], HIGH);  
      delay(100);     
    }
    // 열을 모두 초기화 한다
    rowClear();       
  }
  // 모든 행을 반복했으면 열을 모두 소등한다
  rowClear();
}

// 행을 모두 초기화하는 루틴
void colClear(){               
  for(int i = 0; i < 8; i++){
    digitalWrite(colPins[i], HIGH); 
  }
}

// 열을 모두 초기화하는 루틴
void rowClear(){   
  for(int i = 0; i < 8; i++){
    digitalWrite(rowPins[i], LOW); 
  }  
}  
    
