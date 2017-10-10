#include <stdio.h>
#include <graphics.h>

int main()
{
int tx, ty, i, j, k;

int gdriver = DETECT, gmode, errorCode;


    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic error", grapherrormsg(errorCode));
        exit(1);
    }
printf("Enter translation factors for x and y: ");
       scanf("%d%d", &tx, &ty);


int b[8][4] = {{50, 100, 35, 1}, {100, 100, 35, 1}, {100, 50, 35, 1}, {50, 50, 35, 1}, {50, 100, 0, 1}, {100, 100, 0, 1}, {100, 50, 0, 1}, {50, 50, 0, 1}};
int c[8][4];
int a[4][4] = {{1,0,0,0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {tx, ty, 0, 1}};
     outtextxy(10, 10, "Initial Cuboid");
     bar3d(50, 100, 100, 50, 35, 1);

     getch();

    //Translation
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
        printf("%d ", c[i][j]);
    }
    printf("\n");
   }
   //DRAW------------------------
   outtextxy(10, 10, "Translated Cuboid");
   bar3d(c[2][0], c[2][1], c[4][0], c[4][1], c[2][2], 1);
    getch();
    closegraph();



    return 0;
}
