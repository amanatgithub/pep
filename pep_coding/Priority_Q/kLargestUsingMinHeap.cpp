#include<bits/stdc++.h>
using namespace std;
int main()
{
    //k=4
    vector<int> arr{2,8,14,5,6,1,9,4,20,3,11};
    priority_queue<int,vector<int>,greater<int> > pq;
    pq.push(arr[0]);
    pq.push(arr[1]);
    pq.push(arr[2]);
    pq.push(arr[3]);
    
    for(int i=4;i<arr.size();i++)
    {
        if(pq.top()<arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
      cout<<pq.top();


}
