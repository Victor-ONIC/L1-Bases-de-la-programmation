#include <iostream>

struct Point {
  int X;  // abscisse
  int Y;  // ordonnée
};

char* tableau_char(int n) {
  if (n <= 0) return nullptr;
  char *T = new char[n];
  return T;
}

Point* tableau_Point(int n) {
  if (n <= 0) return nullptr;
  Point *p = new Point[n];
  return p;
}

int main() { return 0; }
