#include <bits/stdc++.h>
using namespace std;
void showpath(vector<int> & arr,vector<vector<int> > & tab,string ans,int i ,int j)
{
 if(j==0)
   {if(i>0)for(int k=1;k<=i;k++)if(arr[k-1]==0){string s=ans+"0";reverse(s.begin(),s.end());cout<<s<<endl;break;}
    reverse(ans.begin(),ans.end());cout<<ans<<endl; return;}
  if(tab[i-1][j]==1)
    showpath(arr,tab,ans,i-1,j);
  if(tab[i-1][j-arr[i-1]]==1)
      showpath(arr,tab,ans+to_string(arr[i-1]),i-1,j-arr[i-1]);
}
int main() {
   vector<int> arr{0,2,5,3,1,6};
   vector<vector<int> > tab(arr.size()+1,vector<int>(9+1,0));
   for(int i=0;i<tab.size();i++)
     tab[i][0]=1;
 
    for(int i=1;i<tab.size();i++)
    {
        for(int j=1;j<tab[0].size();j++)
        {
            if(tab[i-1][j]==1)
               tab[i][j]=1;
            else {
                if(arr[i-1]>j)
                 tab[i][j]=0;
                 
                 else   tab[i][j]=tab[i-1][j-arr[i-1]];

            }   
        }
    }    
    for(int i=0;i<tab.size();i++)
    {
        for(int j=0;j<tab[0].size();j++)
         cout<<tab[i][j]<<" ";
         cout<<endl;
}

    if(tab[tab.size()-1][tab[0].size()-1]==1)
    showpath(arr,tab,"",tab.size()-1,tab[0].size()-1);


return 0;}

