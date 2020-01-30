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
class Dhelper
{
    public:
     int v;
     string path;
     int w;
     Dhelper(int a,string b,int c)
     {
         v=a;
         path=b;
         w=c;
     }
     bool operator>(const Dhelper& o) const{ return this->w>o.w;}
};
class Primhelper
{
    public:
     int v;
     int par;
     int w;
     Primhelper(int a,int b,int c)
     {
         v=a;
         par=b;
         w=c;
     }
     bool operator>(const Primhelper& o) const{ return this->w>o.w;}
};
class DijAns
{
    public:
      int w=0;
      string path="";
      
};
void addEdge(vector<vector<Edge> > & graph,int v1,int v2,int w)
{
    graph[v1].push_back(Edge(v2,w));
    graph[v2].push_back(Edge(v1,w));
}
void display(vector<vector<Edge> > & graph)
{
    for(int i=0;i<graph.size();i++)
    {   cout<<i<<"--> ";
        for(int j=0;j<graph[i].size();j++)
        {
            Edge e=graph[i][j];
            cout<<"("<<e.n<<"@"<<e.w<<") ";
        }
         cout<<endl;
    }
}
void dijikstra(vector<vector<Edge> > & graph,int s)
{
    priority_queue<Primhelper,vector<Dhelper>,greater<Dhelper> > pq;
    pq.push(Dhelper(s,to_string(s),0));
    vector<int> vis(graph.size(),0);
    vector<DijAns> result(graph.size());


    while(pq.size()>0)
    {
        Dhelper dij=pq.top();
        pq.pop();
        if(vis[dij.v]==0)
        {  vis[dij.v]=1;
            result[dij.v].w=dij.w;
        result[dij.v].path=dij.path;
        for(int i=0;i<graph[dij.v].size();i++)
            if(vis[graph[dij.v][i].n]==0)
              pq.push(Dhelper(graph[dij.v][i].n,dij.path+to_string(graph[dij.v][i].n),dij.w+graph[dij.v][i].w));
        }
}
for(int i=0;i<result.size();i++)
{
    cout<<i<<" "<< result[i].path <<" "<<result[i].w<<endl;

}
}
void prims(vector<vector<Edge> > & graph)
{
    priority_queue<Primhelper,vector<Primhelper>,greater<Primhelper> > pq;
    pq.push(Primhelper(0,-1,0));
    vector<int> vis(graph.size(),0);
    vector<vector<Edge> > res(graph.size());
    


    while(pq.size()>0)
    {
        Primhelper dij=pq.top();
        pq.pop();
        if(vis[dij.v]==0)
        {  vis[dij.v]=1;
            if(dij.par!=-1)addEdge(res,dij.v,dij.par,dij.w);
        for(int i=0;i<graph[dij.v].size();i++)
            if(vis[graph[dij.v][i].n]==0)
              pq.push(Primhelper(graph[dij.v][i].n,dij.v,graph[dij.v][i].w));
        }
}
display(res);

}




int main()
{
    vector<vector<Edge> > graph(7);
    addEdge(graph,0,1,20);
    addEdge(graph,1,2,10);addEdge(graph,2,3,20);addEdge(graph,0,3,40);addEdge(graph,4,3,2);addEdge(graph,4,5,3);addEdge(graph,5,6,3);addEdge(graph,4,6,8);
    
     
     prims(graph);
     return 0;
}


