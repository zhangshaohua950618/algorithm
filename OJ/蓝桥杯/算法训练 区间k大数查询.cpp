#include<iostream>
#include<set>
using namespace std;
const int MAXN = 1000 + 10;
set<int> s; 
int num[MAXN] , n , m , start , end , k;
int main(){
	int i , j;
	cin >> n;
	for(i = 1 ; i <= n ; i++)
		cin >> num[i];
	for(i = 1 ; i <= m ; i++){
		cin >> start >> end >> k; 
		s.clear();
		for(j = start ; j <= end ; j++){
			s.insert(num[j]);
		}
		set<int>::iterator it = s.begin();
		cout << *(it + 1) << endl;
	}
	
	
	
}
