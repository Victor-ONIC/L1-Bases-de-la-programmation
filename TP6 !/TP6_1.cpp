#include <iostream>
using namespace std;

bool est_premier(unsigned int n);
int print_prime(unsigned int a, unsigned int b);

int main() {
  
  int chiffre = 6;
  cout << "Le chiffre " << chiffre
       << " est-il premier ? Passons le dans la fonction est_premier(): ";
  if (est_premier(chiffre))
    cout << chiffre << " est premier." << endl;
  else cout << chiffre << " n'est pas premier." << endl;

  int valeur_A = 0, valeur_B = 10;
  cout << "Quels sont les nombres premiers compris entre " << valeur_A << " et "
       << valeur_B << " ?" << endl;
  cout << "Passons les deux valeurs dans la fonction print_prime(): ";
  print_prime(valeur_A, valeur_B);

  return 0;
}


bool est_premier(unsigned int n) {
  for (int i = 2; i < n; i++) if (n % i == 0) return false;
  return true;
}

int print_prime(unsigned int a, unsigned int b) {
  for(int i = a; i < b; i++) {
    if (i == 0 || i == 1) continue;
    if (est_premier(i)) cout << i << ' ';
  }
  cout << endl;
  return 0;
}