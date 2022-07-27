CC = clang

all : test_robot 

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



test_robot.o : test_robot.c robot.h image.h contour.h geom2d.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_robot"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<



test_robot : test_robot.o image.o robot.o contour.o sequence_point.o geom2d.o 
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@ -lm


clean:
	rm -fR test_robot *.o 

