#include<iostream>
#define MAX 10001
void vInput(int nArray[],int nN);
int nGetResult(int nArray[],int nN);
void vOutput(int nResult);
int main()
{
	int nN;
	int nArray[MAX];
	int nResult;
	while(1==scanf("%d",&nN))
	{
		vInput(nArray,nN);
		nResult=nGetResult(nArray,nN);
		vOutput(nResult);
	}
	return 0;
}
void vInput(int nArray[],int nN)
{
	int i;
	for(i=1;i<=nN;i++)
	{
		scanf("%d",&nArray[i]);
	}
}
int nGetResult(int nArray[],int nN)
{
	int nF[MAX];
	int nResult=1;
	int nTemp;
	int i;
	int j;
	for(i=1;i<=nN;i++)
	{
		nF[i]=1;
	}
	for(i=nN-1;i>=1;i--)
	{
		nTemp=1;
	for(j=i+1;j<=nN;j++)
	{
	if((nArray[i]<=nArray[j])&&nTemp<nF[j]+1)
	{
		nTemp=nF[j]+1;
	}
	}
	nF[i]=nTemp;
	if(nResult<nF[i])
	nResult=nF[i];
	}
return nResult;
}
void vOutput(int nResult)
{
	printf("%d\n",nResult);
}


