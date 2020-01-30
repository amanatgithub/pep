#include<bits/stdc++.h>
using namespace std;
void ngeLeft(vector<int> &a)
{
stack<int> st;
vector<int> ans(a.size(),0);
for(int i=0;i<a.size();i++)
{
    while(st.size()>0 && a[st.top()]<a[i])
    {
      ans[st.top()]=i;
      st.pop();
    }
    st.push(i);
}
while(st.size()>0)
{
ans[st.top()]=-1;
st.pop();
}
for(int i=0;i<ans.size();i++)
    cout<<ans[i];
}
int main()
{
    vector<int> v{4,1,2,7,9,6,5,3,8};
    ngeLeft(v);
    return 0;
}
