/*
	

	Author : Yanujz

	Created in : 01/09/2020

    Copyright (C) 2020  Yanujz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

	You may contact the author by:
		e-mail: yanujz@live.it
*/

#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


namespace yanujz {

class string
{
public:
    string();
    string(const char* str);
    const char* c_str();
    int size();

    void concat(string &str);
    void concat(const char* str);

    int find_first_of(const char* subStr);

    //operators
    bool operator=(string &rhs);
    bool operator=(const char* rhs);

    bool operator+(string &rhs);
    bool operator+(const char* rhs);

    bool operator==(string &rhs);
    bool operator==(const char* rhs);

private:
    char* _buf;
    int _str_size;
    int _malloc_size;

};


}

