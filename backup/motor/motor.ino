#include <iarduino_OLED_txt.h> // SDA- Analog4; SCL Analog5
class Motor // имя класса
{
private: // спецификатор доступа private
  int pinA = 8;
  int pinB = 9;
  int pinC = 10;
  int pinD = 11;
  
public: // спецификатор доступа public
    Motor (int _pinA, int _pinB, int _pinC,int _pinD ) // конструктор класса
    {
  pinA =_pinA;
  pinB = _pinB;
  pinC = _pinC;
  pinD = _pinD;
  pinMode(pinA, OUTPUT); 
  pinMode(pinB, OUTPUT); 
  pinMode(pinC, OUTPUT); 
  pinMode(pinD, OUTPUT);
    }
   
void rotA (int n)
{  
  digitalWrite(pinA, HIGH);  
  delayMicroseconds(n);
  delayMicroseconds(n); 
  digitalWrite(pinD, LOW);
  delayMicroseconds(n);
  delayMicroseconds(n); 
  digitalWrite(pinB, HIGH);
  delayMicroseconds(n);
  delayMicroseconds(n); 
  digitalWrite(pinA, LOW);
  delayMicroseconds(n);
  delayMicroseconds(n); 
  digitalWrite(pinC, HIGH);  
  delayMicroseconds(n);
  delayMicroseconds(n);    
  digitalWrite(pinB, LOW);
  delayMicroseconds(n);
  delayMicroseconds(n); 
  digitalWrite(pinD, HIGH); 
  delayMicroseconds(n);
  delayMicroseconds(n); 
  digitalWrite(pinC, LOW);
  delayMicroseconds(n);
  delayMicroseconds(n); 
}

void rotB (int n)
{
  digitalWrite(pinD, HIGH);  
  delayMicroseconds(n);
  delayMicroseconds(n);  
  digitalWrite(pinA, LOW);
  delayMicroseconds(n);
  delayMicroseconds(n);  
  digitalWrite(pinC, HIGH);
  delayMicroseconds(n);
  delayMicroseconds(n);  
  digitalWrite(pinD, LOW);
  delayMicroseconds(n);
  delayMicroseconds(n);  
  digitalWrite(pinB, HIGH);  
  delayMicroseconds(n);
  delayMicroseconds(n);     
  digitalWrite(pinC, LOW);
  delayMicroseconds(n);
  delayMicroseconds(n);  
  digitalWrite(pinA, HIGH); 
  delayMicroseconds(n);
  delayMicroseconds(n);  
  digitalWrite(pinB, LOW);
  delayMicroseconds(n);
  delayMicroseconds(n);  
}   
}; // конец объявления класса 

//////////////////////////////////////////////////////////////////////////////
////////GLOBAL//////////////////////////////////////////////////////////////// 
  extern uint8_t MediumFontRus[];   //Russ font  
  extern uint8_t SmallFontRus[];      
  iarduino_OLED_txt myOLED(0x3C);  // Object Display
  int delayPotenc=1000; // Значение потенциометра
  int delayStep;        // Значение задержки для двигателя
  int delaytodisplay; //Значение выводимое на дисплей 
  Motor stepMotor(8,9,10,11); //Create object Motor
  int delayBuf=0; // Временное значение
  int pinIn =2;  // Вход кнопки Set
////////////////////////////////
  void setup()
    {       
    myOLED.begin();
    myOLED.setCoding(TXT_UTF8);                                        // Меняем кодировку на UTF-8 (по умолчанию).                                                     
    pinMode(pinIn, INPUT);
    }
  
  void loop()
  { 

    if (digitalRead(2)==HIGH){ 
    delayPotenc = analogRead(3);      //potenciometr for set speed
    }
    delaytodisplay=map(1024-delayPotenc,0,1024,1,100);
    delayStep = map(delayPotenc, 0, 1023, 1000, 15000);

   
    if(delayBuf > delayStep+25 or delayBuf < delayStep-25 )
      {
      delayBuf= delayStep; 
      myOLED.print("            ", 0, 2);                //Clear  row
      myOLED.print("            ", 0, 1);                //Clear  row
      myOLED.setFont(MediumFontRus);
      myOLED.print(delaytodisplay, 0, 2);               // Выводим текст начиная с 0 столбца 0 строки.
      // myOLED.setFont(SmallFontRus);
      // myOLED.print("Ардуино iArduino", OLED_C, 6);      // Выводим текст по центру 4 строки.
      }  
    
    stepMotor.rotB(delayStep);
    
}














