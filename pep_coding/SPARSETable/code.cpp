#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > tab;
vector<int> diff;
int getLog(int n)
{
    int x=0;
    while((1<<(x))<=n)
     x++;
     return x-1;
}
void build(vector<int> & arr)
{  int row=arr.size();
   int col=getLog(arr.size())+1;
   tab=vector<vector<int> >(row,vector<int>(col,0));
   diff=vector<int>(row+1,0);
   for(int i=1;i<diff.size();i++)
   {
       diff[i]=getLog(i);
   }

   for(int i=0;i<col;i++)
   {
       for(int j=0;j<row;j++)
       {
           if(i==0)
             tab[j][i]=arr[j];
           else
           {
               if(j+(1<<(i-1))<row)
               {
                   tab[j][i]=min(tab[j][i-1],tab[j+(1<<(i-1))][i-1]);
               }
           }
             
       }
   }
}
void query(int l,int r)
{
   int a=diff[r-l+1];
   cout<<min(tab[l][a],tab[r-(1<<(a))+1][a])<<endl;
}
int  main()
{  
    vector<int> arr{2,4,-1,6,8,-4,7,12,5,4,9,3,20,16,4,11};
    build(arr);
    query(3,14);

    query(0,0);
    query(0,15);
    return 0;



}