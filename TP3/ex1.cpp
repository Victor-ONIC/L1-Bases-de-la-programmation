#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  int T[1000] = {};
  int boundA, boundB, N, x, min, max, indexOdd = 0, indexEven = 0;
  float sumOdd = 0, sumEven = 0;
  srand(time(NULL));
  do {
    cout << "a, b, N tel que a<b et 1<N<1000:\n";
    cin >> boundA >> boundB >> N;
  } while (N >= 1000 || N < 1 || boundA > boundB);
  for (int i = 0; i < N; i++) {
    T[i] = rand() % (boundB - boundA) + boundA + 1;
    if (T[i] % 2 == 0) {
      sumEven += i;
      indexEven++;
    } else {
      sumOdd += i;
      indexOdd++;
    }
    if (T[i] > max) max = T[i];
    if (T[i] < min) min = T[i];
  }
  cout << endl << "x:" << endl;
  cin >> x;
  for (int i = 0; i < N; i++) {
    if (T[i] == x) {
      cout << "Present dans le tableau.\n";
      goto next;
    }
  }
  cout << "Absent du tableau.\n";
next:
  cout << "\nCaracteristiques du tableau:" << endl;
  cout << "Moyenne: " << (sumOdd + sumEven) / (indexEven + indexOdd) << endl;
  cout << "Moyenne des pairs: " << sumEven / indexEven << endl;
  cout << "Moyenne des impairs: " << sumOdd / indexOdd << endl;
  cout << "Valeur minimale: " << min << endl;
  cout << "Valeur maximale: " << max << endl;
  return 0;
}
