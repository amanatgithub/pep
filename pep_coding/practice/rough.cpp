#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
     int n;
     int w;
     Edge(int a,int b)
     {n=a;w=b;}
};
void addEdge(vector<vector<Edge> > & graph,int v1,int v2,int w)
{
    graph[v1].push_back(Edge(v2,w));
    graph[v2].push_back(Edge(v1,w));
}
void bridgesandap(vector<vector<Edge> >& graph,vector<int>& vis, vector<int>& ap,vector<int>& discovery ,vector<int>& low,int src,int par)
{
  vis[src]=1;
  int counter=0;
  for(int i=0;i<graph[src].size();i++)
  {
      Edge ne=graph[src][i];
      if(vis[ne.n]==1 && ne.n==par)
      {
           continue;
      }
      else if(vis[ne.n]==1 && ne.n!=par)
      {
         low[src]=min(discovery[ne.n],low[src]);
      }
      else 
       {  counter++;
           discovery[ne.n]=discovery[src]+1;
           low[ne.n]=discovery[src]+1;
           bridgesandap(graph,vis,ap,discovery,low,ne.n,src);
         //  low[src]=min(low[src],low[ne.n]);
           if(src==0)
           {
               if(counter>=2)
                 ap[src]=1;
           }
           else
           {
               if(low[ne.n]>=low[src])
               ap[src]=1;
           }
           if(low[ne.n]>low[src])
             cout<<"Bridge from "<<src<<" to "<<ne.n<<endl;
             low[src]=min(low[src],low[ne.n]);

       }
  }
 
}
void display(vector<vector<Edge> > & graph)
{
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            Edge e=graph[i][j];
            cout<<"("<<e.n<<"@"<<e.w<<") ";
        }
         cout<<endl;
    }
}
int main()
{
    vector<vector<Edge> > graph(9);
    addEdge(graph,0,7,10);
    addEdge(graph,0,8,10);
    addEdge(graph,0,3,10);
    addEdge(graph,0,1,10);
    addEdge(graph,7,8,10);
    addEdge(graph,1,2,10);
    addEdge(graph,2,3,10);
    addEdge(graph,3,4,10);
    addEdge(graph,4,5,10);
    addEdge(graph,5,6,10);
    addEdge(graph,4,6,10);
    


  //  addEdge(graph,1,2,10);addEdge(graph,2,3,10);addEdge(graph,0,3,40);addEdge(graph,4,3,2);addEdge(graph,4,5,3);addEdge(graph,5,6,3);addEdge(graph,4,6,8);
    
     
     vector<int> vis(graph.size(),0);
     vector<int> ap(graph.size(),0);
     vector<int> discovery(graph.size(),0);
     vector<int> low(graph.size(),0);
     bridgesandap(graph,vis,ap,discovery,low,0,-1);

    for(int i=0;i<ap.size();i++)
      if(ap[i]==1)
        cout<<i<<" ";
     return 0;
}

