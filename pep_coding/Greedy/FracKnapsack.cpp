#include<bits/stdc++.h>
using namespace std;
class Helper
{
    public:
       int wt;
       int val;
       float rat;
       Helper(int a,int b)
       {
           wt=a;
           val=b;
           rat= val/(wt*1.0);
       }

       bool operator<(const Helper& o)const{return this->rat>o.rat;}
};
int main()
{
    vector<Helper> arr{Helper(10,60),Helper(40,40),Helper(20,100),Helper(30,120)};
    int k=50;
     sort(arr.begin(),arr.end());
     int i=0;
     float cost=0;
     while(arr[i].wt<k)
     {
        cost+=arr[i].val;
        k-=arr[i].wt;
        i++;
     }
     if(k!=0)
     {
         cost+= arr[i].rat*k;
     }
     cout<<cost;
     return 0;
}
