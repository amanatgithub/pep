#include <bits/stdc++.h>
using namespace std;
//CHECK MAY BEEEEEEEEE WRONGGGGGGGGGGG
vector<int> arr{9,3,4,1,2,5,8,7,6};
int partition(int l,int h)
{
    int i=0,j=0;
    
    while(j<=h)
    {
        if(arr[j]>arr[h])
            j++;
          else
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j++;
            }  
    }
    return i-1;
}
int quickselect(int l,int h, int k)
{
    int i=partition(l,h);
    if(i-l+1==k)
    {
        return arr[i];
    }
    if(k<i-l+1)
    {
      return  quickselect(l,i-1,k);
    }
    else
       return quickselect(i+1,h,k-i+l-1);

}
int main() {

   cout<< quickselect(0,arr.size()-1,3);

}

