#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int remplir(int T[], int N);
int afficher(int T[], int N);
int compte_moins_50(int T[], int N);
int moyennes(int T[], int N, float &m1, float &m2, float &m3);
int nb_occurences(int T[], int N, int x);
bool n_dans_tableau(int T[], int N, int n);

int main() {
  srand(time(NULL));
  int Tableau[250];

  // Test de 'remplir'.
  remplir(Tableau, 250);

  // Test de 'afficher'.
  afficher(Tableau, 250);

  // Test de 'compte_moins_50'.
  int nb_inf_50 = compte_moins_50(Tableau, 250);
  cout << "\nLe nombre de valeurs inferieures ou egales a 50 est " << nb_inf_50;

  // Test de 'moyennes'.
  float moyenne_inf_50, moyenne_sup_50, moyenne;
  moyennes(Tableau, 250, moyenne_inf_50, moyenne_sup_50, moyenne);
  cout << "\nLes moyennes du tableau sont:";
  cout << "\nMoyenne des <=50: " << moyenne_inf_50;
  cout << "\nMoyenne des >50: " << moyenne_sup_50;
  cout << "\nMoyenne: " << moyenne;

  // Test de 'nb_occurences'.
  int nb_42 = nb_occurences(Tableau, 250, 42);
  cout << "\nLe nombre 42 est present " << nb_42 << " fois.";

  // Test de 'n_dans_tableau'.
  if (n_dans_tableau(Tableau, 250, 3))
    cout << "\nIl y a une valeur presente 3 fois dans le tableau.";
  else cout << "\nIl n'y a pas de valeur presente 3 fois dans le tableau.";

  return 0;
}

int remplir(int T[], int N) {
  for (int i = 0; i < N; i++) T[i] = rand() % 101;
  return 0;
}

int afficher(int T[], int N) {
  for (int i = 0; i < N; i++) cout << T[i] << " ";
  cout << endl;
  return 0;
}

int compte_moins_50(int T[], int N) {
  int index = 0;
  for (int i = 0; i < N; i++) if (T[i] <= 50) index++;
  return index;
}

int moyennes(int T[], int N, float &m1, float &m2, float &m3) {
  int index_1 = 0, index_2 = 0, index_3 = 0;
  float sum_1 = 0, sum_2 = 0, sum_3 = 0;
  for (int i = 0; i < N; i++) {
    if (T[i] > 50) {
      index_2++;
      sum_2 += T[i];
      sum_3 += T[i];
    } else {
      index_1++;
      sum_1 += T[i];
      sum_3 += T[i];
    }
  }
  m1 = sum_1 / index_1;
  m2 = sum_2 / index_2;
  m3 = sum_3 / (index_1 + index_2);
  return 0;
}

int nb_occurences(int T[], int N, int x) {
  int index = 0;
  for (int i = 0; i < N; i++) if (T[i] == x) index++;
  return index;
}

bool n_dans_tableau(int T[], int N, int n) {
  int index;
  for (int i = 0; i < N; i++) {
    if (nb_occurences(T, N, T[i]) >= n) return true;
  }
  return false;
}