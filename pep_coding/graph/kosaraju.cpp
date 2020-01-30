#include<bits/stdc++.h>

using namespace std;

 int kosaraju(int V, vector<int> adj[])
{
    stack<int> st;
    vector<int> res;
    vector<int> vis(V,0);
    vector<int> visR(V,0);
    vector<int> adjR[V];
    for(int i=0;i<V;i++)
    {
        for(int n=0;n<adj[i].size();n++)
        {
            adjR[adj[i][n]].push_back(i);
        }
    }
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
        {
            st.push(i);
            while(st.size()>0)
            {
                int top=st.top(); res.push_back(top);
                st.pop(); vis[top]=1;
                for(int j=0;j<adj[top].size();j++)
                {
                   if(vis[adj[top][j]]==0)
                     st.push(adj[top][j]);
                }
            
            }
        }
        
    }
    int temp=0;
while(st.size()>0) st.pop();
    for(int k=0;k<res.size();k++)
    {
        int t=res[k];
        if(visR[t]==0)
        {  temp++;
            st.push(t);
            while(st.size()>0)
            {
                int top=st.top(); 
                st.pop(); visR[top]=1;
                for(int j=0;j<adjR[top].size();j++)
                {
                   if(visR[adjR[top][j]]==0)
                     st.push(adjR[top][j]);
                }
            
            }
            
        }
    }
    return temp;
    
}
int main()
{
    int t;
    cin>>t;
   
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        vector<int> adj[a];
        int m,n;
        for(int i=0;i<b;i++)
          {
              cin>>m>>n;
              adj[m].push_back(n);
          }
          cout<<kosaraju(a,adj)<<" ";
    }
    return 0;
}
