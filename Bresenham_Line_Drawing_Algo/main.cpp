#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

using namespace std;     

void BresenhamLine(int x1, int y1, int x2, int y2) {
    // Assumptions
    //--------------------------------
    // Line is drawn from left to right
    // x2>x1 and y2>y1

    int dx = x2-x1;
    int dy = y2-y1;

    int x = x1;
    int y = y1;

    //when 0<m<1
    if(dx>dy) {
        int dS = 2*dy;
        int dT = 2*(dy-dx);
        int di = 2*dy - dx;
        putpixel(x,y,GREEN);

        for(int i=0; i<dx; i++) {
            x = x+1;
            if(di<0) di = di + dS;
            else {
                y = y+1;
                di = di + dT;
            }
            putpixel(x,y,GREEN);
        }
    }

    //when m>=1
    else {
        int dS = 2*dx;
        int dT = 2*(dx-dy);
        int di = 2*dx - dy;
        putpixel(x,y,GREEN);

        for(int i=0; i<dy; i++) {
            y = y+1;
            if(di<0) di = di + dS;
            else {
                x = x+1;
                di = di + dT;
            }
            putpixel(x,y,GREEN);
        }
    }

}

int main() {
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);
    BresenhamLine(100,1,200,360);
    getch();
    closegraph();
}