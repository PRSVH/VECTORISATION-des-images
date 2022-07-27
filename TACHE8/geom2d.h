#ifndef _GEOM2D_H_
#define _GEOM2D_H_

typedef struct Vector_{
    double x,y;
}Vector;

typedef struct Point_
{
    double x,y;
}Point;

typedef struct Segment_
{
    Point P1;
    Point P2;
}Segment;

/*Types courbe bezier degrée 2 et 3 utilisés dans TACHE7*/
typedef struct CourbeBezier_2_
{
    Point C0;
    Point C1;
    Point C2;
    
}CourbeBezier_2;

typedef struct CourbeBezier_3_
{
    Point C0;
    Point C1;
    Point C2;
    Point C3;
    
}CourbeBezier_3;


Point set_point(double x, double y);

Point add_point(Point P1, Point P2);

Point substract_point(Point P1, Point P2);

Vector vect_bipoint(Point A,Point B);

Point int_product(Point A, double a);

double scalar_product(Vector A, Vector B);

double euclidean_norm(Vector A);

double distance_points(Point A, Point B);

void find_line(Point A, Point B);

void printPoint(Point P);

void printVector(Vector V);

double distance_point_to_line(Point P, Segment S);

Point add_points(Point P1, Point P2);

Point int_division(Point A, double a);

#endif
