#include <iostream>
using namespace std;

int main() {
  int a, b;
  cout << "Veuillez donner eux entiers a et b.\n";
  cin >> a >> b;
  if (a > b)
    cout << "Plus grand.\n";
  else if (b > a)
    cout << "Plus petit.\n";
  else
    cout << "Égal.\n";
}
