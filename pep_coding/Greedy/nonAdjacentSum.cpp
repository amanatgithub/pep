#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr{5,6,10,100,10};
    vector<vector<int> > tab(arr.size(),vector<int>(2,0));
    tab[0][0]=arr[0];
    tab[0][1]=0;
    for(int i=1;i<tab.size();i++)
    { 
      tab[i][1]=max(tab[i-1][0],tab[i-1][1]);
      tab[i][0]=tab[i-1][1]+arr[i];  
    }

    cout<<max(tab[tab.size()-1][0],tab[tab.size()-1][1]);
    return 0;
}

