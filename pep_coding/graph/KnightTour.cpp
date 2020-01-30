#include <bits/stdc++.h>
using namespace std;
int ct=0;
bool isSafe(vector<vector<int> > & vis,int i,int j,int n)
{
    if(i<0 || i>=n|| j<0||j>=n || vis[i][j] != 0)
     return false;
     return true;
}
void fun(int i,int j,int count,int n,vector<vector<int> > & vis)
{
  count++;
  vis[i][j]=count;
  
  if(count==n*n)
  {  ct++;
      cout<<"---------"<<ct<<"-----------"<<endl;
      for(int i=0;i<n;i++)
     {  for(int j=0;j<n;j++)
         cout<<vis[i][j]<<" ";
         cout<<endl;}
         cout<<endl<<endl;vis[i][j]=0;
  return;}
  
  
  if(isSafe(vis,i-1,j-2,n)) fun(i-1,j-2,count,n,vis);
  if(isSafe(vis,i-2,j-1,n)) fun(i-2,j-1,count,n,vis);
  if(isSafe(vis,i+1,j-2,n)) fun(i+1,j-2,count,n,vis);
  if(isSafe(vis,i+2,j-1,n)) fun(i+2,j-1,count,n,vis);
  if(isSafe(vis,i-1,j+2,n)) fun(i-1,j+2,count,n,vis);
  if(isSafe(vis,i-2,j+1,n)) fun(i-2,j+1,count,n,vis);
  if(isSafe(vis,i+1,j+2,n)) fun(i+1,j+2,count,n,vis);
  if(isSafe(vis,i+2,j+1,n)) fun(i+2,j+1,count,n,vis);
  vis[i][j]=0;
}
int main() {
     int n;
    n=5;
     vector<vector<int> > vis(n,vector<int> (n,0));
     
  fun(3,1,0,n,vis);
  return 0;
     
     


     
}

