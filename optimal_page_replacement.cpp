//optimal page replacemnet algo
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n; cin>>n;
   vector<int>v(n);
   for(auto &i:v) cin>>i;
   int m;cin>>m;
   int ht=0,ms=0;
   set<int>s;
   for(auto i=0;i<n;i++)
   {
      if(s.find(v[i])!=s.end())
      {
         ht++;
         continue;
      }
      else
      {
            ms++;
         if(s.size()<m)
         {
            s.insert(v[i]);
         }
         else
         {
            vector<int>index(10,INT_MAX);
            for(auto j=i+1;j<n;j++)
            {
               index[v[j]]=min(index[v[j]],j);
            }
            pair<int,int>p={0,0};
            for(auto &it:s)
            {
               if(index[it]>p.second)
               {
                  p.second=index[it];
                  p.first=it;
               }
            }
            s.erase(p.first);
            s.insert(v[i]);

         }
      }
   }
   cout<<ht<<" "<<ms<<endl;
}
