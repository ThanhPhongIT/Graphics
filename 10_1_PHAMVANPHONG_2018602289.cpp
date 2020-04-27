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
    float x = xmin; float y = -2*x*x + 1;
    chuyenden2D(x,y);
    while(x <= xmax){
        x = x + dx;
        y = -2*x*x + 1;
        veden2D(x,y);
    }
}
void tinhtien(float x, float y, float m, float n,float &x1, float &y1){
     x1 = x+m; y1 = y+n;
}
void quayQuayGoc(float x,float y, float &x1, float&y1, float alpha){
     x1 = x*cos(alpha) - y*sin(alpha);
     y1 = x*sin(alpha) + y*cos(alpha);
}
void quayQuanhDiem(float x, float y,float m, float n, float&x1, float &y1){
    float x11, y11, x12, y12;
    tinhtien(x,y,0,n,x11,y11);
    quayQuayGoc(x11,y11,x12,y12,-M_PI/2);
    tinhtien(x12,y12,0,-n,x1,y1);

}
void veAnhDoThi(float xmin, float xmax){
    float dx = 0.1;
    float x = xmin; float y = -2*x*x + 1;
    float x1,y1;
    quayQuanhDiem(x,y,0,1,x1,y1);
    chuyenden2D(x1,y1);
    while(x <= xmax){
        x = x + dx;
        y = -2*x*x + 1;
        quayQuanhDiem(x,y,0,1,x1,y1);
        veden2D(x1,y1);
    }
}

int main(){
    int gd=0, gm;
    initgraph(&gd,&gm,"");
    cuaso(-6, 2, 4, -8);
    khungnhin(150,50,650,550);
    setcolor(10);
    vetructoado();
    veDoThi(0, 2);
    veAnhDoThi(0, 2);
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
    float x = xmin; float y = -2*x*x + 1;
    chuyenden2D(x,y);
    while(x <= xmax){
        x = x + dx;
        y = -2*x*x + 1;
        veden2D(x,y);
    }
}
void tinhtien(float x, float y, float m, float n,float &x1, float &y1){
     x1 = x+m; y1 = y+n;
}
void quayQuayGoc(float x,float y, float &x1, float&y1, float alpha){
     x1 = x*cos(alpha) - y*sin(alpha);
     y1 = x*sin(alpha) + y*cos(alpha);
}
void quayQuanhDiem(float x, float y,float m, float n, float&x1, float &y1){
    float x11, y11, x12, y12;
    tinhtien(x,y,0,n,x11,y11);
    quayQuayGoc(x11,y11,x12,y12,-M_PI/2);
    tinhtien(x12,y12,0,-n,x1,y1);

}
void veAnhDoThi(float xmin, float xmax){
    float dx = 0.1;
    float x = xmin; float y = -2*x*x + 1;
    float x1,y1;
    quayQuanhDiem(x,y,0,1,x1,y1);
    chuyenden2D(x1,y1);
    while(x <= xmax){
        x = x + dx;
        y = -2*x*x + 1;
        quayQuanhDiem(x,y,0,1,x1,y1);
        veden2D(x1,y1);
    }
}

int main(){
    int gd=0, gm;
    initgraph(&gd,&gm,"");
    cuaso(-6, 2, 4, -8);
    khungnhin(150,50,650,550);
    setcolor(10);
    vetructoado();
    veDoThi(0, 2);
    veAnhDoThi(0, 2);
    getch();
    closegraph();
}
>>>>>>> d48019152e324cf5d935541d2ad290a894ee29dd
