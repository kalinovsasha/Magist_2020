
int a = 8;
int b= 9;
int c= 10;
int d= 11;
int n=10;
///////////////////////////
int rotA (int n)
{  
  digitalWrite(a, HIGH);  
  delay(n); 
  digitalWrite(d, LOW);
  delay(n); 
  digitalWrite(b, HIGH);
  delay(n); 
  digitalWrite(a, LOW);
  delay(n); 
  digitalWrite(c, HIGH);  
  delay(n);    
  digitalWrite(b, LOW);
  delay(n); 
  digitalWrite(d, HIGH); 
  delay(n); 
  digitalWrite(c, LOW);
  delay(n); 
}
////////////////////////////////
void setup() {                
  
pinMode(a, OUTPUT); 
pinMode(b, OUTPUT); 
pinMode(c, OUTPUT); 
pinMode(d, OUTPUT); 
}


void loop() { 
 rotA(n);
  
}
