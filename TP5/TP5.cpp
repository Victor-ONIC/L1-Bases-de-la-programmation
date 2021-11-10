#include <iostream>
using namespace std;

struct date {
  int j, m, a;
};

struct compte {
  char nom[20], prenom[20];
  date naissance;
  int solde;
};

void saisir_une_date(date &d);
bool egales(date &d1, date &d2);
void saisir_tab_dates(date T[], int Nmax, int &N);
void afficher_une_date(date &d);
void afficher_tab_dates(date T[], int N);
bool apprtient(date T[], int N, date &D);
bool ant(date &d1, date &d2);
void inserer(date T[], int N, date &D);
void solde_min_max_moy(compte T[], int N, int &min, int &max, double &moyenne);

int main() {

  date d1, d2;

  cout << "------ Fonction 'egales' ------\n";
  cout << "Rentrez deux dates:\n\n";
  cout << "Premiere date:\n";
  saisir_une_date(d1);
  cout << "\nSeconde date:\n";
  saisir_une_date(d2);
  if (egales(d1, d2)) cout << "\nEgales.\n";
  else cout << "\nInegales.\n";
  cout << "------ Fin ------\n\n\n";

  cout << "------ Fonction 'saisir_tab_dates' ------\n";
  date Table_Dates[100];
  int n;
  saisir_tab_dates(Table_Dates, 100, n);
  cout << "------ Fin ------\n\n\n";

  cout << "------ Fonction 'afficher_une_date' ------\n";
  cout << "Affichons la premiere date du tableau:\n";
  afficher_une_date(Table_Dates[0]);
  cout << "------ Fin ------\n\n\n";

  cout << "------ Fonction 'afficher_tab_dates' ------\n";
  cout << "Affichons tout le tableau:\n";
  afficher_tab_dates(Table_Dates, n);
  cout << "------ Fin ------\n\n\n";

  cout << "------ Fonction 'appartient' ------\n";
  cout << "Rentrez une date afin de voir si elle est presente dans le tableau:\n";
  saisir_une_date(d1);
  if (apprtient(Table_Dates, n, d1)) cout << "\nPresente dans le tableau.\n";
  else cout << "\nAbsente du tableau.\n";
  cout << "------ Fin ------\n\n\n";

  cout << "------ Fonction 'ant' ------\n";
  cout << "Entrez deux dates, afin de voir laquelle est anterieure:\n\n";
  cout << "Premiere date:\n";
  saisir_une_date(d1);
  cout << "Seconde date:\n";
  saisir_une_date(d2);
  if (ant(d1, d2)) cout << "\nLa premiere date est anterieure.\n";
  else cout << "\nLa seconde date est anterieure.\n";
  cout << "------ Fin ------\n\n\n";

  cout << "------ Fonction 'inserer' ------\n";
  date dates[11] = {  // 11 car on va ajouter une date
    {1, 1, 2000},
    {1, 1, 2001},
    {1, 1, 2002},
    {1, 1, 2003},
    {1, 1, 2004},
    {1, 1, 2005},
    {1, 1, 2006},
    {1, 1, 2007},
    {1, 1, 2008},
    {1, 1, 2009}
  };
  cout << "Entrez une date a inserer dans le nouveau tableau trie 'dates':\n";
  saisir_une_date(d1);
  inserer(dates, 10, d1);
  afficher_tab_dates(dates, 11);
  cout << "------ Fin ------\n\n\n";

  cout << "------ Fonction 'solde_min_max_moy' ------\n";
  compte V = {"ONIC", "Victor", {4, 3, 2003}, 10000};
  compte M = {"PELLOUX", "Marc", {16, 1, 2003}, 12000};
  compte S = {"SICCHIO", "Simon", {24, 12, 2003}, 16000};
  compte Comptes[] = {V, M, S};
  int minimum, maximum;
  double moyenne;
  cout << "Affichons les details des comptes du tableau Comptes:\n";
  solde_min_max_moy(Comptes, 3, minimum, maximum, moyenne);
  cout << "Solde minimal: " << minimum << endl;
  cout << "Solde maximal: " << maximum << endl;
  cout << "Moyenne des soldes: " << moyenne/3 << endl;
  cout << "------ Fin ------\n";

  return 0;
}


void saisir_une_date(date &d) {
  cout << "\nEntrez le jour: ";
  cin >> d.j;
  cout << "Entrez le mois: ";
  cin >> d.m;
  cout << "Entrez l'annee: ";
  cin >> d.a;
}

bool egales(date &d1, date &d2) {
  if (d1.j == d2.j and d1.m == d2.m and d1.a == d2.a)
    return true;
  else
    return false;
}

void saisir_tab_dates(date T[], int Nmax, int &N) {
  cout << "Entrez N le nombre de dates: ";
  cin >> N;
  while (N > Nmax or N <= 0) {
    cout << "Entrez N le nombre de dates: ";
    cin >> N;
  }
  for (int i = 0; i < N; i++) saisir_une_date(T[i]);
}

void afficher_une_date(date &d) {
  cout << d.j << "/" << d.m << "/" << d.a << endl;
}

void afficher_tab_dates(date T[], int N) {
  for (int i = 0; i < N; i++) afficher_une_date(T[i]);
}

bool apprtient(date T[], int N, date &D) {
  for (int i = 0; i < N; i++)
    if (egales(D, T[i])) return true;
  return false;
}

bool ant(date &d1, date &d2) {
  if (d1.a == d2.a) {
    if (d1.m == d2.m) {
      if (d1.j <= d2.j)
        return true;
      else
        return false;
    } else {
      if (d1.m < d2.m)
        return true;
      else
        return false;
    }
  } else {
    if (d1.a < d2.a)
      return true;
    else
      return false;
  }
}

void inserer(date T[], int N, date &D) {  // N étant le nombre de dates dans T
  T[N] = D;
  int j = N;
  while (j >= 1 and ant(T[j], T[j - 1])) {
    // échanger T[j] et T[j-1]
    date tmp = T[j];
    T[j] = T[j - 1];
    T[j - 1] = tmp;
    j = j - 1;
  }
}

void solde_min_max_moy(compte T[], int N, int &min, int &max, double &moyenne) {
  min = max = T[0].solde;
  moyenne = 0.0;
  for (int i = 0; i < N; i++) {
    if (T[i].solde > max)
      max = T[i].solde;
    else if (T[i].solde < min)
      min = T[i].solde;
    moyenne += T[i].solde;
  }
}