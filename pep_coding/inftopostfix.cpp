#include<bits/stdc++.h>
using namespace std;
int getPrio(char op)
{
    switch(op)
    {
        case '^' : return 3;
        case '/' : return 2;
        case '*' : return 2;
        case '+'  : return 1;
            case '-' : return 1;

    }
}

void inftopost(string exp)
{
    string ans="";

    stack<char> st;
    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
            ans+=exp[i];
        else if(exp[i]=='(') st.push(exp[i]);
         else


             if(exp[i]==')')
               { while(st.top()!='(')
                {
                  ans+=st.top();
                  st.pop();
                 } st.pop();}
         else
              {

                while(st.size()>0 && st.top()!='(' && getPrio(st.top())>=getPrio(exp[i]))
                {
                    ans+=st.top();
                    st.pop();
                }

                st.push(exp[i]);
              }
    }
    while(st.size()>0)
    {ans+=st.top();st.pop();}
    cout<<ans;
}
int main(){
  string s="(8+2)/3+2^(1*1+3)";

  inftopost(s);
  return 0;
}
