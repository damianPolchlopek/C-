#include "stdafx.h"

int TString::count = 0;

TString::TString(const char* s) : ptr(nullptr), len(0)
{
	count++;
    if( s > 0){
        len = strlen(s);
        ptr = new char[ len + 1 ];
        strcpy( ptr,s );
    }

	#ifdef DEBUG
	cout << "TString c-tor " << len << " - " <<
		(ptr ? ptr : "pusty") << endl;
	#endif // DEBUG
}

TString::~TString()
{
	count--;

	#ifdef DEBUG
		cout << "TString d-tor " << len << " - " <<
			(ptr ? ptr : "pusty") << endl;
	#endif // DEBUG

    delete [] ptr;
}

TString::TString(const TString& s) : ptr(nullptr), len(s.len)
{
    if( len > 0){
        ptr = new char[ len + 1 ];
        strcpy( ptr,s.ptr );
    }

	#ifdef DEBUG
		cout << "TString cc-tor " << len << " - " <<
			(ptr ? ptr : "pusty") << endl;
	#endif // DEBUG
}

TString::TString(TString && s) : ptr(s.ptr), len(s.len)
{
	s.ptr = nullptr;
	s.len = 0;

	#ifdef DEBUG
		cout << "TString mvc-tor " << len << " - " <<
			(ptr ? ptr : "pusty") << endl;
	#endif // DEBUG
}

TString& TString::operator=(const TString& s)
{
	if (this != &s) {
		delete ptr;
		ptr = nullptr;
		len = s.len;

		if( len > 0 ) {
			ptr = new char[len + 1];
			strcpy(ptr, s.ptr);
		}
	}

	#ifdef DEBUG
		cout << "TString copy operator= " << len << " - " <<
			(ptr ? ptr : "pusty") << endl;
	#endif // DEBUG

	return *this;
}

TString& TString::operator=(TString&& s)
{
	if(this != &s) {
		delete[] ptr;
		len = s.len;
		ptr = s.ptr;
		s.len = 0;
		s.ptr = nullptr;
	}

	#ifdef DEBUG
		cout << "TString move operator= " << len << " - " <<
			(ptr ? ptr : "pusty") << endl;
	#endif // DEBUG

	return *this;
}

char& TString::operator[](size_t n)
{
	if(!ptr) throw invalid_argument("pusty obiekt");
	if (n >= 0 && n < len) return ptr[n];
	throw out_of_range("In TString::operator[] argument out of scope");
}

const char& TString::operator[](size_t n) const
{
	if (!ptr) throw invalid_argument("pusty obiekt");
	if (n >= 0 && n < len) return ptr[n];
	throw out_of_range("In TString::operator[] argument out of scope");
}

char* TString::insert(size_t pos, const char* c)
{
	if (pos>= 0 && pos <= len) {
		size_t oldlen = len;
		len = len + strlen(c);
		char* tmp = new char[len + 1];
		strcpy(tmp, ptr);
		for (size_t i = pos; i < pos+strlen(c); ++i) {
			tmp[i] = c[i-pos];
		}
		for (size_t i = pos; i < oldlen; ++i) {
			tmp[i+strlen(c)] = ptr[i];
		}
		delete[] ptr;
		ptr = tmp;
		return ptr+pos;
	}
	else {
		throw out_of_range("zly argument");
	}
	return ptr;
}

char* TString::insert(size_t pos, char c)
{
	return insert(pos, string({c}).c_str());
}

char* TString::erase(size_t bpos, size_t len)
{
	if (bpos >= 0 && bpos <= length()) {
		if (bpos == 0 && len == 0) {
			this->clear();
		}
		else if (bpos + len >= length() || len == 0) {
			this->len = bpos;
			char* tmp = new char[this->len+1];
			for (int i = 0; i < bpos; ++i) {
				tmp[i] = this->ptr[i];
			}
			delete[] ptr;
			this -> ptr = tmp;
			this->ptr[this->len] = static_cast<char>(0);
			return ptr+bpos;
		}
		else {
			size_t oldlen = this->len;
			this->len = length() - len;
			char* tmp = new char[len + 1];
			for (int i = 0; i < bpos; ++i) {
				tmp[i] = this->ptr[i];
			}
			for (int i = bpos + len; i < oldlen; ++i) {
				tmp[i-len] = this->ptr[i];
			}
			delete[] ptr;
			ptr = tmp;
			return ptr + bpos;
		}
	}
	else {
		throw out_of_range("zly argument");
	}
	return ptr;
}