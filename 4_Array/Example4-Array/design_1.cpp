#include <iostream>
#include <cstdlib>

class IntArray {
 public:
  IntArray(int n);
  int Size();
  int At(int i);
};

int main() {
  using namespace std;
  IntArray a(10);
  cout << "�}�C a ���j�p��: " << a.Size() << endl;
  a.At(3) = 7;        // [�sĶ���~]
  cout << "�}�C a ���ĤT��������: " << a.At(3) << endl;

  IntArray b = 6;     // �o�O�ƻ�N�� ?
  IntArray c;         // [�sĶ���~]

  const IntArray d = a;
  cout << "�}�C d ���j�p��: " << d.Size() << endl;      // [�sĶ���~]
  cout << "�}�C d ���ĤT��������: " << d.At(3) << endl; // [�sĶ���~]
  system("pause");
  return 0;
}
