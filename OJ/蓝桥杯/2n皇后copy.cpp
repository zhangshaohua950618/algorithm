/*
***************************************
    Title: ���ű���ϰ�⡪�� 2n�ʺ�����
***************************************
    Date��2014/03/17
***************************************
    author������
***************************************
*/
#include<iostream>
using namespace std;
#define N   100
int wq[N];           //whitequeen,�ڻʺ�λ��
int bq[N];           //blackqueen,�׻ʺ�λ��
int cb[N][N];        //chessboard,����
int num;             //�ʺ���Ŀ
int count = 0;       //��ͬ�����������
int bqueen(int pos)  //��ɫ�ʺ����
{
    int i;
    for(i = 0; i < pos -1; i++)
    {
        int judge = bq[i] - bq[pos-1];
        if(0 == judge || judge == pos - 1 - i || -judge == pos - 1 - i)
            return 0;
    }
    if(pos == num)
    {
        count++;
        return 0;
    }

    for(int i = 0; i < num; i++)
    {
        if(i != wq[pos] && cb[pos][i])
        {
            bq[pos] = i;
            bqueen(pos+1);
        }
    }
}
int wqueen(int pos) //��ɫ�ʺ����
{
    int i;
    for(i = 0; i < pos -1; i++)
    {
        int judge = wq[i] - wq[pos-1];
        if(0 == judge || judge == pos - 1 - i || -judge == pos - 1 - i)
            return 0;
    }
    if(pos == num)
    {
        bqueen(0);
        return 0;
    }

    for(int i = 0; i < num; i++)
    {
     if(cb[pos][i])
        {
            wq[pos] = i;
            wqueen(pos+1);
        }

    }
}
int main()
{
    cin>>num;
    for(int i =0; i < num; i++)
        for(int j = 0; j < num; j++)
            cin>>cb[i][j];
    wqueen(0);
    cout<<count;
    return 0;
}


