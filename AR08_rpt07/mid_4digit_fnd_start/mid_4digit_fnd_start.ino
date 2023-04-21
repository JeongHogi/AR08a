// pin no. connected to segment
int segpin[8] = {2,3,4,5,6,7,8,9 }; 
//               a, b, c, d, e, f, g, h

// pin no. connected to digit
int dpin[4] = {10, 11, 12, 13};
//       pin   d1, d2, d3, d4

//          segment        a, b, c, d, e, f, g, h   number
const int arr[10][8] = {  {1, 1, 1, 1, 1, 1, 0, 0},   //0
                          {0, 1, 1, 0, 0, 0, 0, 0},   //1
                          {1, 1, 0, 1, 1, 0, 1, 0},   //2
                          {1, 1, 1, 1, 0, 0, 1, 0},   //3
                          {0, 1, 1, 0, 0, 1, 1, 0},   //4
                          {1, 0, 1, 1, 0, 1, 1, 0},   //5
                          {1, 0, 1, 1, 1, 1, 1, 0},   //6
                          {1, 1, 1, 0, 0, 0, 0, 0},   //7
                          {1, 1, 1, 1, 1, 1, 1, 0},   //8
                          {1, 1, 1, 1, 0, 1, 1, 0}    //9
                  };

int timer=200;

void setup() 
{                
  Serial.begin(9600);     // baud rate = 9600
  
  for (int i=0; i<=7; i++)
  { pinMode(segpin[i], OUTPUT); }
  
  for(int j=0;j<4;j++)
  { pinMode(dpin[j], OUTPUT); }
}

void loop()
{
  Serial.print("전송할 4 자리 정수를 입력: ");
  
  while(Serial.available()==0) { }  //
  
  int num = (Serial.parseInt());  //
  if(num>0){
    Serial.println(num); // 입력 숫자 출력    
    int d0 = num % 10 ;  //         //digit at ones place
    int d1 = (num % 100) / 10 ;     //digit at tens place
    int d2 = (num % 1000) / 100;    //digit at hundreds place
    int d3 = num % 1000 ;   //       //digit at thousands place
  
    for(int k=0; k<timer; k++)
    {
      digitalWrite(dpin[0], LOW);
      digitalWrite(dpin[1], HIGH);
      digitalWrite(dpin[2], HIGH);
      digitalWrite(dpin[3], HIGH);    
      for (int i= 0 ; i<=7 ; i++)  
      { 
        digitalWrite(segpin[i], arr[d3][i]); 
      }        
      delay(5);
    
      digitalWrite(dpin[0],HIGH );  //
      digitalWrite(dpin[1],LOW );  //
      digitalWrite(dpin[2], HIGH);
      digitalWrite(dpin[3], HIGH);    
      for (int i= 0 ; i<=7 ; i++)  
      { 
        digitalWrite(segpin[i], arr[d2][i]); 
      }
      delay(5);
    
      digitalWrite(dpin[0], HIGH);
      digitalWrite(dpin[1], HIGH);
      digitalWrite(dpin[2],LOW );  //
      digitalWrite(dpin[3],HIGH );  //              
      for (int i= 0 ; i<=7 ; i++)  
      { 
        digitalWrite(segpin[i], arr[d1][i]); 
      }
      delay(5); 
    
      digitalWrite(dpin[0], HIGH);
      digitalWrite(dpin[1], HIGH);
      digitalWrite(dpin[2],HIGH ); //
      digitalWrite(dpin[3],LOW ); //   
      for (int i= 0 ; i<=7 ; i++)  
      { 
        digitalWrite(segpin[i], arr[][i]); //
      }
      delay(5); 
    }
      for(int j=0;j<4;j++)  
      { 
        digitalWrite(dpin[j], HIGH); 
      }
  }
  else{
    Serial.println("4 자리 이하 정수를 입력하세요");
  }
}
