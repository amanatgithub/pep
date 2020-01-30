//NOT right Code, We should use List Bucket instead of Vector....
#include <bits/stdc++.h>
using namespace std;
template <class K,class V>
class HM
{
    public:
      int n;
      int N;
      class HMnode
      {
         public: 
            K key;
            V value;
          HMnode(){;}
                HMnode(K key,V value)
                {
                    this->key=key;
                    this->value=value;
                }  
      };
      vector<HMnode>* Bucket;
      HM()
      {
           N=4;
          n=0;
          Bucket=new vector<HMnode>[N];
      }
     int  getBucketIndex(K key)
     {
         int hc=  hash<K>()(key);
         
         
         return (abs(hc))%N;
     }
     int getDataIndex(int bi, K key)
     {
          vector<HMnode> temp=Bucket[bi];
          for(int i=0;i<temp.size();i++)
             if(temp[i].key==key)
                return i;
         return -1;       
     }
      int count(K key)
      {
          int bi=getBucketIndex(key);
          int ditr=getDataIndex(bi,key);
          if(ditr==-1)
            return 0;
            else return 1;
      }
      void rehash()
      {
      vector<HMnode>* old=Bucket;
      N=2*N;
     // n=0;
          Bucket=new vector<HMnode>[N];
          for(int i=0;i<N/2;i++)
          {
              for(int j=0;j<old[i].size();j++)
                {
                    HMnode temp=old[i][j];
                    int bi=getBucketIndex(temp.key);
                    Bucket[bi].push_back(temp);
                    
                }
          }
         
      }
      V& operator[](K key)
      {
          int bi=getBucketIndex(key);
          int ditr=getDataIndex(bi,key);
          if(ditr==-1)
          {
              Bucket[bi].push_back(HMnode(key,V()));
              n++;
              if(n*(1.0)/N>2.0)
              {
                  rehash();
                  bi=getBucketIndex(key);
                  ditr=getDataIndex(bi,key);
                return  Bucket[bi][ditr].value;
              } 
                    
                   else
              
               return Bucket[bi][Bucket[bi].size()-1].value;
          }
          else
          {
              //Bucket[bi][ditr]=HMnode(key,V());
              return Bucket[bi][ditr].value;
          }

          
      }
      void display()
      {
          for(int i=0;i<N;i++)
          {  cout<<i<<"---> ";
              for(int j=0;j<Bucket[i].size();j++)
                cout<<Bucket[i][j].key<<"----"<<Bucket[i][j].value<<"   ";
                cout<<endl;
          }
          
      }
};
int main() {
    HM<string, int> map;
    map["aman"]=2;
     map["a"]=2;
      map["an"]=2;
       map["man"]=2;
        map["b"]=2;
          map["c"]=2;
         map["d"]=2;
          map["e"]=2;
          map["zz"]=2;

         



  //  cout<<map.count("aman");
  map.display();

    
   // map["india"]=2;
   // cout<<map["india"];
}

