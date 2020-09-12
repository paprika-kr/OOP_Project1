#include "String.h"

String::String()
{
	len = 0;
	str = NULL;
}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len = strlen(s.str) + 1;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String()
{
	if (str != NULL)
		delete[] str;
}

String& String::operator=(const String& s)
{
	if (str != NULL)
		delete[] str;
	len = strlen(s.str) + 1;
	str = new char[len];
	strcpy(str, s.str);

	return *this;
}

String& String::operator+(const String& s)
{
	char* tmp_str = new char[len + s.len + 1];
	strcpy(tmp_str, str);
	strcat(tmp_str, s.str);

	String temp = tmp_str;
	delete[] tmp_str;
	return temp;
}

bool String::operator==(const String& s)
{
	return strcmp(str, s.str) ? false : true;
}

String& String::operator+=(const String& s)
{
	len += s.len;
	char* tmp_str = new char[len - 1];
	strcpy(tmp_str, str);
	strcat(tmp_str, s.str);
	str = tmp_str;

	return *this;
}

ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;

	return os;
}
istream& operator>>(istream& is, String& s)
{
	char str[100];
	is >> str;
	s = String(str);

	return is;
}