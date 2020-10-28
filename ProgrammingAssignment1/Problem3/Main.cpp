#include <iostream>
#include "random.h"
#include "gevents.h"
#include "gtypes.h"
#include "gwindow.h"
using namespace std;

#define NUM_POINTS 3
#define CIRCLE_RADIUS 0.5

// draws a filled circle around the given point
void drawFilledCircle(GWindow &window, GPoint point, double circleRadius)
{
    window.fillOval(point.getX() - circleRadius, point.getY() - circleRadius,
                    circleRadius * 2, circleRadius * 2);
}

int main() {
    GWindow gw;
    gw.setCloseOperation(GWindow::CLOSE_EXIT);

    GPoint pts[NUM_POINTS]; // A, B, and C

    int currentPointIndex = 0;
    while (true) {
        GMouseEvent e = waitForEvent(MOUSE_PRESSED);
        if (e.getEventType() == MOUSE_PRESSED) {
            pts[currentPointIndex++] = GPoint(e.getX(), e.getY());
            if (currentPointIndex == NUM_POINTS)
                break;
        }
    }

    // draw triangle
    gw.setColor("BLACK");
    for (int i = 0; i < NUM_POINTS; i++)
        gw.drawLine(pts[i], pts[(i+1)%3]);

    // randomly choose one vertex as the current point
    GPoint currentPoint = pts[randomInteger(0, NUM_POINTS-1)];
    while (true) {
        // draw a small filled circle around the current point
        drawFilledCircle(gw, currentPoint, CIRCLE_RADIUS);

        // randomly choose one vertex
        GPoint randomVertex = pts[randomInteger(0, NUM_POINTS-1)];
        // move currentPoint half of the distance toward randomVertex
        currentPoint = GPoint((currentPoint.getX() + randomVertex.getX()) / 2,
                              (currentPoint.getY() + randomVertex.getY()) / 2);

        // stop when user clicks the mouse
        GEvent e = getNextEvent();
        if (e.getEventType() == MOUSE_PRESSED)
            break;
    }

    return 0;
}
