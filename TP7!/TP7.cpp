#include <iostream>
using namespace std;

int fonction(int n) {
  int S = 0;
  for (int i = 1; i <= n; i++) S = S + i;
  return S;
}
int fonction_recursive(int n) {
  if (n == 1) return 1;
  return (fonction_recursive(n-1)+n);
}

bool palindrome(char const T[], int deb, int fin) {
  if (fin - deb <= 0) return 1;
  return T[deb] == T[fin] && palindrome(T, deb+1, fin-1);
}

bool chercher(int T[], int N, int x) {
  for (int i = 0; i < N; i++) if (T[i] == x) return 1;
  return 0;
}
bool chercher_recursive(int T[], int N, int x) {
  if (N == 0) return 0;
  return T[N-1] == x || chercher_recursive(T, N-1, x);
}

// bool dichotomie(int T, int N, int x) {}  // itérative
/* bool dichotomie(int T, int N, int x) {
  int m = N/2;
  while  {
    if (T[i] == x) return 1;
    else if (T[i] < x) 
  }
} */
bool dichotomie_recursive(int T[], int debut, int fin, int x) {
  int m = (fin - debut) / 2 + debut;
  if (debut > fin) return 0;
  else if (x < T[m]) return T[m] == x || dichotomie_recursive(T, debut, m-1, x);
  else return T[m] == x || dichotomie_recursive(T, m+1, fin, x);
}


void inserer(int T[], int N) {
  for (int i = N-1; i > 0; i--) {
    if (T[i-1] > T[i]) {
      int temp = T[i-1];
      T[i-1] = T[i];
      T[i] = temp;
    }
  }
}

void tri_insertion_recursive (int T[] , int N) {
  if (N == 1) return;
  tri_insertion_recursive(T, N-1);
  inserer(T, N);
  return;
}


int main() {
  int T[] = {0,1,2,3,4,5,6,7,8,9};
  bool p = dichotomie_recursive(T, 0, 10, 6);
  cout << p;

  return 0;
}