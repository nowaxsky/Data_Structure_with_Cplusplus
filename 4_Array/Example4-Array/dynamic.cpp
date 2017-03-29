#include <iostream>
#include <cstdlib>

class Grade {
 public:
  Grade() {
    std::cout << "\t���ͤ@�� Grade ����ñN���k�s" << std::endl;
    data_ = 0;
  }

  Grade(int v) {
    std::cout << "\t���ͤ@�� Grade ����ñN�ȳ]�� " << v << std::endl;
    data_ = v;
  }

  ~Grade() {
    std::cout << "\t����@�� Grade ����" << std::endl;
  }

 private:
  int data_;
};

int main() {
  std::cout << "�@���t�m�@�Ӫ���:" << std::endl;
  Grade *a = new Grade;
  Grade *b = new Grade();
  Grade *c = new Grade(3);
  delete a;
  delete b;
  delete c;

  std::cout << std::endl
            << "�t�m�}�C:" << std::endl;
  Grade *d = new Grade[3];
  delete [] d; // �ոլݱN [] �������t�O

  std::system("pause");
  return 0;
}
