#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>


int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, " ");
    errorcode = graphresult();

    if(errorcode != 0){
        printf("Graphic Error", grapherrormsg(errorcode));
        exit(1);
    }

    line(0, 0, getmaxx(), getmaxy());
    closegraph();


    return 0;
}
