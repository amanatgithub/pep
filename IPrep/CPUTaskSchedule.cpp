#include<bits/stdc++.h>
using namespace std;
class Helper
{
    public:
      char c;
      int frq;
      Helper(char ch,int a)
      {
          c=ch; frq=a;
      }
      bool operator<(const Helper& o) const
      {
          return this->frq<o.frq;
      }
};
int main()
{   
    int n,k;
    cin>>k>>n;
    k++;//SEEEEEEEEEEEEEE THISSSSSSSSSSSSSSSSSSS
    unordered_map<char,int> map;
    char c;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        map[c]= (map.find(c)==map.end())?1:map[c]+1;
    }

    priority_queue<Helper> pq;
    for (unordered_map<char,int>::iterator it=map.begin(); it!=map.end(); ++it)
       {
           pq.push(Helper(it->first,it->second));
       }
    list<Helper> q;
    int count =0;
    while(pq.size()>0)
    {   int kk=k;
        while(pq.size()>0 && kk>0)
            {
                Helper fr=pq.top();
                           pq.pop();
                 if(fr.frq>1) q.push_back(Helper(fr.c,fr.frq-1));
                 count++;   
                 kk--;       
            }
            if(pq.size()==0 && q.size()>0) count+=kk;
            while(q.size()>0)
            {
                pq.push(q.front());
                q.pop_front();
            }
        
    }
    cout<<count;   
    return 0;
}
