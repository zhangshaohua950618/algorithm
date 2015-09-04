#include<fstream>
using namespace std;
ifstream cin("1.in");
ofstream cout("1.out");
const int MAXN = 100 + 10;
int completion , num;
int sweet[MAXN ] , temp[MAXN];
bool Ok(){
	int i;
	int average = sweet[0];
	for(i = 1 ; i < num ; i++)
	if(average != sweet[i])
	return false;
	return true;
}
void Split(int i){
	sweet[i] += sweet[i + 1] / 2;
	sweet[i + 1] /= 2;
}
void Complete(int i){
	if(sweet[i] % 2){
		sweet[i]++;
		completion++;
	}
}
void Output(){
	for(int i = 0 ; i < num ; i++)
	cout << sweet[i] << " ";
	cout << endl; 
}
int main(){
	int i , j = 0 ;
	
	
	cin >> num;
	for(i = 0 ; i < num ; i++)
	cin >> sweet[i];
	
	
	while(j++ < 3){
		sweet[0] /= 2;
		sweet[num] = sweet[0] / 2;
		for(i = 0 ;i < num ; i++)
			Split(i);
		for(i = 0 ;i < num ; i++)
			Complete(i);
		Output();
	}
	
	
	cout << completion << endl;
	
	
	return 0;
}
