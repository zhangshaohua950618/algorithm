/*
ID: zhangsh35
PROG: milk3 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#define LOCAL
using namespace std;
void dfs(int time);
struct Cup
{
int milk;
int capacity;
};
const int MAXN=100;
bool res[MAXN]={0};
int k=0;
Cup cup[3];
int main()
{
#ifdef LOCAL
freopen("milk3.in","r",stdin);
freopen("milk3.out","w",stdout);
#endif
int i;
for(i=0;i<3;i++)
{
cin>>cup[i].capacity;
cup[i].milk=0;
}
cup[2].milk=cup[2].capacity;
dfs(0);

int count=0;
int j=0;
for(i=0;i<=cup[2].capacity;i++)
{
if(res[i])
count++;
}
for(i=0;i<=cup[2].capacity;i++)
{
if(res[i])
{
j++;
cout<<i;
if(j==count)
cout<<endl;
else 
cout<<" ";
}

}
return 0;
}
void dfs(int time)
{
if(time<12)
{
int i,j,l;
int temp_out=0,temp_in=0;
for(i=0;i<3;i++)//倒出的杯子
{
if(cup[i].milk!=0)//判定是否可以倒出
{
for(j=0;j<3;j++)//倒入的杯子
{
temp_out=cup[i].milk;
temp_in=cup[j].milk;
if(i!=j)
{
	cup[j].milk=cup[j].capacity<(cup[j].milk+cup[i].milk)?cup[j].capacity:(cup[j].milk+cup[i].milk);
	cup[i].milk=(cup[i].milk+cup[j].milk)%cup[j].capacity;
if(cup[0].milk==0)
{
/*	for(l=0;l<3;l++)
{
cout<<"第"<<l<<"个杯子中的容量为"<<cup[l].capacity<<" "<<"第"<<l<<"个杯子中的牛奶为"<<cup[l].milk<<endl;
}*/
//cout<<k<<endl;
res[cup[2].milk]=true;
}
dfs(time+1);
cup[i].milk=temp_out;
cup[j].milk=temp_in;
}
}
}
}
}
}
