#include <bits/stdc++.h>
using namespace std;
void minCost(vector<vector<int> >& mat)
{
vector<vector<int> > tab(mat.size(),vector<int>(mat[0].size(),-1));
int sum=0;
for(int i=mat.size()-1;i>-1;i--)
   { sum+=mat[i][mat[0].size()-1];tab[i][mat[0].size()-1]=sum;}
  sum=0;
    for(int i=mat[0].size()-1;i>-1;i--)
   { sum+=mat[mat.size()-1][i];tab[mat.size()-1][i]=sum;}
for(int i=mat[0].size()-2;i>-1;i--)
   for(int j=mat.size()-2;j>-1;j--)
   { 
       tab[i][j]=min(mat[i+1][j],mat[i][j+1]);
       tab[i][j]+=mat[i][j];
   }
cout<<tab[5][0];
}

void minCostSir(vector<vector<int> >& mat)
{
  vector<vector<int> > tab(mat.size(),vector<int>(mat[0].size(),-1));
   for(int i=mat.size()-1;i>-1;i--)
     for(int j=mat[0].size()-1;j>-1;j--)
      {  if(i==mat.size()-1 && j==mat[0].size()-1)
             tab[i][j]=mat[i][j];
        else if(i==mat.size()-1)
              tab[i][j]=mat[i][j]+tab[i][j+1]; 
        else if(j==mat[0].size()-1)
              tab[i][j]=mat[i][j]+tab[i+1][j];
       else 
            tab[i][j]=min(tab[i][j+1],tab[i+1][j])+mat[i][j];


    }
cout<<tab[0][0];
  
  
}


int main() {
  //rectangular matrix
     vector<vector<int> > mat{{2,6,5,1,3,4},{0,4,9,2,9,0},{4,8,1,0,6,5},{0,3,3,1,5,4},{1,2,7,0,6,9},{5,7,1,3,8,2}};
     minCostSir(mat);
     return 0;
   }

