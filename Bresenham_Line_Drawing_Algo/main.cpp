#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

using namespace std;     

void BresenhamLine(int x1, int y1, int x2, int y2) {
  //case: when right coordinate is given first.
  // we simply interchange the coordinates
  if (x1 > x2) {
    int temp;
    temp = x1;
    x1 = x2;
    x2 = temp;

    temp = y1;
    y1 = y2;
    y2 = temp;
  }

  //case: For negative slop,
  //We are going to mirror the line to have a positive slop
  if (y1 > y2) {
    y1 = -y1;
    y2 = -y2;
  }

    int dx = x2-x1;
    int dy = y2-y1;

    int x = x1;
    int y = y1;

    if(dx>dy) {
        int dS = 2*dy;
        int dT = 2*(dy-dx);
        int di = 2*dy - dx;
        putpixel(x,std::abs(y),GREEN);

        for(int i=0; i<dx; i++) {
            x = x+1;
            if(di<0) di = di + dS;
            else {
                y = y+1;
                di = di + dT;
            }
            putpixel(x,std::abs(y),GREEN);
        }
    }

    else {
        int dS = 2*dx;
        int dT = 2*(dx-dy);
        int di = 2*dx - dy;
        putpixel(x,std::abs(y),GREEN);

        for(int i=0; i<dy; i++) {
            y = y+1;
            if(di<0) di = di + dS;
            else {
                x = x+1;
                di = di + dT;
            }
            putpixel(x,std::abs(y),GREEN);
        }
    }

}

int main() {
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);
    BresenhamLine(140,40,20,300);
    getch();
    closegraph();
}