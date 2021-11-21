#include <iostream>
using namespace std;

int fonction(int n);
bool palindrome(char T[], int deb, int fin);
bool chercher(int T[], int N, int x);
bool dikotomy(int T[], int deb, int fin, int x);

int main() {
  // char C[] = "helleh";
  // bool p = palindrome(C, 0, 5);
  // cout << p;

  /* int T[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, '0'};
  bool c = dikotomy(T, 0, 9, 'o');  // très intéressant !
  cout << c;
  return 0; */

  cout << 11/2;
}

int fonction(int n) {
  if (n == 1) return 1;
  return (fonction(n-1)+n);
}

bool palindrome(char T[], int deb, int fin) {  // voir correction
  if (deb >= fin) return 1;
  return T[deb] == T[fin] && palindrome(T, deb+1, fin-1);
}

bool chercher(int T[], int N, int x) {  // une fonction recursive ressemblera toujours a ca
  if (T[N-1] == x) return 1;
  return N != 1 && chercher(T, N-1, x);
}

bool dikotomy(int T[], int deb, int fin, int x) {
  if (x == T[(fin-deb)/2+deb]) return 1;
  else if (x < T[(fin-deb)/2+deb]) return dikotomy(T, deb, (3*fin-deb)/4, x);
  return dikotomy(T, (fin+5*deb)/4, fin, x);
}