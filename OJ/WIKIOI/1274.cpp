#include<iostream>
using namespace std;
int limit, speed;
int main(){
	cout << "Enter the speed limit: Enter the recorded speed of the car: ";
        cin >> limit >> speed;
        int dif = speed - limit;
        if(dif <= 0)
                cout << "Congratulations, you are within the speed limit" << endl;
        else if(dif <= 20)
                cout << "You are speeding and your fine is $ 100" << endl;
        else if(dif <= 30)
                cout << "You are speeding and your fine is $ 270" << endl;
        else
                cout << "You are speeding and your fine is $ 500" << endl;
        return 0;
}
