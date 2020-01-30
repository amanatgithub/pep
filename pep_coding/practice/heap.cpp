#include<bits/stdc++.h>
using namespace std;
template <class T>
class Pq
{
   private:
    vector<T> list;
    bool (*comp)(const T& o1,const T& o2);
    void swap(int t1,int t2)
    {
         T temp=list[t1];
         list[t1]=list[t2];
         list[t2]=temp;
    }
    bool isHp(int t1,int t2)
    {
        if(comp==NULL)
        {
            return list[t1]<list[t2];
        }
        else
        {
            return comp(list[t1],list[t2]);
        }
        
    }
    void upheapify
   public: 
   Pq()
   {
       this->comp=NULL;
   }
   Pq(bool (*comp)(const T& o1,const T& o2))
   {
       this->comp=comp;
   }
   void push(T t)
   {
       list.push_back(t);
       upheapify(size()-1);
   }
   void pop()
   {
       swap(list[0],list[size()-1]);
       list.pop_back();
       downheapify(0);
   }
   int size()
   {
       return list.size();
   }

};