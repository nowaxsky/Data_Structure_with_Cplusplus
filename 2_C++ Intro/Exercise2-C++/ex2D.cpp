#include <stdio.h>
#include <stdlib.h>

class Grade {
 public:
  Grade()         { data_ = 0;}
  Grade(int v)    { data_ = v; }

 public:
  void Set(int v) { data_ = v; }
  int Get() const { return data_; }

 private:
  int data_;
};


const Grade Add(const Grade &lhs, const Grade &rhs) {
  return lhs.Get() + rhs.Get();
}

const Grade operator+(const Grade &lhs, const Grade &rhs) {
  return lhs.Get() + rhs.Get();
}

bool operator>=(const Grade &lhs, const Grade &rhs) {
    if(lhs.Get()>=rhs.Get()) return true;
    else return false;
}

int main() {
  Grade a = 50;
  Grade b = 80;
  if (a >= 80) {
    printf("�F�`��!\n");
  } else if (a >= 60){
    printf("�٤�����\n");
  } else {
    printf("���ή�\n");
  }


  if (b >= 80) {
    printf("�F�`��!\n");
  } else if (b >= 60){
    printf("�٤�����\n");
  } else {
    printf("���ή�\n");
  }

  system("pause");
  return 0;
}
