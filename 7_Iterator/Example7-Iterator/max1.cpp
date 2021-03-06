#include <iostream>
#include <cstdlib>
#include "flist.h"
#include "array.h"

template<class ElemType, class ContainerType>
const ElemType Max(const ContainerType &c) {
  ElemType max = c[0];
  for (int i = 0; i < c.Size(); ++i) {
    const ElemType &e = c[i];
    if (e > max) {
      max = e;
    }
  }
  return max;
}

template<class ElemType>
std::ostream &operator<<(std::ostream &lhs, const ForwardList<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}


template<class ElemType, int kNumberOfElems>
std::ostream &operator<<(std::ostream &lhs, const Array<ElemType, kNumberOfElems> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using std::cout;
  using std::endl;

  Array<int, 10> a;
  ForwardList<int> b(10);

  for (int i = 0; i < 10; ++i) {
    const int r = rand();
    a[i] = b[i] = r;
  }

  cout << "a: " << a << endl
       << "b: " << b << endl;

  cout << "Max<int, Array<int, 10> >(a):   " << Max<int, Array<int, 10> >(a) << endl;
  cout << "Max<int, ForwardList<int> >(b): " << Max<int, ForwardList<int> >(b) << endl;

  cout << "Max<int>(a): " << Max<int>(a) << endl;
  cout << "Max<int>(b): " << Max<int>(b) << endl;


  //cout << "Max(a): " << Max(a) << endl;   // [編譯錯誤] 請移除此行
  //cout << "Max(b): " << Max(b) << endl;   // [編譯錯誤] 請移除此行

  return 0;
}
