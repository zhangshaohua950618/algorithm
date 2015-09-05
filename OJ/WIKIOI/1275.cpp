#include<iostream>
#include<string.h>
using namespace std;
int fish[4];
int ans[3];
int main(){
        int i,j;
        for(i = 0 ;  i < 4 ; i++)
                cin >> fish[i];
        for(i = 1 ; i < 4 ; i++)
                ans[i - 1] = fish[i] - fish[i - 1];
        if(ans[0] == 0 && ans[1] == 0 && ans[2] == 0)
                cout << "Fish At Constant Depth" << endl;
        else if(ans[0] > 0 && ans[1] >0 && ans[2] > 0)
                cout << "Fish Rising" << endl;
        else if(ans[0] < 0 && ans[1] < 0 && ans[2] < 0)
                cout << "Fish Diving" << endl;
        else
                cout << "No Fish" << endl;
        return 0;
}
