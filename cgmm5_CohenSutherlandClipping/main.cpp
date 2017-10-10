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

    int x1, y1, x2, y2, lx1, ly1, lx2, ly2;

    printf("Enter clipping screen dimensions x1, x2, y1, y2: ");
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);

    printf("Enter line co-ordinates x1, y1 and x2, y2: ");
    scanf("%d%d%d%d", &lx1, &ly1, &lx2, &ly2);


    printf("The clipped line is as follows:");



    line(x1, y1, x2, y1);
    line(x1, y2, x2, y2);
    line(x1, y1, x1, y2);
    line(x2, y1, x2, y2);

    if(lx1 < x1 && lx2 > x2){
        while(lx1<x1){
}
    }






   getch();
   closegraph();

    return 0;
}
