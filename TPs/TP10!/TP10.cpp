#include <iostream>

struct matrice {
  // ligne i colonne j : T[i*nbc+j].
  int nbl;
  int nbc;
  double *T;
};

matrice *construit_matrice(int ligne, int colonne) {  // on pourrait prendre des unsigned int (plus propre)
  matrice *m = new matrice;
  m->nbc = colonne;
  m->nbl = ligne;
  m->T = new double[ligne * colonne];
  return m;
}

void construit_matrice(matrice &A, int ligne, int colonne) {
  A.nbc = colonne;
  A.nbl = ligne;
  A.T = new double[ligne * colonne];
}

void transpose(matrice &M) {  // ne marche que pour les matrices carrées ???
  double transpose[M.nbl * M.nbc] = {};
  for (int i = 0; i < M.nbl; i++) {
    for (int j = 0; j < M.nbc; j++) {
      transpose[j * M.nbl + i] = M.T[i * M.nbc + j];
    }
  }
  for (int i = 0; i < M.nbl * M.nbc; i++) {
    M.T[i] = transpose[i];
  } 
}

matrice *add(matrice &A, matrice &B) {  // que pour les matrices carrées ?!
  if (A.nbc != B.nbc || A.nbl != B.nbl) {
    std::cout << "Erreur: fonction add ne peut pas faire la somme.";
    return nullptr;
  }
  matrice *sum = construit_matrice(A.nbl, A.nbc);
  for (int i = 0; i < sum->nbl; i++) {
    for (int j = 0; j < sum->nbc; j++) {
      sum->T[i * sum->nbc + j] = A.T[i * A.nbc + j] + B.T[i * B.nbc + j];
    }
  }
  return sum;
}

matrice *add_pointeur(matrice *A, matrice *B) {
  if (A->nbc != B->nbc || A->nbl != B->nbl) {
    std::cout << "Erreur: fonction add_pointeur ne peut pas faire la somme.";
    return nullptr;
  }
  matrice *sum = construit_matrice(A->nbl, A->nbc);
  for (int i = 0; i < A->nbc * A->nbl; i++) {
    sum->T[i] = A->T[i] + B->T[i];
  }
  return sum;
}

matrice *mult(matrice &A, matrice &B) {
  if (!(A.nbc == B.nbl)) {
    std::cout << "Erreur: fonction mult ne peut pas faire le produit.";
    return nullptr;
  }
  matrice *X = construit_matrice(A.nbl, B.nbc);
  for (int i = 0; i < X->nbc * X->nbl; i++) {
    std::cout << X->T[i] << std::endl;
  }

  /* for (int i = 0; i < A.nbl; i++) {
    for (int j = 0; j < B.nbc; j++) {
      for (int k = 0; k < A.nbc; k++) {
        X->T[i * X->nbc + j] += A.T[i * A.nbc + k] * B.T[k * B.nbc + j];
      }
    }
  } */
  return X;
}



int main() {
  // toutes les fonctions doivent être testées.
  
  // fonction 'matrice *construit_matrice(int ligne, int colonne)' DELETE !!!

  // fonction 'void construit_matrice(matrice &A, int ligne, int colonne)'

  // fonction 'void transpose(matrice &M)'
  double T[] = {1,2,3,4,5,6,7,8,9,10,11,12};
  matrice M = {4, 3, T};
  transpose(M);
  for (int i = 0; i < M.nbl; i++) {
    for (int j = 0; j < M.nbc; j++) {
      std::cout << M.T[i * M.nbc + j] << " ";
    }
  }
  std::cout << std::endl;
  std::cout << std::endl;

  // fonction 'matrice *add(matrice &A, matrice &B)' DELETE !!!

  // fonction 'matrice *add_pointeur(matrice *A, matrice *B)' DELETE !!!//

  // fonction 'matrice *mult(matrice &A, matrice &B)' DELETE !!!
  double tableau_matrice_1[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
  double tableau_matrice_2[6] = {1,2,3,4,5,6};
  matrice matrice_1 = {4, 3, tableau_matrice_1};
  matrice matrice_2 = {3, 2, tableau_matrice_2};
  matrice *produit = mult(matrice_1, matrice_2);
  delete produit->T;
  delete produit;
  // for (int i = 0; i < produit->nbl; i++) {
  //   for (int j = 0; j < produit->nbc; j++) {
  //     std::cout << produit->T[i * produit->nbc + j] << " ";
  //     std::cout << std::endl;
  //   }
  // }
  return 0;
}
