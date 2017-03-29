#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Person {
 public:
  Person(int age, string name, string mobile) {
    this->age = age;
    this->name = name;
    this->mobile = mobile;
  }

  int age;
  string name;
  string mobile;
};

ostream &operator<<(ostream &lhs, const vector<Person> &rhs) {
  lhs << left << setw(10) << "�m�W"
      << left << setw(5)  << "�~��"
      << left << setw(15) << "�q��"
      << endl;
  for (size_t i = 0; i < rhs.size(); ++i) {
    lhs << left << setw(10) << rhs[i].name
        << left << setw(5)  << rhs[i].age
        << left << setw(15) << rhs[i].mobile
        << endl;
  }
  return lhs;
}


struct CompPerson {
  inline bool operator()(const Person &a, const Person &b) {
    // TODO
    if(a.age == b.age){
        return a.name < b.name;
    }
    else{
        return a.age < b.age;
    }
  }
};

int main() {
  vector<Person> a;
  a.push_back(Person(20, "Sam",    "0933813234"));
  a.push_back(Person(18, "Arthur", "0941234122"));
  a.push_back(Person(19, "Carl",   "0999733333"));
  a.push_back(Person(21, "Lance",  "0933123482"));
  a.push_back(Person(19, "Eason",  "0987133412"));
  a.push_back(Person(20, "Ben",    "0988333333"));
  cout  << a << endl;

  vector<Person> b = a;
  sort(b.begin(), b.end(), CompPerson());

  cout << "�̷өm�W�P�~�ֱƧǫ�: " << endl;
  cout << b << endl;
  system("pause");
  return 0;
}
