#include <bits/stdc++.h>
using namespace std;
int main() {
  
    vector<int > v{10,20,30,40,50,60};
    vector<vector<int> > tab(v.size()-1,vector<int>(v.size()-1,0));
    
    
    

//No need to use previous function, But here used
       for(int gap=0;gap<tab.size();gap++)
    {
        for(int i=0,j=i+gap;j<tab.size();i++,j++)
        {    
            if(gap==0)
              tab[i][j]=0;
              else if(gap==1)
              {
                  tab[i][j]=v[j-1]*v[j]*v[j+1];
              }
              
              
               else
               {  int minn=INT_MAX;///BEST
                  for(int k=0;k<gap;k++)
                 {
                  minn=min(minn,tab[i][k+i]+tab[i+k+1][j]+v[k+i+1]*v[i]*v[j+1]);
                 }
                tab[i][j]=minn;
                }
        }
    }
    for(int i=0;i<tab.size();i++)
    {
        for(int j=0;j<tab.size();j++)
        {
            if(tab[i][j]==0)
              cout<<"  ";
              else 
              cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
// cout<<tab[0][tab.size()-1];
    return 0;
}

