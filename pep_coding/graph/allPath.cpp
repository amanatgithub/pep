#include<bits/stdc++.h>
using namespace std;
int mini=INT_MAX;
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
void allPath(vector<vector<Edge> > & graph,int v1,int v2,vector<bool> &vis,string psf)
{   
    
    if(v1==v2)
     {cout<<psf<<v1<<endl;return;}
     vis[v1]=true;
     
     for(int i=0;i<graph[v1].size();i++)
     {
         Edge ne=graph[v1][i];
         if(vis[ne.n]==false)
           allPath(graph,ne.n,v2,vis,psf+to_string(v1));
     }
    vis[v1]=false;
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
    vector<vector<Edge> > graph(7);
    addEdge(graph,0,1,10);
    addEdge(graph,1,2,10);addEdge(graph,2,3,10);addEdge(graph,0,3,40);addEdge(graph,4,3,2);addEdge(graph,4,5,3);addEdge(graph,5,6,3);addEdge(graph,4,6,8);
    
     
display(graph);
vector<bool> vis(graph.size(),false);
string s="";
allPath(graph,0,6,vis,s);

     return 0;
}


