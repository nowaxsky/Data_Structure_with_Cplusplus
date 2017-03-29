#include <iostream>
#include <cstdlib>

using namespace std;

class IntArray {
 public:
  explicit IntArray(int n) {
    size_ = n;
    data_ = new int[n];
  }
  ~IntArray() {
    delete [] data_;
  }

  int Size() const { return size_; }

  // �s�W�U�C��Ө禡
  void Swap(IntArray &x);
  void Reverse();

  int &At(int i)              { return data_[i]; }
  int At(int i) const         { return data_[i]; }
  int &operator[](int i)      { return At(i); }
  int operator[](int i) const { return At(i); }

 private:
  int size_;
  int *data_;
};

// �ڭ̥i�H�N�����禡�w�q�b���O�ŧi�~, ���ɨ禡�W�٪����W�O "���O�W��::�����禡�W��"
void IntArray::Swap(IntArray &x) {
    int *temp = new int[size_];
    int tempsize = size_;
    for(int i=0; i<size_; i++){
        temp[i] = data_[i];
    }

    delete [] data_;

    data_ = x.data_;
    size_ = x.size_;
    delete [] x.data_;

    x.data_ = temp;
    x.size_ = tempsize;
    delete [] temp;

}

void IntArray::Reverse() {
    int *temp = new int[size_];
    for(int i=0; i<size_; i++){
        temp[i] = data_[size_-i-1];
    }

    delete [] data_;
    data_ = temp;
    delete [] temp;
}

ostream &operator<<(ostream &lhs, const IntArray &rhs) {
  for (int i = 0; i < rhs.Size(); ++i) {
    if (i > 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  IntArray a(5);
  for (int i = 0; i < 5; ++i) a[i] = i;
  cout << "a: " << a << endl;

  IntArray b(8);
  for (int i = 0; i < 8; ++i) b[i] = i+5;
  cout << "b: " << b << endl;

  IntArray c = a;
  c.Reverse();
  cout << "c: " << c << endl;
  c.Reverse();
  cout << "c: " << c << endl;

  b.Reverse();
  cout << "b: " << b << endl;
  b.Reverse();
  cout << "b: " << b << endl;

  a.Swap(b);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;


  a.Swap(b);
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  system("pause");
  return 0;
}
