//Дисплей поключается scl - A5; SDA - A4
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
  int delayStep=15000;        // Значение задержки для двигателя
  int delaytodisplay; //Значение выводимое на дисплей 
  Motor stepMotor(8,9,10,11); //Create object Motor
  int delayBuf=0; // Временное значение
  int pinSet =4;  // Вход кнопки Set
  int pinStart =5;  // Вход кнопки Start
  int pinFast =6;  // Вход кнопки Stop
  bool start = false ; // Нажатие кнопок start/stop
  const byte interruptPin = 0; //Вход кнопки stop (0 это digital 2)
////////////////////////////////
  void setup()
    {       
    myOLED.begin();
    myOLED.setCoding(TXT_UTF8);                       // Меняем кодировку на UTF-8 (по умолчанию).   
    myOLED.setFont(MediumFontRus);    
    myOLED.print("Speed:", 0, 1);      // Выводим текст по центру 1 строки 
    myOLED.print(delaytodisplay, 0, 4);               // Выводим текст начиная с 0 столбца 4 строки.                                             
    pinMode(pinSet, INPUT);
    pinMode(pinStart, INPUT);
    pinMode(pinFast, INPUT);
    attachInterrupt(interruptPin, stop, LOW);
    }
  
  void loop()
  { 
    delayPotenc = analogRead(3);      //potenciometr for set speed
    delayStep = map(delayPotenc, 0, 1023, 780, 8000);
    
    if(digitalRead(pinStart)==HIGH and start==false){
      start=true;
      draw(map(1024-delayPotenc,0,1024,1,100));
      myOLED.print("ON  ", 0, 6); // Выводим текст начиная с 0 столбца 6 строки.
      }

    if(digitalRead(pinFast)==HIGH){
      delayStep=800;
    }
    
    if (digitalRead(pinSet)==HIGH){ 
      if(delayBuf > delayStep+25 or delayBuf < delayStep-25 )
      {
        delaytodisplay=map(1024-delayPotenc,0,1024,1,100);
        delayBuf= delayStep; 
        draw(delaytodisplay);
      } 
    }
    
    if (start==true){ 
      stepMotor.rotA(delayStep);
    }
    
}

void fast() 
{
  stepMotor.rotA(800);
}
void draw(int txt) 
{
  myOLED.print("            ", 0, 4);                //Clear  row
  myOLED.print("            ", 0, 3);                //Clear  row
  myOLED.print(txt, 0, 4);               // Выводим текст начиная с 0 столбца 4 строки.
  myOLED.print("Speed:", 0, 1);      // Выводим текст по центру 4 строки.
}
void stop() 
{
 start=false;
 myOLED.print("OFF", 0, 6); // Выводим текст начиная с 0 столбца 6 строки
}













