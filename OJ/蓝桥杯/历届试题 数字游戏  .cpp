#include<iostream>
using namespace std;
int main(){
	int perons,max,limits;
	while(cin>>perons>>max>>limits){
		int temp=1,i=0,times=0,sum=0;
		while(times<limits){
			if(i%perons==0){
			//	cout<<"temp="<<temp<<endl;
				sum+=temp;
				times++;
			}
			i++;
			temp=(temp+i)%max;
		}
		cout<<sum<<endl;
		
	}
	return 0;
}
