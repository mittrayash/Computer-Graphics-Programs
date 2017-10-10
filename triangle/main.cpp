#include <iostream>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>


int main()
{
    int gd = DETECT, gm, errorCode;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    errorCode = graphresult();

    if(errorCode != 0){
        printf("Graphic Error", grapherrormsg(errorCode));
        exit(1);
    }

   line(200, 200, 300, 300);
   line(200, 200, 100, 300);
   line(100, 300, 300, 300);


    getch();
    closegraph();

    return 0;
}
