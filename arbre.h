#ifndef ABR
#define ABR
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

typedef struct _tree_ {
  int x; // coordonee x
  int y; // coordonee y
  int nb_pnt; // nb de points de la case
  int width; // sa longueur
  Interface *lst;
  struct _tree_ *Nord_ouest;
  struct _tree_ *Nord_est;
  struct _tree_ *Sud_est;
  struct _tree_ *Sud_ouest;
} Cellule, *Arbre;



/*
Fonction qui prend en parametre le grand carré et 
calcul le nombre total de cellules que contient l'arbre
*/
int calcule_nb_cel(int largeur);



/*
Fonction qui prend en parametre un tableau e cellule, l'indice
du noeud à traiter et le nombre de cellules de l'arbre. La fonction
initialise chaque noeud (ses fils, sa taille, son nb de noeuds ...)
*/
void init_fils(Cellule *tab, int i, int nb_cel);


/*
Fonction qui prend en parametre le nombre de cellules de l'arbre
est alloue corectement 
*/
Arbre init_arbre(int nb_cel, int largeur);


/*
Fonction qui prend en parametre une cellule et un point et vérifie
si le point appartient à la cellule
*/
int appartient(Cellule cel, Interface point, int largeur);



/*
Fonction qui prend en parametre un arbre et un point à ajouter.
La fonction renvoie 1 si l'ajout est correctement fait.
*/
int remplit(Arbre abr, Interface *point, int max_pnt, int min_taille);


/*
Fonction qui prend en parametre une liste et un nouveau point
puis l'ajoute à la fin
*/
void ajout_fin(Interface **lst, Interface *point);


/*
Fonction qui prend en parametre l'arbre et les tableau de point et libere
se qui a été alloué.
*/
void libere_structure(Arbre abr, Gestion_tab tab);



#endif
