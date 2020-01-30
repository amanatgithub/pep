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
class BHelper
{
    public:
     int v;
     int lev;
    BHelper(int a,int b)
     {v=a;lev=b;}
};
void addEdge(vector<vector<Edge> > & graph,int v1,int v2,int w)
{
    graph[v1].push_back(Edge(v2,w));
    graph[v2].push_back(Edge(v1,w));
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
bool isBipartiteComponent(vector<vector<Edge> > &g,int sr,vector<int> &vis)
{
    list<BHelper> q;
    q.push_back(BHelper(sr,0));
    while(q.size()>0)
    {
        BHelper fr=q.front();
        q.pop_front();
        if(vis[fr.v]!=-1)
           {
                  if(vis[fr.v]%2!=fr.lev%2)
                    return false;
           }
           else
             vis[fr.v]=fr.lev;
        for(int i=0;i<g[fr.v].size();i++)
             {
                 if(vis[g[fr.v][i].n]==-1)
                   q.push_back(BHelper(g[fr.v][i].n,fr.lev+1));
             }

    }
    return true;
}
bool isBipartite(vector<vector<Edge> > &g)
{
   vector<int> vis(g.size(),-1);
    for(int i=0;i<g.size();i++)
    if(vis[i]==-1)
    if(isBipartiteComponent(g,i,vis)==false)
       return false;
    return true  ; 
    }
int main()
{
    vector<vector<Edge> > graph(3);
    // addEdge(graph,0,1,10);
    // addEdge(graph,1,2,10);addEdge(graph,2,3,10);addEdge(graph,0,3,40);addEdge(graph,4,3,2);addEdge(graph,4,5,3);addEdge(graph,5,6,3);addEdge(graph,4,6,8);
    
    //  graph.push_back(vector<Edge>());      // New Edge Added Later
    //  addEdge(graph,4,7,1);
    //  addEdge(graph,6,7,1);
    addEdge(graph,0,1,1);
     addEdge(graph,2,1,1);
      addEdge(graph,2,0,1);
       //addEdge(graph,,3,1);
     cout<<isBipartite(graph);
     return 0;
}


