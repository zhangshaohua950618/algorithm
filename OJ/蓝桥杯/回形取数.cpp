#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
int matrix[300][300];
int main()
{
	std::ios::sync_with_stdio(false);
	ifstream cin("1.in");
//	ofstream cout("1.out");
	memset(matrix,-1,sizeof(matrix));
	int rows,cols;
	int i,j;
	cin>>rows>>cols;
	for(i=1;i<=rows;i++)
	for(j=1;j<=cols;j++)
	cin>>matrix[i][j];
	int num=1;
	i=1,j=1;
	while(num<=rows*cols-1)
	{
		while(num<=rows*cols-1)//向下 
		{
			cout<<matrix[i][j]<<" ";
			num++;
			matrix[i][j]=-1;
			if(matrix[i+1][j]!=-1)
			i++;
			else
			{
			j++;
			break;
			}
		}
	//	cout<<i<<" "<<j<<endl;
		while(num<=rows*cols-1)//向右 
		{
			cout<<matrix[i][j]<<" ";
			num++;
			matrix[i][j]=-1;
			if(matrix[i+1][j]!=-1)
			j++;
			else
			{
				i--;
				break;
			}
		}
		while(num<=rows*cols-1)//向上 
		{
			cout<<matrix[i][j]<<" ";
			matrix[i][j]=0;
			matrix[i][j]=-1;
			if(matrix[i+1][j]!=-1)
			i--;
			else
			{
				j--;
			break;
			}
		}
	
		while(num<=rows*cols-1)//向左 
		{
			cout<<matrix[i][j]<<" ";
			num++;
			matrix[i][j]=-1;
			if(matrix[i+1][j]!=-1)
			j--;
			else
			{	
			i++;
			break;
			}
		}
	
	}
	cout<<matrix[i][j]<<endl;
	return 0;
}
