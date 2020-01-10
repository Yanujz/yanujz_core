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
#include "cast.h"
#include "bit_manipulation.h"
#include "prepoc_math.h"


#define SIZE_OF_ARRAY(x) sizeof(x)/sizeof(x[0])
#define ELEMENT_IN_ARRAY(x)  (*(&x + 1) - x)

#define ABS(N) ((N<0)?(-N):(N))
#ifdef __cplusplus
constexpr unsigned int toABS(int x){
    return ((x<0)?(-x):(x));
}
#endif

#define LO8(x) (x & 0xFF)
#define HI8(x) ((x >> 8) & 0xFF)

#define LO16(x) (x & 0xFFFF)
#define HI16(x) ((x >> 16) & 0xFFFF)



#ifndef YWEAK
#define YWEAK __attribute__((weak))
#endif

#ifndef YPACKED
#define YPACKED __attribute__((packed))
#endif

#ifndef YSECTION
#define YSECTION(x) __attribute__ ((section (x)))
#endif


#define VALUE_FROM_MAP(var, mask) (var & mask)

#define IS_IN_RANGE(x, y, z)(x >= y && x <= z)
