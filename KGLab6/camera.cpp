#include <windows.h>
#include <gl/gl.h>
#include "camera.h"
#include <math.h>
#include <iostream>
void moveCamera(GLfloat &xAngle,GLfloat &zAngle,POINTFLOAT &pos,POINT curPos){

    POINT centerPos = {500,500};
    xAngle=(centerPos.y-curPos.y)/5;
    zAngle=(centerPos.x-curPos.x)/5;
    float angle = -zAngle / 180 * M_PI;
    float speed = 0;
    if (GetKeyState('W') < 0) speed = 0.1;
    if (GetKeyState('S') < 0) speed = -0.1;
    if (GetKeyState('A') < 0) {speed = 0.1; angle -= M_PI*0.5;}
    if (GetKeyState('D') < 0) {speed = 0.1; angle += M_PI*0.5;}
    if(speed!=0){
        pos.x += sin(angle)*speed;
        pos.y += cos(angle)*speed;
    }
    glRotatef(-xAngle,1,0,0);
    glRotatef(-zAngle,0,0,1);
    glTranslatef(-pos.x,-pos.y,-3);

}


