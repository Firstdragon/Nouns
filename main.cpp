#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include "Irregular.h"
#include "Regular.h"
using namespace std;

void filein(nouns *noun, int &n){
	nouns nauns;
	string str;
	int choice = 0;
	ifstream in("in.txt");
	if (in.is_open())
		while (in.good()){
			getline(in, str);
			int k = nauns.obrabotka(noun, n, str, choice);
			if (k!=0)
			ifregular(str, choice);
		}
}

int main(){
	nouns nauns;
	setlocale(LC_ALL, "Russian");
	int n;
	nouns *noun = nauns.read(n);
	filein(noun, n);
	system("pause");
	return 0;
}
