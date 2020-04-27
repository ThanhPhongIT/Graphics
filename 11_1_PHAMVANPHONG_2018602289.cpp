#include<graphics.h>
#include<iostream>
using namespace std;
void TH4(int x1, int y1, int x2, int y2){
    if(x1 > x2){
        int tg = x1;
        x1 = x2;
        x2 = tg;
        tg = y1;
        y1 = y2;
        y2 = tg;
    }
    int x = x1;
    float y=y1;
    float const1 = 2*(y2-y1);
    float const2 = 2*(y2 -y1) + 2*(x2-x1);
    float p = 2*(y2-y1) + (x2 - x1);
    putpixel(x, y, 15);
    while(x <= x2){
        x++;
        if(p>0){
            p += const1;
        }else{
            y--;
            p += const2;
        }
        putpixel(x, y, 15);
    }
}
int main(){
    initwindow(300, 300);
    setcolor(5);
    TH4(150,100,100,120);
    getch();
    closegraph();
    return 0;
}
