#include<iostream>
#include<string.h>
using namespace std;
bool is_prime(int num);//素数判定 
void dfs(int num);//搜索 
const int MAXN=20;
bool prime[MAXN*2];//素数表 
int res[MAXN];//存储结果 
bool occ[MAXN];//数字是否被占用 
int tot;
int main()
{
int i,j;
for(i=2;i<MAXN*2;i++)//得到素数表 
{
if(is_prime(i))
prime[i]=true;
}
int T,t;
cin>>T;
for(t=0;t<T;t++)
{
cin>>tot;
memset(res,0,sizeof(res));
res[0]=1;
dfs(1); //计算 
}

}
void dfs(int num)//搜索第num个位置的数 
{
if(num==tot&&prime[res[0]+res[tot-1]])//检测头和尾，输出 
{
int i;
for(i=0;i<tot;i++)
{
cout<<res[i]<<" ";
}
cout<<endl;
}
else
{
int i;
for(i=2;i<=tot;i++)//所有可能 
{
if(!occ[i]&&prime[res[num-1]+i])//符合条件的 
{
res[num]=i; 
occ[i]=true;
dfs(num+1);
occ[i]=false;
}
}
}

}
bool is_prime(int num)//素数判定=_=筛表忘了怎么写，数据量小，没多大影响 
{
int i;
for(i=2;i*i<=num;i++)	//不用sqrt函数的写法i*i<=num 
{
if(num%i==0)
{
return false;
}
}
return true;
}
