#include<bits/stdc++.h>
using namespace std;
int getLog(int n)
{
    int x=0;
    while((1<<x)<n)
     x++;
     return x;
}
class Lazy
{
    private:
      int* oa;
      int oas;
      int *sa;
      int sas;
      int *la;
    public:
    Lazy(int arr[],int n)
    {
       oa=arr;
       sas=(1<<(getLog(n)+1))-1;
       sa=new int[sas];
       la=new int[sas];
       build(0,n-1,0);
    }
    void build(int ss,int se,int si)
    {   la[si]=0;
        if(ss==se)
        {
            sa[si]=oa[ss];
            return;
        }
        else
        {
            int mid=(ss+se)/2;
            build(ss,mid,2*si+1);
            build(mid+1,se,2*si+2);
            sa[si]=sa[2*si+1]+sa[2*si+2];

        }
        
    }
    void update(int qs,int qe,int ss,int se, int si, int delta)
    {  //important
        handlePendingWork(ss, se, si);
        if(ss>=qs && se<=qe)
        {
            la[si]+=delta; //la[si]=delta also
            handlePendingWork(ss, se, si);
            return;
        }
        else if(se<qs || qe<ss)
           {
               return;
           }
        else
        {   int mid=(ss+se)/2;
            update(qs,qe,ss,mid,2*si+1,delta);
            update(qs,qe,mid+1,se,2*si+2,delta);
            sa[si]=sa[2*si+1]+sa[2*si+2];
        }   
    }
    int query(int qs,int qe,int ss,int se, int si)
    {  //important
        handlePendingWork(ss, se, si);
        if(ss>=qs && se<=qe)
        {
           return sa[si];
        }
        else if(se<qs || qe<ss)
           {
               return 0;
           }
        else
        {   int mid=(ss+se)/2;
           int l= query(qs,qe,ss,mid,2*si+1);
           int r= query(qs,qe,mid+1,se,2*si+2);
            return l+r;
        }   
    }
    void handlePendingWork(int ss,int se,int si)
    {
        sa[si]+=(se-ss+1)*la[si];
        la[2*si+1]+=la[si];
        la[2*si+2]+=la[si];
        la[si]=0;
    }

};
int main()
{
   int* arr=new int[8]{2,5,-3,6,7,4,1,9};
   Lazy lt(arr,8);
   lt.update(2,5,0,7,0,2);
   lt.update(1,4,0,7,0,1);
   cout<<lt.query(3,3,0,7,0);
   cout<<lt.query(4,4,0,7,0);
   cout<<lt.query(5,5,0,7,0);
   

   return 0;
}