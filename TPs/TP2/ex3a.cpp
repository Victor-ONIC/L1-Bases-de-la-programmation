#include <iostream>
using namespace std;

int main() {
  int number, index = -1;
  float sum = 0;
  do {
    cout << "\nEntrez un nombre non nul.\n"
         << "Pour arrêter la saisie, entrez 0. ";
    cin >> number;
    sum += number;
    index += 1;
  } while (number != 0);
  cout << "\nMoyenne: " << sum / index;
  return 0;
}