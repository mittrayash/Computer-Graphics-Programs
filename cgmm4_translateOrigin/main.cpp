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


int ln, br, x = 0, y = 0;

printf("Enter the length and width of the rectangle: ");
scanf("%d%d", &ln, &br);

   x = getmaxx()/2;
   y = getmaxy()/2;

   line(x+ln, y+br, x-ln, y+br);
   line(x+ln, y-br, x-ln, y-br);
   line(x-ln, y-br, x-ln, y+br);
   line(x+ln, y-br, x+ln, y+br);


   getch();
   closegraph();

    return 0;
}
