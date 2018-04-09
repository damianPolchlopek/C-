#include "stdafx.h"
using namespace std;

ostream& MojeOperatory::operator<<(ostream& strumien, const TString& s) {
	return strumien << (s.ptr ? s.ptr : "pusty");
}

istream& MojeOperatory::operator>>(istream& strumien, TString& s) {
	string tmp;
	getline(strumien, tmp);
	delete[] s.ptr;
	s.len = tmp.length();
	if (s.len > 0) {
		s.ptr = new char[s.len + 1];
		strcpy(s.ptr, tmp.c_str());
	}
	else {
		s.ptr = nullptr;
	}
	return strumien;
}

TString MojeOperatory::operator+(const TString& a, const TString& b) {
	TString tmp(a);
	tmp.insert(tmp.size(), b.c_str());
	return tmp;
}

TString& MojeOperatory::operator+=(TString& a, const TString& b) {
	return a = a + b;
}
