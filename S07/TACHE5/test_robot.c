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


    I=lire_fichier_image(argv[1]);

    // int c =0;
    // Image M = create_image_mask(I,&c);
    // ecrire_image(M);
    // p= find_initial_pixel(I);
    // printf("%d",c);   

    // printf("Nom de fichier: %s\n",argv[1]);

    char fileName [100];
    strcat(fileName,argv[1]);
    strcat(fileName,".contour");
    file = fopen(fileName, "w");

    char fileNameOut [100];
    strcat(fileNameOut,argv[1]);
    strcat(fileNameOut,".ps");
    fileOut = fopen(fileNameOut, "w");

    find_multiple_contour(I,file,fileOut);


    // find_contour(I,p,file,fileOut);

    return 0;

}