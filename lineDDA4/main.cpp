#include <stdio.h>
#include <graphics.h>
#define ROUND(x) ((int)(x+0.5))
int main()
{
    int dx, dy, i, x1, x2, y1, y2;
    float xIncrement, yIncrement, x, y, step;
    int gDriver = DETECT, gmode, errorCode;
    initgraph(&gDriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic Error", grapherrormsg(errorCode));
        exit(1);}

    printf("Enter x1, x2, y1, y2\n");
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
    dx = x2 - x1;
    dy = y2 - y1;
    if(dx > dy)
        step = dx;
    else step = dy;

    xIncrement = (float)dx/step;
    yIncrement = (float)dy/step;
    x = x1;
    y = y1;

    putpixel(ROUND(x), ROUND(y), RED);
    for(i = 0; i < step; i++){
        x += xIncrement;
        y += yIncrement;
        putpixel(ROUND(x), ROUND(y), RED);
    }
    getch();
    closegraph();
    return 0;
}
