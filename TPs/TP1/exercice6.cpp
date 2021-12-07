#include <math.h>

#include <iostream>
using namespace std;

int main() {
  double a, b, c, delta;
  cout << "Veuillez entrer les valeurs de a, b et c dans l'équation ax²+bx+c.\n";
  cout << "Valeur de a: ";
  cin >> a;
  cout << "Valeur de b: ";
  cin >> b;
  cout << "Valeur de c: ";
  cin >> c;
  if (a == 0) {
    cout << "a doit être différent de 0.";
    return 1;
  }
  delta = b*b - 4*a*c;
  if (delta > 0) {
    double solution1 = (-b - sqrt(delta)) / (2*a);
    cout << endl << solution1 << endl;
    double solution2 = (-b + sqrt(delta)) / (2*a);
    cout << endl << solution2 << endl;
  } else if (delta == 0) {
    double solution = (-b) / (2*a);
    cout << endl << solution << endl;
  } else 
    cout << "Pas de solutions.";
}
