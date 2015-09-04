#include<iostream>
using namespace std;
int number[100];
int main()
{
	int num,i,j,sum,max;
	while(cin>>num){
		max=-0x7fffffff;
		sum=0;
		for(i=0;i<num;i++)
			cin>>number[i];
		for(i=0;i<num;i++){
				sum=0;
			for(j=i;j<num;j++){
					sum+=number[j];
					if(sum>max)
					max=sum;
			}
		}
		cout<<max<<endl;
	}
}
