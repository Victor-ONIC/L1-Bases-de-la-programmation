#include "func.h"

int main() {

  matrice *Jeu = Init_jeu(18, 18, 1);
  // cout_m(Jeu);

  matrice *mine = mines_autour(Jeu);
  std::cout << "Hello World !";
  std::cout << mine->T[0][0];
  // cout_m(mine);

  // affichage(Jeu, mine);

  destructor_m(Jeu);
  destructor_m(mine);
  return 0;
}
