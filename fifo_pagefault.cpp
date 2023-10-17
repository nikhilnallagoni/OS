#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n;
	cin>>n;
	vector<bool>hit(10);
	queue<int>q;
	int cnt=0;
	for(auto i=0;i<s.length();i++)
	{
		if(hit[s[i]-'0']==1)
		{
			continue;
		}
		if(q.size()==n)
		{
			hit[q.front()]=0;
			q.pop();
			q.push(s[i]-'0');
			hit[s[i]-'0']=1;
		}
		else
		{
			hit[s[i]-'0']=1;
			q.push(s[i]-'0');
		}
		cnt++;
	}
	cout<<cnt;
}