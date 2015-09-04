#include<iostream>
using namespace std;
bool a , b , c , d;
bool A , B , C , D;
int main(){
	for(a = 0 ; a <= 1 ; a++) 
	for(b = 0 ; b <= 1 ; b++)
	for(c = 0 ; c <= 1 ; c++)
	for(d = 0 ; d <= 1 ; d++){
		if(a){
			B = false;
			D = true;
		}
		if(!a){
			B = true;
			D = false;
		}
		
		
		if(b){
			B = false;
			C = true;
		}
		if(!b){
			B = true;
			C = false;
		}
		
		
		
		if(c){
			A = false;
			B = true;
		}
		if(!c){
			A = true;
			B = false;
		}
		
		
		if(d){
			D = false;
		}
		if(!d){
			D = true;
		}
		if(A + B + C + D == 1)
	}
	
}
