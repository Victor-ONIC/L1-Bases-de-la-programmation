/*

--------------------------------------------------------------------------------

tableau d'int de taille n:
int *p = new int[n];

tableau de pointeurs sur int de taille n:
int **p = new int *[n];

Pour créer une tableau à deux dimensions:
int **creer_tab_2D(int n, int m) {
  int **p = new int *[n];  // il y a n lignes.
  for (int i = 0; i < n; i++) {  // n fois je crée un tableau de taille m.
    p[i] = new int[m];  // sur chaque pointeurs de p, je fais un tableau.
  }
  return p;
}

int **Tableau = creer_tab_2D(10, 10);
T[5][5];  // accède à la case (5, 5).

--------------------------------------------------------------------------------

Le jeu est contenu dans une structure matrice (précurseur de la POO):
struct matrice {
  int nbl;
  int nbc;
  int *T;
}

Pour créer une matrice (ici la fonction est donnée mais à faire dans le TP10):
matrice *construit_matrice(int ligne, int colonne) {
  matrice *m = new matrice;
  m->nbl = ligne;
  m->nbc = colonne;
  m->T =  creer_tab_2D(ligne, colonne);
  return p;
}

Pour initialiser une matrice à 0, on met les valeurs des tableaux à 0:
void init_mat_zero(matrice &M) {
  for (int i = 0; i < M.nbl; i++) {
    for (int j = 0; i < M.nbc; j++) {
      M.T[i][j] = 0;
    }
  }
}

Pour créer une matrice on peut faire (dans le main):
matrice *MATRICE = creer_matrice(10, 10);
init_mat_zero((*MATRICE));

--------------------------------------------------------------------------------


























*/