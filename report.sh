#!/bin/sh
#format d'entrée : ./report.sh {nom de ficher} {distance_seuil} {number_de_Tache}
# trosième parametre est optionel 
# si il n'y a pas un tel parametre execute tous les tâches
#si il existe execute que la tâche indiquée
if [ $# -lt 2 ]; then 
    echo "Nombre de argument inferieur a 2"
    echo "Format d'execution : $0 {nom de ficher} {distance_seuil} {number_de_Tache}(optionel)"
    exit 1
elif [ $# -gt 3 ]; then 
    echo "Nombre de argument superieur a 3"
    echo "Format d'execution : $0 {nom de ficher} {distance_seuil} {number_de_Tache}(optionel)"
    exit 1
fi
if [ $# -ne 2 ]; then
    #TACHE 5
    if [ $3 -eq 5 ]
    then
        ./test_multi_contour $1
        gv $1.ps
        exit 0
    #TACHE 6
    elif [ $3 -eq 6 ] 
    then
        ./test_simplification $1 $2
        gv $1_simple1.ps
        exit 0
    #TACHE 7-1 et 7-2
    elif [ $3 -eq 7 ] 
    then
        ./test_bezier $1 $2
        ./test_bezier_3 $1 $2
        gv $1_curve.ps
        gv $1_curve3.ps
        exit 0
    #TACHE 7-1
    elif [ $3 -eq 71 ] 
    then
        ./test_bezier $1 $2
        gv $1_curve.ps

        exit 0
    #TACHE 7-2
    elif [ $3 -eq 72 ] 
    then
        ./test_bezier_3 $1 $2
        gv $1_curve3.ps
        exit 0
    else 
        echo "Tâche invalide"
        exit 1
    fi

fi 

time ./test_multi_contour $1
time ./test_simplification $1 $2
time ./test_bezier $1 $2
time ./test_bezier_3 $1 $2
gv $1.ps
gv $1_simple1.ps
gv $1_curve.ps
gv $1_curve3.ps


