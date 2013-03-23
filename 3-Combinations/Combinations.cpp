/*
 * File: Combinations.cpp
 * ----------------------
 * Name: Dustin Hawkinson
 * Section: None
 * This file is not Combinations, but instead assignment 1 problem 3
 * 
 */

#include "gobjects.h"
#include "gevents.h"
#include "random.h"
using namespace std;

void drawtriangle(GWindow gw, int points[]);
void waitForUserInput(GWindow gw);
int chooseVertex();
void drawCircles(GWindow gw, int points[]);


/*Program starts here*/
int main() {
   
    GWindow gw(1000,600);
    waitForUserInput(gw);
    
    return 0;
}

/*randomly chooses a vertex between 1 and 3*/
int chooseVertex(){
    
    return randomInteger(1, 3);
    
}

/**/
void drawCircles(GWindow gw, int points[]){
    
    int vertex = chooseVertex();
    double vx = points[(vertex - 1) * 2] - 1;
    double vy = points[(vertex - 1) * 2 + 1] - 1;
    double x = vx;
    double y = vy;
    
    while (true) {
        
        gw.fillOval(x, y, 2, 2);
        vertex = chooseVertex();
        vx = points[(vertex - 1) * 2] - 3;
        vy = points[(vertex - 1) * 2 + 1] - 3;
        x = (vx - x) / 2 + x;
        y = (vy - y) / 2 + y;
        
        GMouseEvent e = getNextEvent();
            if (e.getEventType() == MOUSE_PRESSED) {
            break;
            }
    }
    
}


/*takes in the array of 6 points and draws a triangle, then calls drawPoints()*/
void drawtriangle(GWindow gw, int points[]){
    gw.add(new GLine(points[0], points[1],points[2], points[3]));
    gw.add(new GLine(points[2], points[3],points[4], points[5]));
    gw.add(new GLine(points[4], points[5],points[0], points[1]));
    drawCircles(gw, points);
}

/*
 *waits for the three mouse clicks storing the coordinates
 *in an array then calls drawstriangle()
 */
void waitForUserInput(GWindow gw){

    double startX;
    double startY;
    int mousePressed = 0;
    
    //GPoint pt1;
    //GPoint pt2;
    int points [6];

    while (true){
        
        GMouseEvent e = waitForEvent();
        if (e.getEventType() == MOUSE_PRESSED) {
            startX = e.getX();
            startY = e.getY();
            mousePressed++;

        }
        
        if (mousePressed == 1){
            points[0] = startX;
            points[1] = startY;
        }
        
        if (mousePressed == 2){
            points[2] = startX;
            points[3] = startY;
        }
        
        if (mousePressed == 3){
            points[4] = startX;
            points[5] = startY;
            drawtriangle(gw, points);
            break;
        }
    }
}