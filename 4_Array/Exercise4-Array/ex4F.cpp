#include <iostream>
#include <cstdlib>
using namespace std;

class IntVector {
 public:
  IntVector();
  IntVector(const IntVector &rhs);
  explicit IntVector(int n);
  ~IntVector() { delete [] data_; }

  int Size() const { return size_; }
  void Resize(int n);
  int &At(int i)      { return data_[i]; }
  int At(int i) const { return data_[i]; }

  // 實作下列功能:
  void PushFront(int elem) {
    if(size_==0){
        size_++;
        data_ = new int[1];
        data_[0] = elem;
    }
    else{
        size_++;
        int *new_data1 = new int[size_];

        new_data1[0] = elem;
        for(int i=0 ; i<size_-1;i++){
            new_data1[i+1] = data_[i];
        }

        delete [] data_;
        data_ = new_data1;


        //delete [] new_data1; //why not??

    }
  }
  void PopFront() {
    size_--;
    int *new_data2 = new int[size_];
    for(int i=0;i<size_;i++){
        new_data2[i] = data_[i+1];
    }
    delete [] data_;
    data_ = new_data2;
    //delete [] new_data2; //why not??
  }

  int &operator[](int i)      { return At(i); }
  int operator[](int i) const { return At(i); }

  IntVector &operator=(const IntVector &rhs);

 private:
  int size_;
  int *data_;
};

IntVector::IntVector() {
  size_ = 0;
  data_ = NULL;
}

IntVector::IntVector(const IntVector& rhs) {
  size_ = rhs.Size();
  data_ = new int[rhs.size_];
  for (int i = 0; i < rhs.size_; ++i) data_[i] = rhs.data_[i];
}

IntVector::IntVector(int n) {
  size_ = n;
  data_ = new int[n];
}

IntVector &IntVector::operator=(const IntVector &rhs) {
  if (this != &rhs) {
    delete [] data_;
    size_ = rhs.Size();
    data_ = new int[rhs.size_];
    for (int i = 0; i < rhs.size_; ++i) {
      data_[i] = rhs.data_[i];
    }
  }
  return *this;
}

void IntVector::Resize(int n) {
  int *new_data = new int[n];
  for (int i = 0; i < size_ && i < n; ++i) {
    new_data[i] = data_[i];
  }
  delete [] data_;
  data_ = new_data;
  size_ = n;
}

std::ostream &operator<<(std::ostream &lhs, const IntVector &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}


int main() {

  IntVector a;
  for (int i = 0; i < 5; ++i) {
    a.PushFront(i);
  }

  cout << "a: " << a << endl;

  for (int i = 0; i < 3; ++i) {
    a.PopFront();
  }
  cout << "a: " << a << endl;

  system("pause");
  return 0;
}

