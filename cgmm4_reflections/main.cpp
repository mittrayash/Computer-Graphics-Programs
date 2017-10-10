#include <stdio.h>
#include <graphics.h>

int main()
{


 int x, y, a, b, c, d, i, j, k;
   int x1, y1, x2, y2;

    int gdriver = DETECT, gmode, errorCode;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic error", grapherrormsg(errorCode));
        exit(1);

    }

    printf("Enter the x1 and y1 co-ordinates of line which is to be reflected in all 4 quads: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the x2 and y2 co-ordinates of line which is to be reflected in all 4 quads: ");
    scanf("%d%d", &x2, &y2);
    printf("The reflections in all 4 quads are shown now.");
    int lin[3][3] = {{x1, y1, 1}, {x2, y2, 1}, {0, 0, 1}};

    int cas = 1;

    while(cas<5){
            int ans[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (cas == 1){
    a = 1; b = 0; c = 0; d = 1;}
    else if (cas == 2){
    a = 1; b = 0; c = 0; d = -1;}
    else if (cas == 3){
        a = -1; b = 0; c = 0; d = 1;}
    else if (cas == 4){
        a = -1; b = 0; c = 0; d = -1;}



int tr[3][3] = {{a, b, 0}, {c, d, 0}, {0, 0, 1}};

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
             ans[i][j]   += lin[i][k]*tr[k][j];
}}}

printf("\nOutput: \n");
   for(i=0; i<3; i++){
    for(j=0; j<3; j++){
        printf("%d ", ans[i][j]);
    }
    printf("\n");
   }
        line(ans[0][0]+getmaxx()/2, ans[0][1]+getmaxy()/2, ans[1][0]+getmaxx()/2, ans[1][1]+getmaxy()/2);
    cas++;
}
getch();
closegraph();





    return 0;
}


