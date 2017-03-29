#include <iostream>
#include <stdlib.h>

using namespace std;

int i = 5;

void p(){
    i += 1;
    cout << i << endl;
    return;
};

int main()
{
    cout << i << endl;
    int i = 6;
    i += 1;
    p();
    cout << i << endl;
    system("pause");
    return 0;
}
