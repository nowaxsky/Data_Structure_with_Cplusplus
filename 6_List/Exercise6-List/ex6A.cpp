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
    head_ = NULL;
  }
  explicit ForwardList(int n);
  ~ForwardList();

  int Size() const;
  bool Empty() const;

 private:
  Node *head_;  // ���V�Ĥ@�Ӹ`�I
};

template<class ElemType>
ForwardList<ElemType>::ForwardList(int n) {
  head_ = n == 0 ? NULL : new Node();
  Node *cur = head_;
  for (int i = 1; i < n; ++i) {
    cur->link = new Node();
    cur = cur->link;
  }
  cur->link = 0;
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

template<class ElemType>
int ForwardList<ElemType>::Size() const {
    int num = 0;
    Node *cur = head_;
    while(cur!=NULL){
        cur = cur->link;
        num++;
    }
    return num;
}

template<class ElemType>
bool ForwardList<ElemType>::Empty() const {
    return head_ == NULL;
}

int main() {
  using std::cout;
  using std::endl;

  ForwardList<int> a(5);
  cout << "a.Size(): " << a.Size() << endl;

  ForwardList<double> b;
  cout << "b.Size(): " << b.Size() << endl;

  ForwardList<double> c(10);
  cout << "c.Size(): " << c.Size() << endl;

  cout << "a.Empty(): " << a.Empty() << endl
       << "b.Empty(): " << b.Empty() << endl
       << "c.Empty(): " << c.Empty() << endl;
  system("pause");
  return 0;
}
