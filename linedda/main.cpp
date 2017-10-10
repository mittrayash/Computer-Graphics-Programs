#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
int ROUND(int x);
int main()
{
int gdriver = DETECT, gmode,errorcode;
int x1,x2,y1,y2,dx,dy,x,y,step,k;
float mx,my;

initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
errorcode = graphresult();
if(errorcode!=0)
{
printf("graphics error",grapherrormsg(errorcode));
exit(1);
}

printf("Enter value of x1=");
scanf("%d",&x1);
printf("Enter value of x2=");
scanf("%d",&x2);
printf("Enter value of y1=");
scanf("%d",&y1);
printf("Enter value of y2=");
scanf("%d",&y2);
dx = x2-x1;
dy = y2-y1;

if(dx>dy)
step = dx;
else
step = dy;

mx=dx/step;
my=dy/step;
putpixel(ROUND(x),ROUND(y),RED);
for(k =0; k<step;k++)
{
x += mx;
y += my;
putpixel(ROUND(x),ROUND(y),RED);
}
getch();
closegraph();
return 0;
}

int ROUND(int x)
{ return x+0.5; }
