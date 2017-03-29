#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  explicit IntArray(int n) {
    size_ = n;
    data_ = new int[n];
  }
  // �s�W�F�Ѻc�� 
  ~IntArray() {
    delete[] data_;
  }
  int Size() const {
    return size_;
  }    
  int &At(int i) {
    return data_[i];
  }
  int At(int i) const {
    return data_[i];
  }
  int &operator[](int i) {
    return At(i);
  }
  int operator[](int i) const {
    return At(i);
  }
 private:
  int size_;
  int *data_;
};

int main() {
  using namespace std;
  IntArray a(10);
  cout << "�}�C a ���j�p��: " << a.Size() << endl;
  a[3] = 7;
  cout << "�}�C a ���ĤT��������: " << a[3] << endl;

  const IntArray &d = a;
  cout << "�}�C d ���j�p��: " << d.Size() << endl;  
  cout << "�}�C d ���ĤT��������: " << d[3] << endl; 
  system("pause");
  return 0; 
}
