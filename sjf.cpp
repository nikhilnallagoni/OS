#include<bits/stdc++.h>
using namespace std;
#define tab '\t'
struct p
{
public:
	int id;
	int arvl_time;
	int brst_time;
	int st;
	int ct;
	int tat;
	int wt;
};
int main()
{
	int n;cin>>n;
	p process[n+1];
	vector<bool>used(n,false);
	for(auto i=1;i<=n;i++)
	{
		process[i].id=i;
		int at,bt;cin>>at>>bt;
		process[i].arvl_time=at;
		process[i].brst_time=bt;
	}
	


	int completed=0;
	int curr_time=0;
	int prev=0;
	while(completed!=n)
	{
			int ind=-1;
		int min_time=INT_MAX;
		//finding min burst time
		for(auto i=1;i<=n;i++)
		{
			if(curr_time>=process[i].arvl_time and !used[i])
			{
				if(process[i].brst_time<min_time)
				{
					min_time=process[i].brst_time;
					ind=i;
				}
				if(process[i].brst_time==min_time)
				{
					if(process[i].arvl_time<process[ind].arvl_time)
					{
						min_time=process[i].brst_time;
						ind=i;
					}
				}
			}
		}
		if(ind!=-1)//process with arival time less than or equal to current time;
		{
			process[ind].st=curr_time;
			process[ind].ct=process[ind].st+process[ind].brst_time;
			process[ind].tat=process[ind].ct-process[ind].arvl_time;
			process[ind].wt=process[ind].tat-process[ind].brst_time;
			curr_time=process[ind].ct;
			completed++;
			used[ind]=true;

		}
		else//no process within the current time
		{
			curr_time++;
		}

	}
	cout<<"id"<<tab<<"at"<<tab<<"bt"<<tab<<"st"<<tab<<"ct"<<tab<<"tat"<<tab<<"wt"<<endl;
	for(auto i=1;i<=n;i++)
	{
		cout<<process[i].id<<tab<<process[i].arvl_time<<tab<<process[i].brst_time<<tab<<process[i].st<<tab<<process[i].ct<<tab<<process[i].tat<<tab<<process[i].wt<<endl;
	}

}