#include<bits/stdc++.h>
using namespace std;
int t=0;
int main()
{
 string s;
 int c;
 cin>>c;
 while(c!=0)
 {
 t=0;
 cin>>s;
   s+='i';
 stack<int> st;
t++;
 st.push(t);
 for(int i=0;i<s.size();i++)
 {

   if(s[i]=='i')
   {
     while(st.size()>0)
     {
         cout<<st.top();
         st.pop();
     }

    }
   t++;
   st.push(t);
 }
 cout<<endl;
c--;
 }
return 0;
}
