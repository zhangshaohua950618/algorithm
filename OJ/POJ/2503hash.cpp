#include<iostream>
#include<string.h>
#include<vector>
using namespace std ;
struct Fish{
	string key ;
	string value ;
} ;
typedef vector<int> v ;
const int MAXN = 9991 ;
V t[MAXN] ;
Fish fish[100000 + 10] ;
string  line ;
int count ;
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
	if(fish[t[hash]] == str){
		cout << fish[t[hash]].value << endl ;
		ok = true ;
		break ;
	}
	if(!ok)
	cout << "eh" << endl ;
}
void hash(){
	
}
int main(){
	while(getline(cin , line) && line.length())
		hash(line) ;
	while(cin >> line)
		find(line) ;
	return 0 ;
	
}