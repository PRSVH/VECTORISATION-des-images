#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "contour.h"
#include "image.h"
#include "robot.h"

int main(int argc,char** argv ){
    Image I;
    Point p;
    FILE *file_simple_eps_1;
    FILE *file_simple_eps_2;
    List_Multiple_Contours contours;
    double d;

    if (argc < 3) {
        puts("Input format :filename distance_seuil");
        return 1;
    }

    sscanf(argv[2],"%lf",&d);


    I=lire_fichier_image(argv[1]);

    char fileNameSimple1 [100];
    strcat(fileNameSimple1,argv[1]);
    strcat(fileNameSimple1,"_simple1.ps");
    file_simple_eps_1 = fopen(fileNameSimple1, "w");

    contours = find_multiple_contour(I,NULL,NULL,false);

    write_all_simple_segments_eps(I, contours,file_simple_eps_1,d);

    return 0;
    
}