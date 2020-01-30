#include <bits/stdc++.h>
using namespace std;
class Helper{
    public:
    int n;
    string path;
    Helper(int a,string s)
    {
        n=a;
        path=s;
    }
};
void displayPath(vector<int> &arr,vector<int>& lisEndingWithI,int n)
{
   list<Helper> q;
   q.push_back(Helper(n,to_string(arr[n])+" "));
   while(q.size()>0)
   {
       Helper fr=q.front();
       q.pop_front();
       if(lisEndingWithI[fr.n]==1)
       {
           cout<<fr.path<<endl;
           continue;
       }
       for(int i=fr.n-1;i>=0;i--)
       {
           if(lisEndingWithI[i]==lisEndingWithI[fr.n]-1 && arr[i]<arr[fr.n])
           q.push_back(Helper(i,fr.path+to_string(arr[i])+" "));
           }

   }
}
int main() {
    vector<int> v{10,22,9,33,21,50,41,60,80,1};
    vector<int> lisEndingWithI(v.size(),1);
    int maxx=INT_MIN;
    int ind;
    for(int i=1;i<v.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            lisEndingWithI[i]=v[j]<v[i]?max(lisEndingWithI[i],lisEndingWithI[j]+1):lisEndingWithI[i];
        }
        if(maxx<lisEndingWithI[i])
          {
              ind=i;
              maxx=lisEndingWithI[i];
          }
    }
    for(int i=0;i<lisEndingWithI.size();i++)
     cout<<lisEndingWithI[i]<<" ";
     cout<<endl;

     displayPath(v,lisEndingWithI,ind);
     return 0;


}

