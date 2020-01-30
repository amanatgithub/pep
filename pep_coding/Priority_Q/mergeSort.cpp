#include<bits/stdc++.h>
using namespace std;
class helper
{
    public:
     int r;
     int c;
     int val;
     helper(int a,int b,int c)
     {
         r=a;
         this->c=b;
         val=c;
     }
     bool operator<(const helper& o)const
     {
         return this->val>o.val;
     }
};
int main()
{
  vector<vector<int> > arr{{2,5,9,18,20,25},{3,7,8,15,22},{0,4,6,12},{1,10,16,21,28}};
   priority_queue<helper> pq;
   pq.push(helper(0,0,arr[0][0]));
   pq.push(helper(1,0,arr[1][0]));
   pq.push(helper(2,0,arr[2][0]));
   pq.push(helper(3,0,arr[3][0]));
   //cout<<pq.top().val;
   while(pq.size()>0)
   {
       helper fr=pq.top();
             pq.pop();
             if(fr.c+1<arr[fr.r].size())
               pq.push(helper(fr.r,fr.c+1,arr[fr.r][fr.c+1]));
               cout<<fr.val<<" ";
   }
  


}
