#include<iostream>
#include<stdio.h>
using namespace std;
char maze[25 * 3][25 * 3];
int n;
void print(){

        int i, j ;
        for(i  =0 ; i < 3 * n; i++){
                for(j = 0 ; j < 3 * n ; j++)
                        cout << maze[i][j];

                cout<< endl;
        }

}
int main(){
        int i, j, k, l;
   //     for(i = 0 ; i  < 3 ; i++){
   //             for(j = 0  ; j < 3 ; j++)
   //                     old[i][j] = getchar();
   //             getchar();
   //     }
        char old[3][3]={{'*','x','*'},{' ','x','x'},{'*',' ','*'}};
        cin >> n;
       // cout <<"n = " << n << endl;
        for(i = 0 ; i  < 3 ; i++){
                for(j = 0 ; j < 3 ; j++){
                       // cout << "i = " << i << endl;
                       // cout << "j = " << j << endl;
                        for(k = i * n ; k < (i + 1) * n ; k++){
                                for(l = j * n ; l < (j + 1) * n ; l++){
                                       // cout << "k = " << k << endl;
                                      //  cout << "l = " << l << endl;
                                        maze[k][l] = old[i][j];
                                }
                        }
                }
        }

       // cout << "ok" << endl;


       print();

}
