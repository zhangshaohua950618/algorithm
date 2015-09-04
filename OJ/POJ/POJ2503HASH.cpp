#include<iostream>
#include<string.h>
#include<string>
#include<vector>
using namespace std ;
struct Fish{
	string key ;
	string value ;
} ;
typedef vector<int> v ;
const int MAXN = 9991 ;
v t[MAXN] ;
Fish fish[100000 + 10] ;
string  line ;
int c ;
int getHash(string str){
	int i , hash = 0 ;
	for(i = 0 ; i < str.length() ; i++)
	hash += str[i] ;
	return hash % MAXN ;
}
void find(string str){
	int i ;
	bool ok = false ;
	int hash = getHash(str) ;
	for(i = 0 ; i < t[hash].size() ; i++)
	if(fish[t[hash][i]].key == str){
		cout << fish[t[hash][i]].value << endl ;
		ok = true ;
		break ;
	}
	if(!ok)
	cout << "eh" << endl ;
}
void insert(string str){
	string key , value ;
	int i ;
	for(i = 0 ; i < line.length() ; i++)
		if(line[i] == ' '){
		key = line.substr(i + 1 , line.length() - 1);
	    value = line.substr(0 , i) ;
	    break ;
	}
	fish[c].key = key ;
	fish[c].value = value ; 
	t[getHash(key)].push_back(c++) ;
}
int main(){
	while(getline(cin , line) && line.length())
		insert(line) ;
	while(cin >> line)
		find(line) ;
	return 0 ;
	
}
