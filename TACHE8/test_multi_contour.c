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
    

    if (argc < 2) {
        puts("Input format :filename");
        return 1;
    }
    I=lire_fichier_image(argv[1]);

    char fileName [100];
    strcat(fileName,argv[1]);
    strcat(fileName,".contour");
    file = fopen(fileName, "w");

    char fileNameOut [100];
    strcat(fileNameOut,argv[1]);
    strcat(fileNameOut,".ps");
    fileOut = fopen(fileNameOut, "w");

    find_multiple_contour(I,file,fileOut,true);


    // find_contour(I,p,file,fileOut);

    return 0;

}