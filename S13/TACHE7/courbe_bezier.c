#include "courbe_bezier.h"

void write_curve_bezier_in_eps(FILE* fileOut,List_CourbeBezier_3 *L,Image I)
{
    CourbeBezier_3_Node* n;
    n = (CourbeBezier_3_Node *)malloc(sizeof(CourbeBezier_3_Node));
    n = L->head;
    fprintf(fileOut,"%2.1f %2.1f moveto\n",n->courbe.C0.x,n->courbe.C0.y*(-1));
   
    
    while(n != NULL){
        fprintf(fileOut,"%2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f curveto\n",n->courbe.C0.x,n->courbe.C0.y*(-1),n->courbe.C1.x,n->courbe.C1.y*(-1),n->courbe.C2.x,n->courbe.C2.y*(-1),n->courbe.C3.x,n->courbe.C3.y*(-1));
        n = n->next_courbe;
    }
    
}

//Courbe Bezier 2

CourbeBezier_2_Node *create_element_Courbe_Bezier_2(CourbeBezier_2 c)
{
	CourbeBezier_2_Node *el;
	el = (CourbeBezier_2_Node *)malloc(sizeof(CourbeBezier_2_Node));
	if (el==NULL)
	{
		fprintf(stderr, "create_element_Courbe_Bezier_2 : allocation impossible\n");
		exit(-1);
	}
    el->courbe.C0 =c.C0;
    el->courbe.C1 = c.C1;
    el->courbe.C2 = c.C2;
	

	el->next_courbe = NULL;
	return el;
}

List_CourbeBezier_2 create_List_Courbe_Bezier_2_vide()
{
	List_CourbeBezier_2 L = {0, NULL, NULL};
	return L;
}

List_CourbeBezier_2 add_element_Courbe_Bezier_2(List_CourbeBezier_2* L, CourbeBezier_2 e)
{
	CourbeBezier_2_Node *el;
    
	
	el = create_element_Courbe_Bezier_2(e);
    

	if (L->count == 0)
	{
		L->head = L->tail = el;
		el->next_courbe =NULL;
	}
	else
	{

		L->tail->next_courbe = el;
		L->tail = el;
		el->next_courbe = NULL;
	}
	L->count++;
	
	return *L;
}
List_CourbeBezier_2 concatener_List_Courbe_Bezier_2(List_CourbeBezier_2 L1, List_CourbeBezier_2 L2)
{
	
	if (L1.count == 0) return L2; 
	if (L2.count == 0) return L1;
	
	
	L1.tail->next_courbe = L2.head; 
	L1.tail = L2.tail;        
	L1.count += L2.count;   
	return L1;
}

//Courbe Bezier 3
CourbeBezier_3_Node *create_element_Courbe_Bezier_3(CourbeBezier_3 c)
{
	CourbeBezier_3_Node *el;
	el = (CourbeBezier_3_Node *)malloc(sizeof(CourbeBezier_3_Node));
	if (el==NULL)
	{
		fprintf(stderr, "create_element_Courbe_Bezier_3 : allocation impossible\n");
		exit(-1);
	}
    el->courbe.C0 =c.C0;
    el->courbe.C1 = c.C1;
    el->courbe.C2 = c.C2;
    el->courbe.C3 = c.C3;
	

	el->next_courbe = NULL;
	return el;
}

List_CourbeBezier_3 create_List_Courbe_Bezier_3_vide()
{
	List_CourbeBezier_3 L = {0, NULL, NULL};
	return L;
}

List_CourbeBezier_3 add_element_Courbe_Bezier_3(List_CourbeBezier_3* L, CourbeBezier_3 e)
{
	CourbeBezier_3_Node *el;
    
	
	el = create_element_Courbe_Bezier_3(e);
    

	if (L->count == 0)
	{
		L->head = L->tail = el;
		el->next_courbe =NULL;
	}
	else
	{

		L->tail->next_courbe = el;
		L->tail = el;
		el->next_courbe = NULL;
	}
	L->count++;
	
	return *L;
}


List_CourbeBezier_2 simplification_douglas_peucker_bezier2(Tableau_Point cont,int j1,int j2,double d){
    int n = j2 -j1;
    CourbeBezier_2 B; 
    B = approx_bezier2(&cont,j1,j2);
    double dmax =0;
    int k = j1;
    int i;
    double ti,dj;
    List_CourbeBezier_2 L,L1,L2;
    L1 = create_List_Courbe_Bezier_2_vide();
    L2 = create_List_Courbe_Bezier_2_vide();
    for(int j=j1+1;j<=j2;j++){
        i = j-j1;
        ti = (double)i/(double)n;
        dj = distance_point_Bezier(cont.tab[j],B,ti);
        if(dmax< dj){
            dmax = dj;
            k=j;
        }
    }
    if(dmax <= d){
     
        L = create_List_Courbe_Bezier_2_vide();
        add_element_Courbe_Bezier_2(&L,B);
       
    }else{
        L1 = simplification_douglas_peucker_bezier2(cont,j1,k,d);
        L2 = simplification_douglas_peucker_bezier2(cont,k,j2,d);
        L = concatener_List_Courbe_Bezier_2(L1,L2);

    }
    return L;
}

Point calculate_C_t (CourbeBezier_2 courbe,double t){
    Point P;
    P.x = courbe.C0.x*pow((1-t),2)+ courbe.C1.x*2*t*(1-t)+courbe.C2.x*pow(t,2);
    P.y = courbe.C0.y*pow((1-t),2)+ courbe.C1.y*2*t*(1-t)+courbe.C2.y*pow(t,2);
   
    return P;
}

double distance_point_Bezier(Point Pj,CourbeBezier_2 courbe,double ti){

    Point Cti;
    double distance;

    Cti = calculate_C_t(courbe,ti);
    distance = distance_points(Pj,Cti);
    return distance;

}

Point calculate_C1_bezier(Tableau_Point*cont,int j1,int j2,int n){
    Point C0 = cont->tab[j1];
    Point C2 = cont->tab[j2];
    Point C1; // Pj1+i
    
    double alpha,beta;
    alpha = (double)(3*n )/ (double)(pow(n,2)-1);
    double l =  (double)(2*(n+1));
    beta =  (double)(1-2*n )/(double)l;
    
    double x,y;
    double sumX=0;
    double sumY=0;
    
    for(int i = j1+1;i<=j2-1;i++){
        sumX += cont->tab[i].x;
        sumY += cont->tab[i].y;
       
    }

    x = (sumX*alpha) +  beta*(C0.x+C2.x);
    y= (sumY*alpha) +  beta*(C0.y+C2.y);
    C1 = set_point(x,y);
    return C1;
}

CourbeBezier_2 approx_bezier2(Tableau_Point *cont, int j1,int j2){
    int n = j2-j1;
    
    CourbeBezier_2 bezier_2;
    bezier_2.C0.x= cont->tab[j1].x;
    bezier_2.C0.y= cont->tab[j1].y;

    bezier_2.C2.x = cont->tab[j2].x;
    bezier_2.C2.y = cont->tab[j2].y;

    
    if(n == 1){
        bezier_2.C1 = int_division(add_point(bezier_2.C0,bezier_2.C2),2);
    }else if(n >= 2){
        
        bezier_2.C1 = calculate_C1_bezier(cont,j1,j2,n);
    }
    //printf("Bezier courbe with points C0 = (%2.6f, %2.6f) C1 = (%2.6f, %2.6f) C2 = (%2.6f, %2.6f)\n",bezier_2.C0.x,bezier_2.C0.y,bezier_2.C1.x,bezier_2.C1.y,bezier_2.C2.x,bezier_2.C2.y);
    return bezier_2;
}

List_CourbeBezier_3 degreeElevationfrom2To3(List_CourbeBezier_2 *list){
    CourbeBezier_2_Node *node;
    CourbeBezier_3 bezier3;
    CourbeBezier_2 bezier2;

    List_CourbeBezier_3 newList;
    newList = create_List_Courbe_Bezier_3_vide();
    node = (CourbeBezier_2_Node *)malloc(sizeof(CourbeBezier_2_Node));
    node = list->head;

    
    while(node != NULL){
        bezier2 = node->courbe;
        bezier3.C0 = bezier2.C0;
        
        bezier3.C1= int_division((add_point(bezier2.C0,int_product(bezier2.C1,2))),3);
        bezier3.C2= int_division((add_point(bezier2.C2,int_product(bezier2.C1,2))),3);
        bezier3.C3 = bezier2.C2;
        add_element_Courbe_Bezier_3(&newList,bezier3);
        // printf("bezier 2:%2.1f %2.1f %2.1f %2.1f %2.1f %2.1f \n", bezier2.C0.x, bezier2.C0.y, bezier2.C1.x, bezier2.C1.y, bezier2.C2.x, bezier2.C2.y);
        // printf("bezier 3: %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f %2.1f \n", bezier3.C0.x, bezier3.C0.y, bezier3.C1.x, bezier3.C1.y, bezier3.C2.x, bezier3.C2.y, bezier3.C3.x, bezier3.C3.y);

        node = node->next_courbe;
    }
    return newList;

}

void write_all_courbe_bezier_eps(FILE* f,Image I, List_Multiple_Contours contours,int d){
    Node_Multi_Contour* node;
    node = (Node_Multi_Contour *)malloc(sizeof(Node_Multi_Contour));
    node = contours.head;
    Tableau_Point cont;
    cont.size = 0;
    List_CourbeBezier_2 L;
    List_CourbeBezier_3 L_new;
    CourbeBezier_2 c;

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
    printf("Nombre de courbe de bezier est: %d\n",totalCurve);
}