#include <bits/stdc++.h>
using namespace std;
int currentCost,result;
int n,x,y, z,m[100][100];
 
void dfs(int parent,int u,int currentCost)
{
	result=max(result,currentCost);
	for (int i=0;i<n;i++)
		if (i != parent && m[i][u])
			dfs(u,i,currentCost+m[i][u]);
}
 
int main()
{
	cin>>n;
	for (int i=1; i<n; i++)
	{
		cin>>x>>y>>z;
		m[x][y]=z;
		m[y][x]=z;
	}
	dfs(-1,0,0);
	cout<<result<<endl;
}
  