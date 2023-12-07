//bestfit;
#include<bits/stdc++.h>
using namespace std;
#define tab "\t"
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>block(m),process(n);
    vector<bool>used(m,false);
    vector<int>ans(n,0);
    for(auto &i:block)cin>>i;
    for(auto &it:process)cin>>it;
    int allocated=0;
    int ind=0;
    while(allocated!=n)
    {
      int best=INT_MAX;
      int pos=-1;
      for(auto i=0;i<m;i++)
      {
         if(process[ind]<=block[i] and !used[i])
         {
            if(best>block[i])
            {
               best=block[i];
               pos=i;
            }
         }

      }
      
      if(pos!=-1)
      {
         used[pos]=true;
         allocated++;
         ans[ind]=pos+1;
         ind++;
      }

    }
    cout<<"P.No"<<tab<<"p.size"<<tab<<"b.no"<<endl;
    for(auto i=0;i<n;i++)
    {
      cout<<i+1<<tab<<tab<<process[i]<<tab<<tab<<ans[i]<<endl;
    }

}
