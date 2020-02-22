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
  delay(n); 
  digitalWrite(pinD, LOW);
  delay(n); 
  digitalWrite(pinB, HIGH);
  delay(n); 
  digitalWrite(pinA, LOW);
  delay(n); 
  digitalWrite(pinC, HIGH);  
  delay(n);    
  digitalWrite(pinB, LOW);
  delay(n); 
  digitalWrite(pinD, HIGH); 
  delay(n); 
  digitalWrite(pinC, LOW);
  delay(n); 
}

void rotB (int n)
{
  digitalWrite(pinD, HIGH);  
  delay(n); 
  digitalWrite(pinA, LOW);
  delay(n); 
  digitalWrite(pinC, HIGH);
  delay(n); 
  digitalWrite(pinD, LOW);
  delay(n); 
  digitalWrite(pinB, HIGH);  
  delay(n);    
  digitalWrite(pinC, LOW);
  delay(n); 
  digitalWrite(pinA, HIGH); 
  delay(n); 
  digitalWrite(pinB, LOW);
  delay(n); 
}
   
}; // конец объявления класса 

//////////////////////////////////////////////////////////////////////////////
////////GLOBAL//////////////////////////////////////////////////////////////// 
int n=10;

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














