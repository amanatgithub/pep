#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> arr{900,940,950,1100,1500,1800};
    vector<int> dep{910,1200,1120,1130,1900,2000};
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i=0,j=0;
    int maxx=0;
    while(i<arr.size() && j<dep.size())
    {
      while(arr[i]>dep[j])
       j++;
       i++;
       maxx=max(maxx,i-j);
      // cout<<i-j;
       /* if(arr[i]<dep[j])
       {
           i++;
           count++;
       }
       else
       {
           j++; count--;
       }
       maxx=max(maxx,count); */

    }
    cout<<maxx;
    return 0;
}

