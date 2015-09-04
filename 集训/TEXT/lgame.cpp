#include<iostream>
#include<string.h>
#include<string>
#include<time.h>
#include<fstream>
#include<map>
using namespace std;
string Dic[400000+10];
bool s[26+10];
int get_value(string);
map<char,int> score;
map<string,int> dict;
int main()
{
	string std_str;
	cin>>std_str;
	int begin,end;
	std::ios::sync_with_stdio(false);
	ifstream cin_dict("lgame.dict");
	int i=0;
	score['q']=7;
	score['w']=6;
	score['e']=1;
	score['r']=2;
	score['t']=2;
	score['y']=5;
	score['u']=4;
	score['i']=1;
	score['o']=3;
	score['p']=5;
	score['a']=2;
	score['s']=1;
	score['d']=4;
	score['f']=6;
	score['g']=5;
	score['h']=5;
	score['j']=7;
	score['k']=6;
	score['l']=3;
	score['z']=7;
	score['x']=7;
	score['c']=4;
	score['v']=6;
	score['b']=5;
	score['n']=2;
	score['m']=5;
	for(int i=0;i<std_str.length();i++)
	s[std_str[i]-'a']=true;
	string dic;
	int num=0;
	while(cin_dict>>dic&&dic!=".")
	{
		Dic[num++]=dic;
		dict[dic]=get_value(dic);
		
	}
	for(i=0;i<num;i++)
	{
		
		
	}
	return 0;
	
}
int get_value(string str)
{
	int i,tot=0;
	for(i=0;i<str.length();i++)
	{
		if(!s[str[i]-'a'])
		return -1;
	tot+=score[str[i]];
	}
	return tot;	
}
