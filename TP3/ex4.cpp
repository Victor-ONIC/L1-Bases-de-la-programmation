#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  char password[100] = {};
  srand(time(NULL));
  // Création de la base de caractères du test de vérification:
  char sequence[63] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  char special[17] = "<>@&/!?#=+-_.,:";
  char charSpecial = special[rand() % 16];
  // Création du tableau contenant la chaîne de caractères du test de
  // vérification:
  int testLength = rand() % 6 + 5;  // 5, 6, 7, 8, 9, 10.
  const int testTableLength = testLength + 1;
  char test[testTableLength] = {};
  const int answerLength = 2 * testTableLength - 1;
  // Création du tableau contenant la chaîne de caractères de la 'réponse' au
  // test:
  char answer[answerLength] = {};
  // Création du tableau contenant la réponse donnée par l'utilisateur:
  char answerGiven[answerLength] = {};
  int attempts = 1;
  int answerIndex;

wrongPassword:
  int length = 0;
  bool hasNumber = false;
  bool hasUppercase = false;
  bool hasLowercase = false;
  bool hasSpace = false;
  bool hasGoodLength = false;
  cout << "Donnez un mot de passe: ";
  cin.getline(password, 100);
  while (password[length] != '\0')  // Calcul de la longueur du mot de passe.
    length++;
    cout << "length: " << length << endl;
  // Vérification de l'éligibilité du mot de passe:
  for (int i = 0; i < length; i++) {
    if (length >= 4 && length <= 12) hasGoodLength = true;
    if (isdigit(password[i])) hasNumber = true;
    if (islower(password[i])) hasLowercase = true;
    if (isupper(password[i])) hasUppercase = true;
    if (isspace(password[i])) hasSpace = true;
  }
  if (hasGoodLength && hasNumber && hasLowercase && hasUppercase && !hasSpace)
    cout << "\nMot de passe valide.\n" << endl;
  else {
    cout << "\n\nMot de passe invalide. Le mot de passe doit contenir entre 4 "
            "et "
            "12 caracteres inclus, des lettres minuscules, des lettres "
            "majuscules, au moins un chiffre et ne pas contenir d'espaces.\n"
         << endl;
    goto wrongPassword;
  }
  // Création de la chaîne de caractères du test:
  for (int j = 0; j < testLength; j++) {
    test[j] = sequence[rand() % 62];
    // Création de la chaîne 'réponse' en fonction du test:
    answer[2 * j] = test[j];
    answer[2 * j + 1] = charSpecial;
  }
  answer[answerLength - 2] = '\0';  // Conséquence de la boucle de création de 'answer'.
  cout << "- - - - - - Prouvez que vous n'etes pas un robot - - - - - -\n";
  cout << "\nReecrivez: " << '"' << test << '"'
       << " en separant chaque caractere par ceci: " << '"' << charSpecial
       << '"' << endl;
wrongAnswer:
  answerIndex = 0;
  cin >> answerGiven;
  attempts++;
  // Vérification de la correspondance entre la réponse attendue et la réponse
  // donnée:
  for (int k = 0; k < answerLength; k++) {
    if (answer[k] == answerGiven[k])
      answerIndex++;
    else {
      if (attempts > 10) {
        cout << "\nNombre d'essais autorises depasse. Vous avez ete rejete "
                "definitivement.\n";
        return 0;
      }
      // Dès qu'un caractère est différent de la réponse attendue, l'essai est
      // considéré comme érronné.
      cout << "\nPas de correspondance. Reessayez.\n";
      goto wrongAnswer;
    }
  }
  cout << "\n.\n.\n.\nMOT DE PASSE VALIDE DEFINITIVEMENT.\n";
  return 0;
}