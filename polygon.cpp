#include <graphics.h>
#include <iostream>
using namespace std;

#define MAX_VERTICES 20

void drawPolygon(int n, int poly[MAX_VERTICES][2]) {
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        line(poly[i][0], poly[i][1], poly[next][0], poly[next][1]);
    }
}

void clipPolygon(int n, int poly[MAX_VERTICES][2], int xMin, int yMin, int xMax, int yMax) {
    int clippedPoly[MAX_VERTICES][2];
    int clippedVertices = 0;

    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;

        int x1 = poly[i][0];
        int y1 = poly[i][1];
        int x2 = poly[next][0];
        int y2 = poly[next][1];

        if ((x1 < xMin && x2 < xMin) || (x1 > xMax && x2 > xMax) || (y1 < yMin && y2 < yMin) || (y1 > yMax && y2 > yMax)) {
            continue;
        }

        if (x1 < xMin && x2 >= xMin) {
            int newX = xMin;
            int newY = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
            clippedPoly[clippedVertices][0] = newX;
            clippedPoly[clippedVertices][1] = newY;
            clippedVertices++;
        }
        if (x1 >= xMin && x2 < xMin) {
            int newX = xMin;
            int newY = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
            clippedPoly[clippedVertices][0] = newX;
            clippedPoly[clippedVertices][1] = newY;
            clippedVertices++;
        }
        if (x1 <= xMax && x2 > xMax) {
            int newX = xMax;
            int newY = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
            clippedPoly[clippedVertices][0] = newX;
            clippedPoly[clippedVertices][1] = newY;
            clippedVertices++;
        }
        if (x1 > xMax && x2 <= xMax) {
            int newX = xMax;
            int newY = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
            clippedPoly[clippedVertices][0] = newX;
            clippedPoly[clippedVertices][1] = newY;
            clippedVertices++;
        }
        if (y1 < yMin && y2 >= yMin) {
            int newX = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
            int newY = yMin;
            clippedPoly[clippedVertices][0] = newX;
            clippedPoly[clippedVertices][1] = newY;
            clippedVertices++;
        }
        if (y1 >= yMin && y2 < yMin) {
            int newX = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
            int newY = yMin;
            clippedPoly[clippedVertices][0] = newX;
            clippedPoly[clippedVertices][1] = newY;
            clippedVertices++;
        }
        if (y1 <= yMax && y2 > yMax) {
            int newX = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
            int newY = yMax;
            clippedPoly[clippedVertices][0] = newX;
            clippedPoly[clippedVertices][1] = newY;
            clippedVertices++;
        }
        if (y1 > yMax && y2 <= yMax) {
            int newX = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
            int newY = yMax;
            clippedPoly[clippedVertices][0] = newX;
            clippedPoly[clippedVertices][1] = newY;
            clippedVertices++;
        }
    }

    if (clippedVertices > 1) {
        for (int i = 0; i < clippedVertices; i++) {
            int next = (i + 1) % clippedVertices;
            line(clippedPoly[i][0], clippedPoly[i][1], clippedPoly[next][0], clippedPoly[next][1]);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xMin = 100, yMin = 100, xMax = 300, yMax = 300;

    setfillstyle(SOLID_FILL, GREEN);
    rectangle(xMin, yMin, xMax, yMax);
    floodfill((xMin + xMax) / 2, (yMin + yMax) / 2, WHITE);

    int poly[MAX_VERTICES][2] = {{150, 150}, {250, 250}, {350, 200}, {250, 150}};
    int n = 4;

    setcolor(WHITE);
    drawPolygon(n, poly);

    setcolor(RED);
    clipPolygon(n, poly, xMin, yMin, xMax, yMax);

    delay(5000);
    closegraph();
    return 0;
}

void Liang_Barsky_Algorithm(int x1, int y1, int x2, int y2, int xMin, int yMin, int xMax, int yMax) {
    float t1 = 0, t2 = 1; // Initialize parameters of the parametric equation

    int dx = x2 - x1;
    int dy = y2 - y1;

    int p[4] = {-dx, dx, -dy, dy};
    int q[4] = {x1 - xMin, xMax - x1, y1 - yMin, yMax - y1};

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                return; // Line is parallel to clipping edge and outside
            }
        } else {
            float t = (float)q[i] / p[i];
            if (p[i] < 0) {
                if (t > t1) t1 = t; // Update t1
            } else {
                if (t < t2) t2 = t; // Update t2
            }
        }
    }

    if (t1 > t2) {
        return; // Line is completely outside
    }

    // Compute clipped endpoints
    int newX1 = x1 + t1 * dx;
    int newY1 = y1 + t1 * dy;
    int newX2 = x1 + t2 * dx;
    int newY2 = y1 + t2 * dy;

    // Draw clipped line
    line(newX1, newY1, newX2, newY2);
}