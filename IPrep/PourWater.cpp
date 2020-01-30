#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input a heights array, v and k.
 // You have to return the resultant heights array.
 int left(vector<int>& h,int i,int prev)
 {    if(h[prev]>h[i])
         prev=i;
      if(i==0)
      {
          return prev;
      }
    
     if(h[i-1]>h[i])
           {  
               return prev;
           }
       else
       {
           return left(h,i-1,prev);
       }    
      
 }
  int right(vector<int>& h,int i,int prev)
 {   int n=h.size();
      if(h[prev]>h[i])
         prev=i;
     if(i==n-1)
      {
          return prev; 
      }
 
     if(h[i+1]>h[i])
           {    return prev;
           }
       else
       {
           return right(h,i+1,prev);
       }    
      
 }
  void display(vector<int> & arr) {
 
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }
 vector<int> pourWater(vector<int>& h, int v, int k) {
     // write your code here.
     int n=h.size();
     for(int i=0;i<v;i++)
     {   int flag=-1;
         if(k>0 && h[k-1]<=h[k])
            {
                flag=left(h,k-1,k-1);
                if(h[flag]<h[k])
                   h[flag]++;
                   else flag=-1;
                
            }
           if(flag==-1 && k<n-1 && h[k+1]<=h[k])  
             {
                 flag=right(h,k+1,k+1);
                 if(h[flag]<h[k])
                    h[flag]++;
                    else flag=-1;
                 
             }
           if(flag==-1)
          {
              h[k]=h[k]+1;
          }   
          display(h);
               
     }
      return h;

     
 }
 
 // function to display an array.

 
 int main(int argc ,char** argv){
     
     // Input for length of first array.
     int N;
     cin>>N;
 
     vector<int> arr1(N);
 
     // Input for array1 elements.
     for (int i = 0; i < N; i++) {
         cin>>arr1[i];
     }
 
     int V;
     cin>>V;
     int K ;
     cin>>K;
 
     vector<int> res;
     res= pourWater(arr1, V, K);
     display(res);
 
 }
