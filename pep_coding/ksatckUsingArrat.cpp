#include<bits/stdc++.h>
using namespace std;
class kstack
{
    private: 
     int *data;
     int *st; //Contains Stack Header
     int fr;
     int *ptr;
     int cap; 
    public:
      kstack(int cap,int k)
        {
            this->data=new int[cap];
            this->ptr=new int[cap];
            this->st=new int[k];
            fr=0;
            this->cap=cap;
            for(int i=0;i<cap;i++)
             { ptr[i]=i+1; data[i]=0;}
              ptr[cap-1]=-1;
              for(int i=0;i<k;i++)
              {st[i]=-1;}
        }
        bool isFull()
        {
            return this->fr==-1;
        }
        bool isEmpty(int s)
        {
            return st[s]==-1;
        }
        void push(int val,int s)
        {
            if(isFull())
               {cout<<"Stack Overflow\n";return;}
            else
            {
                int a=fr;
                fr=ptr[fr];
                data[a]=val;
                ptr[a]=st[s];
                st[s]=a;
           }   
        }
        void pop(int s)
        {
            if(isEmpty(s))
              {cout<<"Stack "<<s<<" Underflow\n";return;}
              else{
                  
                  int a=st[s]; st[s]=ptr[a];
                  
                  ptr[a]=fr;
                  fr=a; data[a]=-1;
                  }
        }
        int top(int s)
        {if(isEmpty(s))
           {cout<<"Stack "<<s<<" Underflow\n";return -1;}
           else
             return data[st[s]];
        }
        void printt(int s)
        { int a=st[s];
            while(a!=-1)
            {cout<<data[a];
            a=ptr[a];}}
                    
             
};
int main()
{
   
   kstack stt(8,2);
   stt.push(0,0);
   stt.push(1,1);
   stt.push(2,1);
   stt.push(3,0);
   stt.push(7,0);
   stt.push(4,1);
   cout<<stt.top(0)<<endl;
   stt.pop(0);
   stt.printt(0);
  
  return 0;

}
