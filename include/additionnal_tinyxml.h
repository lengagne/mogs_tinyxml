//      additionnal_tinyxml.h
//      Copyright (C) 2012 lengagne (lengagne@gmail.com)
// 
//      This program is free software: you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation, either version 3 of the License, or
//      (at your option) any later version.
// 
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
// 
//      You should have received a copy of the GNU General Public License
//      along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//      This program was developped in the following labs:
//      2009-2011:  Joint robotics Laboratory - CNRS/AIST,Tsukuba, Japan.
//      2011-2012:  Karlsruhe Institute fur Technologie, Karlsruhe, Germany
//      from 2012: IUT de Beziers/ LIRMM, Beziers, France

#ifndef	__ADDITIONNAL_TINYXML__
#define __ADDITIONNAL_TINYXML__

#include <string>
#include <stdint.h>
#include <iostream>
#include <cstdlib>
#include "tinyxml2.h"

std::string double_to_string (const double x);
std::string char_to_string (const char *a);

bool string_to_bool (std::string name, std::string tmp);
double string_to_double (const std::string & s);
int string_to_int (const std::string & s);
float string_to_float (const std::string & s);

uint64_t string_to_uint64 (const std::string & s);
uint32_t string_to_uint32 (const std::string & s);
uint16_t string_to_uint16 (const std::string & s);
uint8_t string_to_uint8 (const std::string & s);

int64_t string_to_int64 (const std::string & s);
int32_t string_to_int32 (const std::string & s);
int16_t string_to_int16 (const std::string & s);
int8_t string_to_int8 (const std::string & s);

#endif
