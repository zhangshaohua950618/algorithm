#include<fstream>
#include<string.h>
using namespace std ;
ifstream cin("1.in") ;
ofstream cout("1.out") ;
const int MAXN = 200 ;
string str ;
bool m[MAXN] , ok ;
bool t1(string str){
	for( int  i= 0 ;  i < str.length() ; i++ )
	if(m[str[i]])
	return true ;
	return false ;
}
bool t2(int num){
	if(num < 2)
	return true ;
	int s = m[str[num]] + m[str[num - 1]] + m[str[num - 2]] ;
	if(s == 0 || s == 3 )
	return false ;
	return true ;
}
bool t3(int num){
	if(num < 1 ||str[num]== 'e' || str[num] == 'o')
	return true ;
	if(str[num] == str[num - 1])
	return false ; 
}
int main(){
	int  i , j ;
	m['a'] = true ;
	m['e'] = true ;
	m['i'] = true ;
	m['o'] = true ;
	m['u'] = true ;
	while( cin >> str && str != "end" ){
		if(!t1(str)){
			cout << "cause by 1" << endl ;
			cout << "<" << str << ">" <<  " is not acceptable." << endl ;
			continue ;
		}
		ok = true ;
		for( i = 0 ;i < str.length() ; i++ ){
			if(false == t2(i) * t3(i)){
				ok = false ;
				if(!t2(i))
				cout << " i = " << i<< "case by 2" << endl ;
				else if(!t3(i))
				cout << " i = " << i<< "case by 3" << endl ;
				break ; 
			}
		}
		cout << "<" << str << ">" ;
		if(ok)
		cout << " is acceptable." << endl ;
		else
		cout << " is not acceptable."<< endl ;
	}
	return  0 ;
}
