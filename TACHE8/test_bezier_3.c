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
    Image I;
    List_Multiple_Contours contours;
    double d; 

    if (argc < 3) {
        puts("Input format :filename distance_seuil");
        return 1;
    }
    
    char fileNameOut1 [100];
    strcat(fileNameOut1,argv[1]);
    strcat(fileNameOut1,"_curve3.ps");
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
    List_CourbeBezier_3 L;
    CourbeBezier_3 c;
    
    
    fprintf(f,"%%!PS−Adobe−3.0 EPSF−3.0\n");
	fprintf(f,"%%%%BoundingBox: 0 -%d %d 0\n",I.H,I.L);
    int totalCurve = 0;
    while (node !=NULL)
    {
        cont.size = 0;
        cont = sequence_points_List_vers_tableau(node->data);
        L = create_List_Courbe_Bezier_3_vide();
        L = simplification_douglas_peucker_bezier3(cont,0,cont.size-1,d);
        
        write_curve_bezier_in_eps(f,&L,I);
        totalCurve+=L.count;
        node = node->next_contour;
    }

    fprintf(f,"fill\n");
    fprintf(f,"showpage\n");
    fclose(f);
    printf("Nombre de courbe de bezier est: %d\n",totalCurve);

    return 0;
}