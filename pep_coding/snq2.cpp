//NGE right
#include<bits/stdc++.h>
using namespace std;
int main()
{
 stack<int> st;
 stack<int> ans;
 int arr[10];
 int n,i;
 cin>>n;
 for(i=0;i<n;i++)
    cin>>arr[i];
 for(i=n;i>0;i--)
 {
     while(st.size()>0)
     {
         if(arr[i-1]>arr[st.top()])
            st.pop();
         else break;
     }
     if(st.size()==0)
        ans.push(-1);
     else
        ans.push(st.top()+1);
     st.push(i-1);
 }
 while(ans.size()>0)
 {cout<<ans.top();ans.pop();}
 return 0;
}
