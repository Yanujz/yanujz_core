#include "string.h"
#include <string.h>

#define STR_SIZE(x) (x + 1)
#define ALLOC_FACTOR 1.5F

using namespace yanujz;

string::string()
{

}

string::string(const char *str)
{
	_str_size  = strlen(str) + 1;
	_malloc_size = static_cast<int>(
				static_cast<float>(_str_size) * ALLOC_FACTOR);
	_buf = new char[_malloc_size];
	memmove(_buf, str, _str_size);
}

string::~string()
{
	delete _buf;
}

const char *string::c_str() const
{
	return _buf;
}

unsigned int string::size() const
{
	return _str_size - 1;
}

const char &string::front() const
{
	return _buf[0];
}

char &string::back() const
{
	return _buf[_str_size  - 1];
}

void string::concat(string &str)
{
	this->concat(str.c_str());
}

void string::concat(const char *str)
{
	int len = strlen(str);
	if((_str_size + len) > _malloc_size){
		_malloc_size = (_str_size + len) * ALLOC_FACTOR;
		_buf = (char*)realloc(_buf, sizeof(char) * _malloc_size);
	}

	if(_buf){
		memmove(_buf + (_str_size - 1), str, len);
		_str_size += (len + 1);
	}
}

int string::find_firsOf(const char *str)
{
	for (int i = 0; i < _str_size; ++i)
	{
		if(_buf[i] == str[0])
		{
			int cnt = 0;
			for (int j = 0; j < strlen(str); ++j)
			{
				if(_buf[i + j] != str[j])
				{
					break;
				}

				if(++cnt == strlen(str))
				{
					return i + 1;
				}

			}
		}
	}
	return -1;

}


// Operators

bool string::operator=(const string &rhs)
{
	*this = string(rhs.c_str());
}

bool string::operator=(const char *str)
{
	if(strlen(str) > _malloc_size){
		_str_size  = strlen(str) + 1;
		_malloc_size = static_cast<int>(
					static_cast<float>(_str_size) * ALLOC_FACTOR);
		if(nullptr == _buf){
			_buf = new char[_malloc_size];
		}
		else {
			_buf = (char*)realloc(_buf, sizeof(char) * _malloc_size);

		}
	}
	memmove(_buf, str, _str_size);

	return true;
}

bool string::operator+(string &rhs)
{

}

bool string::operator+(const char *rhs)
{

}

bool string::operator==(string &rhs)
{
	string temp = *this;
	return (temp == rhs.c_str());
}

bool string::operator==(const char *str)
{
	if(strlen(str) != (_str_size - 1)){
		return  false;
	}
	for (int i = 0; i < _str_size; ++i) {
		if(_buf[i] != str[i]){
			return false;
		}
	}
	return true;
}

bool string::operator+=(string str)
{

}

bool string::operator+=(const char *str)
{

}

char &string::operator[](int index) const
{

}
