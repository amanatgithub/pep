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
class KEdge
{  public:
    int u;
    int v;
    int w;
    KEdge(int a,int b,int c)
    {
        u=a;
        v=b;
        w=c;
    }
    bool operator>(const KEdge& o)const
    {
        return this->w>o.w;
    }
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
//merge() for merging two different subsets
void merge(vector<int> & pa,vector<int> & ra,int sl1,int sl2)
{
    if(ra[sl1]<ra[sl2])
    {
        pa[sl1]=sl2;
    }
    else
     if(ra[sl1]>ra[sl2])
        {pa[sl2]=sl1;}
     else
         {
             pa[sl2]=sl1;
             ra[sl1]++;
         }   
      
}
//find() gives leader of vertex
int find(vector<int> & pa,int v)
{
    if(pa[v]==v)
      return v;
    return find(pa,pa[v]);  
}
vector<vector<Edge> > krushkal(vector<vector<Edge> > & g)
{
    vector<vector<Edge> > mst(g.size());
    vector<int> pa(g.size());
    vector<int> ra(g.size(),1);
    for(int i=0;i<pa.size();i++)
      pa[i]=i;
    priority_queue<KEdge,vector<KEdge>,greater<KEdge> > pq;
    for(int i=0;i<g.size();i++)
    {
        for(int n=0;n<g[i].size();n++)
        {
            Edge ne=g[i][n];
            if(i<ne.n)
            {
                KEdge ke(i,ne.n,ne.w);
                pq.push(ke);
            }
        }
    }
    while(pq.size()>0)
    {
        KEdge rem=pq.top();
        pq.pop();
        int v1sl=find(pa,rem.u);
        int v2sl=find(pa,rem.v);
        if(v1sl!=v2sl)
       { merge(pa,ra,v1sl,v2sl); addEdge(mst,rem.u,rem.v,rem.w);
        //Counter can be used
       }
    }
    display(mst);  
}
int main()
{
    vector<vector<Edge> > graph(7);
    addEdge(graph,0,1,10);
    addEdge(graph,1,2,10);addEdge(graph,2,3,10);addEdge(graph,0,3,40);addEdge(graph,4,3,2);addEdge(graph,4,5,3);addEdge(graph,5,6,3);addEdge(graph,4,6,8);
    
   krushkal(graph);
     return 0;
}


