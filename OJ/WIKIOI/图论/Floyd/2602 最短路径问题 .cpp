#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
const int MAX = 0x7fffffff;
struct Node{
	double x;
	double y;
};
double GetDistance(Node a , Node b){
	return sqrt(pow(a.x - b.x,2) + pow(a.y - b.y,2));
}
Node node[100+10];
double matrix[100+10][100+10];
#define Min(a,b) ((a)<(b)?(a):(b))
int main(){
	int totNode , totRoute , nodeStart , nodeEnd ;
	int i , j , k ;
	cin>>totNode;
	for(i = 1;i <= totNode ;i++)
	cin>>node[i].x>>node[i].y;
/*	for(i = 1;i <= totNode ;i++)
	for(j = 1;j <= totNode ;j++)
		matrix[i][j] = matrix[j][i] = i == j ? 0.0 : MAX;*/
	cin>>totRoute;
	for(i = 1; i <= totRoute ;i++){
		cin>>nodeStart>>nodeEnd;
		matrix[nodeStart][nodeEnd] = matrix[nodeEnd][nodeStart] = GetDistance (node[nodeStart] , node[nodeEnd]);
	}
	for(k = 1;k <= totNode ;k++)
	for(i = 1;i <= totNode ;i++)
	for(j = 1;j <= totNode ;j++)
//	if(matrix[i][k] != MAX && matrix[k][j] != MAX)
	matrix[i][j] = Min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
	cin>>nodeStart>>nodeEnd;
	printf("%.2f",matrix[nodeStart][nodeEnd]);
	return 0;
}
