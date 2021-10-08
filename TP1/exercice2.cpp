#include <iostream>
using namespace std;

int main() {
  int L, l;
  cout << "Veuillez entrer une valeur pour L et l.\nLa valeur de L doit être "
          "supérieure à celle de l.\n";
  cout << "Valeur de L: ";
  cin >> L;
  cout << "Valeur de l: ";
  cin >> l;
  if (L < l)
    cout << "Données incohérentes.\n";
  else
    cout << L * l << endl;
}
