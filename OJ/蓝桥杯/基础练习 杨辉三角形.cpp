#include<iostream>
using namespace std;
const int MAXN = 34 + 10;
int data[MAXN][MAXN]; 
int n;
void output(int num){
	if(num == 0)
	cout << " ";
	else
	cout << num;
}
int main(){
	int i , j;
	cin >> n;
	data[1][1] = 1;
	cout << 1 << endl;
	for(i = 2 ; i <= n ; i++){
	for(j = 1 ; j <= n ; j++){
		data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
		output(data[i][j]);
		if(j == n)
		cout << endl;
		else
		cout << " ";	
		}
	}
}
