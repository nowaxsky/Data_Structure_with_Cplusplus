#include <iostream>
#include <cstdlib>
#include "flist.h"

int main() {
  using std::cout;
  using std::endl;

  ForwardList<int> b(10);
  for (int i = 0; i < 10; ++i) {
    b[i] = i;
  }

  ForwardListNode<int> * const begin = b.head_;  // [½sÄ¶¿ù»~] «ç»ò¿ì? 
  ForwardListNode<int> * const end   = NULL; 
  for (ForwardListNode<int> *p = begin; p != end; p = p->link) {
    cout << p->data << endl;
  } 
  system("pause");
  return 0;
}
