#pragma once
#include <string>
#include <iostream>
#include "rus8.h"
#include "Irregular.h"

using namespace std;

class nouns
{
private:
	string slovo;

	nouns* red(int &n)
	{
		ifstream in("in.txt");
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
			nouns *mas = new nouns[n];

			in.clear();
			in.seekg(0);

			for (int i = 0; i < n; i++)
				in >> mas[i].slovo;
			in.close();
			return mas;
		}
	}

	int obrabotka(irregulars *noun, int &n, string &str, int &choice){
		irregulars irr;
		cout << str << " пропустить(0)/узнать число(1)/поменять число(2)/выйти из программы(3)" << endl;
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3) return 0;
		if (choice == 3) exit(0);
		return irr.checkirregular(noun, n, str, choice);
	}

	void chislo(string &str, int length, int &pl){
		if (str.substr(length - 2, 2) == "es")
			pl = 2;
		else pl = 1;
		return;
	}

	void ifregular(string &str, int choice, int pl, int i)
	{
		if (choice == 2)
		{
			string ending = str.substr(i - 1);
			string ending2 = str.substr(i - 2, 2);

			if (pl == 1)
			{
				if (ending == "z" || ending == "s" || ending == "x" || ending == "o" || (ending2 == "ch") || (ending2 == "sh"))
				{
					str.append("es");
				}
				else if (ending2 == "ay" || ending2 == "ey" || ending2 == "oy" || ending2 == "uy")
				{
					str.append("s");
				}
				else if (ending == "y")
				{
					str.erase(i - 1, 1);
					str.append("ies");
				}
				else
				{
					if (i > 3)
					{
						string ending3 = str.substr(i - 3, 3);
						if ((ending2 == "fe" || ending == "f") && ((ending2 != "ff") || (ending3 != "ffe")))
						{
							if (ending2 == "fe")
							{
								str.erase(i - 2, 2);
								str.append("ves");
							}
							else
							{
								str.erase(i - 1, 1);
								str.append("ves");
							}
						}
					}
					else
					{
						if ((ending2 == "fe" || ending == "f") && ((ending2 != "ff")))
						{
							if (ending2 == "fe")
							{
								str.erase(i - 2, 2);
								str.append("ves");
							}
							else
							{
								str.erase(i - 1, 1);
								str.append("ves");
							}
						}
					}
				}
				cout << str << endl;
			}
			else if (pl == 2)
			{
				if (ending2 == "ys")
				{
					str.erase(i - 1, 1);
				}
				else if (i > 3)
				{
					{
						string ending3 = str.substr(i - 3, 3);
						if (ending3 == "ies")
						{
							str.erase(i - 3, 3);
							str.append("y");
						}
						else if (ending3 == "ves")
						{
							str.erase(i - 3, 3);
							str.append("f(e)");
						}
						else if ((ending3 == "oes") || (ending3 == "xes") || (ending3 == "ses"))
						{
							str.erase(i - 2, 2);
						}
						else if (i >= 4)
						{
							string ending4 = str.substr(i - 4, 4);
							if ((ending3 == "oes") || (ending4 == "ches") || (ending4 == "shes") || (ending3 == "xes") || (ending3 == "ses"))
							{
								str.erase(i - 2, 2);
							}
						}
					}
				}
				cout << str << endl;
			}
		}
		return;
	}

	void filein(irregulars *noun, int &n, string str){
		int choice = 0;
		ifstream in("in.txt");
		int k = obrabotka(noun, n, str, choice);
		if (k != 0)
		{
			int i = str.length(), pl = 0;
			if (i == 1 || i == 0)
			{
				return;
			}
			chislo(str, i, pl);
			if (choice == 1)
			{
				if (pl == 1) cout << "Слово в единственном числе" << endl;
				else if (pl == 2) cout << "Слово во множественном числе" << endl;
			}
			ifregular(str, choice, pl, i);
		}

		str.clear();
	}
public:
	nouns()
	{
		string slovo = "";
	}

	void menu()
	{
		irregulars nauns;
		int j = 0;
		int n = 0;
		nouns *mas = red(j);
		int k = 1;
		irregulars *noun = nauns.read(n);
		while (k>0 && k <= j)
		{
			cout << "Выберите слово" << endl;
			for (int i = 0; i < j; i++)
			{
				cout << i + 1 << "." << mas[i].slovo << endl;
			}
			cin >> k;
			if (k>0 && k <= j)
			{
				filein(noun, n, mas[k - 1].slovo);
				system("pause");
			}
		}

	}

	~nouns()
	{
		slovo.clear();
	}
};
