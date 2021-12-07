#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <thread>

struct matrice {
  int nbl;
  int nbc;
  int **T;
};

// Function list
// void cout_m(matrice *une_matrice);
// void destructor_m(matrice *M);
// int **creer_tab_2D(int ligne, int colonne);
// matrice *construit_matrice(int ligne, int colonne);
// void init_mat_zero(matrice &M);
// matrice *Init_jeu(int ligne, int colonne, int difficulty);
// matrice *mines_autour(matrice *T);
// void clear(void);
// void aff_banner(void);
// void affichage(matrice *T, matrice *M);
// void poser_drapeau(matrice *T, int i, int j);
// void lever_drapeau(matrice *T, int i, int j);
// bool peut_pas_creuser(matrice *T, int i, int j);
// bool creuser (matrice *T, matrice *M, int i, int j, int N, int &mines);

void cout_m(matrice *une_matrice) {  // OK
  std::cout << std::endl;
  for (int i = 0; i < une_matrice->nbl; i++) {
    for (int j = 0; j < une_matrice->nbc; j++) {
      std::cout << une_matrice->T[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void destructor_m(matrice *M) {  // OK
  for (int supp = 0; supp < M->nbl; supp++) {
    delete[] M->T[supp];
  }
  delete[] M->T;
  delete M;
}

int **creer_tab_2D(int ligne, int colonne) {  // OK
  int **T = new int *[ligne];
  for (int i = 0; i < ligne; i++) {
    T[i] = new int[colonne];
  }
  return T;
}

matrice *construit_matrice(int ligne, int colonne) {  // OK
  matrice *m = new matrice;
  m->nbl = ligne;
  m->nbc = colonne;
  m->T = creer_tab_2D(ligne, colonne);
  return m;
}

void init_mat_zero(matrice &M) {  // OK
  for (int i = 0; i < M.nbl; i++) {
    for (int j = 0; j < M.nbc; j++) {
      M.T[i][j] = 0;
    }
  }
}

matrice *Init_jeu(int ligne, int colonne, int difficulty) {  // OK
  srand(time(NULL));

  matrice *T = construit_matrice(ligne, colonne);
  init_mat_zero((*T));  // toutes les cases sont à 0.

  // ici, peut-être cout_m et cin quelle case commencer ?
  // puis, placer les mines en fonction de ça.

  for (int i = 0; i < difficulty; i++) {  // placer les mines
    int p_lig = -1, p_col = -1;
    while (p_lig < 0 || p_col < 0 || T->T[p_lig][p_col] == 2) {
      p_lig = rand() % ligne;
      p_col = rand() % colonne;
    }
    T->T[p_lig][p_col] = 2;
    std::cout << "Mine placee.\n";
  }

  return T;
}

matrice *mines_autour(matrice *T) {  // OK
  // M[i][j] contient le nb_mines autour de T[i][j].
  // M[i][j] = 9 si T[i][j] est une mine.
  matrice *M = construit_matrice(T->nbl, T->nbc);
  init_mat_zero((*M));

  // Toutes les valeurs de M sont à 0 ici.
  for (int ligne = 0; ligne < M->nbl; ligne++) {
    for (int colonne = 0; colonne < M->nbc; colonne++) {  // T[ligne][colonne]
      if (T->T[ligne][colonne] != 2) {
        // Si ligne = 0, tout en haut (is_lig_zero)
        // Si colonne = 0, tout à gauche (is_col_zero)
        // Si ligne = M->nbl - 1, tout en bas (is_lig_max)
        // Si colonne = M->nbc - 1, tout à droite (is_col_max)
        int is_lig_zero = ligne == 0 ? 1 : 0;
        int is_col_zero = colonne == 0 ? 1 : 0;
        int is_lig_max = ligne == (M->nbl - 1) ? 1 : 0;
        int is_col_max = colonne == (M->nbc - 1) ? 1 : 0;
        for (int i = (ligne - 1 + is_lig_zero); i <= (ligne + 1 - is_lig_max); i++) {
          for (int j = (colonne - 1 + is_col_zero); j <= (colonne + 1 - is_col_max); j++) {
            if (i == ligne && j == colonne) continue;
            if (T->T[i][j] == 2) M->T[ligne][colonne]++;
          }
        }
      }
      else {
        M->T[ligne][colonne] = 9;
      }
    }
  }

  return M;
}

void clear(void) {  // OK
  std::cout << "\x1B[2J\x1B[3J\x1B[H";
} 

void aff_banner(void) {  // OK
  clear();
  std::vector<std::string> banner;
  // 10 x 98
  banner.push_back(" ,gggggggggggg,                                                                                   ");
  banner.push_back("dP\"\"\"88\"\"\"\"\"\"Y8b,                                                                                 ");
  banner.push_back("Yb,  88       `8b,                                                                                ");
  banner.push_back(" `\"  88        `8b                              gg                                                ");
  banner.push_back("     88         Y8                              \"\"                                                ");
  banner.push_back("     88         d8  ,ggg,    ,ggg,,ggg,,ggg,    gg    ,ggg,,ggg,    ,ggg,   gg      gg   ,gggggg, ");
  banner.push_back("     88        ,8P i8\" \"8i  ,8\" \"8P\" \"8P\" \"8,   88   ,8\" \"8P\" \"8,  i8\" \"8i  I8      8I   dP\"\"\"\"8I ");
  banner.push_back("     88       ,8P' I8, ,8I  I8   8I   8I   8I   88   I8   8I   8I  I8, ,8I  I8,    ,8I  ,8'    8I ");
  banner.push_back("     88______,dP'  `YbadP' ,dP   8I   8I   Yb,_,88,_,dP   8I   Yb, `YbadP' ,d8b,  ,d8b,,dP     Y8,");
  banner.push_back("    888888888P\"   888P\"Y8888P'   8I   8I   `Y88P\"\"Y88P'   8I   `Y8888P\"Y8888P'\"Y88P\"`Y88P      `Y8");
  for (int i = 0; i < banner.size(); i++) std::cout << banner[i] << std::endl;

  std::cout << std::endl << std::endl;
  for (int j = 0; j < 99; j++) {
    std::cout << "#";
    std::this_thread::sleep_for(std::chrono::milliseconds(4));
  }
}

bool choix(int t, int d) {
  bool a = (
    (t == 1 && d > 2) || (t == 2 && d > 6)
    || t <= 0 || t > 4
    || d <= 0 || d > 8
  );
  return a;
} 

void menu(int &ligne, int &colonne, int &difficulty) {
  using namespace std;
  clear();
  cout << "\n\n\nBienvenue !!!\n\n";
  int choix_taille = 0;
  int choix_diff = 0;
  while (choix(choix_taille, choix_diff)) {
    clear();
    cout << "\n\n\nChoisissez une taille de tableau: \n";  // max 30 x 50
    cout << "1.           10 x 10" << endl;
    cout << "2.           20 x 20" << endl;
    cout << "3.           30 x 30" << endl;
    cout << "4.           30 x 50" << endl;
    cin >> choix_taille;
    clear();
    cout << "\n\n\nChoisissez la difficulte du jeu: \n";
    cout << "1.           10 mines" << endl;
    cout << "2.           50 mines" << endl;
    cout << "3.           100 mines" << endl;
    cout << "4.           150 mines" << endl;
    cout << "5.           200 mines" << endl;
    cout << "6.           300 mines" << endl;
    cout << "7.           400 mines" << endl;
    cout << "8.           500 mines" << endl;
    cin >> choix_diff;
  }
 
  switch (choix_taille) {
    case 1:  
      ligne = 10;
      colonne = 10;
      break;
    case 2:  
      ligne = 20;
      colonne = 20;
      break;
    case 3:  
      ligne = 30;
      colonne = 30;
      break;
    case 4:  
      ligne = 30;
      colonne = 50;
      break;
    default:
      ligne = 3;
      colonne = 3;
      break;
  }
  switch (choix_diff) {
    case 1:
      difficulty = 10;
      break;
    case 2:
      difficulty = 50;
      break;
    case 3:
      difficulty = 100;
      break;
    case 4:
      difficulty = 150;
      break;
    case 5:
      difficulty = 200;
      break;
    case 6:
      difficulty = 300;
      break;
    case 7:
      difficulty = 400;
      break;
    case 8:
      difficulty = 500;
      break;
    default:
      difficulty = 1;
      break;
  }
}

void affichage(matrice *T, matrice *M) {  // OK
  using namespace std;
  clear();
  cout << endl;
  cout << "  " << "   ";
  for (int aff_col = 0; aff_col < T->nbc; aff_col++) {
    if (aff_col < 10) cout << aff_col << "  ";
    else cout << aff_col << " ";
  }
  cout << endl;
  for (int s_h = 0; s_h < T->nbc + 2; s_h++) {  // séparateur horizontal
    cout << "   ";
  }
  cout << endl;

  for (int i = 0; i < T->nbl; i++) {
    if (i < 10) cout << i << "  " << "  ";
    else cout << i << " " << "  ";  // séparateur vertical
    for (int j = 0; j < T->nbc; j++) {  // Pour chaque T[i][j].
    // si la case n'est pas creusée -> ?
    // si la case est creusée -> nb_mines_autour
    // si la case a un drapeau -> d
      if (T->T[i][j] == 0 || T->T[i][j] == 2) {
        cout << "?" << "  ";
      }
      else if (T->T[i][j] == 1) {
        cout << M->T[i][j] << "  ";
      }
      else if (T->T[i][j] == 3 || T->T[i][j] == 4) {
        cout << "d" << "  ";
      }
      else {
        cout << "E" << "  ";  // Erreur
      }
    }
    cout << endl;
  }

}

void poser_drapeau(matrice *T, int i, int j) {
  if (T->T[i][j] == 0) T->T[i][j] = 3;
  else if (T->T[i][j] == 2) T->T[i][j] = 4;
  // cout un message
}

void lever_drapeau(matrice *T, int i, int j) {
  if (T->T[i][j] == 3) T->T[i][j] = 0;
  else if (T->T[i][j] == 4) T->T[i][j] = 2;
  // cout un message
}

bool peut_pas_creuser(matrice *T, int i, int j) {
  bool a = (!(T->T[i][j] == 0 || T->T[i][j] == 2) || 
            (i < 0 || i >= T->nbl || j < 0 || j >= T->nbc)
           );
  return a;
}

bool creuser (matrice *T, matrice *M, int i, int j, int N, int &mines) {
  if (peut_pas_creuser(T, i, j)) // message on peut pas creuser "vous ne pouvez pas creuser ici".
  // ...
  if (T->T[i][j] == 0) return true;
  else return false;
  return false;
}
