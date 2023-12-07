//worst_fit
#include<bits/stdc++.h>
using namespace std;
#define tab "\t"
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>block(m),process(n);
    vector<bool>used(m,false);
    vector<int>ans(n,-1);
    for(auto &i:block)cin>>i;
    for(auto &it:process)cin>>it;
    int ind=0;
    while(ind!=n)
    {
      int best=INT_MIN;
      int pos=-1;
      for(auto i=0;i<m;i++)
      {
         if(process[ind]<=block[i] and !used[i])
         {
            if(best<block[i])
            {
               best=block[i];
               pos=i;

            }
         }

      }

      if(pos!=-1)
         {
            used[pos]=true;
            ans[ind]=pos+1;
         }
         ind++;


    }
    cout<<"P.No"<<tab<<"p.size"<<tab<<"b.no"<<endl;
    for(auto i=0;i<n;i++)
    {
      cout<<i+1<<tab<<tab<<process[i]<<tab<<tab<<ans[i]<<endl;
    }

}
