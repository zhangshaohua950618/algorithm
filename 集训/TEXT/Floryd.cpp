#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<cmath>
#include<climits>
using namespace std;
struct Point{
int x,y;
}p[101];
double dist(int x1,int y1,int x2,int y2){
return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
} 
double f[101][101]; 
int main(){ 
int n,m,v1,v2,s,t;
cin>>n;
//输入点坐标 
for(int i=1;i<=n;i++){
cin>>p[i].x>>p[i].y; 
}
cin>>m;
//初始化邻接点之间的距离 
for(int i=0;i<m;i++){
cin>>v1>>v2; 
f[v1][v2] = f[v2][v1] = dist(p[v1].x,p[v1].y,p[v2].x,p[v2].y);
}
//初始化无边点为无穷 
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{ 
//f[i][j] = f[j][i] == 0.0?INT_MAX:f[i][j]; 
if(i!=j&&f[i][j]==0.0)
f[i][j]= INT_MAX;
} 
//floyd算法核心 
for(int k=1;k<=n;k++)
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{ 
f[i][j] = f[i][j]<f[1][k] + f[k][j]?f[i][j]:f[i][k] + f[k][j]; 
} 
//查看某两点的最短路径 
cin>>s>>t; 
printf("%.2lf\n",f[s][t]); 
return 0; 
} 
