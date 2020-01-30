#include <bits/stdc++.h>
using namespace std;

int main() {
	// CODE MAY NOT BE RIGHT, CHECK FIRST
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int k;
	    cin>>n>>k;
	    vector<int> arr(2*n,0);
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	        arr[i+n]=arr[i];
	    }
	    vector<int> psum(2*n,arr[0]);
	    for(int i=0;i<2*n;i++)
	    {
	        psum[i]=psum[i-1]+arr[i];
	    }
	    
	    int j=0;
	    int maxx=arr[0]; int cs=arr[0];
	    for(int i=1;i<2*n;i++)
	    {
	        cs=cs>0?cs+arr[i]:arr[i];
	        if(cs>maxx)
	        {
	            j=i;
	            maxx=cs;
	        }
	    }
      //  cout<<maxx<<endl;
	    if(psum[n-1]<0)
	      cout<<maxx;
	    else
	    {
	        if(j>n-1)
	        {
	            cout<<(k-2)*psum[n-1]+maxx<<endl;
	        }
	        else
	        {
	           if(maxx>k*psum[n-1])
	              cout<<maxx<<endl;
	              else
	              cout<<k*psum[n-1]<<endl;
	        }
	    }
	    
	}
	return 0;
}

