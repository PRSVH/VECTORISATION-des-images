#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "contour.h"



Point find_initial_pixel(Image I){
    UINT x,y;
	UINT L,H;
	Pixel_Point p1;
    Pixel_Point p2;
	L = I.L;
	H = I.H;
    p1.color = get_pixel_image(I,0,0);
    p1.p.x = 0;
    p1.p.y= 0;
    p1.color = BLANC;
	for(x=1; x<=H;x++){
		for(y=1;y<=L;y++){
			
			p2.color = get_pixel_image(I,y,x);
            p2.p.x =y;
            p2.p.y= x;
            // printf("Point p1 is %f %f color: %d\n", p1.p.x, p1.p.y,p1.color);
            // printf("Point p2 is %f %f color: %d\n", p2.p.x, p2.p.y,p2.color);

			
            if(p1.color==NOIR && p2.color== BLANC){
                return p1.p;
            }else{
                p1.color = p2.color;
                p1.p.x = p2.p.x;
                p1.p.y = p2.p.y;
            }
		}
        
	}

    Point p;
    p.x =-1;
    p.y =-1;
    return p;
}

void find_contour(Image I,FILE *file,FILE *file_eps){
    printf("L: %d, H: %d\n",I.L,I.H);
    Point initial_pixel = find_initial_pixel(I);
    Point inital_point;
    inital_point.x = initial_pixel.x-1;
    inital_point.y = initial_pixel.y-1;

    Point position;
    position.x = inital_point.x;
    position.y = inital_point.y;
    
    Robot r;
    initialize_Robot(&r,position,East);
    
    Orientation orientation = r.o;
    List_Point contour;
    contour = create_List_Point_vide();
    add_element_List_Point(&contour, position);

    int countourCount = 1;

    
    bool flag = true;;
    while (flag){
        
        move(&r);
        
        position.x = r.p.x;
        position.y = r.p.y;

        add_element_List_Point(&contour, position);

        orientation = new_orientation(position,I,&r);
        
        if( position.x == inital_point.x && position.y == inital_point.y && orientation == East ){
            flag = false;
        }
    }
    printf("Nombre de segment: %d\n",contour.size-1);
    fprintf(file,"1\n");
    write_contour_in_file(contour,file);
    convert_to_eps(contour,file_eps,I.L,I.H);
    
    
}


    

