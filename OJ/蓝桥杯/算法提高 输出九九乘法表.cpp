#include<iostream>
using namespace std;
int main(){
		cout << "Nine-by-nine Multiplication Table" << endl;
		cout << "--------------------------------------" << endl;
		cout << "1 2 3 4 5 6 7 8 9" << endl;
		cout << "--------------------------------------" << endl;
		
		for(int i = 1 ; i <= 9 ; i++){
			cout << i << " ";
			for(int j = 1 ; j <= i ; j++)
			cout << i * j << " ";
			cout << endl;
		}
		cout << "--------------------------------------" << endl;
		return 0;
		
}
