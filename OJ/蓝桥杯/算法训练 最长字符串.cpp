#include<iostream>
#include<string.h>
using namespace std;
int length;
string str , res;
int main(){
	for(int i = 0 ; i < 5 ; i++){
		cin >> str;
		if(str.length() > length){
			length = str.length();
			res = str;
		}
	}
	
	cout << res << endl;
	return 0;
}
