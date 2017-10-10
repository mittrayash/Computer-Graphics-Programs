#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int round(float x){
return(x+0.5);
}

int main()
{
    int x1, x2, y1, y2, j,k, dx, dy;
    float mx, my, x, y;
    float step;


    int gdriver = DETECT, gmode, errorCode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

    errorCode = graphresult();

    if(errorCode != 0){
        printf("graphic error", grapherrormsg(errorCode));
        exit(1);
    }

    printf("Enter the values of x1, x2, y1, y2.");
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);

    dx = x2-x1;
    dy = y2-y1;

    if(dx>dy){
        step = dx;
    }
    else{
        step = dy;
    }

    mx = dx/step;
    my = dy/step;

    x = x1;
    y = y1;

    putpixel(round(x), round(y), RED);

    for(k=0; k<step; k++){
        x += mx;
        y += my;
        putpixel(round(x), round(y), RED);
    }
    getch();
    closegraph();

    return 0;
}
