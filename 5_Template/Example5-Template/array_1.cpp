#include <iostream>
#include <cstdlib>
using namespace std;

template<typename ElemType>
class Array {
 public:
  Array();
  Array(const Array<ElemType> &rhs);
  explicit Array(int n);
  ~Array() { delete [] data_; }

  int Size() const { return size_; }
  ElemType &At(int i)                     { return data_[i]; }
  const ElemType &At(int i) const         { return data_[i]; }

  ElemType &operator[](int i)             { return At(i); }
  const ElemType &operator[](int i) const { return At(i); }
  Array<ElemType> &operator=(const Array<ElemType> &rhs);

 private:
  int size_;
  ElemType *data_;
};


// �o�̧ڭ̧⦨���禡���w�q���}�g, �]�����O�����O�ҪO, �ҥH���������禡�̤]���O�禡�ҪO��
template<typename ElemType>
Array<ElemType>::Array() {
  size_ = 0;
  data_ = NULL;
}

template<typename ElemType>
Array<ElemType>::Array(const Array<ElemType> &rhs) {
  size_ = rhs.size_;
  data_ = new ElemType[rhs.size_];
  for (int i = 0; i < rhs.size_; ++i) {
    data_[i] = rhs.data_[i];
  }
}

template<typename ElemType>
Array<ElemType>::Array(int n) {
  size_ = n;
  data_ = new ElemType[n];
}

template<typename ElemType>
Array<ElemType> &Array<ElemType>::operator=(const Array<ElemType> &rhs) {
  if (this != &rhs) {
    delete [] data_;
    size_ = rhs.size_;
    data_ = new ElemType[rhs.size_];
    for (int i = 0; i < rhs.size_; ++i) {
      data_[i] = rhs.data_[i];
    }
  }
  return *this;
}

template<typename ElemType>
ostream &operator<<(ostream &lhs, const Array<ElemType> &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i != 0) { lhs << " "; }
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  Array<double> a(10);
  Array<int>    b(10);

  for (int i = 0; i < a.Size(); ++i) a[i] = 1.1 * i;
  cout << "a: " << a << endl;

  for (int i = 0; i < b.Size(); ++i) b[i] = 1.1 * i;
  cout << "b: " << b << endl;

  system("pause");
  return 0;
}






