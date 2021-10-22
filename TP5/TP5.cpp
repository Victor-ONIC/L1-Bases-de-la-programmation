#include <iostream>
using namespace std;

struct date {
  int j, m, a;
};

struct compte {  // 8
  char nom[15];
  char prenom[15];
  date dateNaissance;
  float solde;
};

bool egale(date& d1, date& d2);
int askN(date T[], int Nmax);
void afficher(date T[], int N);
bool inTable(date T[], int N, date D);
bool anterieure(date d1, date d2);
void insertDate(date T[], int N, date D);
void trier(date T[], int N);
void solde(compte T[], int N, int& soldeMin, int& soldeMax, int& Moyenne);

int main() {

  // 1
  cout << "---Question 1---" << endl;
  date dates1[] = {};
  cout << "Entrez deux dates afin de savoir si elles sont egales:" << endl;
  cout << "Premiere: " << endl;
  cin >> dates1[0].j;
  cin >> dates1[0].m;
  cin >> dates1[0].a;
  cout << "Deuxieme: " << endl;
  cin >> dates1[1].j;
  cin >> dates1[1].m;
  cin >> dates1[1].a;
  if (egale(dates1[0], dates1[1])) cout << "Egales." << endl;
  else cout << "Inegales." << endl << endl;
  
  // 2
  cout << "---Question 2---" << endl;
  date dates2[1000];
  int asked = askN(dates2, 1000);
  cout << "Le tableau contiendra " << asked << " dates." << endl;

  // 3
  cout << "\n---Question 3---" << endl;
  date dates3[5] = {
    {1, 1, 2001},
    {1, 1, 2002},
    {1, 1, 2003},
    {1, 1, 2004},
    {1, 1, 2005},
  };
  cout << "Afficher le tableau dates3:" << endl;
  afficher(dates3, 5);

  // 4
  cout << "\n---Question 4---" << endl;
  date dates4[] = {
    {1, 1, 2001},
    {1, 1, 2002},
    {1, 1, 2003},
    {1, 1, 2004},
    {1, 1, 2005},
  };
  date dates4test = {0, 0, 0};
  cout << "Entrez une date afin de verifier si elle est dans le tableau dates4:" << endl;
  cin >> dates4test.j;
  cin >> dates4test.m;
  cin >> dates4test.a;
  if (inTable(dates4, 5, dates4test)) cout << "Presente." << endl;
  else cout << "Absente." << endl;

  // 5
  cout << "\n---Question 5---" << endl;
  date dates5[] = {};
  cout << "Entrez deux dates pour savoir laquelle est anterieure:" << endl;
  cout << "Premiere: " << endl;
  cin >> dates5[0].j;
  cin >> dates5[0].m;
  cin >> dates5[0].a;
  cout << "Deuxieme: " << endl;
  cin >> dates5[1].j;
  cin >> dates5[1].m;
  cin >> dates5[1].a;
  if (anterieure(dates5[0], dates5[1])) cout << "La premiere est anterieure." << endl;
  else cout << "La seconde est anterieure." << endl;

  // 6
  cout << "\n---Question 6---" << endl;
  date dates6[11] = {  // 11 car on va ajouter une date
    {1, 1, 1995},
    {1, 1, 2002},
    {1, 1, 2003},
    {1, 1, 2004},
    {1, 1, 2005},
    {1, 1, 2006},
    {1, 1, 2007},
    {1, 1, 2008},
    {1, 1, 2009},
    {1, 1, 2010}
  };
  cout << "Tableau dates6 avant ajout:" << endl;
  afficher(dates6, 10);
  date user_date = {0, 0, 0};
  cout << "\nEntrez une date a inserer:" << endl;
  cin >> user_date.j;
  cin >> user_date.m;
  cin >> user_date.a;
  insertDate(dates6, 11, user_date);
  cout << "\nApres insertion:" << endl;
  afficher(dates6, 11);

  // 7
  cout << "\n---Question 7---" << endl;
  date dates7[11] = {  // il y a 11 dates fixes
    {1, 1, 1995},
    {1, 1, 2008},
    {1, 1, 2002},
    {1, 1, 2003},
    {1, 1, 2004},
    {1, 1, 2005},
    {2, 1, 2006},  // le 2 est au dessus du 1
    {1, 1, 2006},
    {1, 1, 2007},
    {1, 1, 2009},
    {1, 1, 2010}
  };
  cout << "Le tableau dates7 avant tri:" << endl;
  afficher(dates7, 11);
  trier(dates7, 11);
  cout << "\nApres le tri:" << endl;
  afficher(dates7, 11);

  // 9
  cout << "\n---Question 9---" << endl;
  compte bouboules[3] = {
    {"ONIC", "Victor", {4, 3, 2003}, 500},
    {"SICCHIO", "Simon", {24, 12, 2003}, 12000},
    {"PELLOUX", "Marc", {16, 1, 2003}, 9999},
  };
  int min, max, mean;
  solde(bouboules, 3, min, max, mean);
  cout << "Caracteristiques des comptes du tableau bouboules:" << endl;
  cout << "Min: " << min << endl;
  cout << "Max: " << max << endl;
  cout << "Moyenne: " << mean << endl; 
  
  return 0;
}

// Fonctions
bool egale(date& d1, date& d2) {  // 1-
  if (d1.a == d2.a && d1.m == d2.m && d1.j == d2.j) return true;
    return false;
}

int askN(date T[], int Nmax) {  // 2-
  int N = 0;
  do {
    cout << "Entrez N le nombre de dates dans le tableau: ";
    cin >> N;
  } while (N < 1 || N > Nmax);
  return N;
}

void afficher(date T[], int N) {  // 3-
  for (int i = 0; i < N; i++) {
    cout << T[i].j << "/" << T[i].m << "/" << T[i].a << endl;
  }
}

bool inTable(date T[], int N, date D) {  // 4-
  for (int i = 0; i < N; i++) if (egale(D, T[i])) return true;
  return false;
}

bool anterieure(date d1, date d2) {  // 5-
  return (d1.a < d2.a || (d1.m < d2.m && d1.a <= d2.a) ||
          (d1.j < d2.j && d1.m <= d2.m && d1.a <= d2.a));
}

void insertDate(date T[], int N, date D) {  // 6-
  T[N - 1] = D;
  for (int i = N - 2; i >= 0; i--) {
    if (anterieure(D, T[i])) {
      T[i + 1] = T[i];
      T[i] = D;
    } else {
      break;
    }
  }
}

void trier(date T[], int N) {  // 7-
  for (int i = 1; i < N; i++) {
    insertDate(T, i, T[i - 1]);
  }
}

void solde(compte T[], int N, int& soldeMin, int& soldeMax,
           int& Moyenne) {  // 9-
  int min = T[0].solde;
  int max = T[0].solde;
  int sum = 0;
  int index = 0;
  for (int i = 0; i < N; i++) {
    if (T[i].solde < min) min = T[i].solde;
    if (T[i].solde > max) max = T[i].solde;
    sum += T[i].solde;
    index++;
  }
  soldeMin = min;
  soldeMax = max;
  Moyenne = sum / index;
}