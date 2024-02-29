#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "QuadTree.h"




int main(int argc, char *argv[]) {
    Menu home = {512, 0, 0, 1, 2000, 3};
    for (int i = 1; i < argc; i++) { // on boucle sur les arguments
        // on regarde pour charque arguments entree s'il est valide
        if (strcmp(argv[i], "-auto") == 0) {
            home.type_generation = 1;
        }
        else if (strcmp(argv[i], "-manuel") == 0) {
            home.type_generation = 0;
        }
        else if (strcmp(argv[i], "-terminal") == 0) {
            home.type_affichage = 1;
        }
        else if (strcmp(argv[i], "-par_point") == 0) {
            home.type_affichage = 0;
        }
        else if (strcmp(argv[i], "-taille") == 0) {
            if (i < argc - 1) {
                // on verifie l'argument suivant décrivant la taille
                if (sscanf(argv[i + 1], "%d", &home.taille) != 1) {
                    printf("Probleme avec l'argument suivant l'option -taille\n");
                    return 0;
                }
                if (home.taille != 1024 && home.taille != 512) { // on verifie que la taille est correcte
                    printf("arguemnt taille non reglementaire (taille = 512 ou taille = 1024)\n");
                    return 0;
                }
                i++;
            }
            else {
                // sinon on affiche le probleme
                printf("Il manque un argument après l'option -taille\n");
                return 0;
            }
        }
        else if (strcmp(argv[i], "-cellule") == 0) {
            if (i < argc - 1) {
                // on regarde si l'argument suivant est correct
                if (sscanf(argv[i + 1], "%d", &home.taille_min) != 1) {
                    printf("Probleme avec l'argument suivant l'option -cellule\n");
                    return 0;
                }
                // on verfie que l'argument est une puissance de 2
                if (floor(log(home.taille_min) / log(2)) != ceil(log(home.taille_min) / log(2))) {
                    printf("La taille d'une cellule doit être une puisance de 2\n");
                    return 0;
                }
                i++;
            }
            else {
                // sinon on affiche le probleme
                printf("Il manque un argument après l'option -cellule\n");
                return 0;
            }
        }
        else if (strcmp(argv[i], "-points_cellule") == 0) {
            // on regarde si l'argument suivant est correct
            if (i < argc - 1) {
                if (sscanf(argv[i + 1], "%d", &home.max_point) != 1) {
                    printf("Probleme avec l'argument suivant l'option -points_cellule\n");
                    return 0;
                }
                if (home.max_point < 0) {
                    printf("le nombre maximum de points dans une cellule doit être positif\n");
                    return 0;
                }
                i++;
            }
            else {
                // sinon on affiche le probleme
                printf("Il manque un argument après l'option -points_cellule\n");
                return 0;
            }
        }
        else if (strcmp(argv[i], "-nb_points") == 0) {
            // on regarde si l'argument suivant est correct
            if (i < argc - 1) {
                if (sscanf(argv[i + 1], "%d", &home.nb_points) != 1) {
                    printf("Probleme avec l'argument suivant l'option -nb_points\n");
                    return 0;
                }
                if (home.nb_points < 0) {
                    printf("le nombre maximum de points dans une cellule doit être positif\n");
                    return 0;
                }
                i++;
            }
            else {
                // sinon on affiche le probleme
                printf("Il manque un argument après l'option -nb_points\n");
                return 0;
            }
        }
        else {
            // si l'argument est incorrect on affiche le probleme sur le terminal avec l'argument correspondant
            printf("l'argument %s est inconnu\n", argv[i]);
            return 0;
        }
    }
    //on verifie si les mode sont compatible
    if (home.type_affichage == 1 && home.type_generation == 0) {
        printf("L'option terminal n'est pas compatible avec la génération point par point.\n");
        return 0;
    }
    jeux(home); // on lance le programme en fonction des differents parametres
    return 0;
}
