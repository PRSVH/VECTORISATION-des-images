#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include"geom2d.h"

int main(int argc,char ** argv){
    Point A,B,C,P,Q;
    Vector V;
    A = set_point(1.0, -3.0);
    B = set_point(4.0, 1.0);
    C = add_point(A,B);
    P = set_point(3.0, 2.0);
    Q = set_point(2.0, 6.0);
    printf("Point A is: ");
    printPoint(A);
    printf("Point B is: ");
    printPoint(B);
    printf("Point C is: ");
    printPoint(C);
    find_line(A,B);
    printf("Point P is: ");
    printPoint(P);
    printf("Point Q is: ");
    printPoint(Q);
    find_line(P,Q);
    printf("The distance between A and B is :%f\n",distance_points(A,B));
    V = vect_bipoint(C,A);
    printf("The midpoint of A and C (V) is: ");
    printVector(V);
    double a;
    printf("Insert integer a: ");
    scanf("%lf",&a);
    printf("The product of A by integer a is :");
    printPoint(int_product(A,a));
    Vector U = vect_bipoint(A,B);
    printf("The midpoint of A and B (U) is: ");
    printVector(U);
    printf("The scalar product of vector V and U is %f\n",scalar_product(U,V));
    printf("The euclidean norm of U is %f\n",euclidean_norm(U));

}
