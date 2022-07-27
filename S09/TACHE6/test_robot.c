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
    FILE *file;
    FILE *fileOut;
    FILE *file_simple_eps_1;
    FILE *file_simple_eps_2;
    List_Multiple_Contours contours;
    double d;
    sscanf(argv[2],"%lf",&d);


    I=lire_fichier_image(argv[1]);

    char fileName [100];
    strcat(fileName,argv[1]);
    strcat(fileName,".contour");
    file = fopen(fileName, "w");

    char fileNameOut [100];
    strcat(fileNameOut,argv[1]);
    strcat(fileNameOut,".ps");
    fileOut = fopen(fileNameOut, "w");

    char fileNameSimple1 [100];
    strcat(fileNameSimple1,argv[1]);
    strcat(fileNameSimple1,"_simple1.ps");
    file_simple_eps_1 = fopen(fileNameSimple1, "w");

    contours = find_multiple_contour(I,file,fileOut);

    write_all_simple_segments_eps(I, contours,file_simple_eps_1,d);

    return 0;
    
}