#include <iostream>
#include <cstdlib>

struct BigInt {
  int data[20];
};

const BigInt Create(unsigned int v);
const BigInt Multiply(const BigInt &a, const BigInt &b);
const BigInt Add(const BigInt &a, const BigInt &b);
void Print(const BigInt &r);

int main() {
    BigInt a = Create(1234567);
    BigInt b = Create(9999999);
    BigInt c = Create(7654321);
    BigInt d = Multiply(Add(a,Multiply(b,c)),a);

    std::cout<<"(";
    Print(a);
    std::cout<<"+";
    Print(b);
    std::cout<<"*";
    Print(c);
    std::cout<<")*";
    Print(a);
    std::cout<<" == ";
    Print(d);
    std::cout<<"\n";


    system("pause");
    return 0;
}

const BigInt Create(unsigned int v) {
  BigInt r;
  for (int i = 0; i < 20; i++) {
    r.data[i] = v % 10;
    v /= 10;
  }
  return r;
}

const BigInt Add(const BigInt &a, const BigInt &b) {
  BigInt r;
  for (int i = 0; i < 20; ++i) {
    r.data[i] = 0;
  }
  for (int i = 0; i < 20; ++i) {
    r.data[i] = a.data[i] + b.data[i];
  }
  int carry = 0;
  for (int i = 0; i < 20; ++i) {
    int next_carry = (r.data[i]+carry)/10;
    r.data[i] = (r.data[i]+carry)%10;
    carry = next_carry;
  }
  return r;
}

const BigInt Multiply(const BigInt &a, const BigInt &b) {
  BigInt r;
  for (int i = 0; i < 20; ++i) {
    r.data[i] = 0;
  }
  for (int i = 0; i < 20; ++i) {
    for (int j = 0; j < 20; ++j) {
      int k = i + j;
      if (k < 20) {
        r.data[k] += a.data[i] * b.data[j];
      }
    }
  }
  int carry = 0;
  for (int i = 0; i < 20; ++i) {
    int next_carry = (r.data[i]+carry)/10;
    r.data[i] = (r.data[i]+carry)%10;
    carry = next_carry;
  }
  return r;
}

void Print(const BigInt &r) {
  int is_zero = 1;
  for (int i = 20-1; i >= 0; --i) {
    if (r.data[i] != 0) is_zero = 0;
    if (!is_zero)
      std::cout << r.data[i];
  }
}


