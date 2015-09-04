#include<iostream>
#include<stdio.h>
using namespace std;
int score[10] , data;
int main(){
	int i , j;
	for(i = 0 ; i < 4 ; i++)
	for(j = 1 ; j <= 4 ; j++){
		cin >> data;
		score[j] += data;
	}
	for(j = 1 ; j <= 4 ; j++)
	printf("%.2lf\n" , score[j] / 4.0);
	return 0;
}
