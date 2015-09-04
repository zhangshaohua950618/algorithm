#include<iostream>
using namespace std;
int n , data , sum;
int main(){
	int i;
	cin >> n;
	
	
	for(i = 0 ;i< n ; i++){
		cin >> data;
		sum += data;
	}
	
	
	cout << sum << " " << sum / n << endl;
	
	return 0;
}
