#include <iostream>
#include<stdio.h>
#include <graphics.h>
int main()
{
    int gd = DETECT, gm, errorCode, cx, cy, x, y, d, r;

    initgraph(&gd, &gm, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic Error", grapherrormsg(errorCode));
        exit(1);
    }

    puts("Enter x and y coordinates of the mid point");
    scanf("%d%d", &cx, &cy);
    printf("\nEnter radius: ");
    scanf("%d", &r);

    d = 1.25 - r;
    x = 0;
    y = r;

    do{
    if(d<0){//EAST
            x = x+1;
            d = d+2*x+3;
    }
    else if (d>=0){//SOUTH EAST
        x = x+1;
        y = y-1;
        d = d+2*x-2*y+5;
    }

    putpixel(x+cx, y+cy, 5);
    putpixel(-x+cx, y+cy, 5);
    putpixel(x+cx, -y+cy, 5);
    putpixel(-x+cx, -y+cy, 5);

    putpixel(y+cy, x+cx, 5);
    putpixel(-y+cy, x+cx, 5);
    putpixel(y+cy, -x+cx, 5);
    putpixel(-y+cy, -x+cx, 5);
    }
    while(x<y);
    getch();



    return 0;
}
