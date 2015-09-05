/*ID:zhangsh39
LANG:C++
TASK:gift1
*/
#include<fstream>
#include<string.h>
using namespace std;
const int MAXN = 10;
ifstream cin("gift1.in");
ofstream cout("gift1.out");
struct Per{
        string name;
        int money;
};
int np;
Per p[MAXN];
int find_person(string name){
        int i;
        for(i = 0; i < np; i++)
                if(p[i].name == name)
                        return i;
        return i;
}
int main(){
        int i, j, k;
        cin >> np;
        for(i = 0; i < np; i++){
                cin >> p[i].name;
                p[i].money = 0;
        }
        string out_name;
        int out_money, in_number;
        for(i = 0 ; i < np ; i++){
                cin >> out_name >> out_money >> in_number;
                string in_name;
                if(in_number != 0){
                out_money -= out_money % in_number;
                p[find_person(out_name)].money -= out_money;
                for(j = 0; j < in_number; j++){
                        cin >> in_name;
                        p[find_person(in_name)].money += (out_money / in_number);
                }
                }
        }

        for(i = 0; i < np; i++){
                cout << p[i].name << " " << p[i].money << endl;
        }
        return 0;



}

