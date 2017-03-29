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
  ElemType &At(int i);
  const ElemType &At(int i) const;
  void PushFront(const ElemType &elem);
  void PopFront();
  // �s�W�U�C�禡:
  void Insert(int pos, const ElemType &elem);
 
  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }

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
ElemType &ForwardList<ElemType>::At(int i) { 
  return (ElemType&)((const ForwardList *)this)->At(i);
}

template<class ElemType>
const ElemType &ForwardList<ElemType>::At(int i) const {
  Node *cur = head_;
  for (int k = 0; k < i; ++k) {
    cur = cur->link;
  }
  return cur->data;
}

template<class ElemType>
void ForwardList<ElemType>::PushFront(const ElemType &elem) {
  Node *ins = new Node();
  ins->data = elem;
  ins->link = head_;
  head_ = ins;
  size_++;
} 

template<class ElemType>
void ForwardList<ElemType>::PopFront() {
  Node *del = head_;
  head_ = head_->link;
  delete del;
  size_--;
} 

// �U���O�o�Ө禡����@: 
template<class ElemType>
void ForwardList<ElemType>::Insert(int pos, const ElemType &elem) {
  if (pos == 0) {
    Node *ins = new Node();
    ins->data = elem;
    ins->link = head_;
    head_ = ins;
  } else {
    // Step 1]
    Node *p = head_;
    for (int i = 0; i < pos - 1; ++i) { p = p->link; }  
    // Step 2]
    Node *ins = new Node(); 
    ins->data = elem;
    // Step 3]
    ins->link = p->link;
    // Step 4]
    p->link = ins;
  } 
  ++size_;
}

template<class ElemType>
std::ostream &operator<<(std::ostream &lhs, const ForwardList<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using std::cout;
  using std::endl;

  ForwardList<int> a;
  for (int i = 0; i < 5; ++i) {  a.Insert(0, i);  }
  cout << "a: " << a << endl;

  for (int i = 0; i < 5; ++i) {  a.Insert(5, i+5);  }
  cout << "a: " << a << endl;

  system("pause");
  return 0;
}