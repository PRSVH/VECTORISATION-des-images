#include "robot.h"
#include "geom2d.h"

#ifndef _SEQUANCE_POINT_H_
#define _SEQUANCE_POINT_H_

Point set_point(double x, double y);

/*---- le type Node de List de point ----*/
typedef struct Node_List_Point_
{
	Point data;    /* donn�e de l'�l�ment de List */
	struct Node_List_Point_* next; /* pointeur sur l'�l�ment suivant */
} Node_List_Point;

/*---- le type List de point ----*/
typedef struct List_Point_
{
	unsigned int size;        /* nombre d'�l�ments dans la List */
	Node_List_Point *first; /* pointeur sur le premier �l�ment de la List */
	Node_List_Point *last;  /* pointeur sur le dernier �l�ment de la List */
	                       /* first = last = NULL et size = 0 <=> List vide */
} List_Point;

typedef List_Point Contour; /* type Contour = type List_Point */
typedef struct Node_Multi_Contour_{
	Contour data;
	struct Node_Multi_Contour_ *next_contour;
}Node_Multi_Contour;

typedef struct List_Multiple_Contour_
{
	unsigned int count;
	Node_Multi_Contour *head;
	Node_Multi_Contour *tail;

} List_Multiple_Contours;


typedef struct Node_Segment_{
	Segment data;
	struct Node_Segment_ *next_segment;
}Node_Segment;

typedef struct List_Segments_
{
	unsigned int count;
	Node_Segment *head;
	Node_Segment *tail;

} List_Segments;

/*---- le type tableau de point ----*/
typedef struct Tableau_Point_
{
	unsigned int size; /* nombre d'�l�ments dans le tableau */
	Point *tab;          /* (pointeur vers) le tableau des �l�ments */
} Tableau_Point;


/* cr�er une Node de List avec l'�l�ment v 
   renvoie le pointeur sur la Node de List cr��e
   la fonction s'arrete si la cr�ation n'a pas pu se faire */
Node_List_Point *create_element_List_Point(Point v);
/* cr�er une List vide */
List_Point create_List_Point_vide();

/* add l'�l�ment e en fin de la List L, renvoie la List L modifi�e */
List_Point add_element_List_Point(List_Point* L, Point e);

List_Multiple_Contours create_List_Multi_empty();

List_Multiple_Contours add_next_Contour(List_Multiple_Contours *List, Contour c);


/* suppression de tous les �l�ments de la List, renvoie la List L vide */
List_Point supprimer_List_Point(List_Point L);

/* concat�ne L2 � la suite de L1, renvoie la List L1 modifi�e */
List_Point concatener_List_Point(List_Point L1, List_Point L2);
/* cr�er une s�quence de points sous forme d'un tableau de points 
   � partir de la List de points L */
Tableau_Point sequence_points_List_vers_tableau(List_Point L);

/* �crire le contour L � l'�cran 
   cette fonction montre un exemple de conversion d'une List de points en
   tableau de points afin de pouvoir par la suite acc�der aux �l�ments d'une
   s�quence de points par indice */
void write_contour(List_Point L,FILE *file);

void write_contour_in_file(List_Point L, FILE* file);

//transforms a file to postscrpt file 
void convert_to_eps(List_Point L,FILE *fileOut,UINT Lenght, UINT Height);


Node_Segment *create_element_List_Segment(Segment v);

List_Segments create_List_Segment_vide();

List_Segments add_element_List_Segments(List_Segments* L, Segment e);

List_Segments concatener_List_Segments(List_Segments L1, List_Segments L2);

#endif
