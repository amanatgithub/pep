#include <bits/stdc++.h>
using namespace std;
int a[]={9,8,7};
int b[]={6,5,4,3,2,1};

int gett(int i,int n,int m)
{
    if(i>n-1)
    {
        return b[i-n];
    }
    else
       return  a[i];
}
void sett(int i,int val,int n,int m)
{
    if(i>n-1)
       b[i-n]=val;
     else
        a[i]=val;  
}
void downHeapify(int ind,int size,int n,int m)
{
    int l=2*ind+1;
    int r=2*ind+2;
    int h=ind,val,lval,rval;
    if(l<size && gett(l,n,m)>gett(h,n,m))
       h=l;
    if(r<size && gett(r,n,m)>gett(h,n,m))
       h=r;
    if(ind!=h)
    {
        int a=gett(ind,n,m);
        sett(ind,gett(h,n,m),n,m);
        sett(h,a,n,m);
        downHeapify(h,size,n,m);  
    }      
  
       
}
void heapSort(int n,int m)
{
    for(int i=(n+m)/2-1;i>=0;i--)
    {
        downHeapify(i,n+m,n,m);
    }
    for(int i=n+m-1;i>=0;i--)
    {
        if(i>n-1)
        {
            swap(a[0],b[i-n]);
        }
        else
           swap(a[0],a[i]);
        downHeapify(0,i,n,m);
    }
}
int main() {
    heapSort(3,6);
    for(int i=0;i<=2;i++)
     cout<<a[i]<<" ";
     cout<<endl;
     for(int i=0;i<=5;i++)
     cout<<b[i]<<" ";

}

