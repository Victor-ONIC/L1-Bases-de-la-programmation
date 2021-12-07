#include "func.h"

int main() {

  aff_banner();

  int a, b, c;
  menu(a, b, c);

  matrice *Jeu = Init_jeu(a, b, c);
  cout_m(Jeu);

  matrice *mine = mines_autour(Jeu);
  cout_m(mine);

  affichage(Jeu, mine);
  std::cin.get();

  destructor_m(Jeu);
  destructor_m(mine);
  return 0;
}