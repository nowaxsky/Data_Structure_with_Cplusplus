#include <iostream>
#include <stdlib.h>

using namespace std;

class Grade{
public:
    void Set(int v){
        if(v > 100){
            data_ = 100;
        }
        else if(v < 0){
            data_ = 0;
        }
        else data_ = v;
    };
    int Get(){
        return data_;
    };

private:
    int data_;
};

int main()
{
    Grade a;
    a.Set(-2);
    cout<<"a = "<<a.Get()<<endl;
    system("pause");
    return 0;
}
