#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "robot.h"
#include "image.h"
#include "sequence_point.h"



void save_position(Point p);

Point find_initial_pixel(Image I);

void find_contour(Image I,Image *M,int *countToWhites,int *countSegments,Point initial_pixel,List_Multiple_Contours* multi_contours);

Image create_image_mask(Image I,int *countBlacks);

void find_multiple_contour(Image I,FILE *file,FILE *file_eps);

void write_in_files(Image I,List_Multiple_Contours multi_contours, FILE* file, FILE* file_eps);
// write the array version later for tache 6 and y




