#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    vector<vector<int> > tab(s.size(),vector<int>(s.size(),1));
    vector<vector<int> > dp(s.size(),vector<int>(s.size(),0));
    
    for(int gap=0;gap<s.size();gap++)
    {
        for(int i=0,j=i+gap;j<s.size();i++,j++)
        {
            if(gap==0)
               tab[i][j]=1;
            else
              if(s[i]==s[j])
              {
                  tab[i][j]=tab[i+1][j-1]==1?1:0;
              }   
              else
                tab[i][j]=0;
              
        }
    }

//No need to use previous function, But here used
       for(int gap=0;gap<s.size();gap++)
    {
        for(int i=0,j=i+gap;j<s.size();i++,j++)
        {    
            if(gap==0)
              dp[i][j]=0;
              else
              {
              if(tab[i][j]==1) dp[i][j]=0;
               else
               {  int minn=s.size();///BEST
                  for(int k=0;k<gap;k++)
                 {
                  minn=min(minn,dp[i][k+i]+dp[i+k+1][j]);
                 }
                dp[i][j]=minn+1;
                }
        }
    }}
for(int i=0;i<dp.size();i++)
 { for(int j=0;j<dp.size();j++)
  cout<<dp[i][j]<<" "; cout<<endl;}
    return 0;
}

