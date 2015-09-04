#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;
int i , j , ii , jj;
int maxNum = -1, data;
int main(){
	for(i = 1 ; i <= 3 ; i++)
	for(j = 1 ; j <= 4 ; j++){
		cin >> data;
		if(abs(data) > maxNum){
			maxNum = abs(data);
			ii = i;
			jj = j;
		}
	}	
	cout << maxNum << " "<< ii << " "<< jj << endl;
	return 0;
}
