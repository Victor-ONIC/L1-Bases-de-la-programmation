#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  int T[1000] = {};
  int N;
  srand(time(NULL));
  do {
    cout << "N tel que 1<N<1000:\n";
    cin >> N;
  } while (N >= 1000 || N < 1);
  for (int i = 0; i < N; i++) {
    T[i] = rand() % 2 + 1;
  }
  for (int j = 1; j < N; j++) {
    if (T[j] < T[j - 1]) {
      int tmp = T[j];
      T[j] = T[j - 1];
      T[j - 1] = tmp;
      if (j == 1) continue;
      j -= 2;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << T[i] << " ";
  }
  return 0;
}