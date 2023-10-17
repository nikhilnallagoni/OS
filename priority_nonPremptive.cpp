#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	vector<int>b(n),p(n);
	for(auto i=0;i<n;i++)
	{
		cin>>p[i];
	}
	for(auto i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(auto i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(auto i=0;i<n;i++)
	{
		for(auto j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
				swap(p[j],p[j+1]);
			}
		}
	}
	for(auto i=0;i<n;i++)
	{
		cout<<p[i]<<" "<<a[i]<<" "<<b[i]<<" "<<endl;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	int temp=a[0];vector<int>ans;
	int k=0;
	pq.push(make_pair(p[k],b[k]));
	k++;
	while(!pq.empty())
	{
		temp+=pq.top().second;
		cout<<pq.top().first<<" "<<pq.top().second<<endl;
		pq.pop();
		ans.push_back(temp);
		while(k<n and temp>=a[k])
		{
			pq.push({p[k],b[k]});
			k++;
		}
		if(k<n and pq.empty())
		{
			temp=a[k];

			pq.push({p[k],b[k]});
			k++;
		}

	}
	for(auto i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}


	

}