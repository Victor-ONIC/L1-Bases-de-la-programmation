#include <iostream>
using namespace std;

int main() {
  int number;
  float sumOdd = 0, sumEven = 0;
  int indexOdd = 0, indexEven = -1;
  do {
    cout << "\nEntrez un nombre non nul.\n"
         << "Pour arrêter la saisie, entrez 0. ";
    cin >> number;
    if (number % 2 == 0) {
      sumEven += number;
      indexEven++;
    } else {
      sumOdd += number;
      indexOdd++;
    }
  } while (number != 0);
  cout << "\nMoyenne des pairs: " << sumEven / indexEven << endl;
  cout << "Moyenne des impairs: " << sumOdd / indexOdd;
  return 0;
}