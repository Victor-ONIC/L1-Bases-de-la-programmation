#include <iostream>
using namespace std;

int main() {
  const int justePrix = 42;
  int number = 0;
  do {
    cout << "\nEssayez de trouver le juste prix ! ";
    cin >> number;
    if (number > justePrix)
      cout << "Plus petit !\n";
    else if (number < justePrix)
      cout << "Plus grand !\n";
    else {
      cout << "\nBRAVO!!!!!!\n";
      return 0;
    }
  } while (number != justePrix);
  return 0;
}
