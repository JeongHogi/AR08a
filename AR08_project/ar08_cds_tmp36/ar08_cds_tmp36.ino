//  temperature & lux
#define TMP36_INPUT 0
#define CDS_INPUT 1

// I2C 통신 라이브러리 설정
#include <Wire.h>
// I2C LCD 라리브러리 설정
#include <LiquidCrystal_I2C.h>

// LCD I2C address 설정 PCF8574:0x27, PCF8574A:0x3F
LiquidCrystal_I2C lcd(0x27,16,2);  // LCD address:0x27, 16X2 LCD, 0x3F

int ledR = 2;

void setup() {
  Serial.begin(9600);
  lcd.init(); // LCD 설정
  lcd.clear();      // LCD를 모두 지운다.
  lcd.backlight();  // 백라이트를 켠다.
  lcd.setCursor(0,0);
  lcd.print("tempC : ");
  lcd.setCursor(0,1);
  lcd.print("lux : ");

  pinMode(ledR, INPUT);
}

void loop() {
  // Temperature from TMP36
  int temp_value = analogRead(TMP36_INPUT);
  // converting that reading to voltage
  float voltage = temp_value * 5.0 * 1000;  // in mV
  voltage /= 1023.0;
  float tempC = (voltage - 500) / 10 ;

  // Lux from CdS (LDR)
  int cds_value = analogRead(CDS_INPUT);
  int lux = int(luminosity(cds_value));
//  Serial.print("ARnn,");
  Serial.print(tempC);
  Serial.print(", lux : ");
  Serial.println(lux);
  
  lcd.setCursor(8,0);
  lcd.print(tempC);
  lcd.setCursor(8,1);
  lcd.print(lux);
  delay(200);
  
  Serial.print("AR08, value = ");
  Serial.print(temp_value);
  Serial.print(" : ");

  Serial.print(voltage);
  Serial.print(" mV, ");
  
  Serial.print(" degrees C : ");
  delay(1000);
  
  if(lux < 10){
    digitalWrite(ledR, LOW);
  } else if(lux > 10){
    digitalWrite(ledR, HIGH);
  }
}

//Voltage to Lux
double luminosity (int RawADC0){
  double Vout=RawADC0*5.0/1023.0;  // 5/1023 (Vin = 5 V)
  double lux=(2500/Vout-500)/10.0;  
  // lux = 500 / Rldr, Vout = Ildr*Rldr = (5/(10 + Rldr))*Rldr
  return lux;
}


