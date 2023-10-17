#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>process;
	vector<int>block;
	vector<int>ans(m,-1);
	vector<int>hash(m+1,0);
	for(auto i=0;i<n;i++)
	{
		int x;
		cin>>x;
		process.push_back({x,i+1});
	}
	for(auto i=0;i<m;i++)
	{
		int y;
		cin>>y;
		block.push_back(y);
	}
	for(auto i=0;i<n;i++)
	{
		for(auto j=0;j<m;j++)
		{
			if(process[i].first<=block[j] and hash[j]==0)
			{
				hash[j]=1;
				ans[j]=i+1;
				break;
			}
		}
	}
	for(auto i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}