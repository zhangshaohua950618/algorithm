#include<iostream>
using namespace std;
const int MAXN = 30 + 10;
bool rs[MAXN];
int sum , count;
void dfs(int step){
	if(step == sum){
		count++;
		return;
	}
		int i;
		for(i =0 ; i < 2 ; i++){
			if(step >= 2 && i == rs[step - 1] && i == rs[step - 2])
			continue;
			rs[step] = i;
			dfs(step + 1);
		}
	
}
int main(){
	cin >> sum;
	if(sum != 0)
	dfs(0);
	cout << count << endl;
	return 0;
}

