#include <bits/stdc++.h>
using namespace std;
class Activity
{
   public:
    int s;
    int e;
    Activity(int a,int b)
    {
        s=a;
        e=b;
    }

    bool operator<(const Activity& o)const
    {
        return this->e<o.e;
    }
};
int main() {
    vector<Activity> arr{Activity(3,4),Activity(0,6),Activity(1,2),Activity(8,9),Activity(5,9),Activity(5,7)};
    sort(arr.begin(),arr.end());
    int end=-1;
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i].s>end)
          {
              count++; end=arr[i].e;
          }
    }
   cout<<count;
    return 0;
}

