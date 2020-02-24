#include <iarduino_OLED_txt.h>
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
  extern uint8_t SmallFontRus[];   //Russ font        
  iarduino_OLED_txt myOLED(0x3C);  // Object Display
  int _delay;
  Motor stepMotor(8,9,10,11); //Create object Motor


////////////////////////////////
  void setup()
    {       
    myOLED.begin();                                                    
    myOLED.setFont(SmallFontRus); 
    }


  void loop()
  { 
    _delay = analogRead(3);
    _delay = map(_delay, 0, 1023, 1000, 15000);
    stepMotor.rotB(_delay);

    myOLED.clrScr();                                                   // Чистим экран.
    myOLED.print("UTF8", 0, 0);                                        // Выводим текст начиная с 0 столбца 0 строки.
    myOLED.setCoding(TXT_UTF8);                                        // Меняем кодировку на UTF-8 (по умолчанию).
    myOLED.print("Ардуино iArduino", OLED_C, 4);                       // Выводим текст по центру 4 строки.
    
  
}














