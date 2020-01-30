#include<bits/stdc++.h>
using namespace std;
void rod(vector<int > & arr)
{
    vector<int> tab(arr.size()+1,INT_MIN);
    tab[0]=0;
    for(int i=1;i<tab.size();i++)
    { tab[i]=arr[i-1];
      for(int j=1;j<=i/2;j++)
      {   
          tab[i]=max(tab[j]+tab[i-j],tab[i]);

      }
    }
   for(int i=0;i<tab.size();i++)
    cout<<tab[i]<<" ";
}
int main() {
   vector<int> arr{3,5,6,15,10,25,12,24};

   rod(arr);
  return 0;

}
