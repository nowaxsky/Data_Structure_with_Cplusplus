#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  explicit IntArray(int n);
  int Size() const;    
  int &At(int i);
  int At(int i) const;
  int &operator[](int i);
  int operator[](int i) const;
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
