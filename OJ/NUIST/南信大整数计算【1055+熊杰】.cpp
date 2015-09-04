#include<stdio.h>
#include<ctype.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(;n>=1;n--)
	{
		char a[1000]={0},sym[1000]={0};
		int num[1000]={0};
		int i=0,j=0,result=0,tmp=1;
		scanf("%s",a);
		while(a[i]!=0)
		{
			if(isdigit(a[i]))
			num[j]=num[j]*10+(a[i]-48);
			else
			{
				sym[j]=a[i];
				j++;
			}
			i++;
		}
		for(i=0;i<=j;i++)
		{
			if((sym[i-1]=='+'||sym[i-1]==0)&&sym[i]=='*')
			{
				tmp=1;
				tmp=num[i]*num[i+1];
				i++;
				while(sym[i]=='*')
				{
					tmp*=num[i+1];
					++i;
				}
				result+=tmp;
			}
			else if((sym[i-1]=='-'||sym[i-1]==0)&&sym[i]=='*')
			{
				tmp=1;
				tmp=num[i]*num[i+1];
				i++;
				while(sym[i]=='*')
				{
					tmp*=num[i+1];
					++i;
				}
				result-=tmp;
			}
			else if(sym[i-1]=='+')
			result+=num[i];
			else if(sym[i-1]=='-')
			result-=num[i];
			else
			result+=num[i];
		}
		printf("%d\n",result);
	}
	return 0;
}
