#include<iostream>
#include<string.h>
using namespace std;
bool is_prime(int num);//�����ж� 
void dfs(int num);//���� 
const int MAXN=20;
bool prime[MAXN*2];//������ 
int res[MAXN];//�洢��� 
bool occ[MAXN];//�����Ƿ�ռ�� 
int tot;
int main()
{
int i,j;
for(i=2;i<MAXN*2;i++)//�õ������� 
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
dfs(1); //���� 
}

}
void dfs(int num)//������num��λ�õ��� 
{
if(num==tot&&prime[res[0]+res[tot-1]])//���ͷ��β����� 
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
for(i=2;i<=tot;i++)//���п��� 
{
if(!occ[i]&&prime[res[num-1]+i])//���������� 
{
res[num]=i; 
occ[i]=true;
dfs(num+1);
occ[i]=false;
}
}
}

}
bool is_prime(int num)//�����ж�=_=ɸ��������ôд��������С��û���Ӱ�� 
{
int i;
for(i=2;i*i<=num;i++)	//����sqrt������д��i*i<=num 
{
if(num%i==0)
{
return false;
}
}
return true;
}
