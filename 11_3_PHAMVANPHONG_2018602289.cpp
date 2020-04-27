#include<graphics.h>
#include<iostream>
using namespace std;

void toMauHinhThangX(int x1, int x2, int yA, int yB, int yC, int yD, int mt){
    int x = x1;
    do{
        float yM1 = (yD - yA)*(x - x1)/(x2-x1) + yA;
        float yM2 = (yC - yB)*(x - x1)/(x2-x1) + yB;
        setcolor(mt);
        line(x,yM1,x,yM2);
        x++;
    }while(x<=x2);
}
void toMauHinhThangY(int y1, int y2, int xA, int xB, int xC, int xD, int mt){
    int y = y1;
    do{
        float xM1 = (xD - xA)*(y - y1)/(y2-y1) + xA;
        float xM2 = (xC - xB)*(y - y1)/(y2-y1) + xB;
        setcolor(mt);
        line(y,xM1,y,xM2);
        y++;
    }while(y<=y2);
}
int main(){
    initwindow(600, 600);
    setcolor(15);
    toMauHinhThangX(100, 300, 350, 50, 150, 300, 4);
    toMauHinhThangX(20, 100, 250, 250, 50, 350, 4);
    getch();
    closegraph();
    return 0;
}
