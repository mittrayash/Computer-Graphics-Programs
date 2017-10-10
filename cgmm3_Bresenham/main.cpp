#include <stdio.h>
#include <graphics.h>
int main(){
    int gdriver = DETECT, gmode, errorCode;
    int x1, y1, x2, y2, dx, dy, p, i, x, y, Eend;
    initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
    errorCode = graphresult();
    if(errorCode != 0){
        printf("Graphic error", grapherrormsg(errorCode));
        exit(1);}
    puts("Enter x1, x2, y1, y2");
    scanf("%d%d%d%d", &x1, &x2, &y1, &y2);
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    p = 2*dy - dx;
    if(x1 > x2){
        x = x2;
        y = y2;
        Eend = x1;}
    else{
        x = x1;
        y = y1;
        Eend = y2;}
    putpixel(x, y, RED);
    for(i=x; i<Eend; i++){
        x = x+1;
        if(p < 0){
            p = p + 2*dy;
        }
        else{
            y = y+1;
            p = p + 2*(dy-dx);
        }
        putpixel(x, y, RED);
    }
    getch();
    closegraph();

    return 0;
}
