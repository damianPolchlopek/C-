#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>
#include "operatory.h"
using namespace std;

class TString
{
    public:
        TString( const char* s = nullptr);
        ~TString();
        TString(const TString& s);
		TString& operator= (const TString& s);
		TString& operator= (TString&& s);
		TString(TString&& s);
		char& operator[](size_t n);
		const char& operator[](size_t n) const;

		char* begin() { return ptr; }
		char* end() { return ptr+len; }
		size_t length() const { return len; }
		void clear() { delete[] ptr; ptr = nullptr; len = 0; }
		bool empty() const { return len ? false : true; }
		char& front() { return *ptr; }
		const char& front() const { return *ptr; }
		char& back() { return *(ptr + len - 1); }
		const char& back() const { return *(ptr + len - 1); }
		size_t size() const { return len; }
		char* insert(size_t pos, const char* c);
		char* insert(size_t pos, char c);
		char* erase(size_t bpos = 0, size_t len = 0);
		char* c_str() { return ptr; }
		const char* c_str() const { return ptr; }
		operator char*() { return ptr; }
		operator const char*() { return ptr; }
		void push_back(char c) { insert(len, c); }
		void push_back(const char* c) { insert(len, c); }
		static size_t getN() { return count; }
		void operator()(const char& c) { push_back(c); }

		friend std::ostream& MojeOperatory::operator<<(std::ostream& strumien, const TString& s);
		friend std::istream& MojeOperatory::operator>>(std::istream& strumien, TString& s);

	protected:

    private:
        char* ptr = nullptr;
        std::size_t len = 0;
		static int count;
};


#endif // TSTRING_H