#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "robot.h"
#include "image.h"
#include "sequence_point.h"


void save_position(Point p);

Point find_initial_pixel(Image I);

void find_contour(Image I,FILE *file,FILE *file_eps);

// write the array version later for tache 6 and y
