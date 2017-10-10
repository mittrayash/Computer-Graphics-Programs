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

float t, tx, ty;
int i, j, k;

float mat[3][3] = {{300,400,1}, {400,300,1}, {500,400,1}};
    line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
    line(mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
    line(mat[2][0], mat[2][1], mat[0][0], mat[0][1]);

printf("Enter the point co-ordinates x & y about which rotation is to take place : ");
scanf("%f%f", &tx, &ty);
printf("\nEnter the angle of rotation: ");
scanf("%f", &t);

t = (3.1416*t)/180;
static float a[3][3] = {{1, 0, 0}, {0, 1, 0}, {-tx, -ty, 1}};
static float b[3][3] = {{cos(t), -sin(t), 0}, {sin(t), cos(t), 0}, {0, 0, 1}};
static float c[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}}, d[3][3], T[3][3], ans[3][3];

    //MULTIPLY 1---------------------
        for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
             d[i][j]   += b[i][k]*c[k][j];
            }
        }
    }

     //MULTIPLY 2---------------------
        for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
             T[i][j]   += a[i][k]*d[k][j];
            }
        }
    }
     //MULTIPLY 3---------------------
        for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
             ans[i][j]   += mat[i][k]*T[k][j];
            }
        }
    }
     //DISPLAY----------------------
    printf("\nOutput: \n");
   for(i=0; i<3; i++){
    for(j=0; j<3; j++){
        printf("%.2f ", ans[i][j]);
    }
    printf("\n");
   }
outtextxy(10,10,"After Rotation");

   line(ans[0][0], ans[0][1], ans[1][0], ans[1][1]);
   line(ans[1][0], ans[1][1], ans[2][0], ans[2][1]);
   line(ans[2][0], ans[2][1], ans[0][0], ans[0][1]);

    getch();
    closegraph();

    return 0;
}
