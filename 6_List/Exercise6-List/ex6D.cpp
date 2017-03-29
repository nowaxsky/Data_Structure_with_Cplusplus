#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

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
  // �s�W�ƻs�غc��
  ForwardList(const ForwardList &x);
  ~ForwardList();

  int Size() const { return size_; }
  ElemType &At(int i);
  const ElemType &At(int i) const;
  void PushFront(const ElemType &elem);
  void PopFront();
  // �s�W�M���禡:
  void Clear();
  // �s�W�洫�禡:
  void Swap(ForwardList<ElemType> &x);

  void PushBack(const ElemType &elem);

  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }
  // �s�W��ȹB��l�h��
  ForwardList &operator=(const ForwardList &rhs);

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
ForwardList<ElemType>::ForwardList(const ForwardList<ElemType> &x) {
  size_ = x.size_;
  if (x.size_ > 0) {
    head_ = new Node();
    head_->data = x.head_->data;
    Node *to   = head_;
    Node *from = x.head_;
    while (from->link != NULL) {
      to->link = new Node();
      to->link->data = from->link->data;
      to = to->link;
      from = from->link;
    }
    to->link = NULL;
  } else {
    head_ = NULL;
  }
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

template<class ElemType>
void ForwardList<ElemType>::Clear() {
    Node *cur = head_;
    while(cur!=NULL){
        Node *del = cur;
        cur = cur->link;
        delete del;
        del->link = NULL; //��������, ���̵M����

    }
    //�i�঳���D �S�R���b
    size_ = 0;
}

template<class ElemType>
void ForwardList<ElemType>::Swap(ForwardList<ElemType> &x) {

    int this_size = this->Size();
    int x_size = x.Size();

    for(int i=0; i<x_size; i++){
        this->PushBack(x[i]);
    }
    for(int i=0; i<this_size; i++){
        x.PushBack(this->At(i));
    }
    for(int i=0; i<this_size;i++){
        this->PopFront();
    }
    for(int i=0; i<x_size; i++){
        x.PopFront();
    }

}

template<class ElemType>
void ForwardList<ElemType>::PushBack(const ElemType &elem) {
    // Step 1]
    Node *p = head_;
    for (int i = 0; i < size_ - 1; ++i) { p = p->link; }
    // Step 2]
    Node *ins = new Node();
    ins->data = elem;
    // Step 3]
    ins->link = p->link;
    // Step 4]
    p->link = ins;
    ++size_;
}


template<class ElemType>
ForwardList<ElemType> &ForwardList<ElemType>::operator=(
    const ForwardList<ElemType> &rhs) {
  // Copy-and-Swap idiom
  ForwardList<ElemType> tmp(rhs); // �I�s�ƻs�غc��
  Swap(tmp);                      // �I�s�洫�禡
  return *this;                   // ���ɷ|�I�s tmp ���Ѻc��
}

template<class ElemType>
ostream &operator<<(ostream &lhs, const ForwardList<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}

int main() {

  ForwardList<int> a(5);
  for (int i = 0; i < 5; ++i) { a[i] = i; }
  ForwardList<int> b = a;
  cout << "a: " << a << endl
       << "b: " << b << endl;

  for (int i = 0; i < 3; ++i) { b.PushFront(i+5); }
  cout << "a: " << a << endl
       << "b: " << b << endl;

  b.Swap(a);
  cout << "b.Swap(a);" << endl
       << "a: " << a << endl
       << "b: " << b << endl;

  b.Clear();
  cout << "b.Clear();" << endl
       << "a: " << a << endl
       << "b: " << b << endl;

  for (int i = 0; i <3; ++i) { b.PushFront(i+8); }
  cout << "a: " << a << endl
       << "b: " << b << endl;


  b = a;
  cout << "b = a; " << endl
       << "a: " << a << endl
       << "b: " << b << endl;

  for (int i = 0; i < b.Size(); ++i) { b[i] = i+10; }
  cout << "a: " << a << endl
       << "b: " << b << endl;

  ForwardList<int> c;
  ForwardList<int> d(c);
  cout << "c: " << c << endl
       << "d: " << d << endl;
  system("pause");
  return 0;
}
