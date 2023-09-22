#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"enter the no of processes:";
	cin>>n;
	vector<int>a(n);
	vector<int>b(n);
	vector<int>ct;
	for(auto i=0;i<n;i++)cin>>a[i];
	for(auto i=0;i<n;i++)cin>>b[i];
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
	int cmp=a[0]+b[0];
	ct.push_back(cmp);
	for(auto i=1;i<n;i++)
	{
		if(a[i]<=cmp)
		{
			cmp+=b[i];
			ct.push_back(cmp);

		}
		else
		{
			cmp=a[i]+b[i];
			ct.push_back(cmp);
		}
		
		
	}
	vector<int>turn;
	int turnsum=0;
	for(auto i=0;i<n;i++)
	{
		int x=ct[i]-a[i];
		turn.push_back(x);
		turnsum+=x;

	}
	vector<int>wait;
	int waitsum=0;
	for(auto i=0;i<n;i++)
	{
		int y=turn[i]-b[i];
		wait.push_back(y);
		waitsum+=y;
	}
	cout<<"aravil time"<<" "<<"burst time"<<" "<<"completion_time"<<" "<<"turn_around_time"<<" "<<"wait_time"<<endl;
	for(auto i=0;i<n;i++)
	{
		cout<<a[i]<<"     "<<b[i]<<"     "<<ct[i]<<"     "<<turn[i]<<"     "<<wait[i]<<"     "<<endl;
	
	}
	cout<<endl;
	cout<<"average turn around time: ";
	cout<<turnsum/n<<endl;
	cout<<"average waiting time:";
	cout<<waitsum/n<<endl;
}
