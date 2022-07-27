#include<stdio.h>  /* utilisation des entr�es-sorties standard de C */
#include<stdlib.h> /* utilisation des fonctions malloc et free */
#include "sequence_point.h"



Point set_point(double x, double y)
{
	Point P = {x,y}; return P;
}


/* cr�er une Node de List avec l'�l�ment v 
   renvoie le pointeur sur la Node de List cr��e
   la fonction s'arrete si la cr�ation n'a pas pu se faire */
Node_List_Point *create_element_List_Point(Point v)
{
	Node_List_Point *el;
	el = (Node_List_Point *)malloc(sizeof(Node_List_Point));
	if (el==NULL)
	{
		fprintf(stderr, "create_element_List_Point : allocation impossible\n");
		exit(-1);
	}
	el->data.x = v.x;
	el->data.y = v.y;

	el->next = NULL;
	return el;
}
/* cr�er une List vide */
List_Point create_List_Point_vide()
{
	List_Point L = {0, NULL, NULL};
	return L;
}

/* add l'�l�ment e en fin de la List L, renvoie la List L modifi�e */
List_Point add_element_List_Point(List_Point* L, Point e)
{
	Node_List_Point *el;
    
	
	el = create_element_List_Point(e);
    

	if (L->size == 0)
	{
		/* premier �l�ment de la List */
		L->first = L->last = el;
		el->next =NULL;
	}
	else
	{

		L->last->next = el;
		L->last = el;
		el->next = NULL;
	}
	L->size++;
	
	return *L;
}

/* suppression de tous les �l�ments de la List, renvoie la List L vide */
List_Point supprimer_List_Point(List_Point L)
{
	Node_List_Point *el=L.first;
	
	while (el) 
	{		
		Node_List_Point *next=el->next;
		free(el);
		el = next;
	}
	L.first = L.last = NULL; L.size = 0;
	return L;
}

/* concat�ne L2 � la suite de L1, renvoie la List L1 modifi�e */
List_Point concatener_List_Point(List_Point L1, List_Point L2)
{
	/* cas o� l'une des deux Lists est vide */
	if (L1.size == 0) return L2; 
	if (L2.size == 0) return L1;
	
	/* les deux Lists sont non vides */
	L1.last->next = L2.first; /* lien entre L1.last et L2.first */
	L1.last = L2.last;        /* le dernier �l�ment de L1 est celui de L2 */
	L1.size += L2.size;   /* nouvelle size pour L1 */
	return L1;
}
/* cr�er une s�quence de points sous forme d'un tableau de points 
   � partir de la List de points L */
Tableau_Point sequence_points_List_vers_tableau(List_Point L)
{
	Tableau_Point T;
	
	/* size de T = size de L */
	T.size = L.size;
	
	/* allocation dynamique du tableau de Point */
	T.tab = malloc(sizeof(Point) * T.size);
	if (T.tab == NULL)
	{
		/* allocation impossible : arret du programme avec un message */
		fprintf(stderr, "sequence_points_List_vers_tableau : ");
		fprintf(stderr, " allocation impossible\n");
		exit(-1);
	}
	
	/* remplir le tableau de points T en parcourant la List L */
	int k = 0; /* indice de l'�l�ment dans T.tab */
	Node_List_Point *el = L.first; /* pointeur sur l'�l�ment dans L */
	while (el) 
	{
		T.tab[k] = el->data;
		k++; /* incr�menter k */
		el = el->next; /* passer � l'�lement nextant dans la List chainee */
	}
	
	return T;
}

/* �crire le contour L � l'�cran 
   cette fonction montre un exemple de conversion d'une List de points en
   tableau de points afin de pouvoir par la suite acc�der aux �l�ments d'une
   s�quence de points par indice */
void write_contour(List_Point L,FILE *file)
{
	Tableau_Point TP = sequence_points_List_vers_tableau(L);
	int k;
	int nP = TP.size;
	
	printf("%d points : [", nP);
	for (k = 0; k < nP; k++)
	{	
		Point P = TP.tab[k]; /* r�cup�rer le point d'indice k */
		printf(" (%5.1f,%5.1f)", P.x, P.y);
	} 
	printf("]\n");
	
	free(TP.tab); /* supprimer le tableau de point TP */


}


void write_contour_in_file(List_Point L,FILE*file)
{
	Tableau_Point TP = sequence_points_List_vers_tableau(L);
	int k;
	int nP = TP.size;
	
    fprintf(file, "%d\n",nP);

	for (k = 0; k < nP; k++)
	{	
		Point P = TP.tab[k]; /* r�cup�rer le point d'indice k */
		fprintf(file,"%5.1f %5.1f\n", P.x, P.y);
	} 
	
	
	free(TP.tab); 
}

void convert_to_eps(List_Point L,FILE *fileOut,UINT Lenght, UINT Height){
	Node_List_Point *elem = L.first; 
	double x,y ; 
	double x_first, y_first;

	x_first = elem ->data.x;
	y_first = elem ->data.y;
	fprintf(fileOut,"%%!PS−Adobe−3.0 EPSF−3.0\n");
	fprintf(fileOut,"%%%%BoundingBox: 0 -%d %d 0\n",Height,Lenght);

	fprintf(fileOut,"%d %d moveto ", (int)x_first, (int)y_first*(-1));
	elem = elem->next;
	while (elem != NULL) 
	{
		x = elem ->data.x;
		y = elem ->data.y;
		fprintf(fileOut,"%d %d lineto \n", (int)x, (int)y*(-1));

		elem = elem->next; 
	}
	if(x_first ==x && y_first == y){
		fprintf(fileOut,"fill\n");
	}
	else{
		fprintf(fileOut,"stroke\n");
	}

	fprintf(fileOut,"showpage\n");
}
