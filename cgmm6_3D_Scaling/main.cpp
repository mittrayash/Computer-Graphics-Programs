#include <stdio.h>
#include <graphics.h>

int main()
{

    int gdriver = DETECT, gmode, errorCode;


    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic error", grapherrormsg(errorCode));
        exit(1);
    }



int i, j, k;
   float sx, sy, sz;
   printf("Enter Sx, Sy and Sz (Scaling factors in x, y and z directions: ");
   scanf("%f%f%f", &sx, &sy, &sz);

float b[8][4] = {{50, 100, 35, 1}, {100, 100, 35, 1}, {100, 50, 35, 1}, {50, 50, 35, 1}, {50, 100, 0, 1}, {100, 100, 0, 1}, {100, 50, 0, 1}, {50, 50, 0, 1}};
float c[8][4];
float a[4][4] = {{sx,0,0,0}, {0, sy, 0, 0}, {0, 0, sz, 0}, {0, 0, 0, 1}};

   outtextxy(10, 10, "Initial Cuboid");
   bar3d(50, 100, 100, 50, 35, 1);
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
             c[i][j] += b[i][k]*a[k][j];
            }}}
   //DISPLAY----------------------
    printf("\nOutput: \n");
   for(i=0; i<8; i++){
    for(j=0; j<4; j++){
        printf("%.2f ", c[i][j]);
    }
    printf("\n");
   }
   //DRAW------------------------
   outtextxy(10, 10, "Scaled Cuboid");
   bar3d(c[2][0], c[2][1]+100, c[4][0], c[4][1]+100, c[2][2], 1);
    getch();
    closegraph();

    return 0;
}
