/*
ID: zhangsh35
PROG: beads 
LANG: C++
*/
#include <fstream>
using namespace std;
ifstream cin("beads.in") ;
ofstream cout("beads.out") ;
int len , maxLen , current, state, i, j;
string str;
int main() {

  	cin >> len >> str;
 	 str += str;
  for( i = 0; i < len ; i++ ) {
    char temp = (char) str[i];
    if(temp == 'w')
      state = 0;
    else
      state = 1;
    j = i;
    current = 0;
    while(state <= 2) { 
      while(j < len + i && ( str[j] == temp || str[j] == 'w')) { 
        current++;
        j++;
      }
      state++;
      temp = str[j];
    } 
    if(current > maxLen )
      maxLen = current;
  } 
  cout << maxLen << endl;
  return 0;
} // main
