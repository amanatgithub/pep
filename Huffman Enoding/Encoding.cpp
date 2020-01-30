#include<bits/stdc++.h>
using namespace std;
class Helper
{
    public:
     string c;
     int fr;
     Helper* left=NULL;
     Helper* right=NULL;
     string psf=" ";
     bool operator<(const Helper& o)const
     {
         return this->fr>o.fr;
     }
};
void encode(string s)
{
    unordered_map<char,Helper> map;
    for(int i=0;i<s.size();i++)
      {
          if(map.count(s[i])==1)
          map[s[i]].fr++;
          else
            {map[s[i]]=Helper(); map[s[i]].fr=1; map[s[i]].c=string(1,s[i]);}
      }

      priority_queue<Helper*> pq;
      for(auto i=map.begin();i!=map.end();i++)
      {
          pq.push(&i->second);
      }

      while(pq.size()>1)
      {
          Helper* r=pq.top();pq.pop();
          Helper* l=pq.top();pq.pop();
          Helper* n=new Helper();
          n->fr=l->fr+r->fr;
          n->c=l->c+r->c;
          n->left=l; n->right=r;
          pq.push(n);

      }
      list<Helper*> q;
      q.push_back(pq.top());
     // cout<<pq.top()->left->c;
      while(q.size()>0)
      {
          Helper* fr=q.front();
                    q.pop_front();
                   //cout<<fr.psf<<" ";
           if(fr->c.size()==1)
           {
               cout<<fr->c<<" "<<fr->psf<<" ";
               continue;
           }         
             {fr->left->psf=fr->psf+"0";q.push_back(fr->left);} 
           
            {fr->right->psf=fr->psf+"1";q.push_back(fr->right);}    
      }
}
int main()
{
    string s;
    cin>>s;
    encode(s);
}
