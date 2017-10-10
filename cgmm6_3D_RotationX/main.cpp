#include <stdio.h>
#include <graphics.h>
#include <math.h>


int main()
{
     int gdriver = DETECT, gmode, errorCode;


    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic error", grapherrormsg(errorCode));
        exit(1);
    }


float t;
int i, j, k;

puts("Enter rotation angle: ");
scanf("%f", &t);

t = (3.1416*t)/180;

float a[4][4] = {{1, 0, 0, 0}, {0, cos(t), sin(t),0}, {0, -sin(t), cos(t), 0}, {0, 0, 0, 1}};
float c[8][4];
float b[8][4] = {{50, 100, 35, 1}, {100, 100, 35, 1}, {100, 50, 35, 1}, {50, 50, 35, 1}, {50, 100, 0, 1}, {100, 100, 0, 1}, {100, 50, 0, 1}, {50, 50, 0, 1}};

   outtextxy(10, 10, "Initial Cuboid");
   bar3d(50+200, 100+200, 100+200, 50+200, 35, 1);
   getch();
//SET ZERO--------------------
    for(i = 0; i<8; i++){
        for(j = 0; j<4; j++){
            c[i][j] = 0;
        }}
    //MULTIPLY---------------------
    for(i=0; i<8; i++){
        for(j=0; j<4; j++){
            for(k=0; k<4; k++){
             c[i][j] += a[j][k]*b[i][j];
            }
            //printf("%f ", a[j][k]);
            }}
   //DISPLAY----------------------
    printf("\nOutput: \n");
   for(i=0; i<8; i++){
    for(j=0; j<4; j++){
        printf("%.2f ", c[i][j]);
    }
    printf("\n");
   }
   //DRAW------------------------
   outtextxy(10, 10, "Rotated Cuboid");
   bar3d(c[2][0]+100, c[2][1]+100, c[4][0]+100, c[4][1]+100, c[2][2], 1);





getch();
closegraph();

    return 0;
}
