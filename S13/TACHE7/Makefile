CC = clang

all : test_bezier

%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<


geom2d.o : geom2d.c geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module geom2d"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< 

robot.o : robot.c robot.h image.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module robot"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $< 

contour.o : contour.c contour.h image.h robot.h sequence_point.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

image.o : image.c image.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

sequence_point.o : sequence_point.c sequence_point.h robot.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module sequence_point"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<



test_bezier.o : test_bezier.c robot.h image.h contour.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_robot"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

courbe_bezier.o : courbe_bezier.c courbe_bezier.h robot.h geom2d.h contour.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module courbe_bezier"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<
		
########################################################
# regles explicites de creation des executables

test_bezier : test_bezier.o image.o robot.o contour.o sequence_point.o geom2d.o courbe_bezier.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@ -lm



# regle pour "nettoyer" le r�pertoire
clean:
	rm -fR test_bezier *.o 
