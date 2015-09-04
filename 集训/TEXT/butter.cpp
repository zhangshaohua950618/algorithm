/*
ID: zhangsh35
PROG: butter 
LANG: C++
*/
#include<fstream>
using namespace std;
const int MAXN=800+10;
int farm[MAXN];
int path[MAXN][MAXN];
int tot_cow,tot_farm,tot_road;
#define Min(a,b) ((a)<(b)?(a):(b))
#define MAX 99999
int main()
{
	ifstream cin("butter.in");
	ofstream cout("butter.out");
	int i,j,k;
	int cow_farm,row,col,dis,min=MAX,now=0;
	cin>>tot_cow>>tot_farm>>tot_road;
	for(i=1;i<=tot_farm;i++)
	for(j=1;j<=tot_farm;j++)
		path[i][j]=path[j][i]=i==j?0:MAX;
/*	for(i=1;i<=tot_farm;i++)
	{
	for(j=1;j<=tot_farm;j++)
	{
		cout<<path[i][j]<<" ";
	}
	cout<<endl;
	}*/
	for(i=1;i<=tot_cow;i++)
	{
	cin>>cow_farm;
	farm[cow_farm]++;
	}
	for(i=1;i<=tot_road;i++)
	{
		cin>>row>>col>>dis;
		if(farm[row])
		path[row][col]=dis*farm[row];
		if(farm[col])
		path[col][row]=dis*farm[col];
		if(!farm[row])
		path[row][col]=dis;
		if(!farm[col])
		path[col][row]=dis;
	}
/*	for(i=1;i<=tot_farm;i++)
	{
	for(j=1;j<=tot_farm;j++)
	{
		cout<<path[i][j]<<" ";
	}
	cout<<endl;
	}*/
	for(k=1;k<=tot_farm;k++)
	for(i=1;i<=tot_farm;i++)
	for(j=1;j<=tot_farm;j++)
//	if(path[i][j]&&path[i][k]&&path[k][j])
	path[i][j]=Min(path[i][j],path[i][k]+path[k][j]);
/*	for(i=1;i<=tot_farm;i++)
	{
	for(j=1;j<=tot_farm;j++)
	{
		cout<<path[i][j]<<" ";
	}
	cout<<endl;
	}*/
	for(i=1;i<=tot_farm;i++)
	{
		now=0;
		for(j=1;j<=tot_farm;j++)
		{
			if(farm[j]!=0)
			now+=path[i][j];
		}	
		min=Min(now,min);
	}
	cout<<min<<endl;
	return 0;
	
}
