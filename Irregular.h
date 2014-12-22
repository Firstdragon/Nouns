#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class nouns
{
public:
	string singular;
	string plural;
};

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


