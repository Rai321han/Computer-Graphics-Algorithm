#include <iostream>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>


using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2-x1;
    int dy = y2-y1; 
    int steps;

    steps = std::abs(dx)>std::abs(dy)?std::abs(dx):std::abs(dy);

    float xInc = dx/(float)steps;
    float yInc = dy/(float)steps;

    float x = x1;
    float y = y1;

    for(int i=0; i<=steps; i++) {
        putpixel(round(x), round(y), LIGHTCYAN);
        x += xInc;
        y +=yInc;
    }
}

int main()
{
    int gd = DETECT, gm;
    //Initialize graphics function
    initgraph(&gd, &gm, (char*)"");
    int x1,x2,y1,y2;
    cout<<"Co-ordinates of point A = ";
    cin>>x1>>y1;

    cout<<"Co-ordinates of point B = ";
    cin>>x2>>y2;

    DDA(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}
