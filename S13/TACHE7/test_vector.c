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
    if(argc >= 7){
        printf("Error\n");
        exit(1);
    }
    sscanf(argv[1], "%d", &Ax);
    sscanf(argv[2], "%d", &Ay);
    sscanf(argv[3], "%d", &Bx);
    sscanf(argv[4], "%d", &By);
    sscanf(argv[5], "%d", &x);
    sscanf(argv[6], "%d", &y);
    A = set_point(Ax, Ay);
    B = set_point(Bx, By);
    S.P1 = A;
    S.P2 = B;
    P = set_point(x,y);
    distance = distance_point_to_line(P,S);
    printf("The distance between the point B andsegment is: %2.5f \n", distance);
    return 0;

}