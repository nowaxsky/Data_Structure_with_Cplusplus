#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

int main() {
  using namespace std;

  stack<int> s;
  cout << "�п�J�A����ǹB�⦡ (�Ҧp: 5 6 * 3 + =) :" << endl;
  while (true) {
    string input;
    cin >> input;
    if (input == "=") {
      cout << "�p�⵲�G�� " << s.top() << endl;
      break;
    }else if (input == "+") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(a+b);
    } else if (input == "-") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(a-b);
    } else if (input == "*") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(a*b);
    } else if (input == "/") {
      int b = s.top();
      s.pop();
      int a = s.top();
      s.pop();
      s.push(a/b);
    } else /* �H�W�ҫD�ɧڭ̰��]���Ʀr */ {
      int v;
      std::stringstream conver;
      conver<<input;
      conver>>v;
      //std::stringstream(input) >> v;
      s.push(v);
    }
  }
  std::system("pause");
  return 0;
}
