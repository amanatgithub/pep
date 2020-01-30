#include<bits/stdc++.h>
using namespace std;
class stackk
{
    private: 
    int *data;
    int cap;
    int tos;
    public:
      stackk(int cap)
        {
            this->data=new int[cap];
            this->cap=cap;
            tos=-1;
        }
        void push(int a)
        {
            if(tos==cap-1)
             { cout<<"Stack Overflow\n";
              return;}
              else
                tos++;
                data[tos]=a;
              
        }
        void pop()
        {
            if(tos==-1)
              {
                  cout<<"Stack Underflow\n";
                  return;
              }
              else
              data[tos]=0;
              tos--;
        }
        int size()
        {return tos+1;}
        int top()
        {
            if(tos==-1)
              {
                  cout<<"Stack Empty\n";
                  return -1;
              }
              else
              return data[tos];
        }
        bool isEmpty()
        {
            if(tos==-1)
             return true;
             return false;
        }
};
int main()
{
    stackk s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(1);
        s.pop();
       cout<< s.top()<<endl;
       cout<< s.size()<<endl<<s.isEmpty();
  return 0;

}
