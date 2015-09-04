#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
struct Rectangle
{
	double x1,x2;
	double y1,y2;
};
int main()
{
//	ifstream cin("1.in");
	Rectangle rec1,rec2;
	while(cin>>rec1.x1>>rec1.y1>>rec1.x2>>rec1.y2>>rec2.x1>>rec2.y1>>rec2.x2>>rec2.y2)
	{
		double s=0.0,width=0.0,height=0.0;
		double start11=rec1.x1,end11=rec1.x2,start22=rec2.x1,end22=rec2.x2;
		double start1,start2,end1,end2;
		start1=(start11<end11?start11:end11);
		end1=(start11>end11?start11:end11);
		start2=(start22<end22?start22:end22);
		end2=(start22>end22?start22:end22);
		if(end1<=start2||end2<=start1)//相离 ,相切 
			width=0.0;
		else if(start1<start2&&start2<end1&&end1<end2)
			width=end1-start2;
			else if(start2<start1&&start1<end2&&end2<end1)
			width=end2-start1;
			else if(start1<=start2&&start2<end2&&end2<=end1)
			width=end2-start2;
			else if(start2<=start1&&start1<end1&&end1<=end2)
			width=end1-end2;
	//		cout<<"width="<<width<<endl;
		start11=rec1.y1,end11=rec1.y2,start22=rec2.y1,end22=rec2.y2;
		start1=(start11<end11?start11:end11);
		end1=(start11>end11?start11:end11);
		start2=(start22<end22?start22:end22);
		end2=(start22>end22?start22:end22);
	//	cout<<start1<<" "<<end1<<" "<<start2<<" "<<end2<<" "<<endl;
		if(end1<=start2||end2<=start1)//相离 ,相切 
			height=0.0;
		else if(start1<start2&&start2<end1&&end1<end2)//相交 
			height=end1-start2;
			else if(start2<start1&&start1<end2&&end2<end1)//相交 
			height=end2-start1;
			else if(start1<=start2&&start2<end2&&end2<=end1)//包含 
			height=end2-start2;
			else if(start2<=start1&&start1<end1&&end1<=end2)//包含 
			height=end1-end2;
		//	cout<<"height="<<height<<endl;
	//	cout<<width*height<<endl;
		printf("%.2lf\n",width*height);
	}
	
}
