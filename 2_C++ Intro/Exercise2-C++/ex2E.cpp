#include <stdio.h>
#include <stdlib.h>

class ConsoleOut {
};

const ConsoleOut &operator<<(const ConsoleOut &lhs, float rhs) {
    printf("%f",rhs);
    //printf("float"); for test
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, double rhs) {
    printf("%f",rhs);
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, int rhs) {
    printf("%d",rhs);
    //printf("int"); for test
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, char rhs) {
    printf("%c",rhs);
    //printf("line"); for test
  return lhs;
}

const ConsoleOut &operator<<(const ConsoleOut &lhs, const char *rhs) {
    printf("%s",rhs);
  return lhs;
}

int main() {
  ConsoleOut cout;
  cout << 3.f << '\n'
       << 3. << '\n'
       << 3 << '\n';

  cout << "Hello world!\n";
  system("pause");
  return 0;
}
