#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,a; cin>>n;
    int l=0;
    int val;
  unordered_map<int,int> map;
  for(int i=0;i<n;i++)
  {
      cin>>a;
      map[a]=1;
     
  }
   
  for(auto itr=map.begin();itr!=map.end();itr++)
 {  int count=0; int a=itr->first;
 while(map.count(a-1)==1)
 {
     count+=map[a-1]; map.erase(a-1);
     a=a-1;
 } 
 a=itr->first;
  map[a]+=count;
  if(l<map[a])
  {
      l=map[a];val=a;
  }

 }
 while(l--)
 {
     cout<<val--<<" ";
 }


  

}

