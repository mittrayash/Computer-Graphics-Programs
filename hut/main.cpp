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
   line(200, 200, 500, 200);
   line(300, 300, 600, 300);
   line(500, 200, 600, 300);
   rectangle(100, 300, 300, 400);
   rectangle(300, 300, 600, 400);
   rectangle(180, 360 , 220, 400);
   ellipse(212, 380, 0, 0, 5, 5);
   getch();
   closegraph();

    return 0;
}
