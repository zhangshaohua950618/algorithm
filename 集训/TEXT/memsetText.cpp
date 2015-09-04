#include<iostream>
#include<string.h>
int a[100] ;
using namespace std;
int main(){
	memset(a , 0x3 , sizeof(a)) ;
	cout<<a[1]<<endl;
}
