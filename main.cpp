#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include "queue.h"
#include <cstdio>
using namespace std;
int main(){
string str;
char text[1000];
ifstream fin("text.txt",ios::in);
ofstream out("text2.txt", ios::out);
while (true)
{
	int i = 0;
	getline(fin,str);
	cout << str<<endl;
	cout<<str.size()<<endl;
	strcpy_s(text, str.c_str());
	int c = str.size();
	queue<char> A(100);
	queue<char> B(100);
	queue<char> C(100);
	if (fin.eof()) break;
	for (i=0; i < c+1; i++)
	{
		if (((((str[i] >= 65) && (str[i] <= 90)) || ((str[i] >= 97) && (str[i] <= 122)))) && (str[i]!='\0'))
		{
			A.push(str[i]);
		}
		if (((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
		{
			B.push(str[i]);
		}
	}
	i = 0;
	char pr[1000] = {0};
	while (!A.empty())
	{
		pr[i] = A.front();
		A.pop();
		i++;
	}
	while (!B.empty())
	{
		pr[i] = B.front();
		B.pop();
		i++;
	}
	out << pr << endl;
}
	fin.close();
	out.close();
	return(0);
}