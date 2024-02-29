#ifndef _TREE_
#define _TREE_


typedef struct _menu_ {
    int taille; // taille de la fenetre
    int type_generation; // 0 si generation manuel 1 si automatique
    int type_affichage; //0 si on affiche etape par etape 1 pour afficher tout à la fin
    int taille_min; // longueur minimum d'un coté
    int nb_points; // nb de points a generer
    int max_point; // nb max de points dans une case
} Menu;



/*
Fonction qui prend en parametre une structure menu composée des differents parametres et qui
affiche le quadtree en fonction des paramteres choisis
*/
void jeux(Menu settings);


#endif
