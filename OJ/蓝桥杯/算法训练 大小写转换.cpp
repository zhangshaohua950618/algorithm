#include<iostream>
#include<string.h>
using namespace std;
string str;
bool Judge(char c){
	if(c >= 'a' && c <= 'z')
	return true;
	return false;
}
int main(){
	int i;
	cin >> str; 


	for(i = 0 ; i < str.length() ; i++)
	if(Judge(str[i]))
	str[i] -= 32;
	else
	str[i] += 32;
	
	
	cout << str<< endl;
	
	
	return 0;
}
