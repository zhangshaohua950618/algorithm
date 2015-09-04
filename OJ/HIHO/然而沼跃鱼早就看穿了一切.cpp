#include<stdio.h>
#include<string.h>
const int MAXN = 200 + 10 ;
char str[MAXN] ;
bool ok(int i){
	if(str[i + 1] != 'A' && str[i + 1] != 'a')
	return false ;
	if(str[i + 2] != 'R' && str[i + 2] != 'r')
	return false ;
	if(str[i + 3] != 'S' && str[i + 3] != 's')
	return false ;
	if(str[i + 4] != 'H' && str[i + 4] != 'h')
	return false ;
	if(str[i + 5] != 'T' && str[i + 5] != 't')
	return false ;
	if(str[i + 6] != 'O' && str[i + 6] != 'o')
	return false ;
	if(str[i + 7] != 'M' && str[i + 7] != 'm')
	return false ;
	if(str[i + 8] != 'P' && str[i + 8] != 'p')
	return false ;
	return true ;
}
void  traslate(int i){
	str[i] = 'f' ;
	str[i + 1] = 'j' ;
	str[i + 2] = 'x' ;
	str[i + 3] = 'm' ;
	str[i + 4] = 'l' ;
	str[i + 5] = 'h' ;
	str[i + 6] = 'x' ;	
}
int main(){
	int i ,j ; 
	while(gets(str)){
	for(i = 0 ; i < strlen(str) ; i++)
		if((str[i] == 'm' || str[i] == 'M')  && ok(i)){
			traslate(i) ;
		}	
	puts(str) ;
	}
	return 0 ;
}
