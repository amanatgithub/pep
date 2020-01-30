#include <bits/stdc++.h>
using namespace std;
class sq
{
    private:
    int *oa;
    int *sa;
    //vector<int> sa;
     int nob;
     int sob;
    public:
      sq(int arr[],int n)
      {
         sob=sqrt(n);
         nob=n/sob;
         oa=arr;
         sa=new int[nob];

         for(int i=0;i<n;i++)
         {
            sa[i/sob]+=oa[i];
         }
      }
      void update(int idx,int val)
      {
           int diff=val-oa[idx];
           oa[idx]=val;
           sa[idx/sob]+=diff;
      } 
      int query(int l,int r)
      {
          if(l/sob==r/sob)
          {  int sum=0;
             for(int i=l;i<=r;i++)
              sum+=oa[i];
              return sum;
          }
          else
          {
              int lbi=l/sob;
              int rbi=r/sob;
              int sum=0;
              for(int i=lbi+1;i<rbi;i++)
                sum+=sa[i];
             for(int i=l;i/sob==lbi;i++)
                sum+=oa[i];  
                 for(int i=r;i/sob==rbi;i--)
                sum+=oa[i];   
                return sum;
          }
      }
      int triv(int l,int r)
      {
          int sum=0;
          for(int i=l;i<=r;i++)
              sum+=oa[i];
              return sum;
      }
};
int main() {
   int arr[49];
   for(int i=0;i<49;i++)
    { arr[i]=rand()%49; cout<<arr[i]<<" ";}
    cout<<endl;
   sq temp(arr,49);
  cout<< temp.query(6,29)<<endl;
 cout<<  temp.triv(6,29)<<endl;
 temp.update(23,10);
 cout<< temp.query(6,29)<<endl;
 cout<<  temp.triv(6,29)<<endl;
}

