#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

template <class Iterator, class Type>
Iterator find(Iterator first, Iterator last, const Type &val) {
  for (Iterator p = first; p != last; ++p) {
    if (*p == val) return p;
  }
  return last;
}

ostream &operator<<(ostream &lhs, const list<int> &rhs) {
  for (list<int>::const_iterator i = rhs.begin(); i != rhs.end(); ++i) {
    if (i != rhs.begin()) lhs << " ";
    lhs << *i;
  }
  return lhs;
}

ostream &operator<<(ostream &lhs, const vector<int> &rhs) {
  for (vector<int>::const_iterator i = rhs.begin(); i != rhs.end(); ++i) {
    if (i != rhs.begin()) lhs << " ";
    lhs << *i;
  }
  return lhs;
}

int main() {
  vector<int> a;
  for (int i = 1; i <= 10; ++i) {
    a.push_back(i);
  }
  cout << "a: " << a << endl;
  // ��� 4 ������N�� 11
  *find(a.begin(), a.end(), 4) = 11;
  cout << "a: " << a << endl;

  // ���O�S���@�w��o��?
  vector<int>::iterator p = find(a.begin(), a.end(), 0);
  if (p == a.end()) {
    cout << "�b a ���䤣�� 0" << endl;
  } else {
    // �p�G��쪺�ܱN�L�]�� 12
    *p = 12;
  }
  cout << "a: " << a << endl;

  list<int> b(a.begin(), a.end());
  cout << "b: " << b << endl;
  list<int>::iterator q = find(b.begin(), b.end(), 11);
  if (q == b.end()) {
    cout << "�b b ���䤣�� 11" << endl;
  } else {
    // �p�G��쪺�ܱN�L�]�� 4
    *q = 4;
  }
  cout << "b: " << b << endl;


  system("pause");
  return 0;
}


