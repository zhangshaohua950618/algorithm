#include<iostream>
using namespace std;
int matrix[30+10][30+10];
int matrix_copy[30+10][30+10];
int matrix_res[30+10][30+10];
int rows;
int get_value(int i,int j)
{
	int k,sum=0;
	for(k=1;k<=rows;k++)
	sum+=matrix[i][k]*matrix_copy[k][j];
//	cout<<sum<<endl;
	return sum;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int times;
	cin>>rows>>times;
	int i,j,k;
	for(i=1;i<=rows;i++)
	for(j=1;j<=rows;j++)
	{
	cin>>matrix[i][j];
	matrix_copy[i][j]=matrix[i][j];
	}
	if(times==0)
	{
	for(i=1;i<=rows;i++)
	{
		
		for(j=1;j<rows;j++)
		{
		int a;
		a=i==j?1:0;
		cout<<a<<" ";
		}
		int a;
		a=i==j?1:0;
		cout<<a<<endl;
	}
	return 0;
	}
	for(k=1;k<times;k++)
	{
	for(i=1;i<=rows;i++)
	for(j=1;j<=rows;j++)
		matrix_res[i][j]=get_value(i,j);
	for(i=1;i<=rows;i++)
	for(j=1;j<=rows;j++)
	matrix[i][j]=matrix_res[i][j];
	}
	for(i=1;i<=rows;i++)
	{
		for(j=1;j<rows;j++)
		cout<<matrix[i][j]<<" ";
		cout<<matrix[i][j]<<endl;
	}
	return 0;
}
