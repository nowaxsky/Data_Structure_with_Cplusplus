#include <iostream>
#include <cstdlib>

class Grade {
 public:
  Grade()         { data_ = 0; }
  Grade(int v)    { this->Set(v); }
  void Set(int v) { data_ = v; }
  int Get() const { return data_; }
  bool operator>(const Grade &rhs) {
    return this->Get() > rhs.Get();
  }

 private:
  int data_;
};


// ��U���o�� Max �禡�ܦ��@�ӼҪO�禡�ӳB�z�U�ظ������

template<class T>
T Max(T a, T b, T c) {
  T ret = a;
  if (b > ret) ret = b;
  if (c > ret) ret = c;
  return ret;
}

std::ostream &operator<<(std::ostream &lhs, const Grade &rhs) {
  lhs << rhs.Get();
  return lhs;
}


int main() {
  using namespace std;
  Grade a = 5, b = 4, c = 3;
  cout << "Max(3, 5, 4)      : " << Max(3, 5, 4)       << endl
       << "Max(3.5, 4.5, 5.5): " << Max(3.5, 4.5, 5.5) << endl
       << "Max(a, b, c)      : " << Max(a, b, c)       << endl;
  system("pause");
  return 0;
}
