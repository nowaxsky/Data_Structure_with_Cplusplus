#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct Record {
  string name;
  string mobile;
};

void AddRecord(vector<Record> &addressbook) {
    cout<<"�п�J�m�W: ";
    string tempName;
    cin>>tempName;
    cout<<"�п�J�q��: ";
    string tempMobile;
    cin>>tempMobile;
    Record temp;
    temp.name = tempName;
    temp.mobile = tempMobile;

    addressbook.push_back(temp);
}

void ShowRecords(const vector<Record> &addressbook) {

    cout<<"--------------------------------"<<endl;
    for(int i=0; i<addressbook.size(); i++){
        cout<<i<<") "<<addressbook[i].name<<" ("<<addressbook[i].mobile<<")"<<endl;
    }
    cout<<"--------------------------------"<<endl;
}

void ClearRecords(vector<Record> &addressbook) {
    addressbook.clear();
}

int main() {
  vector<Record> addressbook;
  Record init_data[3] = {
      { "Lee",   "0912345678" },
      { "Huang", "0933112345" },
      { "Liu",   "0944112233" } };
  for (int i = 0; i < 3; ++i) {
    addressbook.push_back(init_data[i]);
  }
/*
  Record a;
  for(int i = 0; i<addressbook.size();i++){
    a = addressbook[i];
    cout<<a.name;
  }*/


  bool quit = false;
  while (!quit) {
    cout << "1] �s�W���"     << endl
         << "2] ��ܩҦ����" << endl
        <<  "3] �M���Ҧ����" << endl
         << "4] �����{��"     << endl
         << "�п�J�A�����: ";
    int choice;
    cin  >> choice;
    switch(choice) {
      case 1: AddRecord(addressbook); break;
      case 2: ShowRecords(addressbook); break;
      case 3: ClearRecords(addressbook); break;
      case 4: quit = true; break;
    }
  }
  return 0;
}
