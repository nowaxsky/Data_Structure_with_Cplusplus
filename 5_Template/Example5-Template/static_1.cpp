#include <iostream>
#include <cstdlib>

using namespace std;

int &static_var() {
  static int a = 3;
  return ++a;
}

int nonstatic_var() {
  int a = 3;
  return ++a;
}

int main() {
  cout << "跋办跑计: ";
  for (int i = 0; i < 5; ++i) cout << nonstatic_var() << " ";
  cout << endl;

  cout << "static 跋办跑计: ";
  for (int i = 0; i < 5; ++i) cout << static_var() << " ";
  cout << endl;

  system("pause");
  return 0;
}
