#include<iostream>
using namespace std;
const int MAXN = 1000 + 10;
int num , k;
int data , res[MAXN];
int main(){
	int i;
	cin >> num;
	
	
	for(i = 0 ; i < num ; i++){
		cin >> data;
		if(data)
		res[k++] = data; 
	}
	
	
	cout << k << endl;
	for(i = 0 ; i < k - 1 ; i++)
	cout << res[i] << " ";
	if(k)
	cout << res[i] << endl;
	
	return 0;
}

