#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  int attemptsTotal = 0;
beginning:
  srand(time(NULL));
  const int justePrix = rand() % 100;
  int number = 0;
  int attemptsCurrent = 0;
  do {
    cout << "\nEssayez de trouver le juste prix ! ";
    cin >> number;
    if (number > justePrix) {
      cout << "Plus petit !\n";
      attemptsCurrent++;
    } else if (number < justePrix) {
      cout << "Plus grand !\n";
      attemptsCurrent++;
    } else {
      cout << "\nBRAVO!!!!!!\n\n";
      attemptsCurrent++;
      cout << "Nombre de coups pour cette partie: " << attemptsCurrent << endl
           << endl;
      attemptsTotal += attemptsCurrent;
      cout << "Recommencer: tapez 'o'.\nQuitter: tapez n'importe quoi.\n";
      char response;
      cin >> response;
      if (response == 'o')
        goto beginning;
      else {
        cout << "\nNombre total de coups: " << attemptsTotal << endl;
        return 0;
      }
    }
  } while (number != justePrix);
  return 0;
}