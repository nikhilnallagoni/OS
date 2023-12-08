//LRU
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int f_size;
	cin>>f_size;
	int n=s.length();
	unordered_map<char,int>mp;
	int cnt=0;
	int i=0;
	for(;;i++)
	{
		if(mp.size()==f_size)
		{
			break;
		}
		if(mp.find(s[i])!=mp.end())
		{
			mp[s[i]]=i;
			cnt++;
		}
		else
		mp.insert({s[i],i});
	}
	for(auto it:mp)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	for(;i<n;i++)
	{
		if(mp.find(s[i])!=mp.end())
		{
			mp[s[i]]=i;
			cnt++;
		}
		else
		{
			int ind=n+1;
			char a;
			for(auto it:mp)
			{
				if(it.second<ind)
				{
					ind=it.second;
					a=it.first;
				}
			}
			
			mp.erase(a);
			mp.insert({s[i],i});
		}
	}
	cout<<n-cnt<<endl;
}
