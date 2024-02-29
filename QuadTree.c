#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "QuadTree.h"
#include "Point.h"
#include "graphique.h"
#include "arbre.h"


void jeux(Menu settings) {
    srand(time(NULL)); //on initialise une graine pour l'aléatoire
    int nb_cel = calcule_nb_cel(settings.taille); //on clacule le nombre de cellules à allouer
    Arbre abr = init_arbre(nb_cel, settings.taille); //on initialise le quadtree
    if (abr == NULL) {
        return ;
    }
    Gestion_tab pnt = init_pnt(settings.nb_points); //on initialise le tableau de points
    if (pnt.tab_inerface == NULL) { //s'il y a eu un probleme d'allocation
        free(abr); //on libere l'arbre
        return ;
    }
    int x, y, points = 0;
    Interface *new = NULL;
    creer_fenetre(settings.taille); // on cree la fenetre appropriée
    efface_fenetre();
    actualise_fenetre();
    while (points != settings.nb_points) { //tant que le nombre max de points n'est pas atteint
        points ++;
        if (!settings.type_generation) { // si la generation est manuel
            if (!manuel(&x, &y)) { //on attend la saise de l'utilisateur
                break;
            }
        }
        else {
            genere_pnt(&x, &y, settings.taille); //sinon on genere un point aléatoirement
        }
        ajoute_pnt(&pnt, x, y); //on ajoute le points au tableau
        new = &pnt.tab_inerface[pnt.indice - 1]; //on met a jour la nouvelle interface
        remplit(abr, new, settings.max_point, settings.taille_min); //on met à jour le quadtree
        if (!settings.type_affichage) { //si l'affichage est de type point par point
            efface_fenetre();
            affiche_carre(abr); //on affiche la représentation de l'état actuel du quatree
            actualise_fenetre();
        }
    }
    if (settings.type_affichage) { //si l'affichage est de type terminal
        affiche_carre(abr); //on affiche le quadree
        actualise_fenetre();
    }
    if (settings.type_generation || points == settings.nb_points) //si la génération est de type automatique ou qu'on a pas atteint le max point
        attend_touche_q(); //on attend que l'utilisateur appuie sur la touche "q"
    libere_fenetre(); // on libere la fenêtre
    libere_structure(abr, pnt); //on libere nos structures
}
