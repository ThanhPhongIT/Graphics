#include<graphics.h>
#include<iostream>
using namespace std;
void put2pixel(int x, int y, int x1, int y1){
    putpixel(-x+x1, -y+y1, 15);
    putpixel(-y+x1, -x+y1, 15);
}
void phanTuthuHaiDuongTron(int x1, int y1, int r){
    int x = 0;
    int y = r;
    int p = 3 - 2*r;
    while(x<=y){
        delay(20);
        put2pixel(x, y, x1, y1);
        x++;
        if(p<0){
            p = p + (4*x + 6);
        }else{
            y--;
            p = p + 4*(x-y) +10;
        }
    }
}
int main(){
    initwindow(600, 600);
    setcolor(15);
    phanTuthuHaiDuongTron(300, 200, 100);
    getch();
    closegraph();
    return 0;
}
