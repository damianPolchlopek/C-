#include "stdafx.h"
using namespace MojeOperatory;

auto main() -> int
{
	cout << "[TEST] wywolania konstruktorow" << endl << endl;
	TString s1("pierwszy ");
	TString s2 { s1 };
	s2 = "drugi ";
	TString s3 = std::move(s2);
	TString s4 = "czwarty ";
	s2 = std::move(s1) + "string dodany ";

	// --------------------------------------------------
	s3.insert(0, "dodane ");
	s3.insert(1, 'o');
	s3.insert(s3.size(), 'x');
	s3.erase(4, 0);
	cout << "dlugosc s3: " << s3.length() << endl;
	cout << "zawartosc s3: " << s3 << endl;
	
	// --------------------------------------------------
	cout << endl << "[TEST] wczytanie danych " << endl << endl;
	TString s5;
	cin >> s5;
	cout << "zawartosc s5: " << s5 << endl;

	// --------------------------------------------------
	cout << endl << "[TEST] przyklad operatorow" << endl << endl;
	cout << "Test s1 + s2: " << s1 + s2 << endl;
	s1 += s1;
	s1('F');
	cout << "Aktualizacja s1: " << s1 << endl;

	// --------------------------------------------------
	cout << endl << "[TEST] for_each" << endl << endl;
	string ss("sdkfknskf");
	s2 = for_each(ss.begin(), ss.end(), s2);
	cout << "Po for each: " << s2 << endl;


	getchar();
	return 0;
}