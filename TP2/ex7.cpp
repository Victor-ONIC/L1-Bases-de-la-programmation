#include <iostream>
using namespace std;

int main() {
  int size = 0;
  do {
    cout << "\nQuelle taille (>0) ? ";
    cin >> size;
    cout << endl;
  } while (size <= 0);
  for (int i = 1; i <= size; i++) {
    for (int j = 1; j <= size; j++) {
      if (j == i || j == (size - i + 1))
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}