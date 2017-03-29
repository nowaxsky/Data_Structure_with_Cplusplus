#include <iostream>
#include <cstdlib>
using namespace std;

class IntArray {
 public:
  explicit IntArray(int n) {
    size_ = n;
    data_ = new int[n];
  }
  int Size() const {
    return size_;
  }
  int &At(int i) {
    cout<<"input"<<endl;
    cout<<data_[i]<<endl;
    return data_[i];
  }
  int At(int i) const{
    cout<<"output"<<endl;
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
