#include <iostream>
#include <cstdlib>
using namespace std;

class String {
 public:
  String();
  String(const String &s);
  String(const char *s);
  ~String();

  int Size() const;

  char &At(int i);
  char At(int i) const;
  char &operator[](int i);
  char operator[](int i) const;
  String &operator=(const String &rhs);

 private:
  int size_;
  char *data_;
};

String::String() {
  size_ = 0;
  data_ = NULL;
}

String::String(const char *s) {
  int len = 0;
  while (s[len] != '\0') ++len;
  size_ = len;
  data_ = new char[len];
  for (int i = 0; i < len; ++i) data_[i] = s[i];
}

String::~String() {
  delete data_;
}

String::String(const String &s) {
  size_ = s.size_;
  data_ = new char[size_];
  for (int i = 0; i < size_; i++) data_[i] = s[i];
}

int String::Size() const {
  return size_;
}

char &String::At(int i) {
  return data_[i];
}

char String::At(int i) const {
  return data_[i];
}

char String::operator[](int i) const {
  return At(i);
}

char &String::operator[](int i) {
  return At(i);
}

ostream &operator<<(ostream &s, const String &str) {
  for (int i = 0; i < str.Size(); ++i) s << str[i];
  return s;
}
/*
String operator+(const String &lhs, const String &rhs) {

    int temp_size = lhs.Size() + rhs.Size();
    char *temp_data = new char[temp_size];

    for(int i=0; i<lhs.Size(); i++){
        temp_data[i] = lhs[i];
    }
    for(int j=0; j<rhs.Size(); j++){
        temp_data[j+lhs.Size()] = rhs[j];
    }

    String str(temp_data);
    delete [] temp_data;
    return str;
}
*/
String operator+(const String &lhs, const String &rhs) {

    int temp_size = lhs.Size() + rhs.Size();
    char temp_data[temp_size+1] = {'\0'};

    for(int i=0; i<lhs.Size(); i++){
        temp_data[i] = lhs[i];
    }
    for(int j=0; j<rhs.Size(); j++){
        temp_data[j+lhs.Size()] = rhs[j];
    }

    String str(temp_data);
    return str;
}


String &String::operator=(const String &rhs) {
    size_ = rhs.size_;
    data_ = new char[rhs.size_];
    for(int i = 0; i<rhs.size_; i++){
        data_[i] = rhs.data_[i];
    }
    return *this;
}

int main() {

  String a,b;
  cout << "a.Size(): " << a.Size() << endl;
  a = b = "Hello";
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;

  String c = "world";
  cout << "c: " << c << endl;

  String d = a;
  cout << "d: " << d << endl;

  a[0] = 'h';
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "d: " << d << endl;

  String e = a + " " + b + "!";
  cout << "e: " << e << endl;

  system("pause");
  return 0;
}
