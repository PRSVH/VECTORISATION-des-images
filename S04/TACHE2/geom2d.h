typedef struct Vector_{
    double x,y;
}Vector;

typedef struct Point_
{
    double x,y;
}Point;

Point set_point(double x, double y);

Point add_point(Point P1, Point P2);

Vector vect_bipoint(Point A,Point B);

Point int_product(Point A, double a);

double scalar_product(Vector A, Vector B);

double euclidean_norm(Vector A);

double distance_points(Point A, Point B);

void find_line(Point A, Point B);

void printPoint(Point P);

void printVector(Vector V);

void distance_point_to_line(Point P, Point A, Point B)
