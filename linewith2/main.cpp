#include <stdio.h>
#include <graphics.h>

int main()
{
    int gDriver = DETECT, gmode, errorCode;
    initgraph(&gDriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic error", grapherrormsg(errorCode));
        exit(1);
    }
    int x1, x2, y1, y2, start, Eend, b, i, x, y;
    float m;
    puts("Enter b(y-intercept), x1, x2, y1, y2");
    scanf("%d%d%d%d%d", &b, &x1, &x2, &y1, &y2);

    m = ((float)y2-(float)y1)/((float)x2-(float)x1);
    printf("Slope of line = %.2f", m);

    if(abs(m)<1){
        start = x1;
        Eend = x2;}
    else{
        start = y1;
        Eend = y2;}

    for(i = start; i < Eend; i++){
        if(abs(m)<1){
            x = i;
            y = m*i + b;
        }
        else{
            y = i;
            x = (i-b)/m;
        }
        putpixel(x, y, RED);
    }
    getch();
    closegraph();
    return 0;
}
