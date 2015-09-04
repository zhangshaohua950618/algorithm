#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
const int MAXN = 1000 + 10;
string a ,b;
int numA[MAXN] , numB[MAXN] , result[MAXN];
int len , index , start;
int main(){
	int i , j;
	cin >> a >> b;
	for(i = a.length() - 1 ; i  >= 0 ; i--)
	numA[a.length() - 1 - i] = a[i] - '0';	
	for(i = b.length() - 1 ; i  >= 0 ; i--)
	numB[b.length() - 1 - i] = b[i] - '0';	
	len = max(a.length() , b.length()) + 1;
	for(i = 0 ; i <= len ; i++){
		int temp = numA[i] + numB[i] + index;
		result[i] = temp % 10;
		index = temp / 10;
	}
	for(i = len ; i >= 0 ; i --)
	if(result[i] != 0){
		start = i;
		break;
	}
	for(i = start ; i >= 0 ; i--)
	cout << result[i];
	cout << endl;
	return 0;
}
