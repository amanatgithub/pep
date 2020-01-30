#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
   int data;
   Node* next;
   Node(int d)
   {
       data=d;
       next=NULL;
   }
};
int mod=1000000007;
void addLast(Node* & head,Node* & tail,int data)
{
    if(head==NULL)
    {
        head=tail=new Node(data);
    }
    else
      {
          tail->next=new Node(data);
          tail=tail->next;
      }
}

void rev(Node* & head)
{
    Node* cur=head;
    Node* p=NULL;

    while(cur!=NULL)
    {
        Node* n=cur->next;
        cur->next=p;
        p=cur;
        cur=n;
    }
    head=p;
}
void fun(Node* & head1,Node* & head2)
{   int ans,carry,zero,sol=0; int i=0;
    for(Node* cur1=head1; cur1!=NULL ; cur1=cur1->next)
    {   carry=0; zero=i;ans=0; int ten;
        for(Node* cur2=head2; cur2!=NULL ; cur2=cur2->next)
        {   
           int  val=cur2->data * cur1->data + carry;
            carry=val/10;  ten=1;
            for(int j=zero;j>0;j--)
              ten=(ten*10)%mod;
            ans=ans+(ten*(val%10))%(mod);
            zero++;
        }
            ans=(ans+(ten*10)%mod*(carry))%mod;
            sol=(sol%mod +ans%(mod))%mod;
            i++;
    }
    cout<<sol;
}
int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    Node* t1=NULL;
    Node* t2=NULL;
     int n,m,a;cin>>n;
     for(int i=0;i<n;i++)
     {
        cin>>a;
        addLast(head1,t1,a);
     }
     cin>>m;
     for(int i=0;i<m;i++)
     {
        cin>>a;
        addLast(head2,t2,a);
     }
     rev(head1);
     rev(head2);
     fun(head1,head2);
    return 0;
}
