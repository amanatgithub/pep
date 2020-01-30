#include <bits/stdc++.h>
using namespace std;


vector<int> lpsfind(string pat)
{
    vector<int> lps(pat.size(),0);
    int n=pat.size();
   int len=0;
    for(int i=1;i<n;)
    {
        if(pat[len]==pat[i])
        {
          len++;
          lps[i]=len;
          i++;
        }
        else
        {  if(len==0)
             {lps[i]=0; i++;}
             else
           len=lps[len-1];
        }
    }
  return lps;
}

void kmp(string s,string pat)
{
    int i=0,j=0;int n=s.size();
    vector<int> lps=lpsfind(pat);
   
    while(i<n)
    {
        if(s[i]==pat[j])
        {
            i++;
            j++;
            if(j==pat.size())
               {
                   cout<<"Find at "<<i-j<<endl;
                   j=lps[j-1];
               }
        }
        else
        {  if(j==0)
             i++;
            j=lps[j-1];
        }
     }
}
int main() {
    kmp("abcabcbccbaabccbbbccb","bccb");
    return 0;
}

