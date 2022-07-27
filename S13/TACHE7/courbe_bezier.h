#include "robot.h"
#include "geom2d.h"
#include "contour.h"
#include <math.h>


typedef struct CourbeBezier_2_Node_
{
	CourbeBezier_2 courbe;
	struct CourbeBezier_2_Node_ *next_courbe;
}CourbeBezier_2_Node;

typedef struct  List_CourbeBezier_2_
{
	unsigned int count;
	CourbeBezier_2_Node *head;
	CourbeBezier_2_Node *tail;
}List_CourbeBezier_2;

typedef struct CourbeBezier_3_Node_
{
	CourbeBezier_3 courbe;
	struct CourbeBezier_3_Node_ *next_courbe;
}CourbeBezier_3_Node;

typedef struct  List_CourbeBezier_3_
{
	unsigned int count;
	CourbeBezier_3_Node *head;
	CourbeBezier_3_Node *tail;
}List_CourbeBezier_3;



CourbeBezier_2_Node *create_element_Courbe_Bezier_2(CourbeBezier_2 c);
List_CourbeBezier_2 create_List_Courbe_Bezier_2_vide();
List_CourbeBezier_2 add_element_Courbe_Bezier_2(List_CourbeBezier_2* L, CourbeBezier_2 e);
List_CourbeBezier_2 concatener_List_Courbe_Bezier_2(List_CourbeBezier_2 L1, List_CourbeBezier_2 L2);

CourbeBezier_3_Node *create_element_Courbe_Bezier_3(CourbeBezier_3 c);
List_CourbeBezier_3 create_List_Courbe_Bezier_3_vide();
List_CourbeBezier_3 add_element_Courbe_Bezier_3(List_CourbeBezier_3* L, CourbeBezier_3 e);

CourbeBezier_2 approx_bezier2(Tableau_Point *cont, int j1,int j2);
double distance_point_Bezier(Point P,CourbeBezier_2 courbe,double ti);
List_CourbeBezier_2 simplification_douglas_peucker_bezier2(Tableau_Point cont,int j1,int j2,double d);
void write_curve_bezier_in_eps(FILE* fileOut,List_CourbeBezier_3 *L,Image I);
List_CourbeBezier_3 degreeElevationfrom2To3(List_CourbeBezier_2 *list);
Point calculate_C1_bezier(Tableau_Point*cont,int j1,int j2,int n);

void write_all_courbe_bezier_eps(FILE* f,Image I, List_Multiple_Contours contours,int d);