#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include"geom2d.h"

int main(int argc,char ** argv){
    Segment S;
    Point A , B,P;
    double Ax,Ay,Bx,By,x,y;
    double distance;
    sscanf(argv[1], "%lf", &Ax);
    sscanf(argv[2], "%lf", &Ay);
    sscanf(argv[3], "%lf", &Bx);
    sscanf(argv[4], "%lf", &By);
    sscanf(argv[5], "%lf", &x);
    sscanf(argv[6], "%lf", &y);
    A = set_point(Ax, Ay);
    B = set_point(Bx, By);
    S.P1 = A;
    S.P2 = B;
    P = set_point(x,y);
    distance = distance_point_to_line(P,S);
    printf("A = (%2.4f, %2.4f) B = (%2.4f, %2.4f) P = (%2.4f, %2.4f)\nDistance = %2.5f\n",Ax,Ay,Bx,By,x,y, distance);

    return 0;

}