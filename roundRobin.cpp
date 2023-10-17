#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int q;
	cin>>q;
	vector<int>a(n);
	vector<int>b(n);
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
				
			}
		}
	}
	vector<int>ans;
    queue<pair<int,int>>pq;
    int k=0;
    int temp=a[k];
    pq.push({a[k],b[k]});
    k++;
    while(!pq.empty())
    {
    	auto it=pq.front();
    	bool ok=true;
    	pq.pop();
    	if(it.second-q>0)
    	{
          it.second-=q;
          temp+=q;
    	}
    	else
    	{
    		temp+=it.second;
    		ans.push_back(temp);
    		ok=false;
    	}
    	
    	while(k<n and temp>=a[k])
    	{
    		pq.push({a[k],b[k]}); 
    		k++;
    	}
    	if(ok)
    	{
    		pq.push(it);
    	}

    }
    for(auto i=0;i<ans.size();i++)
    {
    	cout<<ans[i]<<" ";
    }

}