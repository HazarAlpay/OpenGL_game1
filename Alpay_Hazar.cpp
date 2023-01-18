/*********
   CTIS164 - Template Source Program
----------
STUDENT : Dogukan Hazar Alpay
SECTION : 02
HOMEWORK: CTIS 164 212 Homework 1
----------
PROBLEMS: Efficiency
----------
ADDITIONAL FEATURES: 
    1. Animated background (stars)
    2. Information on command screen when window is resized
    3. Color changing eyes
    4. Two objects are moving
*********/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <time.h> 

#define WINDOW_WIDTH  1400
#define WINDOW_HEIGHT 800

#define START 1
#define SHOW 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define MANUAL 2
#define AUTO 3
#define NOSET 0


#define TIMER_PERIOD  20 // Period for the timer.
#define TIMER_ON         1 // 0:disable timer, 1:enable timer

#define D2R 0.0174532

int xs = 0, xz = 0;
int xp = 0, yp = 0;
int mode = MANUAL;
int presskey = NOSET;
int app_state = START;

/* Global Variables for Template File */
bool up = false, down = false, right = false, left = false;
int  winWidth, winHeight; // current Window width and height

//
// to draw circle, center at (x,y)
// radius r
//
void circle(int x, int y, int r)
{
#define PI 3.1415
    float angle;
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++)
    {
        angle = 2 * PI * i / 100;
        glVertex2f(x + r * cos(angle), y + r * sin(angle));
    }
    glEnd();
}

void circle_wire(int x, int y, int r)
{
#define PI 3.1415
    float angle;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++)
    {
        angle = 2 * PI * i / 100;
        glVertex2f(x + r * cos(angle), y + r * sin(angle));
    }
    glEnd();
}

void print(int x, int y, const char* string, void* font)
{
    int len, i;

    glRasterPos2f(x, y);
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, string[i]);
    }
}

// display text with variables.
// vprint(-winWidth / 2 + 10, winHeight / 2 - 20, GLUT_BITMAP_8_BY_13, "ERROR: %d", numClicks);
void vprint(int x, int y, void* font, const char* string, ...)
{
    va_list ap;
    va_start(ap, string);
    char str[1024];
    vsprintf_s(str, string, ap);
    va_end(ap);

    int len, i;
    glRasterPos2f(x, y);
    len = (int)strlen(str);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font, str[i]);
    }
}

// vprint2(-50, 0, 0.35, "00:%02d", timeCounter);
void vprint2(int x, int y, float size, const char* string, ...) {
    va_list ap;
    va_start(ap, string);
    char str[1024];
    vsprintf_s(str, string, ap);
    va_end(ap);
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(size, size, 1);

    int len, i;
    len = (int)strlen(str);
    for (i = 0; i < len; i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
    }
    glPopMatrix();
}

void background() {

    glBegin(GL_POLYGON); //background color
    glColor3ub(26, 0, 31);
    glVertex2f(-700, -600);
    glVertex2f(700, -600);
    glColor3ub(115, 0, 42);
    glVertex2f(700, 400);
    glVertex2f(-700, 400);  
    glEnd();

    int x, y, status;
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        x = rand() % 1400;
        y = rand() % 800;

        if (x >= 700) {
            x = x / 2 * (-1);
        }
        if (y >= 800) {
            y = y / 2 * (-1);
        }
        glColor3f(1, 1, 1);
        circle(x, y, 1);
    }

    for (int i = 0; i < 100; i++) {
        x = rand() % 1400;
        y = rand() % 800;

        if (x <= 700) {
            x = x / 2 * (-1);
        }
        if (y <= 800) {
            y = y / 2 * (-1);
        }
        glColor3f(1, 1, 1);
        circle(x, y, 1);
    }

    for (int i = 0; i < 100; i++) {
        x = rand() % 1400;
        y = rand() % 800;

        if (x <= 700) {
            x = x / 2 * (-1);
        }
        if (y >= 800) {
            y = y / 2 * (-1);
        }
        glColor3f(1, 1, 1);
        circle(x, y, 1);
    }

    for (int i = 0; i < 100; i++) {
        x = rand() % 1400;
        y = rand() % 800;

        if (x >= 700) {
            x = x / 2 * (-1);
        }
        if (y <= 800) {
            y = y / 2 * (-1);
        }
        glColor3f(1, 1, 1);
        circle(x, y, 1);
    }
    vprint(-650, -350, GLUT_BITMAP_8_BY_13, "Dogukan Hazar Alpay 22003159");
}

void background1() {
        
    glBegin(GL_POLYGON); //background color
    glColor3ub(26, 0, 31);
    glVertex2f(-700, -600);
    glVertex2f(700, -600);
    glColor3ub(115, 0, 42);
    glVertex2f(700, 400);
    glVertex2f(-700, 400);
    glEnd();
    
    int x, y, status, i;
    srand(time(NULL));

    for (i = 0; i < 100; i++) {
        x = rand() % 1400;
        y = rand() % 800;
        
        if (x >= 700) {
            x = x / 2 * (-1);
        }
        if (y >= 800) {
            y = y / 2 * (-1);
        }
        glColor3f(1, 1, 1);
        circle(x, y, 1);
    }

    for (i = 0; i < 100; i++) {
        x = rand() % 1400;
        y = rand() % 800;
        
        if (x <= 700) {
            x = x / 2 * (-1);
        }
        if (y <= 800) {
            y = y / 2 * (-1);
        }
        glColor3f(1, 1, 1);
        circle(x, y, 1);
    }

    for (i = 0; i < 100; i++) {
        x = rand() % 1400;
        y = rand() % 800;
        
        if (x <= 700) {
            x = x / 2 * (-1);
        }
        if (y >= 800) {
            y = y / 2 * (-1);
        }
        glColor3f(1, 1, 1);
        circle(x, y, 1);
    }

    for (i = 0; i < 100; i++) {
        x = rand() % 1400;
        y = rand() % 800;
        
        if (x >= 700) {
            x = x / 2 * (-1);
        }
        if (y <= 800) {
            y = y / 2 * (-1);
        }
        glColor3f(1, 1, 1);
        circle(x, y, 1);
    }
    vprint(-190, -350, GLUT_BITMAP_8_BY_13, "PRESS <F1> to switch the mode control of the figure");
    vprint(-650, -350, GLUT_BITMAP_8_BY_13, "Dogukan Hazar Alpay 22003159");
    vprint(400, -360, GLUT_BITMAP_8_BY_13, "PRESS <ESC> to exit");

    if (mode == MANUAL)
        vprint(400, -300, GLUT_BITMAP_8_BY_13, "Current Mode = Manuel");
    else
        vprint(400, -300, GLUT_BITMAP_8_BY_13, "Current Mode = Auto");

    if (presskey == UP)
        vprint(400, -330, GLUT_BITMAP_8_BY_13, "Direction = UP");
    else if (presskey == DOWN)
        vprint(400, -330, GLUT_BITMAP_8_BY_13, "Direction = DOWN");
    else if (presskey == LEFT)
        vprint(400, -330, GLUT_BITMAP_8_BY_13, "Direction = LEFT");
    else if (presskey == RIGHT)
        vprint(400, -330, GLUT_BITMAP_8_BY_13, "Direction = RIGHT");
    else
        vprint(400, -330, GLUT_BITMAP_8_BY_13, "Direction = NOTSET");

    glColor3ub(200, 130, 30);
    circle(600 - xs, 300, 48);

    glBegin(GL_TRIANGLES);
    glColor3ub(200, 130, 30);
    glVertex2f(500 - xs, 300);
    glVertex2f(600 - xs, 350);
    glVertex2f(600 - xs, 250);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(200, 130, 30);
    glVertex2f(700 -xs, 300);
    glVertex2f(600 -xs, 350);
    glVertex2f(600 -xs, 250);
    glEnd();

    glColor3f(0, 0, 0);
    circle(600 -xs, 300, 35);

    int red, green, blue;
    for (i = 0; i < 20; i++) {
        red = rand() % 255;
        green = rand() % 255;
        blue = rand() % 255;
        glColor3ub(red, green, blue);
    }

    circle(600-xs, 300, 30);

    glColor3ub(0, 0, 0);
    circle(600 -xs, 300, 20);

    glColor3f(1, 1, 1);
    circle(608 -xs, 308, 5);

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(500 -xs, 300);
    glVertex2f(565 -xs, 335);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(700 -xs, 300);
    glVertex2f(635 -xs, 335);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(700 -xs, 300);
    glVertex2f(635 -xs, 265);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(500 -xs, 300);
    glVertex2f(565 -xs, 265);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(575 -xs, 345);
    glVertex2f(565 -xs, 370);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(600 -xs, 355);
    glVertex2f(600 -xs, 380);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(625 -xs, 345);
    glVertex2f(635 -xs, 370);
    glEnd();

    //second
    glColor3ub(200, 130, 30);
    circle(400 -xz, 200, 48);

    glBegin(GL_TRIANGLES);
    glColor3ub(200, 130, 30);
    glVertex2f(300 -xz, 200);
    glVertex2f(400 -xz, 250);
    glVertex2f(400 -xz, 150);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(200, 130, 30);
    glVertex2f(500 -xz, 200);
    glVertex2f(400 -xz, 250);
    glVertex2f(400 -xz, 150);
    glEnd();

    glColor3f(0, 0, 0);
    circle(400 -xz, 200, 35);

    int red2, green2, blue2;

    for (i = 0; i < 50; i++) {
        red2 = rand() % 255;
        green2 = rand() % 255;
        blue2 = rand() % 255;
        glColor3ub(red2, green2, blue2);
    }

    //circle(408 -x, 208, 5);
    circle(400 -xz, 200, 30);

    glColor3ub(0, 0, 0);
    circle(400 -xz, 200, 20);

    glColor3f(1, 1, 1);
    circle(408 -xz, 208, 5);

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(300 -xz, 200);
    glVertex2f(365 -xz, 235);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(500 -xz, 200);
    glVertex2f(435 -xz, 235);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(500 -xz, 200);
    glVertex2f(435 -xz, 165);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(300 -xz, 200);
    glVertex2f(365 -xz, 165);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(375 -xz, 245);
    glVertex2f(365 -xz, 270);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(400 -xz, 255);
    glVertex2f(400 -xz, 280);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(425 -xz, 245);
    glVertex2f(435 -xz, 270);
    glEnd();
}

void darkSideOfTheMoon() {

    //perspective of triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    glVertex2f(0 + xp, 60 + yp);
    glVertex2f(-60 + xp, -30 + yp);
    glVertex2f(-70 + xp, -20 + yp);
    glEnd();

    //purple light
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(232, 112, 255);
    glVertex2f(17 + xp, 11 + yp);
    glVertex2f(160 + xp, -15 + yp);
    glEnd();

    //center triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0, 0, 0);
    glVertex2f(0 + xp, 60 + yp);
    glVertex2f(-60 + xp, -30 + yp);
    glVertex2f(60 + xp, -31 + yp);
    glEnd();

    //first light
    glLineWidth(2); 
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    glVertex2f(-130 + xp, -15 + yp);
    glVertex2f(-30 + xp, 20 + yp);
    glEnd();

    //red light
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2f(18 + xp, 31 + yp);
    glVertex2f(150 + xp, 10 + yp);
    glEnd();

    //orange light
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(255, 119, 0);
    glVertex2f(21 + xp, 27 + yp);
    glVertex2f(152 + xp, 5 + yp);
    glEnd();

    //yellow light
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(249, 255, 58);
    glVertex2f(20 + xp, 23 + yp);
    glVertex2f(154 + xp, 0 + yp);
    glEnd();

    //green light
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(84, 226, 61);
    glVertex2f(19 + xp, 19 + yp);
    glVertex2f(156 + xp, -5 + yp);
    glEnd();

    //blue light
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(50, 155, 226);
    glVertex2f(18 + xp, 15 + yp);
    glVertex2f(158 + xp, -10 + yp);
    glEnd();

    //light in triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1, 1, 1);
    glVertex2f(-30 + xp, 20 + yp);
    glColor3ub(188, 188, 188);
    glVertex2f(18 + xp, 32 + yp);
    glColor3ub(145, 145, 145);
    glVertex2f(36 + xp, 5 + yp);
    glEnd();
}

//
// To display onto window using OpenGL commands
//
void display() {
    //
    // clear window to black
    //
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    background();

    glColor3f(1, 1, 1);
    vprint(-250, 0, GLUT_BITMAP_8_BY_13, "Click to see the cover image of The Dark Side of The Moon album");

    if (app_state == SHOW){
        background1();
        darkSideOfTheMoon();//The dark side of the moon triangle
    }
    
    glutSwapBuffers();
}

//
// key function for ASCII charachters like ESC, a,b,c..,A,B,..Z
//
void onKeyDown(unsigned char key, int x, int y)
{
    // exit when ESC is pressed.
    if (key == 27)
        exit(0);

    // to refresh the window it calls display() function
    glutPostRedisplay();
}

void onKeyUp(unsigned char key, int x, int y)
{
    // exit when ESC is pressed.
    if (key == 27)
        exit(0);

    // to refresh the window it calls display() function
    glutPostRedisplay();
}   

//
// Special Key like GLUT_KEY_F1, F2, F3,...
// Arrow Keys, GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_RIGHT, GLUT_KEY_RIGHT
//
void onSpecialKeyDown(int key, int x, int y)
{
    // Write your codes here.
    switch (key) {
    case GLUT_KEY_UP: up = true; break;
    case GLUT_KEY_DOWN: down = true; break;
    case GLUT_KEY_LEFT: left = true; break;
    case GLUT_KEY_RIGHT: right = true; break;
    }

    if (key == GLUT_KEY_F1) {
        if (mode == MANUAL)
            mode = AUTO;
        else
            mode = MANUAL;
    }

    if (mode == MANUAL)
    {
        switch (key)
        {
            case GLUT_KEY_UP: 
                if (yp < winHeight / 2)
                    yp = yp + 3;
                break;

            case GLUT_KEY_DOWN:
                if (yp < winHeight / 2)
                    yp = yp - 3;
                break;
            
            case GLUT_KEY_LEFT:
                if (xp < winWidth / 2)
                    xp = xp - 3;
                break;
            
            case GLUT_KEY_RIGHT:
                if (xp < winWidth / 2)
                    xp = xp + 3;
                break;
        }
    }

    if (key == GLUT_KEY_UP)
        presskey = UP;
    if (key == GLUT_KEY_DOWN)
        presskey = DOWN;
    if (key == GLUT_KEY_LEFT)
        presskey = LEFT;
    if (key == GLUT_KEY_RIGHT)
        presskey = RIGHT;

    // to refresh the window it calls display() function
    glutPostRedisplay();
}

//
// Special Key like GLUT_KEY_F1, F2, F3,...
// Arrow Keys, GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_RIGHT, GLUT_KEY_RIGHT
//
void onSpecialKeyUp(int key, int x, int y)
{
    // Write your codes here.
    switch (key) {
    case GLUT_KEY_UP: up = false; break;
    case GLUT_KEY_DOWN: down = false; break;
    case GLUT_KEY_LEFT: left = false; break;
    case GLUT_KEY_RIGHT: right = false; break;
    }

    // to refresh the window it calls display() function
    glutPostRedisplay();
}

//
// When a click occurs in the window,
// It provides which button
// buttons : GLUT_LEFT_BUTTON , GLUT_RIGHT_BUTTON
// states  : GLUT_UP , GLUT_DOWN
// x, y is the coordinate of the point that mouse clicked.
//
void onClick(int button, int stat, int x, int y)
{
    // Write your codes here.
    if (button == GLUT_LEFT_BUTTON && stat == GLUT_DOWN) {
        if (app_state == START) {
            app_state = SHOW;
            xp = x - (winWidth / 2);
            yp = (winHeight / 2) - y;
        }
        else
        {
            xp = x - (winWidth / 2);
            yp = (winHeight / 2) - y;
        }
    }

    // to refresh the window it calls display() function
    glutPostRedisplay();
}

//
// This function is called when the window size changes.
// w : is the new width of the window in pixels.
// h : is the new height of the window in pixels.
//
void onResize(int w, int h)
{
    winWidth = w;
    winHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    display(); // refresh window.
    printf("Event : RESIZE New width: %4d height: %4d\n", w, h);
}

void onMoveDown(int x, int y) {
    // Write your codes here.



    // to refresh the window it calls display() function   
    glutPostRedisplay();
}

// GLUT to OpenGL coordinate conversion:
//   x2 = x1 - winWidth / 2
//   y2 = winHeight / 2 - y1
void onMove(int x, int y) {
    // Write your codes here.



    // to refresh the window it calls display() function
    glutPostRedisplay();
}

#if TIMER_ON == 1
void onTimer(int v) {

    glutTimerFunc(TIMER_PERIOD, onTimer, 0);
    // Write your codes here.
    
    if (mode == AUTO) {
        if (presskey == UP)
            if (yp < winHeight / 2)
                yp += 3;
            else
                presskey = DOWN;

        if (presskey == DOWN)
            if (yp > -winHeight / 2)
                yp -= 3;
            else
                presskey = UP;
            
        if (presskey == RIGHT)
            if (xp < winWidth / 2)
                xp += 3;
            else
                presskey = LEFT;
          
        if (presskey == LEFT)
            if (xp > -winWidth / 2)
                xp -= 3;
            else
                presskey = RIGHT;
    }
    
    xs += 3;
    xz += 1;
    
    // to refresh the window it calls display() function
    glutPostRedisplay(); // display()
}
#endif

void Init() {

    // Smoothing shapes
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    //glutInitWindowPosition(100, 100);
    glutCreateWindow("The Dark Side of The Moon");

    glutDisplayFunc(display);
    glutReshapeFunc(onResize);

    //
    // keyboard registration
    //
    glutKeyboardFunc(onKeyDown);
    glutSpecialFunc(onSpecialKeyDown);

    glutKeyboardUpFunc(onKeyUp);
    glutSpecialUpFunc(onSpecialKeyUp);

    //
    // mouse registration
    //
    glutMouseFunc(onClick);
    glutMotionFunc(onMoveDown);
    glutPassiveMotionFunc(onMove);

#if  TIMER_ON == 1
    // timer event
    glutTimerFunc(TIMER_PERIOD, onTimer, 0);
#endif

    Init();

    glutMainLoop();
}