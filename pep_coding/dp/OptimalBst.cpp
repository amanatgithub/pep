#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr{5,7,8,17,20};
    vector<int> sum{0,4,11,16,17,19};
    vector<vector<int> > tab(arr.size(),vector<int>(arr.size(),0));

    for(int gap=0; gap<arr.size(); gap++)
    {
        for(int i=0, j=gap+i; j<arr.size(); i++,j++)
        {
            if(gap==0)
            {
                tab[i][j]=sum[j+1]-sum[j];
            }
            else
            {   int minn=INT_MAX;
                for(int k=0; k<=gap; k++)
                {
                    if(k==0)
                      minn=min(minn,tab[i+1][j]);
                    else if(k==gap)
                      minn=min(minn,tab[i][j-1]);
                    else minn=min(minn,tab[i][i+k-1]+ tab[i+k+1][j]);    
                }
                tab[i][j]=minn+sum[j+1]-sum[i];
            }
        }
    }
    for(int i=0;i<tab.size();i++)
    {
        for(int j=0;j<tab.size();j++)
         cout<<tab[i][j]<<" ";
         cout<<endl;
    }
    return 0;
}

