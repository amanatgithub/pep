#include<bits/stdc++.h>
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
bool isCyclicComponent(vector<vector<Edge>> &g,int s,vector<int> &vis)
{
    list<int> q;
    q.push_back(s);
    while(q.size()>0)
    {
        int fr=q.front();
        q.pop_front();
        if(vis[fr]==1)
           return true;
           else vis[fr]=1;
           {
               for(int i=0;i<g[i].size();i++)
                 {
                     Edge ee=g[s][i];
                     if(vis[ee.n]==0)
                      q.push_back(ee.n);
                 }
           }
    }
    return false;
}
int getAstroComponent(vector<vector<Edge>> &g,int s,vector<int> &vis)
{
     list<int> q;
     int countt=0;
    q.push_back(s);
    while(q.size()>0)
    {
        int fr=q.front();
        q.pop_front();
        if(vis[fr]==1)
           continue;
           else vis[fr]=1;
           countt++;
               for(int i=0;i<g[fr].size();i++)
                 {  
                     Edge ee=g[fr][i];
                     if(vis[ee.n]==0)
                      q.push_back(ee.n);
                 }
}
return countt;
}
int astronaut(vector<vector<Edge>> &g)
{
    vector<int> vis(g.size(),0);
    vector<int> ans;
    for(int i=0;i<g.size();i++)
    {
        if(vis[i]==0)
          {ans.push_back(getAstroComponent(g,i,vis));}
    }
    int result=0;
    int i=ans.size()-1;
    while(i>0)
    {
        
        
        for(int j=i-1;j>-1;j--)
        {
            result+=ans[i]*ans[j];
        }
        i--;
    }
    return result;
}
void addEdge(vector<vector<Edge> > & graph,int v1,int v2,int w)
{
    graph[v1].push_back(Edge(v2,w));
    graph[v2].push_back(Edge(v1,w));
}
int main()
{ 

    vector<vector<int> > v{{1,6,8,2,9,10,0},{2,9,3,5,5,3,11}};
    vector<vector<Edge> > graph(12);
    for(int i=0;i<v[0].size();i++)
       {
           addEdge(graph,v[0][i],v[1][i],1);
       }
       cout<<astronaut(graph);
       return 0;

}
