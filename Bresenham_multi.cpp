#include<GL/glut.h>
#include<iostream>
using namespace std;

int r;

void E_way(int x, int y){
   glBegin(GL_LINE_LOOP);
   glVertex2i(120,235);
   glVertex2i(320,40);
   glVertex2i(520,235);
   glVertex2i(320,440);
   glEnd();

   glBegin(GL_LINE_LOOP);
   glVertex2i(120,40);
   glVertex2i(520,40);
   glVertex2i(520,440);
   glVertex2i(120,440);
   glEnd();

   glBegin(GL_POINTS);
   glVertex2i(x+320,y+240);
   glVertex2i(y+320,x+240);
   glVertex2i(y+320, -x+240);
   glVertex2i(x+320, -y+240);
   glVertex2i(-x+320,-y+240);
   glVertex2i(-y+320,-x+240);
   glVertex2i(-y+320,x+240);
   glVertex2i(-x+320,y+240);
   glEnd();
   glFlush();

}

void B_circle(){

    float d;
    d = 3 - 2*r;

    int x,y;
    x = 0 ; 
    y = r ;

    do{
        E_way(x,y);

        if(d<0){
        x=x+1;
        y=y;

            d=d+4*x+6;
        }
        else{
         x=x+1;
        y=y-1;

            d=d+4*(x-y)+10;   

        }
        

    }while(x<y);


}

void init(){

    glClearColor(0,0,0,0);
    glColor3f(1,0,0);
    gluOrtho2D(0,640,0,480);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv){

    cout<<"\n Enter Radius \t ";
    cin>>r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    init();
    glutDisplayFunc(B_circle);

    glutMainLoop();

    return 0;
}
