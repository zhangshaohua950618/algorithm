#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN = 100000 + 10;
bool sweet[MAXN];
int a , b , len , maxLen , res;


void GetValue(int num){
	if(num == max(a , b)){
		sweet[num] = true;
		return;
	}
	sweet[num] = max(sweet[num - a]  , sweet[num - b]);
}


int main(){
	 
	cin >> a >> b;
	
	
	int i = maxLen = min(a , b);
	sweet[i++] = true;
	
	
	while(len < maxLen){
		GetValue(i);
		if(sweet[i])
		len++;
		else{
			res = i;
			len = 0;	
		}
		i++;
	}
	
	
	cout << res << endl;

	
	
	return 0;
}
