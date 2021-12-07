#include <iostream>
using namespace std;

int main() {
  int number = 1, index = -1, min, max;
  float sum = 0;
  do {
    cout << "\nEntrez un nombre non nul.\n"
         << "Pour arrêter la saisie, entrez 0. ";
    cin >> number;
    if (index == -1) min = number, max = number;
    sum += number;
    index++;
    if (number > max) max = number;
    if (number < min && number != 0) min = number;
  } while (number != 0);
  cout << "\nMoyenne: " << sum / index << endl;
  cout << "Maximum: " << max << endl;
  cout << "Minimum: " << min;
  return 0;
}