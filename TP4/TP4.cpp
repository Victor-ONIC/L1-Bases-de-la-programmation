// --------------------
// VICTOR ONIC TP4 BDP
// --------------------
// main() line 151
// Partie 1: ligne 167
// Partie 2: ligne 170
// Partie 3: ligne 180
// Partie 4: ligne 203
// Partie 5: ligne 225
// Partie 6: ligne 262
// Partie 7: ligne 29
// Partie 8: ligne 290
// Partie 9: ligne 301
// Partie 10: ligne 320

#include <math.h>

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;

struct date {
  char jour[10];
  int j, m, a;
};

// Partie 7 ----------
struct personne {
  char nom[15];
  char prenom[15];
  date dateNaissance;
};

void coutDate(date d) {
  cout << d.jour << " " << d.j << " " << d.m << " " << d.a << endl;
}

void coutPersonne(personne p, bool v = false) {
  cout << p.prenom << " " << p.nom << " ";
  if (v) coutDate(p.dateNaissance);
  if (!v) cout << endl;
}

int whichWeekDay(int d, int m, int y) {  // 0: Dimanche, 1: Lundi, ...
  int fDay, fMonth, fYear, fCentury, W;  // 'f' pour 'formula'

  fDay = d;  // fDay
  if (m == 1)  // fMonth
    fMonth = 11;
  else if (m == 2)
    fMonth = 12;
  else
    fMonth = m - 2;
  if (y > 1999) {  // fYear & fCentury
    fYear = (fMonth == 11 || fMonth == 12) ? y - 2001 : y - 2000;
    fCentury = 20;
  } else {
    fYear = (fMonth == 11 || fMonth == 12) ? y - 1901 : y - 1900;
    fCentury = 19;
  }
  W = (fDay + (int)floor((2.6 * fMonth) - 0.2) - (2 * fCentury) + fYear +
       (int)floor(fYear / 4) + (int)floor(fCentury / 4)) % 7;
  W = W < 0 ? W + 7 : W;  // si W<0, alors W=W+7, ça arrive et c'est normal
  return W;
}

date createNewDate(int a, int b) {  // créer une date entre les années a et b
  int year, month, day, weekDay;
  bool isLeap;
  char daysList[10][10] = {
    {"Dimanche"}, {"Lundi"}, {"Mardi"}, {"Mercredi"}, {"Jeudi"}, {"Vendredi"}, {"Samedi"}
  };
  date returnDate;

  if (a > b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  year = rand() % (b - a) + a + 1;  // a
  isLeap = year % 4 == 0 xor (year % 100 == 0 xor year % 400 == 0);
  month = rand() % 12 + 1;  // m
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
      month == 10 || month == 12)  // j
    day = rand() % 31 + 1;
  else if (month == 2)
    day = rand() % 28 + isLeap + 1;
  else
    day = rand() % 30 + 1;

  strcpy(returnDate.jour, daysList[whichWeekDay(day, month, year)]);
  returnDate.j = day;
  returnDate.m = month;
  returnDate.a = year;
  return returnDate;
}

date createDateFromArray(char* T) {  // crée une date à partir d'un tableau de
                                     // caractères T de la forme "jj/mm/aaaa"
  char daysList[10][10] = {{"Dimanche"}, {"Lundi"},    {"Mardi"}, {"Mercredi"},
                           {"Jeudi"},    {"Vendredi"}, {"Samedi"}};
  date d = {
    "",  
    10 * (T[0] - '0') + (T[1] - '0'),
    10 * (T[3] - '0') + (T[4] - '0'),
    1000 * (T[6] - '0') + 100 * (T[7] - '0') + 10 * (T[8] - '0') + (T[9] - '0')
  };
  strcpy(d.jour, daysList[whichWeekDay(d.j, d.m, d.a)]);
  return d;
}

// Les fonctions isPrior et isEqual sont utilisées seulement pour faciliter la
// lecture du code.

bool isPrior(date d1, date d2) { // si d1 < d2, return 1
  return (d1.a < d2.a || (d1.m < d2.m && d1.a <= d2.a) || 
          (d1.j < d2.j && d1.m <= d2.m && d1.a <= d2.a));
}

bool isEqual(date d1, date d2) {  // si d1 = d2, return 1
  if (d1.a == d2.a) {
    if (d1.m == d2.m) {
      if (d1.j == d2.j) {
        return true;
      }
    }
  }
  return false;
}

personne createNewPersonne() {  // créer une personne
  char PRENOMS[30][30] = {
    {"Ayzrael"}, {"Brivael"},   {"Ciel"},    {"Doriel"},   {"Ezekiel"},
    {"Frigiel"}, {"Galaadiel"}, {"Haykiel"}, {"Iziel"},    {"Judikael"},
    {"Kenael"},  {"Lydiel"},    {"Mel"},     {"Natanael"}, {"Oriel"},
    {"Primael"}, {"Quiriel"},   {"Rigel"},   {"Samael"},   {"Tael"},
    {"Umbriel"}, {"Viel"},      {"Wadjiel"}, {"Xarael"},   {"Yaretziel"},
    {"Zaphkiel"}
  };
  char NOMS[30][30] = {
    {"Bouboule"},      {"Bonk"},    {"Lonk"},
    {"Biboule"},       {"Shaygai"}, {"Statu"},
    {"Essceypet"},     {"Chien"},   {"Qelplesyr"},
    {"Owi"},           {"Uwu"},     {"Owo"},
    {"Star"},          {"Moon"},    {"Comet"},
    {"Meteora"},       {"Eclipsa"}, {"Solaris"},
    {"Byttes"},        {"Help"},    {"Leutelefaunpleurs"},
    {"Michel"},        {"Ouahw"},   {"Aime"},
    {"Haais"},         {"Pedet"},   {"Ayamget"},
    {"Enndailaikitt"}, {"Biz"},     {"Feuques"}
  };

  personne returnPersonne;
  strcpy(returnPersonne.nom, NOMS[rand() % 30]);
  strcpy(returnPersonne.prenom, PRENOMS[rand() % 26]);
  returnPersonne.dateNaissance = createNewDate(1000, 1500);

  return returnPersonne;
}


int main() {
  srand(time(NULL));

  // Partie 1 ----------
  date T[1000];

  // Partie 2 ----------
  int N;
  do {
    cout << "Veuillez entrer un nombre N compris entre 0 et 999 exclus, "
            "correspondant au nombre de dates dans le tableau: ";
    cin >> N;
  } while (N < 1 || N > 998);

  for (int i = 0; i < N; i++) T[i] = createNewDate(1950, 2021);

  // Partie 3 ----------
  char askDateChar[15] = {};
  bool presente = false;
  do {
    cout << "\nVeuillez entrer une date, afin de verifier si ladite date est "
            "presente dans le tableau: ";
    cout << "\nAttention de bien respecter la syntaxe: 'jj/mm/aaaa' !\n";
    cin >> askDateChar;
  } while (askDateChar[2] != '/' && askDateChar[5] != '/');  // pas optimal, mais pas important

  date asked = createDateFromArray(askDateChar);

  for (int k = 0; k < N; k++) {
    if (isEqual(T[k], asked)) {
      presente = true;
      break;
    }
  }
  if (presente)
    cout << "Presente!" << endl;
  else
    cout << "Absente." << endl;

  // Partie 4 ----------
  char date1Char[15] = {};
  char date2Char[15] = {};
  do {
    cout << "\nVeuillez entrer deux dates, en respectant toujours la syntaxe, "
            "afin de savoir laquelle des deux est anterieure a l'autre: "
         << endl;
    cout << "Premiere date d1: ";
    cin >> date1Char;
    cout << "Seconde date d2: ";
    cin >> date2Char;
  } while ((date1Char[2] != '/' && date1Char[5] != '/') && 
           (date2Char[2] != '/' && date2Char[5] != '/'));

  date d1 = createDateFromArray(date1Char);
  date d2 = createDateFromArray(date2Char);

  if (isPrior(d1,d2))
    cout << "d1 est anterieure a d2 !" << endl;
  else
    cout << "d2 est anterieure a d1 !" << endl;

  // Partie 5 ----------
  // TODO Si la date ajoutée est déjà dans le tableau ?
  int indexMin;
  date tmp[2];
  char insertDateChar[15] = {};
  int spot = 0;

  for (int n = 0; n < N; n++) {  // tri
    indexMin = n;
    for (int m = n + 1; m < N; m++) {
      if (isPrior(T[m],T[indexMin])) {
        indexMin = m;
      }
    }
    if (indexMin != n) {
      tmp[0] = T[n];
      T[n] = T[indexMin];
      T[indexMin] = tmp[0];
    }
  }

  do {
    cout << "\nVeuillez entrer une date qui sera ajoutee au tableau: ";
    cin >> insertDateChar;
  } while (insertDateChar[2] != '/' && insertDateChar[5] != '/');

  date addDate = createDateFromArray(insertDateChar);

  while (!isPrior(addDate, T[spot])) spot++;
  tmp[0] = addDate;

  for (spot; spot < N + 1; spot++) {  // ajout et décalage des autres dates
    tmp[1] = T[spot];
    T[spot] = tmp[0];
    tmp[0] = tmp[1];
  }

  // Partie 6 ----------
  char betweenDate1Char[15] = {};
  char betweenDate2Char[15] = {};
  int spotStart = 1, spotEnd = 1;
  bool has = false;
  do {
    cout << "\nVeuillez entrer deux dates afin d'afficher toutes les dates "
            "comprises entre les deux: "
         << endl;
    cout << "Premiere date, Date 1: ";
    cin >> betweenDate1Char;
    cout << "Seconde date, Date 2: ";
    cin >> betweenDate2Char;
  } while ((betweenDate1Char[2] != '/' && betweenDate1Char[5] != '/') &&
           (betweenDate2Char[2] != '/' && betweenDate2Char[5] != '/'));

  date bDate1 = createDateFromArray(betweenDate1Char);
  date bDate2 = createDateFromArray(betweenDate2Char);

  cout << "\nVoici les dates comprises entre les dates 1 et 2: \n" << endl;
  for (int p = 0; p < N + 1; p++) {
    if (isPrior(bDate1, T[p]) && isPrior(T[p], bDate2)) {
      coutDate(T[p]);
      has = true;
    }
  }
  if (!has) cout << "Aucune.";

  // Partie 8 ----------
  personne P[1000];
  int M;
  do {
    cout << "\nVeuillez entrer un nombre M compris entre 0 et 1000 exclus, "
            "correspondant au nombre de personnes dans le tableau: ";
    cin >> M;
  } while (M < 1 || M > 999);

  for (int q = 0; q < M; q++) P[q] = createNewPersonne();

  // Partie 9 ----------
   char personnesDateChar[15] = {};
   bool has2 = false;
  do {
    cout << "\nVeuillez entrer une date afin d'afficher les personnes nees a "
            "cette date: ";
    cin >> personnesDateChar;
  } while (personnesDateChar[2] != '/' && personnesDateChar[5] != '/');

  date askedPersonDate = createDateFromArray(personnesDateChar);

  for (int r = 0; r < M; r++) {
    if (isEqual(askedPersonDate, P[r].dateNaissance)) {
      coutPersonne(P[r]);
      has2 = true;
    }
  }
  if (!has2) cout << "Aucune.";

  // Partie 10 ----------
  char personneDate1Char[15] = {};
  char personneDate2Char[15] = {};
  bool has3 = false;
  do {
    cout << "\nVeuillez entrer deux dates, afin d'afficher les personnes nees "
            "entre ces deux dates: "
         << endl;
    cout << "Premiere date d1: ";
    cin >> personneDate1Char;
    cout << "Seconde date d2: ";
    cin >> personneDate2Char;
  } while ((personneDate1Char[2] != '/' && personneDate1Char[5] != '/') &&
           (personneDate2Char[2] != '/' && personneDate2Char[5] != '/'));

  date personD1 = createDateFromArray(personneDate1Char);
  date personD2 = createDateFromArray(personneDate2Char);

  cout << "Voici les personnes nees entre les dates d1 et d2: \n";
  for (int t = 0; t < N + 1; t++) {
    if (isPrior(personD1, P[t].dateNaissance) &&
        isPrior(P[t].dateNaissance, personD2)) {
      coutPersonne(P[t]);
      has3 = true;
    }
  }
  if (!has3) cout << "Aucune.";

  return 0;
}