#include <iostream>

int partitionner(int T[], int debut, int fin);
void tri_rapide(int T[], int debut, int fin);

int main() {
  int T[]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  tri_rapide(T, 0, 10);
  for (int i = 0; i < 10; i++) std::cout << T[i] << " ";
}

int partitionner(int T[], int debut, int fin) {
  int compteur = debut;
  int pivot = T[debut];
  for (int i = debut + 1; i <= fin; i++) {
    if (T[i] < pivot) {
      compteur++;
      int tmp = T[i];
      T[i] = T[compteur];
      T[compteur] = tmp;
    }
  }
  int tmp = T[debut];
  T[debut] = T[compteur];
  T[compteur] = tmp;
  return compteur;
}

void tri_rapide(int T[], int debut, int fin) {
  if (debut < fin) {
    int pivot = partitionner(T, debut, fin);
    tri_rapide(T, debut, pivot - 1);
    tri_rapide(T, pivot + 1, fin);
  }
}