#include<bits/stdc++.h>
using namespace std;
int main() {
    string s1,s2;
    cin>>s1>>s2;
    unordered_map<char,int> map1;
    unordered_map<char,int> map2;  ////RESTRICTION USE ONE HASH MAP
     for(int i=0;i<s1.size();i++)
   {
      map1[s1[i]]=map1.count(s1[i])==1?map1[s1[i]]+1: 1;
   }
    for(int i=0;i<s2.size();i++)
   {
      map2[s2[i]]=map2.count(s2[i])==1?map2[s2[i]]+1: 1;
   }
    for(auto itr=map1.begin();itr!=map1.end();itr++)
   {
       if(map2.count(itr->first)==1)
       cout<<itr->first<<" ";
    }
    cout<<endl;
    for(auto itr=map1.begin();itr!=map1.end();itr++)
   {
       if(map2.count(itr->first)==1)
       for(int i=0;i<min(itr->second,map2[itr->first]);i++)
       cout<<itr->first<<" ";
    }

}

