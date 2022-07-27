#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "image.h"
#include "types_macros.h"

int main(int argc,char ** argv){
    if(argc< 2){
        printf("ERROR");
    }

    Image I;
    I = lire_fichier_image(argv[1]);
    ecrire_image(I);
    printf("\n");
    ecrire_image(negatif_image(I));
    return 0;
}