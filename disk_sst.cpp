#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	cin >> n >> x;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	sort(v.begin(),v.end());
	auto l=lower_bound(v.begin(),v.end(),x);
		l--;
	auto u=upper_bound(v.begin(),v.end(),x);
	int left=l-v.begin();
	int right=u-v.begin();
	int count=0,sum=0;
	while(count<n)
	{

		if(abs(v[left]-x)<(abs(v[right]-x)) and left>=0)
		{
			
			sum+=abs(v[left]-x);
			x=v[left];
			left--;
		}
		
		else 
		{
			
			sum+=abs(v[right]-x);
			x=v[right];
			right++;
		}
		count++;
	}
	cout<<sum<<endl;
}