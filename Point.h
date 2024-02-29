#ifndef _DM_
#define _DM_
#include <stdio.h>
#include <stdlib.h>



typedef struct Particule {
  int x; // coordonee x
  int y; // coordonne y
} Particule;


typedef struct _int_ {
  Particule *part; // particule actuelle
  struct _int_ *next; // pointeur vers la particule suivante
} Interface;



typedef struct _tab_ {
  Particule *tab; //le tableau de points
  Interface *tab_inerface; //le tableau d'interface
  int indice; //le dernier point qui a été ajouté
} Gestion_tab;



/*
Fonction qui prend en parametr e nombre maximal de points
et initialise une structe permettant de gérer le tableau de points
*/
Gestion_tab init_pnt(int max_pnt);


/*
Fonction qui ajoute un point à la structure de points
*/
void ajoute_pnt(Gestion_tab *structure, int x, int y);




/*
Fonction qui genre un point aleatoirement dans la fenetre graphique
*/
void genere_pnt(int *x, int *y, int taille);

#endif
