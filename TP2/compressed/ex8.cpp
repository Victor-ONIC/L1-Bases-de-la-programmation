#include <iostream>
using namespace std;

int main() {
  long long int factorial = 1;
  int number = 0;
  do {
    cout << "\nNombre (>0) : ";
    cin >> number;
  } while (number <= 0);
  for (int i = 1; i <= number; i++) factorial *= i;
  cout << number << "! = " << factorial << endl;
  return 0;
}