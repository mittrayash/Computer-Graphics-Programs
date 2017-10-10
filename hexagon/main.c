#include <iostream>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
void main()
{
    int gdriver = DETECT, gmode, errorCode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();

    if(errorCode != 0){
        printf("graphic error", grapherrormsg(errorCode));
    }

    line(100,200,200,100);
	line(200,100,300,200);
	line(300,200,300,300);
	line(300,300,200,400);
	line(200,400,100,300);
	line(100,300,100,200);
	getch();
	closegraph();
	}
