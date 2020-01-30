
#include <bits/stdc++.h>
using namespace std;
vector<int>* fun()
{
    vector<int> a{1,2,3,2,3,3,3};
    cout<< &a<<endl;
    vector<int>* aa=&a;
    cout<<&aa<<endl;
    return aa;
}
class
 person{
     public:
       int a=2;
 };
 person fun1()
 {   person a; a.a=555;
     cout<<&a<<endl;
     return a;
 }
int main() {
    double a=5;
    double *b=&a;
    int k=7;
    int *aa=&k;
    char *c;
    cout<<sizeof(b)<<" "<<sizeof(k)<<sizeof(c)<<endl;
    cout<<*b<<" "<<b<<endl;
    b++;
    cout<<b<<" "<<*b;
}
