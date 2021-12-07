#include <iostream>
using namespace std;

int main() {
  int number = 0, divisors = 0;
  do {
    cout << "Entrez un entier strictement positif: ";
    cin >> number;
  } while (number <= 0);
  for (int i = 1; i <= number; i++) {
    if (number % i == 0) {
      divisors++;
    }
  }
  if (divisors == 2)
    cout << "PREMIER";
  else
    cout << "PAS PREMIER";
  return 0;
}