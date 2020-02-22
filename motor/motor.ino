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
  digitalWrite(pinD, LOW);
  delayMicroseconds(n); 
  digitalWrite(pinB, HIGH);
  delayMicroseconds(n); 
  digitalWrite(pinA, LOW);
  delayMicroseconds(n); 
  digitalWrite(pinC, HIGH);  
  delayMicroseconds(n);    
  digitalWrite(pinB, LOW);
  delayMicroseconds(n); 
  digitalWrite(pinD, HIGH); 
  delayMicroseconds(n); 
  digitalWrite(pinC, LOW);
  delayMicroseconds(n); 
}

void rotB (int n)
{
  digitalWrite(pinD, HIGH);  
  delayMicroseconds(n); 
  digitalWrite(pinA, LOW);
  delayMicroseconds(n); 
  digitalWrite(pinC, HIGH);
  delayMicroseconds(n); 
  digitalWrite(pinD, LOW);
  delayMicroseconds(n); 
  digitalWrite(pinB, HIGH);  
  delayMicroseconds(n);    
  digitalWrite(pinC, LOW);
  delayMicroseconds(n); 
  digitalWrite(pinA, HIGH); 
  delayMicroseconds(n); 
  digitalWrite(pinB, LOW);
  delayMicroseconds(n); 
}   
}; // конец объявления класса 

//////////////////////////////////////////////////////////////////////////////
////////GLOBAL//////////////////////////////////////////////////////////////// 
int n=10*1000;

Motor stepMotor(8,9,10,11); 


////////////////////////////////
void setup() {                
  
 
}


void loop() { 
  for(int k=0;k<50;k++)
  {
 stepMotor.rotA(n);
  }
  for(int k=0;k<50;k++)
  {
 stepMotor.rotB(n);
  }
}














