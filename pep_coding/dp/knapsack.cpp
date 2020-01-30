#include <bits/stdc++.h>
using namespace std;
void knap(vector<vector<int> > & arr){
     vector<vector<int> > tab(arr[0].size()+1,vector<int>(7+1,0));
   for(int i=1;i<tab.size();i++)
   for(int j=1;j<tab[0].size();j++)
   {
       if(arr[0][i-1]<=j)
       {
           tab[i][j]=max(tab[i-1][j],arr[1][i-1]+tab[i-1][j-arr[0][i-1]]);
       }
       else
         tab[i][j]=tab[i-1][j];
   }

  cout<<tab[5][7];
}
void unbknap(vector<vector<int> > & arr)
{
    vector<int> tab(7+1,INT_MIN);
    tab[0]=0;
    for(int i=1;i<tab.size();i++)
    {
      for(int j=0;j<arr[0].size();j++)
      {
          if(i>=arr[0][j])
          {
              tab[i]=max(tab[i],tab[i-arr[0][j]]+arr[1][j]);
          }

      }
    }
    cout<<tab[7];
}
void fknap(vector<vector<int> > & arr){
     vector<vector<float> > tab(arr[0].size()+1,vector<float>(5+1,0.0));
   for(int i=1;i<tab.size();i++)
   for(int j=1;j<tab[0].size();j++)
   {
       if(arr[0][i-1]<=j)
       {
           tab[i][j]=max(tab[i-1][j],arr[1][i-1]+tab[i-1][j-arr[0][i-1]]);
       }
       else{
             tab[i][j]=max(tab[i-1][j]*1.0,(arr[1][i-1]/(arr[0][i-1]*1.0))*j );   }
        
   }

  cout<<tab[5][5];
}
int main() {
   vector<vector<int> > arr{{2,5,1,3,4},{15,14,10,45,30}};
   fknap(arr);
  return 0;

}

