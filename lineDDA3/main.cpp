#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

#define Round(x) ((int)(x+0.5))
int main()
{
    float xIncrement, yIncrement, x, y, step;
    int dx, dy, i, x1, x2, y1, y2;

    int gDriver = DETECT, gmode, errorCode;

    initgraph(&gDriver, &gmode, "C:\\TC\\BGI");

    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic Error", grapherrormsg(errorCode));
         exit(1);
    }

    printf("Enter x1, y1, x2, y2");
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    if(dx>dy)
        step = dx;
    else step = dy;

    xIncrement = dx/step;
    yIncrement = dy/step;

    x = x1;
    y = y1;

    putpixel(Round(x), Round(y), RED);

    for(i=0; i<step; i++){
        x += xIncrement;
        y += yIncrement;
        putpixel(Round(x), Round(y), RED);
    }

    getch();
    closegraph();

    return 0;
}
