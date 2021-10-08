#include <iostream>
using namespace std;

int main() {
  int entier;
  float moyenne = 0;
  cout << "Veuillez entrer cinq entiers.\n";
  for (int i = 0; i < 5; i++) {
    cin >> entier;
    moyenne += entier;
  }
  cout << "La moyenne est " << moyenne / 5 << endl;
}