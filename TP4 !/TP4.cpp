#include <math.h>

#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

struct date {
  char jour[10];
  int j, m, a;
};

int main() {
  srand(time(NULL));
  int N;
  int year, month, day, weekDay;
  int fDay, fMonth, fYear, fCentury, W;  // 'f' pour 'formula'
  bool isLeap;
  date T[1000];
  do {
    cout << "Donnez N (0<N<1000): ";
    cin >> N;
  } while (N < 1 || N > 999);

  for (int i = 0; i < N; i++) {
    year = rand() % 71 + 1950 + 1;
    isLeap = year % 4 == 0 xor (year % 100 == 0 xor year % 400 == 0);
    month = rand() % 12 + 1;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
        month == 10 || month == 12) {
      day = rand() % 31 + 1;
    } else {
      if (month != 2) day = rand() % 30 + 1;
      day = rand() % 28 + isLeap + 1;
    }

    fDay = day;
    if (month == 1) {
      fMonth = 11;
    } else if (month == 2) {
      fMonth = 12;
    } else {
      fMonth = month - 2;
    }
    if (year > 1999) {
      fYear = (fMonth == 11 || fMonth == 12) ? year - 2001 : year - 2000;
      fCentury = 20;
    } else {
      fYear = (fMonth == 11 || fMonth == 12) ? year - 1901 : year - 1900;
      fCentury = 19;
    }

    W = (fDay + (int)floor((2.6 * fMonth) - 0.2) - (2 * fCentury) + fYear + (int)floor(fYear / 4) + (int)floor(fCentury / 4)) % 7;
    weekDay = W < 0 ? W + 7 : W;
    switch (weekDay) {
      case 0:
        strcpy(T[i].jour, "Dimanche");
        break;
      case 1:
        strcpy(T[i].jour, "Lundi");
        break;
      case 2:
        strcpy(T[i].jour, "Mardi");
        break;
      case 3:
        strcpy(T[i].jour, "Mercredi");
        break;
      case 4:
        strcpy(T[i].jour, "Jeudi");
        break;
      case 5:
        strcpy(T[i].jour, "Vendredi");
        break;
      case 6:
        strcpy(T[i].jour, "Samedi");
        break;
      default:
        cout << "\nERROR weekDay is out of bounds!\n";
        return 0;
    }
    T[i].j = day;
    T[i].m = month;
    T[i].a = year;
  }

}