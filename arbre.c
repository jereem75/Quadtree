#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Point.h"
#include "arbre.h"
#include "graphique.h"


int calcule_nb_cel(int largeur) {
  int res = 0;
  int puissance = (int)(log2(largeur)); // on calcule la hauteur de l'arbre
  for (int i = 0; i <= puissance; i++) { // tant qu'on n'a pas dépassé la hauteur
    res += pow(4, i); // on ajoute au résultat les fils engendrés par les noeuds de la hauteur courante
  }
  return res;
}


void init_fils(Cellule *tab, int i, int nb_cel) {
  tab[i].nb_pnt = 0; // on initialise le nombre de points
  tab[i].lst = NULL; // la lite de points
  int indice = i * 4 + 1; // l'indice du premier fils
  if (indice >= nb_cel) { // si l'indice est plus grand que le nombre de cellules
    tab[i].Nord_ouest = NULL; // on initialise les fils à NULL
    tab[i].Nord_est = NULL;
    tab[i].Sud_ouest = NULL;
    tab[i].Sud_est = NULL;
    return;
  }
  int x = tab[i].x; // on initialise les future x et y des fils
  int y = tab[i].y;
  int new_taille = tab[i].width / 2; // La taille des fils
  tab[i].Nord_ouest = &tab[indice]; //pour chaque fils
  tab[indice].width = new_taille; // on met sa taille
  tab[indice].x = x; //les coordonnées de son points supérieur gauche
  tab[indice].y = y;
  init_fils(tab, indice, nb_cel); // et on initialise ses fils
  tab[i].Nord_est = &tab[indice + 1];
  tab[indice + 1].width = new_taille;
  tab[indice + 1].x = x + new_taille;
  tab[indice + 1].y = y;
  init_fils(tab, indice + 1, nb_cel);
  tab[i].Sud_est = &tab[indice + 2];
  tab[indice + 2].width = new_taille;
  tab[indice + 2].x = x + new_taille;
  tab[indice + 2].y = y + new_taille;
  init_fils(tab, indice + 2, nb_cel);
  tab[i].Sud_ouest = &tab[indice + 3];
  tab[indice + 3].width = new_taille;
  tab[indice + 3].x = x;
  tab[indice + 3].y = y + new_taille;
  init_fils(tab, indice + 3, nb_cel);
}




Arbre init_arbre(int nb_cel, int largeur) {
  Cellule *tab = (Cellule *)malloc(sizeof(Cellule) * nb_cel); //on alloue le tableau de cellules
  if (tab == NULL) {
    printf("erreur d'allocaion\n");
    return NULL;
  }
  tab[0].width = largeur; //on initialise la premiere cellule
  tab[0].x = 0;
  tab[0].y = 0;
  init_fils(tab, 0, nb_cel);
  return tab;
}





int appartient(Cellule cel, Interface point, int largeur) {
  if ((point.part->x > cel.x + largeur) || (point.part->y > cel.y + largeur) || (point.part->x < cel.x) || (point.part->y < cel.y)) { // on compare les coordonnees
    return 0; // n'appartient pas
  }
  return 1; //appartient
}




void ajout_fin(Interface **lst, Interface *point) {
  point->next = NULL; //on initialise le suivant comme la fin de la liste
  if (*lst == NULL) { //si la liste est vide
    *lst = point; // le point est la tête de la liste
    return;
  }
  Interface *parcours = *lst; 
  while (parcours->next != NULL) { //on parcourt jusqu'à l'avant dernier
    parcours = parcours->next;
  }
  parcours->next = point;
}




int remplit(Arbre abr, Interface *point, int max_pnt, int min_taille) {
  if (appartient(*abr, *point, abr->width)) { // si le point appartient au carré
    if (abr->width <= min_taille || abr->nb_pnt < max_pnt) { // si la taille du carré est minimale ou max points n'est pas atteint
      ajout_fin(&abr->lst, point); //on ajoute le point à sa liste chainée
      abr->nb_pnt += 1;
      return 1;
    }
    if (abr->nb_pnt == max_pnt) { //si le max points est atteint
      abr->nb_pnt += 1;
      ajout_fin(&abr->lst, point); //on ajoute le points à la liste chainée
      Interface *parcours = abr->lst;
      Interface *suivant = parcours->next; //on garde en mémoire le suivant car la cellule d'avant peut changer
      for (; parcours != NULL;) { //on parcours la liste chaine pour distribuer les points dans les fils
        if (remplit(abr->Nord_ouest, parcours, max_pnt, min_taille) == 0) {
          if (remplit(abr->Nord_est, parcours, max_pnt, min_taille) == 0) {
            if (remplit(abr->Sud_est, parcours, max_pnt, min_taille) == 0) {
              if (remplit(abr->Sud_ouest, parcours, max_pnt, min_taille) == 0) {
                return -1;
              }
            }
          }
        }
        parcours = suivant;
        if (suivant != NULL)
          suivant = suivant->next;
      }
      abr->lst = NULL; //on oublie pas de dire que la liste de points est vide
      return 1;
    }
    abr->nb_pnt += 1; //sinon on cherche ou l'ajouter dans ses fils
    if (remplit(abr->Nord_ouest, point, max_pnt, min_taille) == 0) {
      if (remplit(abr->Nord_est, point, max_pnt, min_taille) == 0) {
        if (remplit(abr->Sud_est, point, max_pnt, min_taille) == 0) {
          if (remplit(abr->Sud_ouest, point, max_pnt, min_taille) == 0) {
            return - 1;
          }
        }
      }
    }
    return 1;
  }
  return 0;
}




void libere_structure(Arbre abr, Gestion_tab tab) {
  free(abr); //on libere le tableau de cellules
  free(tab.tab); //puis le tableau de points
  free(tab.tab_inerface); //on libere le tableau d'interface
}



