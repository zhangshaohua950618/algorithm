#include<stdio.h>
#include<fstream>
using namespace std;
ifstream cin("1.in");
ofstream cout("1.out");
ofstream fout("2.out");
#include<string.h> 
char a[10][100000];
int m,c[200000],h=0,b[500000];
void put(char s)
{
	switch(s-'0')
	{
		case 0:b[m++]=0,b[m++]=0,b[m++]=0,b[m++]=0;break;
		case 1:b[m++]=0,b[m++]=0,b[m++]=0,b[m++]=1;break;
		case 2:b[m++]=0,b[m++]=0,b[m++]=1,b[m++]=0;break;
		case 3:b[m++]=0,b[m++]=0,b[m++]=1,b[m++]=1;break;
		case 4:b[m++]=0,b[m++]=1,b[m++]=0,b[m++]=0;break;
		case 5:b[m++]=0,b[m++]=1,b[m++]=0,b[m++]=1;break;
		case 6:b[m++]=0,b[m++]=1,b[m++]=1,b[m++]=0;break;
		case 7:b[m++]=0,b[m++]=1,b[m++]=1,b[m++]=1;break;
		case 8:b[m++]=1,b[m++]=0,b[m++]=0,b[m++]=0;break;
		case 9:b[m++]=1,b[m++]=0,b[m++]=0,b[m++]=1;break;
		case 17:b[m++]=1,b[m++]=0,b[m++]=1,b[m++]=0;break;
		case 18:b[m++]=1,b[m++]=0,b[m++]=1,b[m++]=1;break;
		case 19:b[m++]=1,b[m++]=1,b[m++]=0,b[m++]=0;break;
		case 20:b[m++]=1,b[m++]=1,b[m++]=0,b[m++]=1;break;
		case 21:b[m++]=1,b[m++]=1,b[m++]=1,b[m++]=0;break;
		case 22:b[m++]=1,b[m++]=1,b[m++]=1,b[m++]=1;break;
	}
}
void out(int i)
{
	if(b[i]==0&&b[i+1]==0&&b[i+2]==0)
	c[h++]=0;
	if(b[i]==0&&b[i+1]==0&&b[i+2]==1)
	c[h++]=1;
	if(b[i]==0&&b[i+1]==1&&b[i+2]==0)
	c[h++]=2;
	if(b[i]==0&&b[i+1]==1&&b[i+2]==1)
	c[h++]=3;
	else if(b[i]==1&&b[i+1]==0&&b[i+2]==0)
	c[h++]=4;
	else if(b[i]==1&&b[i+1]==0&&b[i+2]==1)
	c[h++]=5;
	else if(b[i]==1&&b[i+1]==1&&b[i+2]==0)
	c[h++]=6;
	else if(b[i]==1&&b[i+1]==1&&b[i+2]==1)
	c[h++]=7;
}
int main()
{
	int n,i,r,j;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
		fout<< "这是第"<< i << "组输入"<< endl;
		fout << a[i] << endl;
	}
	for(i=0;i<n;i++)
	{
		r=strlen(a[i]);
		m=3-r*4%3;
		h=0;
		for(j=0;j<r;j++)
		put(a[i][j]);
		for(j=0;j<m-1;j++,j++,j++)
		out(j);
		for(j=0;j<h;j++)
		{
			if(c[0]==0)
			continue;
			cout << c[j];
		}
		cout << endl;
	}
	return 0;
}
