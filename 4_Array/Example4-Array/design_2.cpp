#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  explicit IntArray(int n);
  int Size() const;
  int &At(int i);
  int At(int i) const;
};

int main() {
  using namespace std;
  IntArray a(10);
  cout << "�}�C a ���j�p��: " << a.Size() << endl;
  a.At(3) = 7;
  cout << "�}�C a ���ĤT��������: " << a.At(3) << endl;

  IntArray b = 5;     // [�sĶ���~] �в�������
  IntArray c;         // [�sĶ���~] �в�������

  const IntArray &d = a;
  cout << "�}�C d ���j�p��: " << d.Size() << endl;
  cout << "�}�C d ���ĤT��������: " << d.At(3) << endl;
  system("pause");
  return 0;
}
