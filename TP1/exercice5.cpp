#include <iostream>
using namespace std;

int main() {
  int operation, op1, op2;
  cout << "Veuillez choisir une opération puis entrez deux opérandes.\n";
  cout << "Addition: 1\nSoustraction: 2\nMultiplication: 3\nDivision: 4 "
          "(Attention à ne pas diviser par 0)\n";
  cin >> operation;
  cout << "Opérande 1: ";
  cin >> op1;
  cout << "Opérande 2: ";
  cin >> op2;
  if (operation == 1) cout << op1 + op2 << endl;
  if (operation == 2) cout << op1 - op2 << endl;
  if (operation == 3) cout << op1 * op2 << endl;
  if (operation == 4) {
    if (op2 == 0) {
      cout << "Division par 0 !\n";
      return 1;
    }
    cout << op1 / op2 << endl;
  }
}
