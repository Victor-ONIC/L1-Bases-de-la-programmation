#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

  srand(time(NULL));
  int T[1000], N, x;
  bool a = false;
  int index_A = 0, index_B = 0;
  float sum_A = 0, sum_B = 0;

  do {
    cout << "Rentrez N le nombre de valeurs dans le tableau: ";
    cin >> N;
  } while (N < 100 || N > 1000);

  for (int i = 0; i < N; i++) T[i] = rand() % 101;

  do {
    cout << "\nVeuillez rentrer x tel que 0 <= x <= 100: ";
    cin >> x;
  } while (x < 0 || x > 100);

  for (int i = 0; i < N; i++) if (x == T[i]) a = true;
  if (a) cout << endl << x << " est present dans le tableau.\n";
  else cout << endl << x << " n'est pas present dans le tableau.\n";

  for (int i = 0; i < N; i++) {
    if (T[i] % 2 == 0 && T[i] <= 50) {
      index_A++;
      sum_A += T[i];
    } else if (T[i] % 2 == 0 && T[i] > 50) {
      index_B++;
      sum_B += T[i];
    }
  }
  cout << "\nLa moyenne des valeurs paires inferieures (ou egales) a 50 est " << sum_A / index_A;
  cout << "\nLa moyenne des valeurs paires superieures (strictement) a 50 est " << sum_B / index_B;


  return 0;
}