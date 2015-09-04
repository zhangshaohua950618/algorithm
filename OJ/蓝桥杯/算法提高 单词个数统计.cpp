#include<stdio.h>
#include<string.h>
const int MAXN = 80 + 10;
char str[MAXN];
int num;
int main(){
	gets(str);
	for(int i = 0 ; i < strlen(str) ; i++)
	if(str[i] == ' ')
	num++;
	printf("%d\n" , num + 1);
	return 0;
}
