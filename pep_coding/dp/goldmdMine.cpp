#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> gold{{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};;
    vector<vector<int> > tab(gold.size(),vector<int>(gold[0].size(),0));
    
    for(int i=0;i<gold.size();i++)
      for(int j=gold[0].size()-1;j>=0;j--)
      {
          if(j==gold[0].size()-1)
            tab[i][j]=gold[i][j];
          else if(i==0)
            {
                tab[i][j]=max(tab[i][j+1],tab[i+1][j+1])+gold[i][j];
            }  
          else if(i==gold.size()-1)
          {
              tab[i][j]=max(tab[i][j+1],tab[i-1][j+1])+gold[i][j];
          }  
          else
             tab[i][j]=max(tab[i-1][j+1],max(tab[i][j+1],tab[i+1][j+1]))+gold[i][j];
      }
      int maxx=INT_MIN;
      for(int i=0;i<gold.size();i++)
        maxx=max(maxx,tab[i][0]);
     cout<<maxx;
     return 0;   

}

