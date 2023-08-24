#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
static float tp3 = 0;
float xpos=-1,x=-1;


void init()
{
    glClearColor(0.75, 0.75, 0.75,1);
    gluOrtho2D(0,1000,0,1000);
}



void idle()
{
    glutPostRedisplay();
}


void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad=0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<=360;i++){
        rad=i*(3.1416/180);
        glVertex2f(x+rx*cos(rad),y+ry*sin(rad));
    }
    glEnd();
}

void sun()
{
    glPushMatrix();
    glTranslated(870, 900, 0);
    glColor3f(1.0, 0.76, 0.3);
    circle(40, 50, 0, 0);

    // Sun rays
    glColor3f(1.0, 1.0, 0.0); // Set color to white
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++)
    {
        float angle = i * (2 * M_PI / 8); // Divide 360 degrees into 8 rays
        float x1 = 40 * cos(angle);
        float y1 = 40 * sin(angle);
        float x2 = 60 * cos(angle);
        float y2 = 60 * sin(angle);

        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();

    glPopMatrix();
}



//bird body
void bird1()
{
    glPushMatrix();
    glTranslated(870,290,0);
    glColor3f(1.0,1.0,0.0);
    circle(100,50,0,0);
    glPopMatrix();
}
//bird head
void bird2()
{
    glPushMatrix();
    glTranslated(770,310,0);
    glColor3f(1.0,1.0,0.0);
    circle(40,40,0,0);
    glPopMatrix();
}
//bird eyes
void bird3()
{
    glPushMatrix();
    glTranslated(760,310,0);
    glColor3f(0.0, 0.0, 0.0);
    circle(5,5,0,0);
    glPopMatrix();
}


void cloud_move_right(GLfloat t){
    tp3=tp3+t;
    if(tp3>600)
        tp3 = -300;
    glutPostRedisplay();
}


void make_cloud(int x, int y)
{

    glColor3f(1.0, 1.0, 1.0);
    circle(20,20,x,y);
    circle(20,20,x+20,y);
    circle(20,20,x+40,y);
    circle(20,20,x+15,y-10);
    circle(20,20,x+30,y-10);
    circle(20,20,x+15,y+20);
    circle(20,20,x+30,y+20);

}


void cloud()
{
    glPushMatrix();
    glTranslatef(tp3,0,0);
    make_cloud(-400,880);
    make_cloud(-600,880);
    make_cloud(-300,850);
    make_cloud(-500,850);
    make_cloud(300,850);
    make_cloud(-200,850);
    make_cloud(-450,830);
    glPopMatrix();
    cloud_move_right(.1);

    glEnd();
}



void rectangle1(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    glBegin(GL_QUADS);
        glVertex2d(x1,y1);
        glVertex2d(x3,y3);
        glVertex2d(x4,y4);
        glVertex2d(x2,y2);
        glEnd();
}

void make_tree2()
{
    glColor3f(0.0, 0.6, 0.0);
    circle(20,30,0,0);
    circle(20,30,20,0);
    circle(20,30,40,0);
    circle(20,30,30,30);
    circle(20,30,10,30);
    circle(20,30,10,-30);
    circle(20,30,30,-30);

    circle(10,20,50,-70);
    circle(10,20,60,-60);
    circle(10,20,60,-80);


    glColor3f(0.75, 0.5, 0.25);
    rectangle1(10,-130,30,-130,10,-30,30,-30);
    rectangle1(10,-30,17,-30,5,0,5,0);
    rectangle1(17,-30,22,-30,19,0,19,0);
    rectangle1(22,-30,30,-30,35,0,35,0);
    rectangle1(30,-90,30,-100,55,-70,55,-75);
}

void tree1()
{
    glPushMatrix();
    glTranslated(-150,670,0);
    make_tree2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,670,0);
    make_tree2();
    glPopMatrix();


    glPushMatrix();
    glTranslated(-350,670,0);
    make_tree2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(200,670,0);
    make_tree2();
    glPopMatrix();



}

void tree2()
{
    glPushMatrix();
    glTranslated(-850,670,0);
    make_tree2();
    glPopMatrix();

    glPushMatrix();
    glTranslated(950,670,0);
    make_tree2();
    glPopMatrix();

}

void rectangle(int x, int y, int x1, int y1)
{
    glBegin(GL_QUADS);
        glVertex2d(x,y);
        glVertex2d(x,y1);
        glVertex2d(x1,y1);
        glVertex2d(x1,y);


    glEnd();
}


void make_beach()
{
    glColor3f(0.118,0.565,1.000);
    circle(80,200,-340,50);
    circle(80,200,-240,50);
    circle(80,200,-200,50);
    circle(80,200,-160,50);
    circle(80,200,-100,50);
    circle(80,200,-80,50);

    circle(80,200,-40,50);
    circle(80,200,0,50);
    circle(80,200,40,50);
    circle(80,200,100,50);
    circle(80,200,160,50);
    circle(80,200,220,50);
    circle(80,200,280,50);
    circle(80,200,340,50);
    circle(80,200,380,50);
    circle(80,200,420,50);
    circle(80,200,480,50);
    circle(80,200,540,50);
    circle(80,200,600,50);
    circle(80,200,660,50);
    circle(80,200,720,50);
    circle(80,200,780,50);
    circle(80,200,840,50);
    circle(80,200,900,50);
    circle(80,200,950,50);


    circle(30,20,50,-70);
    circle(20,20,60,-60);
    circle(10,20,60,-80);
}

void beach3()
{
    if(xpos<=300) {
    xpos+=0.3;
}
else
{
    xpos=xpos-300;
}
    glPushMatrix();
    glTranslated(xpos,0,0);
    make_beach();
    glPopMatrix();
}

void move_cloud()
{
    if(xpos<=300) {
    xpos+=0.3;
}
else
{
    xpos=xpos-300;
}
    glPushMatrix();
    glTranslated(xpos,0,0);
    cloud();
    glPopMatrix();
}

void polygon()
{


    glBegin(GL_POLYGON);
    glColor3f(0.118,0.565,0.000);
    glVertex2i(0,0);
    glVertex2i(0,80);
    glVertex2i(500,80);
    glVertex2i(500,0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.87, 1.0);
    glVertex2i(0,800);
    glVertex2i(0,1000);
    glVertex2i(1000,1000);
    glVertex2i(1000,800);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3, 1.0, 0.53);
    glVertex2i(0,540);
    glVertex2i(0,800);
    glVertex2i(1000,800);
    glVertex2i(1000,540);
    glEnd();


    //glColor3f(169, 117, 83);

    glPushMatrix();
    glTranslated(0, 0, 0); // You can adjust the translation values as per your requirements

    // Main building
    glBegin(GL_POLYGON);
    glColor3f(169, 117, 83);
    glVertex2f(575, 375);
    glColor3ub(181, 145, 113);
    glVertex2f(575, 500);
            glColor3ub(181, 145, 113);

    glVertex2f(300, 500);
glColor3f(169, 117, 83);
    glVertex2f(300, 375);

    glEnd();

    // Home Bottom Border
    glBegin(GL_LINE_LOOP);
    glColor3ub(20, 20, 20);
    glVertex2f(575, 375);
    glVertex2f(575, 500);
    glVertex2f(300, 500);
    glVertex2f(300, 375);
    glEnd();






    // Home Top Left
    glBegin(GL_POLYGON);
    glColor3f(169, 117, 83);
    glVertex2f(300, 500);
    glVertex2f(420, 500);
    glColor3ub(169, 117, 83);
    glVertex2f(420, 600);
    glVertex2f(300, 600);
    glEnd();

    // Home Top Left Border
    glBegin(GL_LINE_LOOP);
    glColor3ub(20, 20, 20);
    glVertex2f(300, 500);
    glVertex2f(420, 500);
    glVertex2f(420, 600);
    glVertex2f(300, 600);
    glEnd();

    // Triangle Rooftop
    glBegin(GL_TRIANGLES);
    glColor3ub(69, 39, 23);
    glVertex2f(290, 600);
    glVertex2f(430, 600);
    glVertex2f(360, 650);
    glEnd();

    // Rooftop window
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0, 0);
    glVertex2f(370, 550);
    glVertex2f(370, 575);
    glVertex2f(340, 575);
    glVertex2f(340, 550);
    glEnd();


    // Triangle Rooftop Border
    glBegin(GL_LINE_LOOP);
    glColor3ub(20, 20, 20);
    glVertex2f(290, 600);
    glVertex2f(430, 600);
    glVertex2f(360, 650);
    glEnd();

    // Home Top Right
    glBegin(GL_POLYGON);
    glColor3ub(69, 39, 23);
    glVertex2f(420, 575);
    glVertex2f(575, 575);
    glVertex2f(575, 500);
    glVertex2f(420, 500);
    glEnd();

    // Door
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0, 0);
    glVertex2f(375, 375);
    glVertex2f(375, 475);
    glVertex2f(425, 475);
    glVertex2f(425, 375);
    glEnd();

    // Window
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0, 0);
    glVertex2f(480, 445);
    glVertex2f(480, 475);
    glVertex2f(525, 475);
    glVertex2f(525, 445);
    glEnd();

    glPopMatrix();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(x<=300) {
        x-=0.05;
    }
    polygon();
    sun();
    cloud();
    tree1();
    tree2();
    beach3();

    glPushMatrix();
    glTranslated(x,0,0);
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(690,220);
    glVertex2f(770,270);
    glVertex2f(770,330);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(0.01);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(690,220);
    glVertex2f(770,300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2i(850,300);
    glVertex2i(850,400);
    glVertex2i(910,400);
    glVertex2i(910,300);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,0.0);
    glVertex2i(850,400);
    glVertex2i(850,480);
    glVertex2i(910,400);
    glEnd();
    bird1();
    bird2();
    bird3();
    glPopMatrix();

    glFlush();
}


int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Computer Graphics Project");
    glutDisplayFunc(display);
    init();
    glutIdleFunc(idle);
    glutMainLoop();
}