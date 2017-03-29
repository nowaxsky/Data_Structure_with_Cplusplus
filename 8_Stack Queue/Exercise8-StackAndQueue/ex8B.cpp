#include <iostream>
#include <list>
#include <cstdlib>

template<class ElemType>
class Stack {
 public:
  ElemType Top() const {
    return data_.back();
  }
  void Push(const ElemType &elem) {
    data_.push_back(elem);
  }
  void Pop() {
    data_.pop_back();
  }
  bool Empty() const {
    return data_.empty();
  }
 private:
  std::list<ElemType> data_;
};


int main() {
  using std::cout;
  using std::endl;

  Stack<int> s;
  for (int i = 1; i <= 5; ++i) {
    s.Push(i);
  }
  cout << "s.Top(): " << s.Top() << endl;

  cout << "s: ";
  while (!s.Empty()) {
    cout << s.Top();
    s.Pop();
    cout << " ";
  }
  cout << endl;
  system("pause");
  return 0;
}
