#include <SoftwareSerial.h>

void setup() {
  Serial.begin(9600);
  
  pinMode(2,INPUT);  // rotary A pin
  pinMode(3,INPUT);  // rotary B pin

}

int previous;   // previous pattern
int now;        // current patten

int count = 0;  // counter

int sign;       // direction of rotation

void loop(){

  int a1 = digitalRead(2);
  int a2 = digitalRead(3);
  
  if(a1 == 0 && a2 == 1) now = 0;
  else if(a1 == 1 && a2 == 0) now = 1;
  else if(a1 == 1 && a2 == 1) now = 2;

  if(now != previous){ // check rotating
    if(previous == 2 && now == 1){count++;sign=0;}
    if(previous == 1 && now == 0){count++;sign=0;}
    if(previous == 2 && now == 0){count--;sign=1;}
    if(previous == 0 && now == 1){count--;sign=1;}
    changeValue();
  }
  
  previous = now;  
  
  //count = count%10; // limit count at 10
  
}

void changeValue(){
  // use "count"  for check step of rotation
  // use "sign"   for check direction of retation
  Serial.println(count);
}
