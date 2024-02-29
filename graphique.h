#ifndef GRAPH
#define GRAPH
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "arbre.h"
#include <MLV/MLV_all.h>



/*
Fonction qui affiche la liste des points sur l'interface graphique
*/
void affiche_pnt(Interface* lst);



/*
Fonction qui trace les carres de l'arbre recursivement
*/
void affiche_carre(Arbre abr);


/*
Fonction qui cree la fenetre graphique 
*/
void creer_fenetre(int taille);



/*
Fonction qui nettoie la fenetre graphique
*/
void efface_fenetre();


/*
Fonction qui recupere les informations de la souris ou du clavier
*/
int manuel(int *x, int *y);


/*
Fonction qui actualise l'affichage de la fenetre
*/
void actualise_fenetre();


/*
Fonction qui libere la fentre graphique
*/
void libere_fenetre();


/*
Fonction qui attend que l'utilisateur appuie sur la touche Q
*/
void attend_touche_q();


#endif
