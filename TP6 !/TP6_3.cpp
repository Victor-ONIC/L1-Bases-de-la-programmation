#include <iostream>
using namespace std;

struct date {
  int j, m, a;
};

int sever(int n, int& a, int& b);
int which_day(date &d);
int afficher_dates(date T[], int N);
bool ant(date &d1, date &d2);
int min_max(date T[], int N, date &d1, date &d2);

int main() {
  date victor = {4, 3, 2003};
  cout << "Le 4 mars 2003: " << which_day(victor) << endl;

  date T[] = {
    {4, 3, 2003},
    {24, 12, 2003},
    {16, 1, 2003},
    {30, 7, 2001},
    {1, 1, 2000},
    {31, 12, 2019},
    {6, 6, 2006}
  };
  int taille = sizeof(T)/sizeof(date);
  cout << "Les dates du tableau: " << endl;
  afficher_dates(T, taille);

  date date1, date2;
  min_max(T, taille, date1, date2);
  cout << "Date la plus recente: " << date1.j << "/" << date1.m << "/" << date1.a << endl;
  cout << "Date la plus ancienne: " << date2.j << "/" << date2.m << "/" << date2.a << endl;

  return 0;
}


int afficher_dates(date T[], int N) {
  char daysList[15][15] = {
    {"Dimanche"},
    {"Lundi"},
    {"Mardi"},
    {"Mercredi"},
    {"Jeudi"},
    {"Vendredi"},
    {"Samedi"}
  };
  for (int i = 0; i < N; i++)
    cout << "T[" << i << "]" << ": " << daysList[which_day(T[i])] << endl;

  return 0;
}

int sever(int n, int &a, int &b) {
  a = (int)n / 100;
  b = n - (100 * a);
  return 0;
}

int which_day(date &d) {
  int M, A, ns, as, f;
  if (d.m < 3) {
    M = d.m + 10;
    A = d.a - 1;
  }
  else {
    M = d.m - 2;
    A = d.a;
  }
  sever(A, ns, as);
  f = (d.j + as + (as/4) - (2*ns) + (ns/4) + (((26*M)-2)/10)) % 7;
  f = f < 0 ? f + 7 : f;
  return f;
}

bool ant(date &d1, date &d2) {
  return (d1.a < d2.a || (d1.m < d2.m && d1.a <= d2.a) || 
          (d1.j < d2.j && d1.m <= d2.m && d1.a <= d2.a));
}

int min_max(date T[], int N, date &recente, date &ancienne) {
  date min = T[0], max = T[0];
  for (int i = 0; i < N; i++) {
    if (ant(T[i], min)) min = T[i];
    else if (ant(max, T[i])) max = T[i];
  }
  ancienne = min;
  recente = max;
  
  return 0;
}