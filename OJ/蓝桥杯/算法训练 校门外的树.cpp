#include<iostream>
using namespace std;
const int MAXN = 10000 + 10;
bool tree[MAXN];
int tot , num , start , end , sum;
int main(){ 
	int i , j;
	cin >> tot >> num;
	for(i = 0 ; i < num ; i++){
		cin >> start >> end;
		for(j = start ; j <= end ; j++){
			tree[j] = true;
		}
	}
	for(i = 0 ; i <= tot ; i++){
		if(!tree[i])
		sum++;
	}
	cout << sum << endl;
	return 0;
}
