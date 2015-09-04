#include<iostream>
#include<string.h>
using namespace std;
string s1 , s2;
int count;
int main(){
	int i;
	cin >> s1 >> s2;
	for(i =0 ;i < s1.length() ; i++){
		if(s1[i] != s2[i]){
			s1[i + 1] = s1[i + 1] == '*' ? 'o' : '*';
			count++;
		}
	}
	cout << count << endl;
	return 0;
	
}
