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
void floyd(vector<vector<Edge> > &fwg)
{
    vector<vector<int> > res(fwg.size(),vector<int> (fwg.size(),INT_MAX));
    for(int i=0;i<fwg.size();i++)
     for(int j=0;j<fwg[i].size();j++)
     {Edge ne=fwg[i][j];
        res[i][ne.n]=ne.w;
     }
     
     for(int i=0;i<fwg.size();i++)
     for(int s=0;s<fwg.size();s++)
     for(int d=0;d<fwg.size();d++)
     {
        if(i==s || i==d || s==d)
        continue;
        else if(res[s][i]==INT_MAX || res[i][d]==INT_MAX) continue;
        else
        { if(res[s][d]>res[s][i]+res[i][d])
            res[s][d]=res[s][i]+res[i][d];}
     }
     for(int s=0;s<fwg.size();s++)
    { for(int d=0;d<fwg.size();d++)
     {
         cout<<res[s][d]<<" ";
     }cout<<endl;}
}
int main()
{
    vector<vector<Edge> > fwg(4);
    fwg[0].push_back(Edge(1,2));
    fwg[0].push_back(Edge(2,4));
    fwg[0].push_back(Edge(3,8));
    fwg[1].push_back(Edge(2,1));
    fwg[1].push_back(Edge(3,5));
    fwg[2].push_back(Edge(3,1));
    floyd(fwg);
   

     return 0;
}


