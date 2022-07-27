#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "contour.h"
#include "image.h"
#include "robot.h"
#include "courbe_bezier.h"

int main(int argc,char** argv ){   	
	FILE *f,*file,*file_eps;
    Image I;
    List_Multiple_Contours contours;
    double d; 

    if (argc < 3) {
        puts("Input format :filename distance_seuil");
        return 1;
    }
    
    
    char fileNameOut1 [100];
    strcat(fileNameOut1,argv[1]);
    strcat(fileNameOut1,"_curve.ps");
    f = fopen(fileNameOut1, "w");


    //read distance_seuil
    sscanf(argv[2],"%lf",&d); 
    
    I=lire_fichier_image(argv[1]);
    contours = find_multiple_contour(I,NULL,NULL,false);
  

    Node_Multi_Contour* node;
    node = (Node_Multi_Contour *)malloc(sizeof(Node_Multi_Contour));
    node = contours.head;
    Tableau_Point cont;
    cont.size = 0;
    List_CourbeBezier_2 L;
    CourbeBezier_2 c;
    List_CourbeBezier_3 L_new;
    
    fprintf(f,"%%!PS−Adobe−3.0 EPSF−3.0\n");
	fprintf(f,"%%%%BoundingBox: 0 -%d %d 0\n",I.H,I.L);
    int totalCurve = 0;
    while (node !=NULL)
    {
        cont.size = 0;
        cont = sequence_points_List_vers_tableau(node->data);
        L = simplification_douglas_peucker_bezier2(cont,0,cont.size-1,d);
        
        L_new = degreeElevationfrom2To3(&L);
        write_curve_bezier_in_eps(f,&L_new,I);
        totalCurve+=L_new.count;
        node = node->next_contour;
    }

    fprintf(f,"fill\n");
    fprintf(f,"showpage\n");
    fclose(f);
    printf("Nombre de courbe de bézier est: %d\n",totalCurve);

    return 0;
}