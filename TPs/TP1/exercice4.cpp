#include <iostream>
using namespace std;

int main() {
  int a, b, c, temp;
  cout << "Veuillez donner trois nombres A, B et C.\n";
  cout << "Valeur de A: ";
  cin >> a;
  cout << "Valeur de B: ";
  cin >> b;
  cout << "Valeur de C: ";
  cin >> c;
  if (a > b) {
    temp = a;
    a = b;
    b = temp;
  }
  if (b > c) {
    temp = b;
    b = c;
    c = temp;
  }
  if (a > b) {
    temp = a;
    a = b;
    b = temp;
  }
  cout << c << "," << b << "," << a << endl;
}
