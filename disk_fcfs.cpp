#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,x;cin>>n>>x;
   queue<int>q;
   for(auto i=0;i<n;i++)
   {
      int x;cin>>x;
      q.push(x);
   }
   int sum=0;
   while(!q.empty())
   {
      sum+=abs(x-q.front());
      x=q.front();
      cout<<x<<" ";
      q.pop();

   }
   cout<<sum<<endl;

}