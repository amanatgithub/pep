#include<bits/stdc++.h>
using namespace std;
class stackk
{
    private: 
    int *data;
    int cap;
    int tos1;
    int tos2;
    public:
      stackk(int cap)
        {
            this->data=new int[cap];
            this->cap=cap;
            tos1=-1;
            tos2=cap;
        }
        void push1(int a)
        {
            if(tos1==tos2-1)
             { cout<<"Stack1 Overflow\n";
              return;}
              else
                tos1++;
                data[tos1]=a;
              
        }
        void push2(int a)
        {
            if(tos1==tos2-1)
             { cout<<"Stack2 Overflow\n";
              return;}
              else
                tos2--;
                data[tos2]=a;
              
        }
        void pop1()
        {
            if(tos1==-1)
              {
                  cout<<"Stack1 Underflow\n";
                  return;
              }
              else
              data[tos1]=0;
              tos1--;
        }
         void pop2()
        {
            if(tos2==cap)
              {
                  cout<<"Stack2 Underflow\n";
                  return;
              }
              else
              data[tos2]=0;
              tos2++;
        }
        int size1()
        {return tos1+1;}
        int size2()
        {return cap-tos2;}
        int top1()
        {
            if(tos1==-1)
              {
                  cout<<"Stack1 Empty\n";
                  return -1;
              }
              else
              return data[tos1];
        }
         int top2()
        {
            if(tos2==cap)
              {
                  cout<<"Stack2 Empty\n";
                  return -1;
              }
              else
              return data[tos2];
        }
        bool isEmpty1()
        {
            if(tos1==-1)
             return true;
             return false;
        }
         bool isEmpty2()
        {
            if(tos2==cap)
             return true;
             return false;
        }
};
int main()
{
    stackk s(5);
    s.push1(10);
    s.push1(20);
    s.push2(30);
    s.push2(40);
    s.push2(50);
    s.push2(1);
    cout<<s.top1()<<endl;
    cout<<s.top2()<<endl;
    s.pop1();
    s.pop2();
   cout<< s.top1()<<endl<<s.size1()<<endl;
    cout<<s.top2()<<endl<<s.size2();
    s.push2(60);
    s.push2(70);
    s.push2(2);
    cout<<s.top2();

  return 0;

}
