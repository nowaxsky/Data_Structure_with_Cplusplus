#include <iostream>
#include <cstdlib>

template<class ElemType>
struct ForwardListNode {
  ElemType                   data;      // ����
  ForwardListNode<ElemType> *link;      // �U�@�Ӹ`�I������
};

template<class ElemType>
class OrderedForwardList {
  typedef ForwardListNode<ElemType> Node;

 public:
  OrderedForwardList() {
    size_ = 0;
    head_ = NULL;
  }
  ~OrderedForwardList();

  int Size() const { return size_; }
  ElemType &At(int i);
  const ElemType &At(int i) const;
  void Insert(const ElemType &elem);

  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }

 private:
  int size_;
  Node *head_;
};

template<class ElemType>
OrderedForwardList<ElemType>::~OrderedForwardList() {
  Node *cur = head_;
  while (cur != NULL) {
    Node *del = cur;
    cur = cur->link;
    delete del;
  }
}

template<class ElemType>
ElemType &OrderedForwardList<ElemType>::At(int i) {
  return (ElemType&)((const OrderedForwardList *)this)->At(i);
}

template<class ElemType>
const ElemType &OrderedForwardList<ElemType>::At(int i) const {
  Node *cur = head_;
  for (int k = 0; k < i; ++k) {
    cur = cur->link;
  }
  return cur->data;
}

template<class ElemType>
void OrderedForwardList<ElemType>::Insert(const ElemType &elem) {
    if(size_==0){
        head_ = new Node();
        head_->data = elem;
        head_->link = NULL;
        size_++;
    }
    else{
        Node *cur = head_;
        Node *pre = NULL;
        while(elem>(cur->data) && cur->link!=NULL){
            pre = cur;
            cur = cur->link;
        }

        Node *ins = new Node();
        ins->data = elem;
        if(cur->link==NULL){    //�Y���̫᭱
            ins->link = NULL;
            cur->link = ins;
        }
        else if(pre==NULL){ //�Y���̫e��
            ins->link = cur;
            head_=ins;
        }

        else{
            ins->link = cur;
            pre->link = ins;
        }
        size_++;

    }
}

template<class ElemType>
std::ostream &operator<<(std::ostream &lhs, const OrderedForwardList<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  using std::cout;
  using std::endl;
  OrderedForwardList<int> a;

  for (int i = 0; i < 3; ++i) { a.Insert(i+2); }
  cout << "a: " << a << endl;

  for (int i = 0; i < 3; ++i) { a.Insert(i); }
  cout << "a: " << a << endl;

  for (int i = 0; i < 2; ++i) { a.Insert(4+i); }
  cout << "a: " << a << endl;
  system("pause");
  return 0;
}
