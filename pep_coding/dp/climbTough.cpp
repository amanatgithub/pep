#include <bits/stdc++.h>
using namespace std;

int stair(int n,vector<int>& dp,vector<int>& jum,int count)
{   
    if(n==0)
     return 1;
   if(n<0 )
     return 0;
   if(dp[n]!=0)
     return dp[n];
    else
      for(int i=1;i<=jum[n];i++)
        {dp[n]+=stair((n-i),dp,jum,count+i); }    
   
    return dp[n];
    
   }
   int stairTabul(vector<int>& jum)
   {
       vector<int> tab(jum.size(),0);
        vector<int> minSteps(jum.size(),INT_MAX);
     vector<int> minJumps(jum.size(),INT_MAX);
vector<vector<string> > path(jum.size());

       tab[0]=1;
       minSteps[0]=0;
      minJumps[0]=0;
     path[0].push_back("0");
       for(int i=1;i<jum.size();i++)
       {
          
           for(int j=1;j<=jum[i];j++)
           {
               int k=i-j;
               if(k>=0)
                 {if(tab[k]!=0){minSteps[i]=min(minSteps[i],minSteps[k]+j);minJumps[i]=min(minJumps[i],minJumps[k]+1);}
                     tab[i]+=tab[k];
                      for(int tt=0;tt<path[k].size();tt++)
                              path[i].push_back(path[k][tt]+to_string(i));


                 }
                else
                break; 
           }
        
       }
    //Should Use DfS instead of this, memory Occpying
       cout<<minJumps[2]<<endl;
        for(int i=0;i<path[5].size();i++)
            cout<<path[5][i]<<endl;
       return tab[jum.size()-1];
   }


int main() {

    vector<int> dp(6,0); 
    vector<int> jum{0,2,1,0,3,3};
      cout<<stairTabul(jum);return 0;
   }

