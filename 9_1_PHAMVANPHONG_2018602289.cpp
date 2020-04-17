# include <graphics.h>
# include <math.h>
#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct
{
    float x; float y; float z;
}Diem3D;
typedef struct
{
    int x; int y;
}Diem2Di;
typedef struct
{
    float x; float y;
}Diem2Df;
typedef struct
{
    Diem3D d1; Diem3D d2;
}Canh;
float R, phi, teta, D, tlx, tly;
int phepchieu; //Quy uoc phepchieu = 1: phoi canh = 0: song song
Diem2Di o; // O goc toa do hien thi tren man hinh
Diem3D a[8];
Canh c[12];
// Xay dung cac ham phu tro
void chuyenhqs(Diem3D m, Diem3D &mv )
// Tính Mv la toa do cua M trong he toa do quan sat
{
    mv.x= -m.x*sin(teta)+m.y*cos(teta);
    mv.y= -m.x*cos(teta)*sin(phi)-m.y*sin(teta)*sin(phi)+m.z*cos(phi);
    mv.z= -m.x*sin(teta)*cos(phi) - m.y*cos(teta)*sin(phi)-m.z*sin(phi)+R;
}
void chieu3D_2D (Diem3D mv, Diem2Df &mp )
// Tinh toa do Mp tren mat phang chieu P
{
    if (phepchieu==1)
     { mp.x=D*mv.x/mv.z; mp.y=D*mv.y/mv.z;}
     else
     { mp.x=mv.x; mp.y=mv.y;}
}
void chuyenmh(Diem2Df mp, Diem2Di &mm)
//Tinh toa do Mm trên màn hình tuong ung voi Mp
{
    mm.x= (int) (tlx*mp.x+o.x+0.5);
    mm.y= (int) (-tly*mp.y +o.y+0.5);
}
// Hai ham ve doan thang
void chuyenden3D(Diem3D m)
{
    Diem3D mv; Diem2Df mp; Diem2Di mm;
    chuyenhqs(m,mv);
    chieu3D_2D(mv,mp);
    chuyenmh(mp,mm);
    moveto(mm.x,mm.y);
}
void veden3D(Diem3D m)
{
     Diem3D mv; Diem2Df mp; Diem2Di mm;
     chuyenhqs(m,mv);
     chieu3D_2D(mv,mp);
     chuyenmh(mp,mm);
     lineto(mm.x,mm.y);
}
void khoitao()
{
     R=7; phi=60; teta=30; D=4; tlx=200; tly=200;
     teta=teta*M_PI/180; phi=phi*M_PI/180;
     phepchieu=1;
     o.x=getmaxx()/2;
     o.y=getmaxy()/2;
}
void input(){
    char a[1];
    cout<<"Nhap vao 1 trong cac phim p,t,r,d: ";      fflush(stdin); gets(a);
    if(strcmp(a,"p")==0||strcmp(a,"P")==0){
        phi++;
    }
    if(strcmp(a,"t")==0||strcmp(a,"T")==0){
        teta++;
    }
    if(strcmp(a,"r")==0||strcmp(a,"R")==0){
        R++;
    }
    if(strcmp(a,"d")==0||strcmp(a,"D")==0){
        D++;
    }
}
void khoitaoHLP()
{
     //Khoi tao cac dinh
     a[0].x=1; a[0].y=0; a[0].z=1;
     a[1].x=0; a[1].y=0; a[1].z=1;
     a[2].x=0; a[2].y=1; a[2].z=1;
     a[3].x=1; a[3].y=1; a[3].z=1;
     a[4].x=1; a[4].y=1; a[4].z=0;
     a[5].x=1; a[5].y=0; a[5].z=0;
     a[6].x=0; a[6].y=0; a[6].z=0;
     a[7].x=0; a[7].y=1; a[7].z=0;
     //Khoi tao cac canh
     c[0].d1=a[0]; c[0].d2=a[1];
     c[1].d1=a[1]; c[1].d2=a[2];
     c[2].d1=a[2]; c[2].d2=a[3];
     c[3].d1=a[3]; c[3].d2=a[0];
     c[4].d1=a[3]; c[4].d2=a[4];
     c[5].d1=a[2]; c[5].d2=a[7];
     c[6].d1=a[1]; c[6].d2=a[6];
     c[7].d1=a[0]; c[7].d2=a[5];
     c[8].d1=a[5]; c[8].d2=a[6];
     c[9].d1=a[5]; c[9].d2=a[4];
     c[10].d1=a[4]; c[10].d2=a[7];
     c[11].d1=a[7]; c[11].d2=a[6];
}
void veHLP(){
    for(int i=0; i<12; i++){
         chuyenden3D(c[i].d1);
         veden3D(c[i].d2);
    }
}
void nhap(){

}
int main()
{
     input();
     int gd=0, gm;
     initgraph(&gd, &gm, "");
     khoitao();
     khoitaoHLP();
     veHLP();
     getch();
     closegraph();
     return 0;
}
