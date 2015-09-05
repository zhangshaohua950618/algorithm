/*ID:zhangsh35
LANG:C++
TASK:ride
*/

#include<string.h>
#include<fstream>
using namespace std;
ifstream cin("ride.in");
ofstream cout("ride.out");
const int MOD = 47;
int clu(string str){
        int i, j;
        int ans = 1;
        for(i = 0; i < str.length(); i++){
                ans *= (str[i] - 'A' + 1);
                ans %= MOD;
        }
        return  ans;

}
string ufo, uni;
int main(){
        cin >> ufo >> uni;
        if(clu(ufo) == clu(uni))
                cout << "GO" << endl;
        else cout << "STAY" << endl;
        return 0;

}
