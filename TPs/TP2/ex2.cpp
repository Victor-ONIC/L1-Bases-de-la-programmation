#include <iostream>
using namespace std;

int main() {
  int number = 0;
  while (number < 2 || number > 9) {
    cout << "\nDonnez un nombre entre 2 et 9 inclus: ";
    cin >> number;
  }
  for (int i = 1; i <= 10; i++) {
    cout << i << "x" << number << "=" << i * number << endl;
  }
  return 0;
}