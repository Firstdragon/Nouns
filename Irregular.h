#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class nouns
{
private:
	string singular;
	string plural;

public:
	nouns* read(int &n)
	{
		ifstream in("irregular.txt");
		if (!in)
		{
			cout << "File can not be open\n";
			return 0;
		}
		else
		{
			for (n = 0;; n++)
			{
				string str;
				getline(in, str);
				if (in.eof()) break;
			}

			nouns *noun = new nouns[n];

			in.clear();
			in.seekg(0);

			for (int i = 0; i < n; i++)
				in >> noun[i].singular >> noun[i].plural;
			in.close();
			return noun;
		}
	}

	int obrabotka(nouns *noun, int &n, string &str, int &choice){
		cout << str << " пропустить(0)/узнать число(1)/поменять число(2)/выйти из программы(3)" << endl;
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3) return 0;
		if (choice == 3) exit(0);
		for (int i = 0; i < n; i++)
		{
			if (noun[i].singular == str)
			{
				if (choice == 1) cout << "Слово в единственном числе" << endl;
				else cout << noun[i].plural << endl;
				return 0;
			}
			else if (noun[i].plural == str)
			{
				if (choice == 1) cout << "Слово во множественном числе" << endl;
				else cout << noun[i].singular << endl;
				return 0;
			}
		}
		return 1;
	}
};

