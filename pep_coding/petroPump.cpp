#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a;
    cin>>n;
    vector<int> p;
    vector<int> diff;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        p.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        cin>>a;
        diff.push_back(p[i]-a);
    }
    int sum,j,ans=-1;
    for(int i=0;i<n;i++)
    {   sum=0;
        if(diff[i]>=0)
        {
           for( j=i;j<i+n;j++)
           {
               sum+=diff[j%n];
               if(sum<0)
                break;
           }
           if(i==j%n) {ans=i; break;}
           else if(i>j%n) break;
           else i=j%n;
        }
    }
    cout<<ans;
    return 0;
}

