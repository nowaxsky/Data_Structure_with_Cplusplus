#include <iostream>
#include <cstdlib>
#include <set>
 
using namespace std;

int main() {
  set<int> q;
  for (int i = 1; i <= 5; ++i) {
    int v = rand() % 10; 
    q.insert(v);
    cout << "���J " << v << endl;  
  } 

  for (int i = 0; i < 10; ++i) {
    if (q.find(i) != q.end()) {
      cout << i << " ���" << endl; 
    } else {
      cout << i << " �䤣��" << endl;
    }
  }
  system("pause");
  return 0;
}
