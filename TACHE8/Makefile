CC = clang

PROGRAMMES=test_bezier test_bezier_3 test_simplification test_multi_contour
all: $(PROGRAMMES)

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

test_multi_contour.o : test_multi_contour.c robot.h image.h contour.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_multi_contour"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_simplification.o : test_simplification.c robot.h image.h contour.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_simplification"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

courbe_bezier.o : courbe_bezier.c courbe_bezier.h geom2d.h robot.h contour.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module sequence_point"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_bezier.o : test_bezier.c robot.h image.h contour.h geom2d.h courbe_bezier.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_bezier"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_bezier_3.o : test_bezier_3.c robot.h image.h contour.h geom2d.h courbe_bezier.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_bezier_3"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

test_multi_contour : test_multi_contour.o image.o robot.o contour.o sequence_point.o geom2d.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@ -lm

test_simplification : test_simplification.o image.o robot.o contour.o sequence_point.o geom2d.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@ -lm

test_bezier_3 : test_bezier_3.o image.o robot.o contour.o sequence_point.o geom2d.o courbe_bezier.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@ -lm

test_bezier : test_bezier.o image.o robot.o contour.o sequence_point.o geom2d.o courbe_bezier.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@ -lm

clean:
	rm -f $(PROGRAMMES) *.o

