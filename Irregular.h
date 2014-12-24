class irregulars
{
public:
	string singular;
	string plural;

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

	~irregulars()
	{
		singular.clear();
		plural.clear();
	}
};
