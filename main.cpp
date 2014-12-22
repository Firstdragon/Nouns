#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include "Irregular.h"
#include "Regular.h"
using namespace std;

void obrabotka(nouns *noun, int &n, string &str){
	int choice;
	cout << str << " пропустить(0)/узнать число(1)/поменять число(2)/выйти из программы(3)" << endl;
	cin >> choice;
	if (choice != 1 && choice != 2 && choice != 3) return;
	if (choice == 3) exit(0);
	for (int i = 0; i < n; i++)
	{
		if (noun[i].singular == str)
		{
			if (choice == 1) cout << "Слово в единственном числе" << endl;
			else cout << noun[i].plural << endl;
			return;
		}
		else if (noun[i].plural == str)
		{
			if (choice == 1) cout << "Слово во множественном числе" << endl;
			else cout << noun[i].singular << endl;
			return;
		}
	}
	ifregular(str, choice);
}

void filein(nouns *noun, int &n){
	string str;
	ifstream in("in.txt");
	if (in.is_open())
		while (in.good()){
			getline(in, str);
			obrabotka(noun, n, str);
		}
}

int main(){
	setlocale(LC_ALL, "Russian");
	int n;
	nouns *noun = read(n);
	filein(noun, n);
	system("pause");
	return 0;
}