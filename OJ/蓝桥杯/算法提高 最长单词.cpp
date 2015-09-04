#include<stdio.h>
#include<string.h>
#include<iostream>
const int MAXN = 100000 + 10;
using namespace std;
int len[MAXN] , tot , start , end , maxLen;
char str[MAXN]; 
int main(){
	int i;
	gets(str);
	len[tot++] = -1;
	for(i = 0 ;i < strlen(str) ; i++){
		if(str[i] == ' ')
		len[tot++] = i;
	}
	len[tot++] = strlen(str);
	
	for(i = 0; i < tot - 1 ; i++){
		if(len[i + 1] - len[i] > maxLen){
			maxLen = len[i + 1] - len[i];
			start = len[i];
			end = len[i + 1];
		}
	}
	for(i = start + 1 ; i <= end ; i++){
		cout << str[i];
	}
	cout << endl;
	return 0;
}
