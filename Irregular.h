#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "rus8.h"
#include "Nouns.h"

using namespace std;


class irregulars
{
private:
	string singular;
	string plural;

public:

	irregulars()
	{
		string singular = "";
		string plural = "";
	}


	irregulars* read(int &n)
	{
		ifstream in("irregular.txt");
		if (!in)
		{
			cout << "Файл с существительными-исключениями не может быть открыт" << endl;
			return 0;
		}
		else
		{
			string str;
			for (n = 0;; n++)
			{
				getline(in, str);
				if (in.eof()) break;
			}
			irregulars *noun = new irregulars[n];

			in.clear();
			in.seekg(0);

			for (int i = 0; i < n; i++)
				in >> noun[i].singular >> noun[i].plural;
			in.close();
			return noun;
		}
	}

	int checkirregular(irregulars *noun, int &n, string &str, int &choice)
	{
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


	~irregulars()
	{
		singular.clear();
		plural.clear();
	}
};
