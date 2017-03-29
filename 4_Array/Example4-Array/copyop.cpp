#include <iostream>
using namespace std;

class Grade {
 public:
  Grade() {
    cout << "�I�s Grade() " << endl;
    data_ = 0;
  }
  Grade(int v) {
    cout << "�I�s Grade(int) " << endl;
    data_ = v;
  }
  Grade(const Grade& rhs) {
    cout << "�I�s Grade(const Grade &) " << endl;
    data_ = rhs.data_;
  }
  Grade &operator=(const Grade &rhs) {
    cout << "�I�s Grade::operator=(const Grade&) " << endl;
    data_ = rhs.data_;
    return *this; // ��ȹB�⪺�^�ǭȧκA�@�묰�Ĥ@�ӹB�⤸���A, �b�����禡����Ȭ� *this
    // �g b = a �|�I�s b.operator=(a), �Ӧ��� this �O &b �B *this �N�O b
  }

  int Get() const { return data_; }
  void Set(int v) { data_ = v; }
 private:
  int data_;
};

ostream &operator<<(ostream &lhs, const Grade &rhs) {
  lhs << rhs.Get();
  return lhs;
}

int main() {
  cout << "[Case 1]" << endl;
  Grade a(30), b, c;
  cout << "a: " << a << endl;
  cout << endl;

  cout << "[Case 2]" << endl;
  b = a;
  cout << "a: " << a << endl
       << "b: " << b << endl;
  cout << endl;

  cout << "[Case 3]" << endl;
  b = 50;
  cout << "b: " << b << endl;
  cout << endl;

  cout << "[Case 4]" << endl;
  c = a = 30;
  cout << "a: " << a << endl
       << "c: " << c << endl;
  cout << endl;

  cout << "[Case 5]" << endl;
  (c = 20) = b;
  cout << "b: " << b << endl
       << "c: " << c << endl;
  cout << endl;

  cout << "[Case 6]" << endl;
  Grade d = c = b;
  cout << endl;
  return 0;
}
