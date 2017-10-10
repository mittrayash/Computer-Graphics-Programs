#include <stdio.h>
#include <graphics.h>
#include <math.h>


float t;
static float b[3][3], c[3][3];
static float a[3][3];
//NOTE: EVEN WHEN WE NEED A 3x3 MATRIX, WE DO NOT INITIALIZE IT AS A[2][2]. WRONG!
//INITIALIZE BY A[3][3] AND THE COLUMN NAMES WOULD BE: A[][0], A[][1] AND A[2].
//RELATE TO 1D ARRAYS WHERE A[10] WILL STORE 10 ELEMENTS IN INDICES 0-9.
void takeData(float a[3][3], float b[3][3]){

b[0][0] = 300;
b[0][1] = 400;
b[0][2] = 1;

b[1][0] = 400;
b[1][1] = 300;
b[1][2] = 1;

b[2][0] = 500;
b[2][1] = 400;
b[2][2] = 1;

puts("Enter rotation angle: ");
scanf("%f", &t);

t = (3.1416*t)/180;

a[0][0] = (float)(cos(t));
a[0][1] = (float)(-sin(t));
a[0][2] = 0;

a[1][0] = (float)(sin(t));
a[1][1] = (float)cos(t);
a[1][2] = 0;

a[2][0] = 0;
a[2][1] = 0;
a[2][2] = 1;


}

void MatrixMultiply( float a[3][3], float b[3][3]){

  int    i, j, k;
    //SET ZERO--------------------
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            c[i][j] = 0;
            }}
            for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
             c[i][j]   += b[i][k]*a[k][j];
            }}}
}

void display(float c[3][3]){
   int i, j;
   printf("\nOutput: \n");
   for(i=0; i<3; i++){
    for(j=0; j<3; j++){
        printf("%.2f ", (float)c[i][j]);
    }
    printf("\n");
   }

}

int main()
{
     int gdriver = DETECT, gmode, errorCode;


    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic error", grapherrormsg(errorCode));
        exit(1);
    }

    takeData(a, b);
    MatrixMultiply(a, b);
    display(c);

   line(b[0][0], b[0][1], b[1][0], b[1][1]);
   line(b[1][0], b[1][1], b[2][0], b[2][1]);
   line(b[2][0], b[2][1], b[0][0], b[0][1]);

   line(c[0][0], c[0][1]+500, c[1][0], c[1][1]+500);
   line(c[1][0], c[1][1]+500, c[2][0], c[2][1]+500);
   line(c[2][0], c[2][1]+500, c[0][0], c[0][1]+500);

    getch();
    closegraph();

    return 0;
}
