#include <iostream>
#include <cstdlib>

template<class ElemType>
struct ForwardListNode {
  ElemType                   data;      // ���� 
  ForwardListNode<ElemType> *link;      // �U�@�Ӹ`�I������ 
};

template<class ElemType>
class ForwardList {
  typedef ForwardListNode<ElemType> Node;

 public:
  ForwardList() {
    size_ = 0; 
    head_ = NULL;
  }
  explicit ForwardList(int n);
  ~ForwardList();

  int Size() const { return size_; }

 private:
  int size_;
  Node *head_;  // ���V�Ĥ@�Ӹ`�I 
};

template<class ElemType>
ForwardList<ElemType>::ForwardList(int n) {
  size_ = n;
  head_ = n == 0 ? NULL : new Node();
  Node *cur = head_;
  for (int i = 1; i < n; ++i) {
    cur->link = new Node();
    cur = cur->link;
  }
  cur->link = NULL;
}

template<class ElemType>
ForwardList<ElemType>::~ForwardList() {
  Node *cur = head_;
  while (cur != NULL) {
    Node *del = cur;
    cur = cur->link;
    delete del;
  }
}

int main() {
  using std::cout;
  using std::endl;
 
  ForwardList<int> list(5);
  cout << "list.Size(): " << list.Size() << endl;
  system("pause");
  return 0;
}
