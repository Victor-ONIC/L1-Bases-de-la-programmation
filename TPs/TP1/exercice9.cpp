#include <iostream>
using namespace std;

int main() {
  int entier, min, max;
  cout << "Veuillez taper six entiers.\n";
  cin >> entier;
  min = entier;
  max = entier;
  for (int i = 0; i < 5; i++) {
    cin >> entier;
    if (entier > max)
      max = entier;
    else if (entier < min)
      min = entier;
  }
  cout << "Plus petite valeur: " << min << endl;
  cout << "Plus grande valeur: " << max << endl;
}