#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;cin>>n>>x;
	string s;cin>>s;
	vector<int>v(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(),v.end());
	int ind=-1,rind=-1;
	int sum=0;
	for(auto i=0;i<n;i++)
	{
		if(v[i]>x)
		{
			rind=i;
			break;
		}
		ind=i;
	}
	if(s=="left")
	{
		while(ind>=0)
		{
			sum+=abs(x-v[ind]);
			x=v[ind];
			ind--;
		}
		sum+=abs(x-0);
		x=0;
		while(rind<n)
		{
			sum+=abs(x-v[rind]);
			x=v[rind];
			rind++;
		}
	}
	else
	{
		while(rind<n)
		{
			sum+=abs(x-v[ind]);
			x=v[rind];
			rind++;
		}
		sum+=abs(x-199);
		while(ind>=0)
		{
			sum+=abs(x-v[ind]);
			x=v[ind];
			ind--;
		}

	}
	cout<<sum<<endl;

}