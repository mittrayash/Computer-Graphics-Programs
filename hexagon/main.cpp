#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
int main()
{
	int gdriver= DETECT, gmode,errorcode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	errorcode = graphresult();
	if(errorcode!=0)
	{
	printf("graphics error",grapherrormsg(errorcode));
	exit(0);
	}
	line(100,200,200,100);
	line(200,100,300,200);
	line(300,200,300,300);
	line(300,300,200,400);
	line(200,400,100,300);
	line(100,300,100,200);

	getch();
	closegraph();

	return 0;
	}
