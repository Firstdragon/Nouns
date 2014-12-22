#pragma once
#include <string>
#include <iostream>
using namespace std;

void chislo(string &str, int length, int &pl){
	if (str.substr(length - 2, 2) == "es")
		pl = 2;
	else pl = 1;
	return;
}

void ifregular(string &str, int choice)
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
