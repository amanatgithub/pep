#include<bits/stdc++.h>
using namespace std;
template <class K,class V>
class Hmap
{
    private:
      int n;
      int N;
      class Hmnode
      {
          public:
            K key;
            V value;
            Hmnode(K k,V v)
            {
                key=k;
                value=v;
            }
           
      }
      list<Hmnode>* bucket;
      int getBucketInd(K key)
      {
          return abs(hash<K>()(key))%N;
      }
      list<Hmnode>::iterator getDataindex(int bi, K key)
      {
          for(auto itr=bucket[bi].begin();itr!=bucket[bi].end();itr++)
          {
              if(*itr==key)
                return itr;

          }
          return bucket[bi].end();
      }
    public:
      Hmap()
      {
          n=0;
          N=4;
        bucket=new list<Hmnode>[N];
      }
      int count(K key)
      {
          int bi=getBucketInd(key);
          auto itr=getDataindex(bi,key);
          if(itr==bucket[bi].end())
             return 0;
             else return 1;
          
      }
        

};
int main()
{
    int a=hash<string>()("aman");
    cout<<a;
}
