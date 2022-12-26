#include "Keyboard.h"
int num = 1;
int pastRandnum = 0;
int X = 1;
int Y = 1;
int movecount = 0;
int rowcount = 0;
//
void setup(){
  Serial.begin(9600);
  Keyboard.begin();
  delay(2000);
}

void keyput(char unexpectedChar){ 
  Keyboard.press(unexpectedChar);
  Keyboard.release(unexpectedChar);
}

void upteleport(){
  delay1();
  Keyboard.press(KEY_LEFT_SHIFT);
  delay2();
  Keyboard.releaseAll();
}
void downteleport(){
  Keyboard.press(KEY_DOWN_ARROW);
  delay1();
  Keyboard.press(KEY_LEFT_ALT);
  delay2();
  Keyboard.releaseAll();
  delay1();
}
void leftteleport(){
  Keyboard.press(KEY_LEFT_ARROW);
  delay1();
  Keyboard.press(KEY_LEFT_ALT);
  delay1();
  Keyboard.releaseAll();
  delay1();
  Keyboard.press(KEY_LEFT_ALT);
  delay1();
  Keyboard.releaseAll();
  delay1();
  keyput('z');
  delay1();
  Keyboard.releaseAll();
  delay2();
}
void rightteleport(){
  Keyboard.press(KEY_RIGHT_ARROW);
  delay1();
  Keyboard.press(KEY_LEFT_ALT);
  delay1();
  Keyboard.releaseAll();
  delay1();
  Keyboard.press(KEY_LEFT_ALT);
  delay1();
  Keyboard.releaseAll();
  delay1();
  keyput('z');
  delay1();
  Keyboard.releaseAll();
  delay2();
}
void moveTo(){
  Serial.println("moveTo / Lala");
  if (X != 1 and X != 4 and movecount < 7) {
    int randNum = random(0,2);
    if (rowcount == 0) {
      if (randNum == 0){ 
          leftteleport();
          X -= 1;
          movecount += 1;   
      }
      else if (randNum == 1){
          rightteleport();
          X += 1;
          movecount += 1;   
      }
    }
    else if (rowcount != 0) {
      if (rowcount >= 1){ 
          rightteleport();
          X += 1;
          movecount += 1; 
          rowcount -= 0;   
      }
      else if (rowcount <= -1){
          leftteleport();
          X -= 1;
          movecount += 1;   
          rowcount += 0;   
      }
    }
  }
  else if ((X == 1 or X == 4) and movecount < 7){
    if (X == 1){
      rightteleport();
      X += 1;
      movecount += 1;
      rowcount += 1;
    }
    else if (X == 4){
      leftteleport();
      X -= 1;
      movecount += 1;
      rowcount -= 1;
    }
  }
  else if ((X == 2 or X == 3) and movecount >= 7){
    upteleport();
    delay1();
    movecount = 0;
  }
  else {
    movecount = 0;
    moveTo();
  }
  exact();
  Serial.println("moveTo / Lala - X:" + String(X) + " Y:" + String(Y));
  
}

void exact() {
  if (X == 1) {
    Keyboard.press(KEY_RIGHT_ARROW);
    delay1();
    Keyboard.releaseAll();
  }
  else if (X == 4) {
    Keyboard.press(KEY_LEFT_ARROW);
    delay1();
    Keyboard.releaseAll();
  }
}

void delay1(){
  int randomDelay = random(95,120);
  delay(randomDelay);
}

void delay2(){
  int randomDelay = random(360,430);
  delay(randomDelay);
}

void delay3(){
  int randomDelay = random(520,620);
  delay(randomDelay);
}

void delay4(){
  int randomDelay = random(1360,1430);
  delay(randomDelay);
}

void delay5(){
  int randomDelay = random(2290,2390);
  delay(randomDelay);
}

void buff(){
  Serial.println("Buff Activate / Lala");
}

void specialRoutine(){
  int i = random(0,4);
  if (i == pastRandnum){
    specialRoutine();
  }
  else {
    pastRandnum = i;
    Serial.println("specialRoutine :" + String(i) + " / Lala    try :" + String(num));
    num += 1;
    delay1();
    switch(i){
      case 0:
            Keyboard.press(KEY_LEFT_SHIFT);
            delay2();
            Keyboard.releaseAll();
      case 1:
            Keyboard.press(KEY_LEFT_CTRL);
            delay2();
            Keyboard.releaseAll();
      case 2:
            keyput('f');
            delay2();
            break;
      case 3:
            keyput('f');
            delay2();
            break;
    }
  }
}


void mapList1(){
  buff();
  for (int j = 0; j <= 19; j++) {
    int repeatRand = random(3,5);
    for (int i = 0; i <= repeatRand; i++) {
      moveTo();
      exact();
      int a = random(0,4);
      if (a == 0 and X != 1 and X != 4) {
        delay1();
        keyput('`');
        delay2();
      }
      else {
        delay1();
        keyput('`');
        delay2();
        keyput('z');
        delay2();
      }
      delay2();
    }
    Serial.println("specialRoutine / Lala");
    specialRoutine();
  }
  delay1();
  mapList1();
}


void loop(){
  char ch = ' ';
  //if (Serial.available()) {
    //ch = Serial.read();
    //if (ch == '1') {
  delay(2000);
  Serial.println("sequence_1 Start / Lala");
  mapList1();
    //}
  //}
}