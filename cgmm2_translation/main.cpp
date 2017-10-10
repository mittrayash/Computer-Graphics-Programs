#include <stdio.h>
#include <graphics.h>

int tx, ty;
int b[3][3], c[3][3];
int a[3][3] = {{1,0,tx}, {0, 1, ty}, {0, 0, 1}};
//NOTE: EVEN WHEN WE NEED A 3x3 MATRIX, WE DO NOT INITIALIZE IT AS A[2][2]. WRONG!
//INITIALIZE BY A[3][3] AND THE COLUMN NAMES WOULD BE: A[][0], A[][1] AND A[2].
//RELATE TO 1D ARRAYS WHERE A[10] WILL STORE 10 ELEMENTS IN INDICES 0-9.
void takeData(int a[3][3], int b[3][3]){
printf("Enter x1, x2, x3: ");
scanf("%d%d%d", &b[0][0], &b[0][1], &b[0][2]);
printf("\nEnter y1, y2, y3: ");
scanf("%d%d%d", &b[1][0], &b[1][1], &b[1][2]);
b[2][0] = 1;
 b[2][1] = 1;
 b[2][2] = 1;


   line(b[0][0], b[1][0], b[0][1], b[1][1]);
   line(b[0][2], b[1][2], b[0][1], b[1][1]);
   line(b[0][0], b[1][0], b[0][2], b[1][2]);

   printf("Enter translation factors for x & y: ");
    scanf("%d%d", &tx, &ty);

a[0][2] = tx;
a[1][2] = ty;
}

void MatrixMultiply(int a[3][3],int b[3][3]){

    int i, j, k;
    //SET ZERO--------------------
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            c[i][j] = 0;

        }
    }
    //-----------------------
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
             c[i][j]   += a[i][k]*b[k][j];
            }
        }
    }
}
void display(int c[3][3]){
   int i, j;
   printf("\nOutput: \n");
   for(i=0; i<3; i++){
    for(j=0; j<3; j++){
        printf("%d ", c[i][j]);
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
   line(c[0][0], c[1][0], c[0][1], c[1][1]);
   line(c[0][1], c[1][1], c[0][2], c[1][2]);
   line(c[0][2], c[1][2], c[0][0], c[1][0]);

    getch();
    closegraph();

    return 0;
}
