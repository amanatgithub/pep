#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
   cin>>s;
  unordered_map<char,int> map;
 unordered_map<char,int>::iterator itr ;
 
  for(int i=0;i<s.size();i++)
   {
      map[s[i]]=map.count(s[i])==1?map[s[i]]+1: 1;
   }
  int maxx=0;
   char c;

  for(itr=map.begin();itr!=map.end();itr++)
   {
       if(itr->second>maxx)
         { c=itr->first; maxx=itr->second;}
    }
cout<<c<<endl;
return 0;

}
