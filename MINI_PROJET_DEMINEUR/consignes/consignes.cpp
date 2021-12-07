/*

Le jeu consiste en une matrice de cases où chaque case a une valeur selon la
situation:
- 0: pas de mine    pas creusée
- 1: pas de mine    creusée
- 2: mine           pas creusée
- 3: pas de mine    drapeau
- 4: mine           drapeau
- -1: espace vide

Au début du jeu, aucune case n'est minée, et certaines cases ont une mine.
Donc toutes les cases sont soit 0, soit 2.


matrice *Init_jeu(int n, int m, int difficulty);
  Renvoie une matrice n x m (T).
    Mines disposées aléatoirement (selon la difficulté).

matrice *mines_autour(matrice *T);
  Renvoie M matrice de même taille que T la matrice du jeu.
    (i,j) de M contient le nombre de mines autour de (i,j) de T (1-8).

void affichage(matrice *T, matrice *M);
-> Présente le jeu au joureur (terminal, ou interface graphique).
  Chaque "case" contient un symbole, selon la valeur de (i,j):
    - 1: 1,2,3,4,5,6,7,8: le nombre de mines autour, donc M[i][j];
    - 0 et 2: ?: case non découverte;
    - 3 et 4: d: un drapeau a été posé;
    - -1: []: rien pour faire de l'espace.
  Afficher les numéros de lignes et de colonne.

  //    0 1 2 3 4 5 6 7 8
  //
  // 0   ? ? 1….
  // 1   ? ? ?…..d
  // 2   . . .

void poser_drapeau(matrice *T, int i, int j);
  Selon la case, mettre le drapeau:
    - si (i,j)=0 (pas de mine, pas creusée) -> (i,j)=3 (pas de mine, drapeau).
    - si (i,j)=2 (mine, pas creusée) -> (i,j)=4 (mine, drapeau).
    - sinon, rien faire.


void lever_drapeau(matrice *T, int i, int j);
  Selon la case, retirer le drapeau:
    - si (i,j)=3 -> (i,j)=0.
    - si (i,j)=4 -> (i,j)=2.
    - sinon, rien faire.

bool creuser(matrice *T, matrice *M, int i, int j, int N???, int &mines);
Arguments:
  -T la matrice du jeu et M la matrice des mines.
  -Creuse la case de T de coordonnées (i,j).
  -N le nombre de cases déjà découvertes (pour quoi faire ?).
</Arg>
  - /!\ On ne peut pas creuser:
    - une case déjà creusée (1);
    - une case avec un drapeau (3 ou 4);
    - une case non-existante ((i,j) n'est pas dans la matrice T).
    - on ne peut creuser QUE 0 ou 2.
  - Renvoie true si la case ne contient pas de mines, false sinon.
  - Renvoie le nombre de mines découvertes (mines) (utilisé dans la boucle du main pour gagner.)

void creuser_recu(???);
  RECURSIVITÉ............

long score(???);
-> Donne le score basé sur plusieurs paramètres:
  - difficulté (proportions nb_cases/nb_mines).
  - nb_cases découvertes / nb_cases sans mines (avancement).
  - temps (timer).

--------------------------------------------------------------------------------
int main()  // mettre des cout à chaque action du joueur.
// Les actions possibles par le joueur:
// - Creuser une case:
//   - C'est une mine:
//     -> partie terminée.
//   - C'est pas une mine:
//     -> affiche le nombre de mines adjacentes.
// - Mettre un drapeau:
//   - affiche un symbole sur la case.
//   - la case ne peut plus être creusée.
// - Enlever un drapeau:
//   - retire le symbole sur la case.
//   - la case peut à nouveau être creusée.
// Le jeu est modélisé par une matrice de taille (n, m).

- Créer une matrice de jeu.
- Initialiser la matrice de jeu à 0.
- Remplir la matrice aléatoirement avec des mines selon la difficulté.

- Démarrer le timer.
Tant que ()
  - Afficher.
  - Demander quelle action faire ?
    - Creuser.
    - Mettre/Enlever drapeau.
  - Si le nombre de mines découvertes ((i,j) de T = 4) est égal au nombre de cases libres ((i,j) de T = 2), alors la partie est gagnée:
    Partie gagnée.
  - Si une case avec une mine (2) est creusée, la partie est perdue:
    Partie perdue.
Fin tant que.
- Terminer le timer.

- DELETE TOUT.
--------------------------------------------------------------------------------

JOKER ?????????

Les mines ont une puissance, et le joueur a une barre de vie ?????????????


















*/