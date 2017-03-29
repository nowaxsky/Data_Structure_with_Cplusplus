#include <iostream>
#include <string.h>
#define MAX 100

using namespace std;

class number{
public:
    number(){}
    void create(char input[]){
        int i;
        int len = strlen(input);
        for(i=0; i<len; i++){
            num[i] = input[len-i-1]-'0';
        }
        for(; i<MAX; i++){
            num[i] = 0;
        }
    }

    void output(){
        int stop=0;
        while(num[stop] != 0){
            stop++;
        }
        for(int i=0; i<stop;i++){
            cout<<num[stop-i-1]<<endl;
        }

    }

    number add(number &b){
        int i=0;
        number sum;
        sum.num[0] = 0;
        //cout<<num[0]<<b.num[0];
        while((this->num[i] != 0) && (b.num[i] != 0)){
            //cout<<"Yes";

            sum.num[i] += this->num[i] + b.num[i];
            cout<<sum.num[i]<<endl;
            if(sum.num[i]>=10){
                sum.num[i+1] = 1;
            }
            i++;
        }


        return sum;
    }

    int num[MAX];
};

int main(){
    number a,b,c;
    char m[MAX],n[MAX];

    cout<<"Please enter two number: "<<endl;
    cin>>m>>n;

    a.create(m);
    b.create(n);

    //a.output();
    //b.output();

    c = a.add(b);
    c.output();
    //cout<<c.output()<<"end";

    return 0;
}
