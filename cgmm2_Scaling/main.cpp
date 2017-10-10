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

float sx, sy;
printf("Enter Sx and Sy (Scaling factors in x and y directions: ");
scanf("%f%f", &sx, &sy);
float b[3][3] = {{300,400,1}, {400,300,1}, {500,400,1}}, c[3][3];
float a[3][3] = {{sx,0,0}, {0, sy, 0}, {0, 0, 1}};

  int i, j, k;
    //SET ZERO--------------------
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            c[i][j] = 0;
        }}
    //MULTIPLY---------------------
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
             c[i][j] += b[i][k]*a[k][j];
            }}}
    //DISPLAY----------------------
    printf("\nOutput: \n");
   for(i=0; i<3; i++){
    for(j=0; j<3; j++){
        printf("%.2f ", c[i][j]);
    }
    printf("\n");
   }
   //DRAW--------------------------

   line(b[0][0], b[0][1], b[1][0], b[1][1]);
   line(b[1][0], b[1][1], b[2][0], b[2][1]);
   line(b[2][0], b[2][1], b[0][0], b[0][1]);

   line(c[0][0], c[0][1], c[1][0], c[1][1]);
   line(c[1][0], c[1][1], c[2][0], c[2][1]);
   line(c[2][0], c[2][1], c[0][0], c[0][1]);
    getch();
    closegraph();

    return 0;
}


