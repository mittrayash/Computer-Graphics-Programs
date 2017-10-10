#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

int main()
{
int gdriver = DETECT, gmode,errorcode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
errorcode = graphresult();
if(errorcode!=0)
{
printf("graphics error",grapherrormsg(errorcode));
exit(0);
}
int x1,x2,y1,y2,x,y,i,start,Eend,b;
float m;
printf("Enter value of y-intercept i.e.b=");
scanf("%d",&b);
printf("Enter value of x1=");
scanf("%d",&x1);
printf("Enter value of x2=");
scanf("%d",&x2);
printf("Enter value of y1=");
scanf("%d",&y1);
printf("Enter value of y2=");
scanf("%d",&y2);

m = ((float)y2-(float)y1)/((float)x2-(float)x1);
printf("Slope of line is = %f",m);
if (m<1)
{
start  = x1;
Eend =x2;
}
else
{
start=y1; Eend=y2;
}
for (i=start; i<Eend;i++)
{
if(m<1)
{
y=m*i+b;
x=i;
}
else
{
x=(i-b)/m;
y=i;
}
putpixel (x,y,RED);
}
getch();
closegraph();
return 0;

}

