#include<fstream>
//#include<iostream>
using namespace std ;
ifstream cin("1.in") ;
ofstream cout("1.out") ;
const int MAXN = 20 ;
int result ;
/*
path��¼����״̬
Right��¼�ҶԽ���
Left��¼��Խ���
rows��¼ÿ�е�״̬����������Ѿ��Ź�������Ϊtrue
cols��¼ÿ�е�״̬����������Ѿ��Ź�������Ϊtrue
Right��Left����Ҫ���ᣬֻҪ�б�׼���ж��Ϳ����� 
*/
bool path[MAXN][MAXN] , Right[MAXN * 2] , Left[MAXN * 2] , rows[MAXN] , cols[MAXN] ;
void dfs( int step ){//��ʵ�ݹ������~ 
	int i ;
	if(step == 8){
		result++ ;
		return ;
	}
	if(cols[step])
		dfs(step + 1) ;
		else{
		for( i = 0 ; i < 8 ; i++ )
			if(!rows[i] && !Right[ i - step + 8] && !Left[i + step]){//������λ�ÿ��Է�ֹ���ӣ���ô�͸��������е�״̬ 
				rows[i] = true ;
				Right[ i - step + 8] = true ;
				Left[i + step] = true ;
				dfs(step + 1) ;
				rows[i] = false ;
				Right[ i - step + 8] = false ;
				Left[i + step] = false ;
			}
	}
}
int main(){
	int i , j ;
	for( i = 0 ; i< 8 ; i++ )
		for( j = 0 ; j < 8 ; j++){
		cin >> path[i][j] ;
		if(path[i][j]){//�����ʱ��ҲҪ��ʼ�� rows ��cols ��Right ��Left��״̬ 
			rows[i] = true ;
			cols[j] = true ;
			Right[ i - j + 8] = true ;
			Left[i + j] = true ;
		}
	}
	dfs(0) ;
	cout << result << endl ;
	return 0 ;
}
