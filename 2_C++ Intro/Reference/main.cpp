#include <iostream>

using namespace std;

int *add(int *v){
    *v = *v + 1;
    return v;

}

int &add2(int &v){
    v = v + 1;
    return v;
}

void Swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int main(){
    int a = 4;
    int b = *add(&a);
    int &c = add2(a);
    cout <<"address a = "<< &a << endl;
    cout <<"address b = "<< &b << endl;
    cout <<"address c = "<< &c << endl;
    cout <<"a = "<< a <<"\tb = "<<b<<"\tc = "<<c<<endl;

    int d = 10;
    int e = 5;
    Swap(d,e);
    cout<<d<<"\t"<<e<<endl;
    return 0;
}
