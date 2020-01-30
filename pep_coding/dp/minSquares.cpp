#include <bits/stdc++.h>
using namespace std;
int fun(vector<vector<int> > & dp,int i,int j)
{
   
    if(i==0 || j==0 )
     {  return 0;}
  if(i==j)
    { 
    return 1;
    }
     if(dp[i][j]!=-1) return dp[i][j];
    
   
        int minn=min(i,j);
        int min2=INT_MAX;
        for(int k=1;k<=minn;k++)
        {
            int val1= fun(dp,k,j-k);
            int val2= fun(dp,i-k,j);
            int val3=fun(dp,i-k,k);
            int val4=fun(dp,i,j-k);
            min2=min(min2,min(val1+val2+1,val3+val4+1));
            
        }
        dp[i][j]=min2;
        return dp[i][j];
    
}
int main() {
    vector<vector<int> > dp(30+1,vector<int>(36+1,-1));
    cout<<fun(dp,30,36);
    return 0;
}

