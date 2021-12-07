#include <iostream>
#include <vector>

std::vector<int> fusion(std::vector<int> a, std::vector<int> b);
std::vector<int> tri_fusion(std::vector<int> v);

int main() {
  std::vector<int> T{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> Trie = tri_fusion(T);
  for (int i = 0; i < Trie.size(); i++) std::cout << Trie[i] << " ";

  return 0;
}

std::vector<int> fusion(std::vector<int> a, std::vector<int> b) {
  std::vector<int> K{};
  int indice_A = 0, indice_B = 0;

  while (indice_A < a.size() && indice_B < b.size()) {
    if (a[indice_A] < b[indice_B]) {
      K.push_back(a[indice_A]);
      indice_A++;
    } else {
      K.push_back(b[indice_B]);
      indice_B++;
    }
  }
  if (indice_A >= a.size())
    for (indice_B; indice_B < b.size(); indice_B++) K.push_back(b[indice_B]);
  else if (indice_B >= b.size())
    for (indice_A; indice_A < a.size(); indice_A++) K.push_back(a[indice_A]);

  return K;
}

std::vector<int> tri_fusion(std::vector<int> v) {
  if (v.size() <= 1) return v;

  std::vector<int> V1{}, V2{};
  int m = v.size() / 2;
  for (int i = 0; i < m; i++) V1.push_back(v[i]);
  for (int i = m; i < v.size(); i++) V2.push_back(v[i]);

  std::vector<int> tri_V1 = tri_fusion(V1);
  std::vector<int> tri_V2 = tri_fusion(V2);
  return fusion(tri_V1, tri_V2);
}