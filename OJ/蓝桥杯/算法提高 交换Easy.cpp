#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN = 1000 + 10;
int n , m , a , b;
int num[MAXN];
int main(){
	int i;
	cin >> n >> m;
	for(i = 1 ; i <= n ; i++)
	cin >> num[i];
	for(i = 1 ; i <= m ; i++){
		cin >> a >> b;
		swap(num[a] , num[b]);
	}
	for(i = 1 ; i <= n ; i++)
	cout << num[i] << endl;
	return 0;
}
