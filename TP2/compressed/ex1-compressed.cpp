#include <iostream>
using namespace std;

int main() {
  int number=0;
  while (number>=100||number<1) {
    cout<<"Donnez un entier positif et strictement inférieur à 100: ";
    cin>>number;
  }
  cout<<"Merci pour le nombre "<<number;
  return 0;
}
