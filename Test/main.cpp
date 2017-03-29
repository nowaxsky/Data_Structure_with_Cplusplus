#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
const int MAX=100;
struct point{
    double x;
    double y;
};
int main(){
    int i;
    point a[MAX];
    int number;
    double min=numeric_limits<double>::max();
    double tmp;
    point result1,result2;
    cout<<"Please enter the number of points and the coordinates of points"<<endl
    <<"for example : for 4 points (1, 1), (4, 9), (2, 2) and (7, 8)"<<endl
    <<"Input: 4 1 1 4 9 2 2 7 8"<<endl;
    cout<<endl<<"Please enter now"<<endl;
    cin>>number;
    for( i=0;i<number;i++){
        cin>>a[i].x;
        cin>>a[i].y;
    }
    for(i=0;i<number;i++){
        for(int j=i+1;j<number;j++){
            tmp=sqrt(pow((a[i].x-a[j].x),2)+pow((a[i].y-a[j].y),2));
            if(tmp<min){
                min=tmp;
                result1.x=a[i].x;
                result1.y=a[i].y;
                result2.x=a[j].x;
                result2.y=a[j].y;
            }
        }
    }
    cout<<"The shortest distance "<<min<<" occurs on ("<<result1.x<<","<<result1.y<<")"
        <<"and ("<<result2.x<<","<<result2.y<<")"<<endl;

    return 0;
}
