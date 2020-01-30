#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    vector<vector<int> > tab(s.size(),vector<int>(s.size(),1));
    
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
    for(int i=0;i<tab.size();i++)
  {  for(int j=0;j<tab.size();j++)
   {   if(j>=i)
        cout<<tab[i][j]<<" ";
        else cout<<"  ";
    }  cout<<endl;}
    //cout<<tab[0][tab.size()-1];
    return 0;
}

