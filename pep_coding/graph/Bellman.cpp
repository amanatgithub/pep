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
class BellEdge
{
    public:
     int u;
     int v;
     int w;
     BellEdge(int a,int b,int c)
     {
         u=a;
         v=b;
         w=c;
     }
};
void bellman(vector<vector<Edge> > &g,int src)
{
  vector<BellEdge> AllEdges;
  vector<int> res(g.size(),INT_MAX);
  res[src]=0;
  for(int i=0;i<g.size();i++)
   {
       for(int n=0;n<g[i].size();n++)
         AllEdges.push_back(BellEdge(i,g[i][n].n,g[i][n].w));
   }
   for(int j=0;j<g.size()-1;j++)
   for(int i=0;i<AllEdges.size();i++)
   {
     BellEdge be=AllEdges[i];
     if(res[be.v]>res[be.u]+be.w)
        res[be.v]=res[be.u]+be.w;
   }
   for(int i=0;i<res.size();i++)
    cout<<res[i];
}
int main() {
   vector<vector<Edge> >graph(4);
   graph[0].push_back(Edge(1,2));
   graph[0].push_back(Edge(3,8));
   graph[0].push_back(Edge(2,4));
   graph[1].push_back(Edge(2,1));
   graph[1].push_back(Edge(3,5));
   graph[2].push_back(Edge(3,1));
   //graph[3].push_back(Edge(1,1));
  // graph[4].push_back(Edge(3,-3));
   bellman(graph,0);
   return 0;
   

}

