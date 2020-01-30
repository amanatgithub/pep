#include <bits/stdc++.h>
using namespace std;
int getLog(int n)
{
    int x=0;
    while((1<<x)<n)
    x++;
    return x;
}
class Ip
{
    public:
      virtual int operation(int a,int b)=0;
      virtual int identity()=0;
};
class Sum : public Ip
{
   public:
     int operation(int a,int b)
      {return a+b;}
    int identity()
       {
           return 0;
       }
};
class Min : public Ip
{
   public:
     int operation(int a,int b)
      {return min(a,b);}
     int identity()
       {
           return INT_MAX;
       }
};
class stree
{
    private:
     int *oa;
     int oas;
     int *sa;
     int sas;
     Ip* ip;
    public:
     void build(int ss,int se,int ind)
      {
         if(ss==se)
          { sa[ind]=oa[ss]; return;
           }
         int mid=(ss+se)/2;
         build(ss,mid,2*ind+1);
         build(mid+1,se,2*ind+2);
         int l=sa[2*ind+1];
         int r=sa[2*ind+2];
         sa[ind]=ip->operation(l,r);
         
      }

      void update(int ss,int se,int ind, int idx, int val)
      {
          if(ss==se && idx==ss)
            { sa[ind]=val; return;}
          int mid=(ss+se)/2;
            if(idx>mid)
               update(mid+1,se,2*ind+2,idx,val);
             else
                  update(ss,mid,2*ind+1,idx,val); 
            int l=sa[2*ind+1];
         int r=sa[2*ind+2];
         sa[ind]=ip->operation(l,r);     
      }
     
     int query(int ss,int se, int qs, int qe, int ind)
     {
         if(ss>=qs && se<=qe)
           return sa[ind];
         else if(se<qs || ss>qe)
               return ip->identity();
          else
            {
                int mid=(ss+se)/2;
                int l=query(ss,mid,qs,qe,2*ind+1);
                int r=query(mid+1,se,qs,qe,2*ind+2);
                return ip->operation(l,r);
            }       
     }

      stree(int *oa,int oas,Ip* ip)
      {
         this->oa=oa;
         this->oas=oas;
         this->ip=ip;
         sas=getLog(oas)+1;
         sa=new int[(1<<(sas))-1];
         build(0,oas-1,0);

      } 

};
int main() {
    int *arr=new int[8]{2,5,-3,6,7,14,1,9};
    stree* st=NULL;
    int n=2;
    if(n==1)
    {
        Ip* ip=new Sum();
        st=new stree (arr,8,ip);
    }
    else
    {
        Ip* ip=new Min();
        st=new stree(arr,8,ip);
    }

   // stree st(arr,8);
   cout<< st->query(0,7,2,5,0)<<endl;
   st->update(0,7,0,2,17);
   cout<< st->query(0,7,2,5,0)<<endl;
   cout<< st->query(0,7,5,7,0)<<endl;



}

