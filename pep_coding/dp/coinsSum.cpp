#include <bits/stdc++.h>
using namespace std;
class helper
{
    public:
     int ind;
     string s;
     helper(int a,string b)
     {
         ind=a;
         s=b;
     }
};

void permShow(int n,vector<int> & coins, vector<int> & tab)
{
  if(tab[n]==0) return;
  list<helper> q;
  q.push_back(helper(tab.size()-1,""));
  while(q.size()>0)
  {
      helper fr=q.front();
      q.pop_front();
      if(fr.ind==0)
       {cout<<fr.s<<endl;continue;}
      for(int j=0;j<coins.size();j++)
      {
         if(fr.ind>=coins[j] && tab[fr.ind-coins[j]]>0)
           q.push_back(helper(fr.ind-coins[j],fr.s+to_string(coins[j])));
           
      }


  }

  
}
void perm(int n,vector<int> & coins)
{
    vector<int> tab(n+1,0);
    tab[0]=1;
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<coins.size();j++)
         if(i>=coins[j]) tab[i]+=tab[i-coins[j]];
    }
   cout<<tab[n]<<endl;
   permShow(n,coins,tab);
}
void comb(int n,vector<int> & coins)
{
    vector<int> tab(n+1,0);
    tab[0]=1;
    for(int j=0;j<coins.size();j++)
    {
      for(int i=1;i<n+1;i++)
      {
          if(i>=coins[j]) tab[i]+=tab[i-coins[j]];
      }
    }
  cout<<tab[n];
}
int main() {
   vector<int> coins{2,3,5,6};
   perm(7,coins);
   cout<<endl;
   comb(7,coins);
   
        


return 0;}

