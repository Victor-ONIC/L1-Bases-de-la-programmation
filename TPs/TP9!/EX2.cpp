#include <math.h>
#include <iostream>

#define delete_2_t(x, y) delete[]x;delete[]y;

struct Point {
  int X;  // abscisse
  int Y;  // ordonnée
};

double distance(Point *A, Point *B) {
  // distance = sqrt[(x2 - x1)^2 + (y2 - y1)^2]
  return sqrt(pow((B->X - A->X), 2) + pow((B->Y - A->Y), 2));
}

Point *milieu(Point &A, Point &B) {
  // X: (x1 + x2)/2 et Y: (y1 + y2)/2
  Point *p = new Point;
  p->X = (A.X + B.X) / 2;
  p->Y = (A.Y + B.Y) / 2;
  return p;
  /*
    Point p;
    p.X = (A.X + B.X) / 2;
    p.Y = (A.Y + B.Y) / 2;
    return &p;
    Ca marche pas car p sera détruit a la fin de la fonction.
  */
}

Point *tableau_abscisse_sup(Point P[], int n, int &t) {
  int compteur_valeurs_abs_sup = 0, index = 0;
  // compter les valeurs dont l'abscisse > ordonnée
  for (int i = 0; i < n; i++) {
    if (P[i].X > P[i].Y) compteur_valeurs_abs_sup++;
  }

  if (compteur_valeurs_abs_sup == 0) return nullptr;

  Point *p = new Point[compteur_valeurs_abs_sup];
  t = compteur_valeurs_abs_sup;

  for (int i = 0; i < n; i++) {
    if (P[i].X > P[i].Y) {
      p[index] = P[i];
      index++;
    }
  }

  return p;
}

void repartition(Point P[], int n, Point *&T1, int &taille_T1, 
                                   Point *&T2, int &taille_T2) {
  // les valeurs dont l'abscisse > l'ordonnée:
  T1 = tableau_abscisse_sup(P, n, taille_T1);

  // les valeurs dont l'abscisse < l'ordonnée:
  int compteur_valeurs_ord_sup = 0, index = 0;
  // compter les valeurs dont l'abscisse < ordonnée
  for (int i = 0; i < n; i++) {
    if (P[i].X <= P[i].Y) compteur_valeurs_ord_sup++;
  }

  if (compteur_valeurs_ord_sup == 0) T2 = nullptr;

  Point *p = new Point[compteur_valeurs_ord_sup];
  taille_T2 = compteur_valeurs_ord_sup;

  for (int i = 0; i < n; i++) {
    if (P[i].X <= P[i].Y) {
      p[index] = P[i];
      index++;
    }
  }

  T2 = p;
}

int main() {
  // Test de la fonction 'distance()'
  Point a = {3, 4}, b = {1, 2};
  std::cout << "La distance entre a et b est: " << distance(&a, &b)
            << std::endl;

  // Test de la fonction 'milieu()'
  a = {0, 2};
  b = {5, 4};
  Point *milieu_ab = milieu(a, b);

  std::cout << "Le milieu de a et b est le point: (" << milieu_ab->X << ","
            << milieu_ab->Y << ")" << std::endl;
  delete milieu_ab;

  std::cout << std::endl;

  // Test de la fonction 'tableau_abscisse_sup'
  Point P[] = {
      // La taille de P est 16
      {1, 2}, {1, 5}, {1, 9}, {1, 6}, 
      {2, 2}, {2, 5}, {2, 9}, {2, 6},
      {5, 2}, {5, 5}, {5, 9}, {5, 6}, 
      {9, 2}, {9, 5}, {9, 9}, {9, 6},
  };
  int taille_nouveau_tableau;
  Point *T_abscisse_sup = tableau_abscisse_sup(P, 16, taille_nouveau_tableau);

  std::cout << "Les points dont l'abscisse est superieure a l'ordonnee sont: "
            << std::endl;
  for (int i = 0; i < taille_nouveau_tableau; i++) {
    std::cout << "(" << T_abscisse_sup[i].X << "," << T_abscisse_sup[i].Y << ")"
              << std::endl;
  }
  delete[] T_abscisse_sup;

  std::cout << std::endl;

  // Test de la fonction 'repartition'
  // On utilise le même tableau P
  int taille_abs_sup, taille_ord_sup;
  Point *T_abs_sup, *T_ord_sup;
  repartition(P, 16, T_abs_sup, taille_abs_sup, T_ord_sup, taille_ord_sup);

  std::cout << "Les points dont l'abscisse est superieure a l'ordonnee sont: "
            << std::endl;
  for (int i = 0; i < taille_abs_sup; i++) {
    std::cout << "(" << T_abs_sup[i].X << "," << T_abs_sup[i].Y << ")"
              << std::endl;
  }

  std::cout << "Les points dont l'ordonnee est superieure a l'abscisse sont: "
            << std::endl;
  for (int i = 0; i < taille_ord_sup; i++) {
    std::cout << "(" << T_ord_sup[i].X << "," << T_ord_sup[i].Y << ")"
              << std::endl;
  }

  delete_2_t(T_abs_sup, T_ord_sup); 

  return 0;
}
