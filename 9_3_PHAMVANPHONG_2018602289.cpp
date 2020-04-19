#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;
typedef struct {
    float x;    float y;    float z;
}Diem3D;
typedef struct{
    int x;  int y;
}Diem2Di;
typedef struct{
    float x;    float y;
}Diem2Df;
typedef struct{
    Diem3D d1;      Diem3D d2;
}Canh;
float R,phi,teta,D,tlx,tly;
int phepChieu;
Diem2Di O;
Diem3D a[8];
Canh c[12];
float ScaleX=1,ScaleY=1,ScaleZ=1;
void chuyenHQS(Diem3D m,Diem3D &mv){
    mv.x=-m.x*sin(teta)+m.y*cos(teta);
    mv.y=-m.x*cos(teta)*sin(phi)-m.y*sin(teta)*sin(phi)+m.z*cos(phi);
    mv.z=-m.x*sin(teta)*cos(phi)-m.y*cos(teta)*sin(phi)-m.z*sin(phi)+R;
}
void chieu3D_2D(Diem3D mv,Diem2Df &mp){
    if(phepChieu==1){
        mp.x=mv.x*D/mv.z;       mp.y=mv.y*D/mv.z;
    }
    else{
        mp.x=mv.x;      mp.y=mv.y;
    }
}
void chuyenMH(Diem2Df mp,Diem2Di &mi){
    mi.x=(int)(tlx*mp.x+O.x+0.5);
    mi.y=(int)(-tly*mp.y+O.y+0.5);
}
void chuyenDen3D(Diem3D m){
    Diem3D mv;      Diem2Df mp;     Diem2Di mi;
    chuyenHQS(m,mv);
    chieu3D_2D(mv,mp);
    chuyenMH(mp,mi);
    moveto(mi.x,mi.y);
}
void veDen3D(Diem3D m){
    Diem3D mv;      Diem2Df mp;     Diem2Di mi;
    chuyenHQS(m,mv);
    chieu3D_2D(mv,mp);
    chuyenMH(mp,mi);
    lineto(mi.x,mi.y);
}
void khoiTao(){
    R= 7;    teta= 30;     phi= 60;      D=4;       tlx= 200;      tly= 200;
    teta=teta*M_PI/180;     phi=phi*M_PI/180;       phepChieu=1;
    O.x=getmaxx()/2;
    O.y=getmaxy()/2;
}
void khoiTaoDinhHLP(){
    a[0].x=1;       a[0].y=0;        a[0].z=1;
    a[1].x=0;       a[1].y=0;        a[1].z=1;
    a[2].x=0;       a[2].y=1;        a[2].z=1;
    a[3].x=1;       a[3].y=1;        a[3].z=1;
    a[4].x=1;       a[4].y=0;        a[4].z=0;
    a[5].x=0;       a[5].y=0;        a[5].z=0;
    a[6].x=0;       a[6].y=1;        a[6].z=0;
    a[7].x=1;       a[7].y=1;        a[7].z=0;
}
void khoiTaoCanhHLP(){
    c[0].d1=a[0];        c[0].d2=a[1];
    c[1].d1=a[1];        c[1].d2=a[2];
    c[2].d1=a[2];        c[2].d2=a[3];
    c[3].d1=a[3];        c[3].d2=a[0];
    c[4].d1=a[4];        c[4].d2=a[5];
    c[5].d1=a[5];        c[5].d2=a[6];
    c[6].d1=a[6];        c[6].d2=a[7];
    c[7].d1=a[7];        c[7].d2=a[4];
    c[8].d1=a[0];        c[8].d2=a[4];
    c[9].d1=a[1];        c[9].d2=a[5];
    c[10].d1=a[2];        c[10].d2=a[6];
    c[11].d1=a[3];        c[11].d2=a[7];
}
void tile(){
    for(int i=0;i<12;i++){
        a[i].x*=ScaleX;
        a[i].y*=ScaleY;
        a[i].z*=ScaleZ;
    }
    khoiTaoCanhHLP();
}
void veHLP(){
    for(int i=0;i<12;i++){
        chuyenDen3D(c[i].d1);
        veDen3D(c[i].d2);
    }
}
int main(){
    cout<<"\nScaleX: ";     cin>>ScaleX;
    cout<<"\nScaleY: ";     cin>>ScaleY;
    cout<<"\nScaleZ: ";     cin>>ScaleZ;
    initwindow(640,480);

    khoiTao();
    khoiTaoDinhHLP();
    khoiTaoCanhHLP();
    veHLP();
    delay(1000);

    setcolor(0);
    veHLP();
    delay(200);

    setcolor(15);
    tile();
    khoiTaoCanhHLP();
    veHLP();

    getch();
    closegraph();
    return 0;
}
