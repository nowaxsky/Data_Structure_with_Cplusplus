#include <iostream>
#include <cstdlib>

template<class ElemType>
struct ForwardListNode {
  ElemType                   data;      // 元素
  ForwardListNode<ElemType> *link;      // 下一個節點的指標
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
  // 新增下列函式:
  void Resize(int n);
  void Reverse();

  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }

 private:
  int size_;
  Node *head_;  // 指向第一個節點
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

// 實作下列函式:
template<class ElemType>
void ForwardList<ElemType>::Resize(int n) {

    if(n <= size_){
        Node *cur = head_;
        for(int i=0; i<n ;i++){
            cur = cur->link;
        }
        cur->link = NULL;
    }


    else if(n > size_){
        Node *cur = head_;
        for(int i=0; i<size_;i++){
            cur = cur->link;
        }

        for(int i=size_;i<n;i++){
            cur->link = new Node();
            cur = cur->link;
        }
        cur->link = NULL;
    }
    size_ = n;
}

template<class ElemType>
void ForwardList<ElemType>::Reverse() {

    if(size_ <= 1) return;
    else{
        Node *pre = NULL;
        Node *cur = head_;
        Node *nex = cur->link;
        while(nex!=NULL){
            //std::cout<<cur->data;
            cur->link = pre;
            pre = cur;
            cur = nex;
            nex = nex->link;
            //std::cout<<nex->data;
            ;
        }
        cur->link = pre;


        head_ = pre; //???
    }
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

  ForwardList<int> a(5);
  for (int i = 0; i < 5; ++i) { a[i] = i; }
  cout << "a: " << a << endl;
  a.Resize(3);
  cout << "a: " << a << endl;
  a.Resize(8);
  for (int i = 3; i < 8; ++i) { a[i] = i+5; }
  cout << "a: " << a << endl;
  a.Resize(0);
  cout << "a: " << a << endl;
  a.Resize(5);
  for (int i = 0; i < 5; ++i) { a[i] = i; }
  cout << "a: " << a << endl;
  a.Reverse();
  cout << "a: " << a << endl;
  a.Resize(1);
  a.Reverse();
  cout << "a: " << a << endl;
  system("pause");
  return 0;
}
