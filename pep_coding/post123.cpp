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
int cal(int a,int b,char c)
{
     switch(c)
    {
        case '^' : return pow(a,b);
        case '/' : return a/b;
        case '*' : return a*b;
        case '+'  : return a+b;
     case '-' : return a-b;
            
    }
}
void post123(string post)
{
    stack<int> eval;
    stack<string> inf;
    stack<string> pre;
    
    for(int i=0;i<post.size();i++)
    {
        if(post[i]>='0' && post[i]<='9')
        {
            eval.push(post[i]-'0');
        }
        else
          {
              int a=eval.top();eval.pop();
              int b=eval.top();eval.pop();
              eval.push(cal(b,a,post[i]));
          }
    }
    cout<<eval.top()<<endl;
     for(int i=0;i<post.size();i++)
      {
        if(post[i]>='0' && post[i]<='9')
        {  string a="";
           a+=post[i];
            inf.push(a);
        }
        else
          {
              string a=inf.top()+')';
              inf.pop();
              string b='('+inf.top();inf.pop();
               inf.push(b+post[i]+a);
          }
    }
    cout<<inf.top()<<endl;
    for(int i=0;i<post.size();i++)
      {
        if(post[i]>='0' && post[i]<='9')
        {  string a="";
           a+=post[i];
            pre.push(a);
        }
        else
          {
              string a=pre.top();
              pre.pop();
              string b=pre.top();pre.pop();
              string aa="";
              aa=post[i]+b+a;
               pre.push(aa);
          }
    }
    cout<<pre.top();
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
    cout<<ans<<endl;
    post123(ans);

}

int main(){
  string s="(8+2)/3+2^(1*1+3)";
  
  inftopost(s);
  return 0;
}
