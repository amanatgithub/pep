#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
     int n;
     int w;
     Edge(int a,int b)
     {
         n=a;
         w=b;
     }
};
int temp=0;
void topo(vector<vector<Edge> > &graph, stack<int> & st,int top, vector<int> & vis,vector<int>  &stvis)
{
  
  vis[top]=1;
  stvis[top]=1;
  for(int i=0;i<graph[top].size();i++)
  {  if(stvis[graph[top][i].n]==1)
  temp=1;
      if(vis[graph[top][i].n]==0){
      
     topo(graph,st,graph[top][i].n,vis,stvis);}
    
  }  
   
 
  st.push(top);
  stvis[top]=0;
 
 
}

int main() {
   vector<vector<Edge> >graph(7);
    graph[0].push_back(Edge(1,1));
    graph[1].push_back(Edge(2,1));
    graph[2].push_back(Edge(3,1));
    graph[5].push_back(Edge(3,1));
    graph[6].push_back(Edge(5,1));
    graph[6].push_back(Edge(4,1));
    graph[0].push_back(Edge(4,1));
   
    stack<int> st;
    vector<int> vis(graph.size(),0);
    vector<int> stvis(graph.size(),0);
    for(int i=0;i<graph.size();i++)
     {   if(vis[i]==0)
         topo(graph,st,i,vis,stvis);
     }
     if(temp==0)
     {while(st.size()>0)
     {
         cout<<st.top()<<" ";
      st.pop();
     }}
     else 
     cout<<"Cycle Detect\n";
     return 0;
}
