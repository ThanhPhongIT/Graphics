<<<<<<< HEAD
#include<graphics.h>
#include<math.h>
float xwmin, xwmax, ywmin, ywmax;
float tlx, tly;
int xvmin, xvmax, yvmin, yvmax;
void cuaso(float x1, float y1, float x2, float y2){
    xwmin = x1;     ywmin = y1;
    xwmax = x2;     ywmax = y2;
}
void khungnhin(int x1, int y1, int x2, int y2){
    xvmin = x1;     yvmin = y1;
    xvmax = x2;     yvmax = y2;
    tlx = (xvmax - xvmin)/(xwmax - xwmin);
    tly = (yvmax - yvmin)/(ywmax - ywmin);
}
void chuyenden2D(float x,float y){
    int xm = (int)(tlx * (x - xwmin) + xvmin + 0.5);
    int ym = (int)(tly * (y - ywmin) + yvmin + 0.5);
    moveto(xm, ym);
}
void veden2D(float x, float y){
    int xm = (int)(tlx * (x - xwmin) + xvmin + 0.5);
    int ym = (int)(tly * (y - ywmin) + yvmin + 0.5);
    lineto(xm, ym);
}
void veDoThi(float xmin, float xmax){
    float dx = 0.1;
    float x = xmin; float y = 2*tan(x) - 1;
    chuyenden2D(x,y);
    while(x <= xmax){
        x = x + dx;
        y = 2*tan(x) - 1;
        veden2D(x,y);

    }
}
void vetructoado()
{
    chuyenden2D(xwmin,0);
    veden2D(xwmax,0);
    chuyenden2D(0,ywmin);
    veden2D(0,ywmax);
}
void tinhtien(float x, float y, float m, float n,float &x1, float &y1){
     x1=x+m; y1=y+n;
}
void doixungOx(float x,float y, float &x1, float&y1){
     x1=x; y1=-y;
}
//d: y=y0 //Ox
void doixungdssOx(float x, float y, float y0, float&x1, float &y1){
    float x11, y11, x12, y12;
    tinhtien(x,y,0,-y0,x11,y11);
    doixungOx(x11,y11,x12,y12);
    tinhtien(x12,y12,0,y0,x1,y1);
}
void veanhdothi(float xmin, float xmax)
{
    float dx=0.01;
    float x=xmin; float y=2*tan(x)-1;
    float x1, y1;
    doixungdssOx(x,y, -1, x1, y1);
    chuyenden2D(x1,y1);
    while (x<=xmax){
        x=x+dx;
        y=2*tan(x) - 1;
        doixungdssOx(x,y, -1, x1, y1);
        veden2D(x1,y1);
    }
}
void xoaDuong(){
    setcolor(BLACK);
    chuyenden2D(M_PI_2, 0);
    veden2D(M_PI_2, 1000);
    setcolor(BLACK);
    chuyenden2D(M_PI_2, 0);
    veden2D(M_PI_2, -1000);
}
int main(){
    int gd=0, gm;
    initgraph(&gd,&gm,"");
    cuaso(-4, 8, 4, -8);
    khungnhin(150,50,650,550);
    setcolor(10);
    vetructoado();
    veDoThi(-M_PI, M_PI);
    veanhdothi(-M_PI, M_PI);
    getch();
    closegraph();
}
=======
#include<graphics.h>
#include<math.h>
float xwmin, xwmax, ywmin, ywmax;
float tlx, tly;
int xvmin, xvmax, yvmin, yvmax;
void cuaso(float x1, float y1, float x2, float y2){
    xwmin = x1;     ywmin = y1;
    xwmax = x2;     ywmax = y2;
}
void khungnhin(int x1, int y1, int x2, int y2){
    xvmin = x1;     yvmin = y1;
    xvmax = x2;     yvmax = y2;
    tlx = (xvmax - xvmin)/(xwmax - xwmin);
    tly = (yvmax - yvmin)/(ywmax - ywmin);
}
void chuyenden2D(float x,float y){
    int xm = (int)(tlx * (x - xwmin) + xvmin + 0.5);
    int ym = (int)(tly * (y - ywmin) + yvmin + 0.5);
    moveto(xm, ym);
}
void veden2D(float x, float y){
    int xm = (int)(tlx * (x - xwmin) + xvmin + 0.5);
    int ym = (int)(tly * (y - ywmin) + yvmin + 0.5);
    lineto(xm, ym);
}
void veDoThi(float xmin, float xmax){
    float dx = 0.1;
    float x = xmin; float y = 2*tan(x) - 1;
    chuyenden2D(x,y);
    while(x <= xmax){
        x = x + dx;
        y = 2*tan(x) - 1;
        veden2D(x,y);

    }
}
void vetructoado()
{
    chuyenden2D(xwmin,0);
    veden2D(xwmax,0);
    chuyenden2D(0,ywmin);
    veden2D(0,ywmax);
}
void tinhtien(float x, float y, float m, float n,float &x1, float &y1){
     x1=x+m; y1=y+n;
}
void doixungOx(float x,float y, float &x1, float&y1){
     x1=x; y1=-y;
}
//d: y=y0 //Ox
void doixungdssOx(float x, float y, float y0, float&x1, float &y1){
    float x11, y11, x12, y12;
    tinhtien(x,y,0,-y0,x11,y11);
    doixungOx(x11,y11,x12,y12);
    tinhtien(x12,y12,0,y0,x1,y1);
}
void veanhdothi(float xmin, float xmax)
{
    float dx=0.01;
    float x=xmin; float y=2*tan(x)-1;
    float x1, y1;
    doixungdssOx(x,y, -1, x1, y1);
    chuyenden2D(x1,y1);
    while (x<=xmax){
        x=x+dx;
        y=2*tan(x) - 1;
        doixungdssOx(x,y, -1, x1, y1);
        veden2D(x1,y1);
    }
}
void xoaDuong(){
    setcolor(BLACK);
    chuyenden2D(M_PI_2, 0);
    veden2D(M_PI_2, 1000);
    setcolor(BLACK);
    chuyenden2D(M_PI_2, 0);
    veden2D(M_PI_2, -1000);
}
int main(){
    int gd=0, gm;
    initgraph(&gd,&gm,"");
    cuaso(-4, 8, 4, -8);
    khungnhin(150,50,650,550);
    setcolor(10);
    vetructoado();
    veDoThi(-M_PI, M_PI);
    veanhdothi(-M_PI, M_PI);
    getch();
    closegraph();
}
>>>>>>> d48019152e324cf5d935541d2ad290a894ee29dd
