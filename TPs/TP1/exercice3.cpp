#include <iostream>
using namespace std;

int main() {
  int nombre;
  cout << "Veuillez entrer un nombre.\n";
  cin >> nombre;
  if ((nombre > 10 && nombre <= 20) || (nombre >= 50 && nombre <= 100))
    cout << "Dans l'intervalle.\n";
  else
    cout << "En dehors de l'intervalle.\n";
}
