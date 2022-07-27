#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "image.h"

typedef struct Point_
{
    double x,y;

}Point;

typedef struct Pixel_Point_
{
    Pixel color;
    Point p;

}Pixel_Point;

typedef enum { North, East, South, West } Orientation;

typedef struct {
  Point p;
  Orientation o;
}Robot;

/* initialiser le robot r en position (x,y) et orientation o */
void initialize_Robot(Robot *r, Point p,Orientation o);

/* faire avancer le robot d'une case */
void move(Robot *r);

/* faire tourner le robot à gauche */
void turn_left(Robot *r);

/* faire tourner le robot à droite */
void turn_right(Robot *r);

/* recupere la position de la case du robot */
void position(Robot *r, Point *p);

/* recupere la position en abscisse de la case du robot */
int abscisse(Robot *r);

/* recupere la position en ordonnee de la case du robot */
int ordonnee(Robot *r);

/* recupere l'orientation du robot */
Orientation orient(Robot *r);

Orientation new_orientation(Point p,Image I,Robot *r);

/* recupere la position de la case devant le robot */
void position_devant(Robot *r, int *x, int *y);

void value_of_pixel(Image I,Robot *r,Pixel*p_r,Pixel*p_l,Point p);

void value_of_pixel_right(Image I,Robot *r,Pixel*p_r,Point p);

#endif
