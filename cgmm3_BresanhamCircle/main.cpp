#include <stdio.h>
#include <graphics.h>
int main()
{
    int gdriver = DETECT, gmode, errorCode;
    int x, y, cx, cy, r, d, i;

    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic error", grapherrormsg(errorCode));
        exit(1);
    }

    printf("Enter the radius: ");
    scanf("%d", &r);
    printf("Enter the co-ordinates of the center x and y\n");
    scanf("%d%d", &cx, &cy);

    x = 0;
    y = r;
    d = 3 - 2*r;
    while (x<=y){
            delay(100);
        putpixel(x+cx, y+cy, RED);
        putpixel(x+cx, -y+cy, GREEN);
        putpixel(-x+cx, y+cy, BLUE);
        putpixel(-x+cx, -y+cy, WHITE);
        putpixel(y+cy, x+cx, 15);
        putpixel(-y+cy, x+cx, 14);
        putpixel(y+cy, -x+cx, 11);
        putpixel(-y+cy, -x+cx, 3);

    if(d<0){
        d = (d + (4*x) + 6);
    }
    else{
        d = (d + (4*(x-y)) + 10);
        y--;
    }
    x++;
    }
    getch();
    closegraph();
   return 0;
}
