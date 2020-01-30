#include <bits/stdc++.h>
using namespace std;
class pq
{
  private: 
    vector<int> arr;
    bool type;
    void swap(int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    bool isHp(int i,int j)
    {
        if(type)
        {
            return arr[i]<arr[j];
        }
        else
          return arr[i]>arr[j]; //MAX HEAP
    }
    void upHeapify(int i)
    {
        if(i==0) return;
        int p=(i-1)/2;
        if(isHp(i,p)==true)
        {
            swap(i,p);
            upHeapify(p);
        }

    }
    void downHeapify(int i)
    {
        int li=2*i +1;
        int ri= 2*i + 2;
        int hp=i;
        if(li<arr.size() && isHp(li,hp)==true)
        {
             hp=li;
        }
        if(ri<arr.size() && isHp(ri,hp)==true)
        {
             hp=ri;
        }
        if(hp!=i)
        {
            swap(hp,i);
            downHeapify(hp);
        }
    }
    public:
       pq(bool type)
       {
           this->type=type;
       }
       int top()
       {    if(arr.size()!=0)
           return arr[0];
           else return -1;
       }
       void push(int k)
       {
           arr.push_back(k);
           upHeapify(arr.size()-1);
       }
       void pop()
       {
           swap(0,arr.size()-1);
           arr.pop_back();
            downHeapify(0);
       }
       int size()
       {
           return arr.size();
       }
};
int main() {
    pq p(false);
    p.push(1);
    p.push(10);
    p.push(2);
    p.push(88);
    p.push(23);
    p.pop();
    p.pop();
    while(p.size()>0)
  {
      cout<<p.top()<<" ";
      p.pop();
  }
    


}

