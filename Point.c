#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include <time.h>


void genere_pnt(int *x, int *y, int taille) {
  // on genere x et y aleatoirement 
  *x = rand() % (taille + 1);
  *y = rand() % (taille + 1);
}




void ajoute_pnt(Gestion_tab *structure, int x, int y) {
  structure->tab[structure->indice].x = x; //on initialise les points
  structure->tab[structure->indice].y = y;
  structure->tab_inerface[structure->indice].next = NULL; //on initialise une nouvelle interface pour le point
  structure->tab_inerface[structure->indice].part = &structure->tab[structure->indice];
  structure->indice += 1; //on indique le prochain point à remplir
}




Gestion_tab init_pnt(int max_pnt) {
  Gestion_tab structure;
  structure.tab = (Particule *)malloc(sizeof(Particule) * max_pnt); //on alloue le tableau de points à la bonne taille
  if (structure.tab == NULL) { //en cas d'erreur
      printf("erreur d'llocation\n");
      structure.tab_inerface = NULL; //on met le tableau d'interface à NULL
      return structure;
  }
  structure.tab_inerface = (Interface *)malloc(sizeof(Interface) * max_pnt); //on alloue le tableau d'interfaces à la bonne taille
  if (structure.tab_inerface == NULL) { //en cas d'erreur
      printf("erreur d'llocation\n");
      free(structure.tab); //on libere le tableau d'interfaces
      return structure;
  }
  structure.indice = 0; //on initialie l'indice d'ajout
  return structure;
}




