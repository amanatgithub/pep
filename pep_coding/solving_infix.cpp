#include<bits/stdc++.h>
using namespace std;
int getPrior(char op)
{
 switch(op)
  {case '^' : return 3;
  case '/' : return 2;
  case '*' : return 2;
  case '+' : return 1;
  case '-' : return 1;
  case '(' : return -1;
  case ')'  : return -2;
  default : return 0;}
    }

    int cal(int a,int b,char op)
    {

 switch(op)
 { case '^' : return pow(a,b);
  case '/' : return a/b;
  case '*' : return a*b;
  case '+' : return a+b;
  case '-' : return a-b;}
    }
 int infixeval(string exp)
 {
     stack<char> os;
     stack<int> vs;
     int flag=0;
     for(int i=0;i<exp.size();i++)
     {
         if(getPrior(exp[i])==0)
           {  if(flag==0)
              vs.push(exp[i]-'0');
              else
              {   int a=vs.top();
                  vs.pop();
                  vs.push(a*pow(10,flag)+(exp[i]-'0'));
              }
              flag++;
           }
         else
         {
             if(getPrior(exp[i])!=-1)
             {while(os.size()>0 && os.top()!='(' && getPrior(os.top())>getPrior(exp[i]))
             {
                 int a=vs.top();
                   vs.pop();
                   int b=vs.top();
                   vs.pop();

           vs.push(cal(b,a,os.top()));
                   os.pop();

            }
             }
             if(os.size()>0 &&os.top()=='(' && exp[i]==')')
                    os.pop();

            if(exp[i]!=')')
                os.push(exp[i]);
                flag=0;

         }



     }
     while(os.size()>0)
{
  int a=vs.top();
                   vs.pop();
                   int b=vs.top();
                   vs.pop();
vs.push(cal(b,a,os.top()));
                   os.pop();
}
     return vs.top();
 }
int main()
{
 string s="10+2*13";

 cout<< infixeval(s);
return 0;

}
