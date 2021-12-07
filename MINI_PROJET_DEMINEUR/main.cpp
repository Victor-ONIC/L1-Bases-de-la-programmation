#include <iostream>  // attention au double include
#include "func.h"

int main() {

  // Prompt player to choose difficulty level
  // difficulty parameters: ligne, colonne, nb_mines (nb_joker...)
  // base difficulty is 1.
  // Easy: 1, Medium: 2, Hard: 3.

  aff_banner();

  int t_ligne, t_colonne, difficulty;
  menu(t_ligne, t_colonne, difficulty);

  // le truc, c'est qu'il faut calculer les mines après que le joueur ait choisi un emplacement, pour ne pas qu'il tombe sur une mine dès le début...
  // VOIR LA FONCTION Init_jeu !!!!!


  matrice *Jeu = Init_jeu(t_ligne, t_colonne, difficulty);
  matrice *mine_map = mines_autour(Jeu);  // map des mines de Jeu
  // TODO supprimer et replacer les mines entourées de 8 autres mines.

  bool win = 0, lose = 0;
  int mines_OK = 0, discovered = 0;

  while (win == 0 || lose == 0) {
    affichage(Jeu, mine_map);
    // input from player (creuser, drapeau, quitter)
  }

/*
  while ( ! (joueur a gagné || joueuer a perdu) ) {
    affichage(Jeu, mine_map);
    int1 = nombre de mines découvertes (avec drapeau = 4)
    int2 = nombre de cases découvertes (creusées = 1)
    if int1 = nb_mines ET int2 = ligne*colonne - nb_mines
      GAGNÉ
    if case creusée est une mine (= 2)
      PERDU
  }
*/
  // le joueuer gagne si:
  // - toutes les cases contenant des mines ont un drapeau.
  // - toutes les cases ne contenant pas de mines sont creusées.

  destructor_m(Jeu);
  destructor_m(mine_map);

  return 0;
}
