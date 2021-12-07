#include <iostream>
#include <math.h>
using namespace std;

int solution_quadratique(int a, int b, int c);
int resoudre(int a, int b, int c, float &x1, float &x2, int &nb_sol);
int afficher(float x1, float x2, int nb_sol);

int main() {

  // fonction qui affiche les solutions: solution_quadratique()
  int A = 1, B = 0, C = 1;
  cout << "Quelles sont les solutions de l'equation ax^2+bx+c=0 ? Trois cas: " << endl;
  cout << "Dans le premier cas, il n'y a pas de solutions: ";
  solution_quadratique(A, B, C);
  cout << "Puis il peut y avoir une ou deux solutions: " << endl;
  C = 0;
  solution_quadratique(A, B, C);
  C = -1;
  solution_quadratique(A, B, C);
  cout << "Le dernier cas est special, il y a une infinite de solutions: ";
  A = 0, C = 0;
  solution_quadratique(A, B, C);

  cout << endl << "////////////////////////////////////////////" << endl;

  // fonction qui retourne les solutions: resoudre()
  // fonction qui les affiche: afficher()
  float solution_1, solution_2;
  int nb_solution = 4;
  A = 1, B = 0, C = -1;  // équation x^2-1=0

  resoudre(A, B, C, solution_1, solution_2, nb_solution);
  afficher(solution_1, solution_2, nb_solution);

  return 0;
}


int solution_quadratique(int a, int b, int c) {
  if (a == 0) {
    if (b == 0) {
      if (c == 0) cout << "Une infinite de solutions." << endl;
      else cout << "Aucune solution." << endl;
    }
    else cout << "Une solution: " << -c / b << endl;
  }
  else {
    float delta = b*b - 4*a*c;
    if (delta < 0) cout << "Aucune solution." << endl;
    else if (delta == 0) cout << "Une solution: " << (float)-b / (2*a) << endl;
    else cout << "Deux solutions: "
              << (float)-b + sqrt(delta) / (2*a) << " et "
              << (float)-b - sqrt(delta) / (2*a) << endl;
  }
  return 0;
}

int resoudre(int a, int b, int c, float &x1, float &x2, int &nb_sol) {
  if (a == 0) {
    if (b == 0) {
      if (c == 0) nb_sol = 3;
      else nb_sol = 0;
    }
    else {
      nb_sol = 1;
      x1 = -c / b;
    }
  }
  else {
    float delta = b*b - 4*a*c;
    if (delta < 0) nb_sol = 0;
    else if (delta == 0) {
      nb_sol = 1;
      x1 = -b / (2*a);
    }
    else {
      nb_sol = 2;
      x1 = -b + sqrt(delta) / (2*a);
      x2 = -b - sqrt(delta) / (2*a);
    }
  }
  return 0;
}

int afficher(float x1, float x2, int nb_sol) {
  switch (nb_sol) {
    case 0:
      cout << "Il n'y a pas de solutions." << endl;
      break;
    case 1:
      cout << "Il y a une solution: " << x1 << "." << endl;
      break;
    case 2:
      cout << "Il y a deux solutions: " << x1 << " et " << x2 << "." << endl;
      break;
    case 3:
      cout << "Il y a une infinite de solutions." << endl;
      break;
    default:
      cout << "//////////////// ERREUR ////////////////";
      break;
  }
  return 0;
}