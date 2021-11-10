#include <iostream>
#include <math.h>
using namespace std;

int n = 1;  // variable globale

void func(void);  // void remplace (), c'est une possibilité

int main() {
  unsigned int n = 6;  // variable locale, prend le dessus sur le n global
  
  return 0;
}


void func(void) {}  // (void) est à privilégier, pour éviter la confusion