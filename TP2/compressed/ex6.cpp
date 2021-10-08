#include <iostream>
using namespace std;

int main() {
  int L = 0, l = 0;
  do {
    cout << "Donnez une longueur et une largeur: \n\n";
    cout << "La longueur et la largeur doivent être deux nombres entiers "
            "positifs.\n\n";
    cout << "Longueur: ";
    cin >> L;
    cout << "Largeur ";
    cin >> l;
    cout << endl;
  } while (L <= 0 || l <= 0);
  for (int i = l; i > 0; i--) {
    for (int j = L; j > 0; j--) cout << '*';
    cout << endl;
  }
  return 0;
}