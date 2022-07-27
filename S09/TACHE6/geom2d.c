#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


#include"geom2d.h"

Point set_point(double x, double y){
    Point p = {x,y};
    return p;
}

Point add_point(Point P1, Point P2){
    return set_point(P1.x+P2.x,P1.y+P2.y);
}



Vector vect_bipoint(Point A,Point B){
    Vector V ={B.x-A.x,B.y-A.y};
    return V;
}

void printPoint(Point P){
    printf("%f %f\n",P.x,P.y);
}

void printVector(Vector V){
    printf("%f %f\n",V.x,V.y);

}

Point int_product(Point A, double a){
    Point P = {a*A.x,a*A.y};
    return P;
}

double scalar_product(Vector A, Vector B){

    return A.x*B.x+A.y*B.y;
}

double euclidean_norm(Vector A){

    return sqrt(pow(A.x,2)+pow(A.y,2));
}

double distance_points(Point A, Point B){

    return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));
}

void find_line(Point A, Point B){
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = a * (A.x) + b * (A.y);
 
    if (b < 0) {
        printf("The line passing through two points given is: %f x + %f y = %f\n",a,b*-1,c);
    }
    else {
        printf("The line passing through two points given is: %f x + %f y = %f\n",a,b,c);
    }
}

int comp_Points(Point A, Point B){
    if ((A.x==B.x)&&(A.y==B.y)){
        return 1;
    }
    return 0;
}
Point substract_point(Point A, Point B){
    Point P;
    P.x = B.x - A.x;
    P.y = B.y - A.y;
    return P;
}
double distance_point_to_line(Point P, Segment S){
    double x;
    double distance;
    Point A,B,Q;
    A = S.P1;
    B = S.P2;

    if (comp_Points(A,B)==1){
        distance=distance_points(A, P);
    }
    else{
        x= scalar_product(vect_bipoint(A,P),vect_bipoint(A,B))/scalar_product(vect_bipoint(A,B),vect_bipoint(A,B));
        // printf("lambda is : %lf \n",x);
        if (x<0){   
            distance=distance_points(A,P);
        }else if (x>1){
            distance= distance_points(B,P);
        }
        else{
            Q=add_point(int_product(substract_point(A,B),x),A);
            distance=distance_points(Q,P);
        }
    }
    
    return distance;  
}

