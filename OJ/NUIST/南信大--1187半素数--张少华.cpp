#include<iostream>
#include<string.h>
const int MAXN=1000000+10;
bool is_prime[MAXN];
int prime[MAXN];
int i,j,k=0;
void get_prime();
using namespace std;
int main()
{
    int num;
    int i,j;
    bool ok=false;
    get_prime();
    while(cin>>num)
    {
        ok=false;
        for(i=0;prime[i]<num;i++)
        {
            if(num%prime[i]==0&&is_prime[num/prime[i]])
            {
                ok=true;
                break;
            }
        }
        if(ok)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
void get_prime()//欧拉筛法求素数，速度很快，没有重复筛选 ，貌似别的都要超时 
{
    memset(is_prime,true,sizeof(is_prime));
    for(i=2;i<=MAXN;i++)
    {
        if(is_prime[i])
            prime[k++]=i;
        for(j=0;j<k&&prime[j]*i<=MAXN;j++)
        {
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0)
                break;
        }
    }       
}  
