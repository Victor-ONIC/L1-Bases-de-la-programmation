#include <iostream>
using namespace std;

int main() {
  int number1, number2, divisors = 0;
  do {
    cout << "\nEntrez deux entiers strictement positifs, tel que le premier "
            "soit inférieur au second: ";
    cout << "\nPremier entier: ";
    cin >> number1;
    cout << "Second entier: ";
    cin >> number2;
  } while (number2 < number1 || number1 <= 0 || number2 <= 0);
  cout << "Liste des entiers premiers entre " << number1 << " et " << number2
       << " inclus:" << endl;
  for (int i = number1; i <= number2; i++) {
    for (int j = 1; j <= i; j++)
      if (i % j == 0) divisors++;
    if (divisors == 2) cout << i << " ";
    divisors = 0;
  }
  return 0;
}