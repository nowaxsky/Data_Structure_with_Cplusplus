#include <iostream>

using namespace std;

class Grade{
public:
    Grade(){
        data_ = 0;
    }
    void set(int value){
        data_ = value;
    }
    int get() const{
        return data_;
    }


private:
    int data_;
};

Grade add(const Grade &a, const Grade &b){
        Grade ret;
        ret.set(a.get()+b.get());
        return ret;
}

const Grade add2(const Grade &a, const Grade &b){
        Grade ret;
        ret.set(a.get()+b.get());
        return ret;
}

int main(){
    Grade a,b,c,sum,sum2;
    a.set(5);
    b.set(10);
    c.set(20);

    sum = add(add(a,b),c);
    //add2(a,b).set(100);

    cout<<sum.get()<<endl;
    cout<<add2(a,b).get();
    return 0;
}
