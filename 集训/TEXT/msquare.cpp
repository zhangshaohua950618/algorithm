#include<iostream>
int res[100];
int Matrix[3][6];
int Standard[3][6];
using namespace std;
void dfs(int num);
int main()
{
	int i,j,k=1;
	for(i=1;i<=2;i++)
	for(j=1;j<=4;j++)
	{
	cin>>Matrix[i][j];
	Standard[i][j]=k++;	
	}
	dfs(0);
}
void dfs(int num)
{
	int i,j,k;
	int temp;
	bool ok=true;
	for(i=1;i<=2;i++)
	{
	for(j=1;j<=4;j++)
	{
		cout<<Standard[i][j]<<" ";
	Matrix[i][j]!=Standard[i][j];
	ok=false;
	}
	cout<<endl;
	}
	if(ok)//output
	{
		cout<<num<<endl;
		int i=0;
		for(i=0;i<num;i++)
		if(res[i]==0)
		cout<<'A';
		else if(res[i]==1)
		cout<<'B';
		else if(res[i]==2)
		cout<<'C';
		exit(0);
	}
	else if(num<=33)
	{
		
		for(k=0;k<3;k++)
		{
			if(k==0)
			{
				for(j=1;j<=4;j++)//上下交换 
				{
					
					temp=Standard[1][j];
					Standard[1][j]=Standard[2][j];
					Standard[2][j]=temp;
				}
				res[num]=k;
				dfs(num+1);
				for(j=1;j<=4;j++)//上下交换 还原 
				{
					
					temp=Standard[1][j];
					Standard[1][j]=Standard[2][j];
					Standard[2][j]=temp;
				}	
				
			}
			else if(k==1)
			{
				Standard[1][0]=Standard[1][4];
				Standard[2][0]=Standard[2][4];
				for(i=1;i<=2;i++)
				for(j=4;j>0;j--)
				{
					Standard[i][j]=Standard[i][j-1];
				}
				res[num]=k;
				dfs(num+1);
				Standard[1][5]=Standard[1][1];
				Standard[2][5]=Standard[2][1];
				for(i=1;i<=2;i++)
				for(j=1;j<=4;j++)
				{
					Standard[i][j]=Standard[i][j+1];
				}
			}
			else if(k==3)//顺时针旋转 
			{
				temp=Standard[1][1];
				Standard[1][1]=Standard[2][1];
				Standard[2][1]=Standard[2][4];
				Standard[2][4]=Standard[1][4];
				Standard[1][4]=temp;
				res[num]=k;
				dfs(num+1);
				temp=Standard[1][1];
				Standard[1][1]=Standard[1][4];
				Standard[1][4]=Standard[2][4];
				Standard[2][4]=Standard[2][1];
				Standard[2][1]=temp;
			}

		}
	}
}
