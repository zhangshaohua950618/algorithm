	#include<iostream>
	#include<string.h>
	using namespace std;
	const int MAXN = 20;
	bool book[MAXN];
	int res[MAXN];
	void dfs(int step){
		if(step == 10){
			int a , b , c;
			a = res[1] * 100 + res[2] * 10 + res[3];
			b = res[4] * 100 + res[5] * 10 + res[6];
			c = res[7] * 100 + res[8] * 10 + res[9];
			if(b % 2 || c % 3)
			return;
			if(a == b / 2 && a == c / 3)
			cout << a << " " << b << " " << c << endl;
			return;
		}
		else{
			int i;
			for(i = 1 ;i < 10; i++){
				if(book[i]){
					res[step] = i;
					book[i] = false;
					dfs(step + 1);
					book[i] = true;
				}
			}
		}
		
	}
	int main(){
		memset(book , true , sizeof(book));
		dfs(1);
		return 0;
	}
