#include<iostream>
using namespace std;
int number[100];
int main()
{
	int num,i,sum,max;
	while(cin>>num){
		max=-0x7fffffff;
		sum=0;
		for(i=0;i<num;i++)
			cin>>number[i];
		for(i=0;i<num;i++){
			sum+=number[i];
			if(sum>max)
			max=sum;
			if(sum<0)
			sum=0;
		}
		cout<<max<<endl;
	}
}
