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
float tx, ty;
int i, j, k;

printf("Enter the values of scaling factors Sx and Sy : ");
scanf("%d%d", &sx, &sy);

float mat[3][3] = {{300,400,1}, {400,300,1}, {500,400,1}}, c[3][3];

    line(mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
    line(mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
    line(mat[2][0], mat[2][1], mat[0][0], mat[0][1]);


printf("Enter the point co-ordinates x & y about which scaling is to take place : ");
scanf("%f%f", &tx, &ty);

float a[3][3] = {{1, 0, 0}, {0, 1, 0}, {-tx, -ty, 1}}, c[3][3] = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}};;
float b[3][3] = {{sx,0,0}, {0, sy, 0}, {0, 0, 1}};


static float d[3][3], T[3][3], ans[3][3];

//SET ZERO--------------------
    for(i = 0; i<3; i++){
        for(j = 0; j<3; j++){
            d[i][j] = 0;
            T[i][j] = 0;
            ans[i][j] = 0;
        }
    }
    //MULTIPLY 1---------------------
        for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
             d[i][j]   += b[i][k]*c1[k][j];
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



   line(ans[0][0], ans[0][1], ans[1][0], ans[1][1]);
   line(ans[1][0], ans[1][1], ans[2][0], ans[2][1]);
   line(ans[2][0], ans[2][1], ans[0][0], ans[0][1]);

    getch();
    closegraph();

    return 0;
}
