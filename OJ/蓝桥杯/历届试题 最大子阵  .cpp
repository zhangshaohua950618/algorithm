#include<iostream>
#include<string.h>
using namespace std;
int const MAXN=500+10;
int matrix[MAXN][MAXN];
int number[MAXN];
int Max=-0x7fffffff;
int num;
void get_max(int number[]){
	int sum=0;
	for(int i=0;i<num;i++){
		sum+=number[i];
		if(sum>Max)
		Max=sum;
		if(sum<0)
		sum=0;
	}
}
int main()
{
	int rows,cols;
	int i,j,k,l;
	while(cin>>rows>>cols){
		Max=-0x7fffffff;
		num=cols;
		for(i=0;i<rows;i++)
			for(j=0;j<cols;j++)
			cin>>matrix[i][j];
		for(i=0;i<rows;i++){//¿Õ¼äÑ¹Ëõ 
			memset(number,0,sizeof(number));
			for(j=i;j<rows;j++){
				for(k=0;k<cols;k++){
					number[k]+=matrix[j][k];
				}
				get_max(number);
			}
		}
		cout<<Max<<endl;	
	}
}
