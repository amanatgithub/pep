#include<bits/stdc++.h>
using namespace std;
void funcc(int arr[][n],int n)
{
  int i,j;
  j=0;
  for(i=0;i<n;i++)
  {
    k=i;
    while(arr[j][k]==0)
        k++;
    j=k;
  }
  for(int i=0;i<n;i++)
    if(arr[j][i]==1)
     return;
  int sum=0;
  for(int i=0;i<n;i++)
    if(arr[j][i]==1)
     sum++;
  if(sum==n-1)
    cout<<j;

}
int main()
{
 int arr[6][6]={{0,0,1,0,1,1},
                 {1,0,1,1,1,1},
                 {1,0,0,1,1,0},
                 {1,1,1,0,1,0},
                 {0,0,0,0,0,0},{1,0,1,1,1,0}};

       funcc(arr,6);
       return 0;








}
