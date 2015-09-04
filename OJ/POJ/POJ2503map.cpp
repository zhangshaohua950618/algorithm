#include<iostream>
#include<string.h>
#include<string>
#include<map>
using namespace std ;
string a , b ;
map<string , string> m ;
string line ;
void mapWord(string line){
	int i ;
	for(i = 0 ; i < line.length() ; i++)
		if(line[i] == ' ')
		 m[line.substr(i + 1 , line.length() - 1)] = line.substr(0 , i) ;	
}
int main(){
	while(getline(cin , line) && line.length())
		mapWord(line) ;
	while(cin >> line)
	if(m[line] != "")
	    cout << m[line] << endl ;
    else
	    cout << "eh" << endl ;
	return 0 ;
}
