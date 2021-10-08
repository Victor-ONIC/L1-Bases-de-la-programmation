// TOUT REECRIRE AVEC DES FONCTIONS AAAAAAAAAAAAAAAAAA

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
beginning:
  int ex;
  char exChoice;
  int numberEx1;
  int numberEx2;
  int numberEx3, indexEx3 = -1;
  float sumEx3 = 0;
  int numberEx3b = 1, indexEx3b = -1, minEx3b, maxEx3b;
  float sumEx3b = 0;
  int numberEx4;
  float sumOddEx4 = 0, sumEvenEx4 = 0;
  int indexOddEx4 = 0, indexEvenEx4 = -1;
  const int justePrixEx5 = 42;
  int numberEx5 = 0;
  int attemptsTotalEx5b = 0;
  srand(time(NULL));
  int justePrixEx5b = rand() % 100;
  int numberEx5b = 0;
  int attemptsCurrentEx5b = 0;
  int LEx6 = 0, lEx6 = 0;
  int sizeEx7 = 0;
  long long int factorialEx8 = 1;
  int numberEx8 = 0;
  int numberEx9 = 0, divisorsEx9 = 0;
  int number1Ex9_2, number2Ex9_2, divisorsEx9_2 = 0;

  cout << "Veuillez choisir quel exercice lancer. ";
  cout << "";  // TODO description des exos
  cin >> ex;
  switch (ex) {
    default:
      goto error;
    case 1:
      goto ex1;
    case 2:
      goto ex2;
    case 3:
      cout << "Pour l'exercice 3a, tapez A.\nPour le 3b, tapez B.\n";
      cin >> exChoice;
      if (exChoice == 'A' || exChoice == 'a')
        goto ex3a;
      else if (exChoice == 'B' || exChoice == 'b')
        goto ex3b;
      else
        goto beginning;
    case 4:
      goto ex4;
    case 5:
      cout << "Pour l'exercice 5a, tapez A.\nPour le 5b, tapez B.\n";
      cin >> exChoice;
      if (exChoice == 'A' || exChoice == 'a')
        goto ex5a;
      else if (exChoice == 'B' || exChoice == 'b')
        goto ex5b;
      else
        goto beginning;
    case 6:
      goto ex6;
    case 7:
      goto ex7;
    case 8:
      goto ex8;
    case 9:
      cout << "Pour l'exercice 9-1, tapez 1.\nPour le 9-2, tapez 2.\n";
      cin >> exChoice;
      if (exChoice == '1')
        goto ex9_1;
      else if (exChoice == '2')
        goto ex9_2;
      else
        goto beginning;
  }
error:
  cout << "Veuillez taper un chiffre valide.";
  goto beginning;

ex1:;
  while (numberEx1 >= 100 || numberEx1 < 1) {
    cout << "\nDonnez un entier positif strictement inférieur à 100: ";
    cin >> numberEx1;
  }
  cout << "Merci pour le nombre " << numberEx1;
  return 0;

ex2:;
  while (numberEx2 < 2 || numberEx2 > 9) {
    cout << "\nDonnez un nombre entre 2 et 9 inclus: ";
    cin >> numberEx2;
  }
  for (int i = 1; i <= 10; i++) {
    cout << i << "x" << numberEx2 << "=" << i * numberEx2 << endl;
  }
  return 0;

ex3a:;
  do {
    cout << "\nEntrez un nombre non nul.\n"
         << "Pour arrêter la saisie, entrez 0. ";
    cin >> numberEx3;
    sumEx3 += numberEx3;
    indexEx3 += 1;
  } while (numberEx3 != 0);
  cout << "\nMoyenne: " << sumEx3 / indexEx3;
  return 0;

ex3b:;
  do {
    cout << "\nEntrez un nombre non nul.\n"
         << "Pour arrêter la saisie, entrez 0. ";
    cin >> numberEx3b;
    if (indexEx3b == -1) minEx3b = numberEx3b, maxEx3b = numberEx3b;
    sumEx3b += numberEx3b;
    indexEx3b++;
    if (numberEx3b > maxEx3b) maxEx3b = numberEx3b;
    if (numberEx3b < minEx3b && numberEx3b != 0) minEx3b = numberEx3b;
  } while (numberEx3b != 0);
  cout << "\nMoyenne: " << sumEx3b / indexEx3b << endl;
  cout << "Maximum: " << maxEx3b << endl;
  cout << "Minimum: " << minEx3b;
  return 0;

ex4:;
  do {
    cout << "\nEntrez un nombre non nul.\n"
         << "Pour arrêter la saisie, entrez 0. ";
    cin >> numberEx4;
    if (numberEx4 % 2 == 0) {
      sumEvenEx4 += numberEx4;
      indexEvenEx4++;
    } else {
      sumOddEx4 += numberEx4;
      indexOddEx4++;
    }
  } while (numberEx4 != 0);
  cout << "\nMoyenne des pairs: " << sumEvenEx4 / indexEvenEx4 << endl;
  cout << "Moyenne des impairs: " << sumOddEx4 / indexOddEx4;
  return 0;

ex5a:;
  do {
    cout << "\nEssayez de trouver le juste prix ! ";
    cin >> numberEx5;
    if (numberEx5 > justePrixEx5)
      cout << "Plus petit !\n";
    else if (numberEx5 < justePrixEx5)
      cout << "Plus grand !\n";
    else {
      cout << "\nBRAVO!!!!!!\n";
      return 0;
    }
  } while (numberEx5 != justePrixEx5);
  return 0;

ex5b:;
beginningEx5b:
  justePrixEx5b = rand() % 100;
  numberEx5b = 0;
  attemptsCurrentEx5b = 0;
  do {
    cout << "\nEssayez de trouver le juste prix ! ";
    cin >> numberEx5b;
    if (numberEx5b > justePrixEx5b) {
      cout << "Plus petit !\n";
      attemptsCurrentEx5b++;
    } else if (numberEx5b < justePrixEx5b) {
      cout << "Plus grand !\n";
      attemptsCurrentEx5b++;
    } else {
      cout << "\nBRAVO!!!!!!\n\n";
      attemptsCurrentEx5b++;
      cout << "Nombre de coups pour cette partie: " << attemptsCurrentEx5b << endl
           << endl;
      attemptsTotalEx5b += attemptsCurrentEx5b;
      cout << "Recommencer: tapez 'o'.\nQuitter: tapez n'importe quoi.\n";
      char response;
      cin >> response;
      if (response == 'o')
        goto beginningEx5b;
      else {
        cout << "\nNombre total de coups: " << attemptsTotalEx5b << endl;
        return 0;
      }
    }
  } while (numberEx5b != justePrixEx5b);
  return 0;

ex6:;
  do {
    cout << "Donnez une longueur et une largeur: \n\n";
    cout << "La longueur et la largeur doivent être deux nombres entiers "
            "positifs.\n\n";
    cout << "Longueur: ";
    cin >> LEx6;
    cout << "Largeur ";
    cin >> lEx6;
    cout << endl;
  } while (LEx6 <= 0 || lEx6 <= 0);
  for (int i = lEx6; i > 0; i--) {
    for (int j = LEx6; j > 0; j--) cout << '*';
    cout << endl;
  }
  return 0;

ex7:;
  do {
    cout << "\nQuelle taille (>0) ? ";
    cin >> sizeEx7;
    cout << endl;
  } while (sizeEx7 <= 0);
  for (int i = 1; i <= sizeEx7; i++) {
    for (int j = 1; j <= sizeEx7; j++) {
      if (j == i || j == (sizeEx7 - i + 1))
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;

ex8:;
  do {
    cout << "\nNombre (>0) : ";
    cin >> numberEx8;
  } while (numberEx8 <= 0);
  for (int i = 1; i <= numberEx8; i++) factorialEx8 *= i;
  cout << numberEx8 << "! = " << factorialEx8 << endl;
  return 0;

ex9_1:;
  do {
    cout << "Entrez un entier strictement positif: ";
    cin >> numberEx9;
  } while (numberEx9 <= 0);
  for (int i = 1; i <= numberEx9; i++) {
    if (numberEx9 % i == 0) {
      divisorsEx9++;
    }
  }
  if (divisorsEx9 == 2)
    cout << "PREMIER";
  else
    cout << "PAS PREMIER";
  return 0;

ex9_2:;
  do {
    cout << "\nEntrez deux entiers strictement positifs, tel que le premier "
            "soit inférieur au second: ";
    cout << "\nPremier entier: ";
    cin >> number1Ex9_2;
    cout << "Second entier: ";
    cin >> number2Ex9_2;
  } while (number2Ex9_2 < number1Ex9_2 || number1Ex9_2 <= 0 || number2Ex9_2 <= 0);
  cout << "Liste des entiers premiers entre " << number1Ex9_2 << " et " << number2Ex9_2
       << " inclus:" << endl;
  for (int i = number1Ex9_2; i <= number2Ex9_2; i++) {
    for (int j = 1; j <= i; j++)
      if (i % j == 0) divisorsEx9_2++;
    if (divisorsEx9_2 == 2) cout << i << " ";
    divisorsEx9_2 = 0;
  }
  return 0;
}