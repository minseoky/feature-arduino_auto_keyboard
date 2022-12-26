#include "Keyboard.h"
//++++++++++++++++++++++++++--전역변수--++++++++++++++++++++++++++
int MAP[3][4] = { //0 : 빈자리 , 1 : 현재위치 , 2 : 막힘
  {0,2,2,0},
  {0,2,2,0},
  {1,0,0,0}
};
int maxRow = 2;
int maxCol = 3;
int currentRow = 2;
int currentCol = 0;
int pastnum = 0;

//++++++++++++++++++++++++++--함수--++++++++++++++++++++++++++

void randD(int a, int b){
  int rand = random(a,b);
  delay(rand);
}
void key(char unexpectedChar){ 
  Keyboard.press(unexpectedChar);
  Keyboard.release(unexpectedChar);
}
void moveUp(){
  randD(95,120);
  Keyboard.press(KEY_UP_ARROW);
  randD(95,120);
  Keyboard.press(KEY_LEFT_SHIFT);
  randD(125,150);
  Keyboard.releaseAll();
  randD(95,120);
}
void moveDown(){
  randD(95,120);
  Keyboard.press(KEY_DOWN_ARROW);
  randD(95,120);
  Keyboard.press(KEY_LEFT_SHIFT);
  randD(125,140);
  Keyboard.releaseAll();
  randD(95,120);
}
void moveRight(){
  randD(95,100);
  Keyboard.press(KEY_RIGHT_ARROW);
  randD(95,100);
  Keyboard.press(KEY_LEFT_SHIFT);
  randD(90,95);
  Keyboard.releaseAll();
  randD(95,100);
}
void moveLeft(){
  randD(95,100);
  Keyboard.press(KEY_LEFT_ARROW);
  randD(95,100);
  Keyboard.press(KEY_LEFT_SHIFT);
  randD(90,95);
  Keyboard.releaseAll();
  randD(95,100);
}
void moveTo(){
  int randnum = random(0,4); // 0 UP, 1 RIGHT, 2 DOWN, 3 LEFT
  while(1){
    if(randnum == 0 && currentRow > 0 && MAP[currentRow-1][currentCol] == 0){//위로이동
      MAP[currentRow][currentCol] = 0;
      currentRow--;
      MAP[currentRow][currentCol] = 1;
      moveUp();
      break;
    }
    else if(randnum == 1 && currentCol < maxCol && MAP[currentRow][currentCol+1] == 0){//오른쪽
      MAP[currentRow][currentCol] = 0;
      currentCol++;
      MAP[currentRow][currentCol] = 1;
      moveRight();
      break;
    }
    else if(randnum == 2 && currentRow < maxRow && MAP[currentRow+1][currentCol] == 0){//아래
      MAP[currentRow][currentCol] = 0;
      currentRow++;
      MAP[currentRow][currentCol] = 1;
      moveDown();
      break;
    }
    else if(randnum == 3 && currentCol > 0 && MAP[currentRow][currentCol-1] == 0){//왼쪽
      MAP[currentRow][currentCol] = 0;
      currentCol--;
      MAP[currentRow][currentCol] = 1;
      moveLeft();
      break;
    }
    else{
      randnum = random(0,4);
    }
  }
}
void turnLeft(){
  Keyboard.press(KEY_LEFT_ARROW);
  randD(50,65);
  Keyboard.releaseAll();
}
void turnRight(){
  Keyboard.press(KEY_RIGHT_ARROW);
  randD(50,65);
  Keyboard.releaseAll();
}
void mod_dir(){
  if(currentCol > maxCol/2){
    turnLeft();
  }
  else{
    turnRight();
  }
}
//++++++++++++++++++++++++++--SKILLS--++++++++++++++++++++++++++
void normalAttack(){
  Keyboard.press(KEY_LEFT_CTRL);
  randD(230,245);
  Keyboard.releaseAll();
}
void zs(){
  key('z');
  randD(240,250);
  key('s');
  randD(200,220);
}
void zd(){
  key('z');
  randD(240,250);
  key('d');
  randD(200,220);
}
void xd(){
  key('x');
  randD(240,250);
  key('d');
  randD(200,220);
}
void xf(){
  key('x');
  randD(240,250);
  key('f');
  randD(200,220);
}
void cf(){
  key('c');
  randD(240,250);
  key('f');
  randD(200,220);
}
void y(){
  key('y');
  randD(540,550);
}
void skills(){
  int randnum = random(0,11);
  if(randnum == pastnum){
    skills();
  }
  else{
    pastnum = randnum;
    switch(randnum){
      case 0:
        normalAttack();
        break;

      case 1:
        zs();
        break;

      case 2:
        zd();
        break;

      case 3:
        xd();
        break;

      case 4:
        xf();
        break;

      case 5:
      case 6:
      case 7:
      case 8:
        cf();
        break;

      case 9:
        y();
        cf();
        break;

      case 10:
        cf();
        randD(840,860);
        key('.');
        break;
    }
  }
}
void skills2(){
  int randnum = random(0,2);
  switch(randnum){
    case 0:
      key('`');
      randD(360,370);
      break;
    case 1:
      key('.');
      randD(95,100);
      key('v');
      randD(235,255);
      key('g');
      break;
  }
}
void meaninglessKey(){
  int randnum = random(0,10);
  randD(10,15);
  switch(randnum){
    case 0:
      key('7');
      break;
    case 1:
      key('8');
      break;
    case 2:
      key('9');
      break;
    case 3:
      key('0');
      break;
    case 4:
      key('b');
      break;
    case 5:
      key('a');
      break;
    case 6:
      key('.');
      break;
    case 7:
      key(']');
      break;
    case 8:
    case 9:
      Keyboard.press(KEY_F10);
      Keyboard.releaseAll();
      break;
  }
}
//++++++++++++++++++++++++++--SETUP AND LOOP--++++++++++++++++++++++++++

void setup(){
  Serial.begin(9600);
  Keyboard.begin();
  delay(5000);
}

void loop(){
  int randnum = random(11,15);
  for(int i = 0 ; i < randnum ; i++){
    moveTo();
    mod_dir();
    randD(360,420);
    meaninglessKey();
    skills();
    randD(490,505);
  }
  skills2();
}