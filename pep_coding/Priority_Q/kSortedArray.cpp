#include<bits/stdc++.h>
using namespace std;
int main()
{
    //k=4
    vector<int> arr{20,40,10,30,50,80,60,90,70,120,110,100};
    priority_queue<int,vector<int>,greater<int> > pq;
    int k=2;
    pq.push(arr[0]);
    pq.push(arr[1]);
    pq.push(arr[2]);
    cout<<pq.top()<<" ";
    pq.pop();
    
    for(int i=3;i<arr.size();i++)
    {
        pq.push(arr[i]);
        cout<<pq.top()<<" ";
        pq.pop();
    }
    while(pq.size()>0)
    {
         cout<<pq.top()<<" ";
        pq.pop();
    }
      


}
