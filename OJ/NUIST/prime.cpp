#include<iostream>
using namespace std; 
bool IsPrime[10000001];
int Pri[2000001],PriN;
const int MaxN=1000000;
int FindPrime()
{
          memset(IsPrime,1,sizeof IsPrime);
          for(int i=2;i<=MaxN;++i)
          {
                    if(IsPrime[i])Pri[PriN++]=i;
                    for(int j=0;j<PriN;++j)
                    {
                              if(i*Pri[j]>MaxN)break;
                              IsPrime[i*Pri[j]]=0;
                              if(i%Pri[j]==0)break;
                    }
          }
}
