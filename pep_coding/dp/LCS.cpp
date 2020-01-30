#include <bits/stdc++.h>
using namespace std;
class Helper{
    public:
    int i,j;
    string path;
    Helper(int a,int b,string s)
    {
        i=a;
        path=s;
        j=b;
    }
};
void displayPath(vector<int> &s1,vector<int>& s2,vector<vector<int>> &tab)
{
list<Helper> q;
int i=4,j=4;
while(s1[i-1]!=s2[j-1])
{
   if(tab[i][j-1]>tab[i-1][j])
      j--;
      else
       i--;
}
q.push_back(Helper(i-1,j-1,to_string(s1[i-1])));
while(q.size()>0)
{
    Helper fr=q.front();
    q.pop_front();
    i=fr.i;
    j=fr.j;
    if(i==0 &&j==0)
     {
         cout<<fr.path<<endl;continue;
     }
    while(s1[i-1]!=s2[j-1])
    {
    if(tab[i][j-1]==tab[i-1][j]) q.push_back(Helper(i,j-1,fr.path));
   if(tab[i][j-1]>tab[i-1][j])
      j--;
      else
       i--;
    }
    q.push_back(Helper(i-1,j-1,fr.path+to_string(s1[i-1])));
}
}

int main() {
    vector<int> s1{1,2,3,4};
    vector<int> s2{1,3,2,4};
    vector<vector<int> > tab(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=1;i<tab.size();i++)
    for(int j=1;j<tab[0].size()+1;j++)
    {
        if(s1[i-1]==s2[j-1])
        {
            tab[i][j]=tab[i-1][j-1]+1;

        }
        else
        tab[i][j]=max(tab[i-1][j],tab[i][j-1]);
    }
    cout<<tab[4][4]<<endl;    
    displayPath(s1,s2,tab); return 0;


}

