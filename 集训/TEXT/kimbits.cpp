/*
ID: zhangsh35
PROG: kimbits 
LANG: C++
*/
#include<fstream>
#include<bitset>
#include<math.h>
#include<string.h>
using namespace std;
long long get_tot( int n, int k ){
	int i,j;
	long long  sum = 1,tra = 1;
	for(i = 1;i <= k;i++){
		tra *= i;
		sum *= n - i + 1;
		if(sum % tra == 0){//防止数据溢出 ,但是还是溢出了，果断long long = =最后一组数据太恶心了 
			sum /= tra;
			tra /= tra;
		}
		
	}
	return  sum;
}
int main(){
	ifstream cin("kimbits.in");
	ofstream cout("kimbits.out");
	int  N , num  ;
	long long tot , number , cnt ;
	long long i ,j ;
	cin>>N>>num>>number;
	tot = 0;
	for(i=0;i <= num;i++){
		tot += get_tot( N , i );
	}
	//cout<<tot<<endl;
	if( number >= (tot / 2)){
	//	cout<<" It is if "<<endl;
		cnt = tot;
	//	cout<<cnt<<endl; 
	//	cout<<number<<endl;
		for(i = pow(2,N) - 1  ; i >= 0 ;i--){
			bitset<32> bit(i);
			if(bit.count() <= num){
				if(cnt == number){
					cout<<bit.to_string().substr(32 - N, N )<<endl;
					return 0;
				}
				cnt--;
			}
		}
	}
	else{
	//	cout<<" It is else "<<endl;
		cnt = 1;
		for(i = 0;i <= pow(2,N) - 1;i++){
			bitset<32> bit(i);
			if(bit.count() <= num){
				if(cnt == number){
					cout<<bit.to_string().substr(32 - N, N)<<endl;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
	
}
