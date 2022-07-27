#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "contour.h"
#include "image.h"
#include "robot.h"
#include "courbe_bezier.h"

int main(int argc,char** argv ){   	
	FILE *f;
    FILE *file;
    FILE *fileOut;
    int d;   
    sscanf(argv[2],"%d",&d); 

    char fileName [100];
    strcat(fileName,argv[1]);
    strcat(fileName,".contour");
    file = fopen(fileName, "w");

    char fileNameOut [100];
    strcat(fileNameOut,argv[1]);
    strcat(fileNameOut,".ps");
    fileOut = fopen(fileNameOut, "w");
    
    char fileNameOut1 [100];
    strcat(fileNameOut1,argv[1]);
    strcat(fileNameOut1,"curve.ps");
    f = fopen(fileNameOut1, "w");

    Image I;
    I=lire_fichier_image(argv[1]);
    List_Multiple_Contours contours;
    contours = find_multiple_contour(I,file,fileOut);
    void write_all_courbe_bezier_eps(f,I,contours,d);
       
    

    return 0;
}