#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

void BresenhamCircle(int r, int h, int k) {
    int x=0, y=r, d = 3-(2*r);
    while(x<=y) {
        putpixel(x+h,y+k,GREEN);
        putpixel(x + h, -y + k,GREEN);
        putpixel(-x + h, -y + k,GREEN);
        putpixel(-x + h, y + k,GREEN);
        putpixel(y + h, x + k,GREEN);
        putpixel(y + h, -x + k,GREEN);
        putpixel(-y + h, -x + k,GREEN);
        putpixel(-y + h, x + k,GREEN);
        if(d<0)
            d = d + 4*x + 6;
        else {
            d = d + 4*(x-y) + 10;
            y--;
        }
        x++;
    }

}

int main() {
    int gd=DETECT, gm;
    initgraph(&gd,&gm,NULL);
    BresenhamCircle(50, 200, 200);
    getch();
    closegraph();
}