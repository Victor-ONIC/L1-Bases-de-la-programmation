#include <iostream>
using namespace std;

int main() {
  int nombre, a, b, c, d;
  cout << "Veuillez entrer un nombre à quatre chiffres.\n";
  cin >> nombre;
  if (nombre < 1000 || nombre > 9999) {
    cout << "Le nombre ne contient pas quatre chiffres.\n";
    return 1;
  }
  a = nombre % 10;
  nombre /= 10;
  b = nombre % 10;
  nombre /= 10;
  c = nombre % 10;
  nombre /= 10;
  d = nombre;
  cout << endl << d << "," << c << "," << b << "," << a << endl;
}
