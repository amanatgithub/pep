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
    
     graph.push_back(vector<Edge>());      // New Edge Added Later
     addEdge(graph,4,7,1);
     addEdge(graph,6,7,1);
display(graph);
     return 0;
}


