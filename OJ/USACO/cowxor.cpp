#include<iostream>
using namespace std;
int main(){
	int num,begin,end;
	cin>>num;
	long long number = 0;
	long long sum = 1;
	long long max = -0x7fffffff;
	for(int i = 0; i < num; i++){
		cin>>number;
		sum = sum xor number;
		if(sum > max){
			max = sum;
			end = i;
		}
		if(sum < 0){
			sum = 0;
			begin = i + 1;
		}
	}
	cout<<max<<" "<<begin<<" "<<end<<endl;
	return 0;
	
}
