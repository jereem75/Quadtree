#include <stdio.h>
#include <stdlib.h>
#include "graphique.h"
#include "Point.h"
#include "arbre.h"




void affiche_pnt(Interface* lst){
    while(lst != NULL){ // tant que la liste n'est pas null
        MLV_draw_filled_circle(lst->part->x, lst->part->y, 2, MLV_COLOR_BLACK); // on affiche le point actuel
        lst = lst->next;
    }
}




void affiche_carre(Arbre abr) {
    if(abr == NULL || abr->nb_pnt == 0){
        return;
    }
    if(abr->lst != NULL){ // si c'est pas null
        // on affiche les differents rectangles
        MLV_draw_filled_rectangle(abr->x,abr->y,abr->width,abr->width,MLV_COLOR_TURQUOISE1);
        MLV_draw_rectangle(abr->x, abr->y, abr->width, abr->width, MLV_COLOR_WHITE);
        affiche_pnt(abr->lst);
        return;
    } // on affiche recursivement les autres carres
    affiche_carre(abr->Nord_ouest);
    affiche_carre(abr->Nord_est);
    affiche_carre(abr->Sud_est);
    affiche_carre(abr->Sud_ouest);
}


void creer_fenetre(int taille) {
    MLV_create_window("QuadTree", "QuadTree", taille, taille); // on cree la fenetre
}


void efface_fenetre() {
    MLV_clear_window(MLV_COLOR_WHITE); // on nettoie la fenetre
}


void actualise_fenetre() {
    MLV_update_window(); // on met a jour la fenetre
}


void libere_fenetre() {
    MLV_free_window(); // on libere la fentre
}

int manuel(int *x, int *y) {
    MLV_Event event;
    MLV_Keyboard_button clavier;
    MLV_Mouse_button souris;
    MLV_Button_state etat;
    while (1) {
        event = MLV_wait_event(&clavier, NULL, NULL, NULL, NULL, x, y, &souris, &etat); //on recupere les eevenements de la souris
        switch (event) { // on regarde les differents cas
            case MLV_MOUSE_BUTTON:
                if (souris == MLV_BUTTON_LEFT && etat == MLV_RELEASED) { // si on a clique on renvoie 1
                    return 1;
                }
                break;
            case MLV_KEY:
                if (clavier == MLV_KEYBOARD_q) { // si on a appuyer sur la touche q on renvoie 0
                    return 0;
                }
                break;
            default:
                break; // sinon on quitte la boucle
        }
    }
}



void attend_touche_q() {
    MLV_Keyboard_button clavier;
    MLV_wait_keyboard(&clavier, NULL, NULL); // on attend une touche du clavier
    while(clavier != MLV_KEYBOARD_q) { // tant que la touche n'est pas q on redemande une touche
        MLV_wait_keyboard(&clavier, NULL, NULL);
    }
}
