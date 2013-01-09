//     	additionnal_tinyxml.cpp
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
//	This program was developped in the following labs:
//	2009-2011:  Joint robotics Laboratory - CNRS/AIST,Tsukuba, Japan.
// 	2011-2012:  Karlsruhe Institute fur Technologie, Karlsruhe, Germany
//	from 2012: IUT de Beziers/ LIRMM, Beziers, France

#include "additionnal_tinyxml.h"
#include <sstream>
#include <boost/algorithm/string.hpp>

// }
// 
// bool get_bool ( TiXmlHandle RNhandle, std::string name, std::string error_message)
// {
// 	return string_to_bool(name, get_string(RNhandle,name,error_message));
// }
// 
// int get_int ( TiXmlHandle RNhandle, std::string name, std::string error_message)
// {
// 	return string_to_int(get_string(RNhandle,name,error_message));
// }


std::string double_to_string( const double x)
{
    std::string s;
    {
        std::ostringstream oss;
        oss << x;
        s = oss.str();
    }
    return s;
}

double string_to_double( const std::string& s )
{
   std::istringstream i(s);
   double x;
   if (!(i >> x))
	   return 0;
   return x;
}

int string_to_int( const std::string& s )
{
   std::istringstream i(s);
   int x;
   if (!(i >> x))
	   return 0;
   return x;
}

float string_to_float ( const std::string& s ) 
{
   std::istringstream i(s);
   float x;
   if (!(i >> x))
	   return 0;
   return x;
}

uint64_t  string_to_uint64 ( const std::string& s ) {
   std::istringstream i(s);
   uint64_t x;
   if (!(i >> x))
	   return 0;
   return x;
}

uint32_t  string_to_uint32 ( const std::string& s ) {
   std::istringstream i(s);
   uint32_t x;
   if (!(i >> x))
	   return 0;
   return x;
}

uint16_t  string_to_uint16 ( const std::string& s ) {
   std::istringstream i(s);
   uint16_t x;
   if (!(i >> x))
	   return 0;
   return x;
}

uint8_t  string_to_uint8 ( const std::string& s ) {
   std::istringstream i(s);
   uint8_t x;
   if (!(i >> x))
	   return 0;
   return x;
}

int64_t  string_to_int64 ( const std::string& s ) {
   std::istringstream i(s);
   int64_t x;
   if (!(i >> x))
	   return 0;
   return x;
}

int32_t  string_to_int32 ( const std::string& s ) {
   std::istringstream i(s);
   int32_t x;
   if (!(i >> x))
	   return 0;
   return x;
}

int16_t  string_to_int16 ( const std::string& s ) {
   std::istringstream i(s);
   int16_t x;
   if (!(i >> x))
	   return 0;
   return x;
}

int8_t  string_to_int8 ( const std::string& s ) {
   std::istringstream i(s);
   int8_t x;
   if (!(i >> x))
	   return 0;
   return x;
}

std::string char_to_string(const char * a)
{
	std::string tmp = a;
	boost::algorithm::trim(tmp);
	return tmp;  
}

bool string_to_bool(std::string name, std::string tmp)
{
	boost::algorithm::trim(tmp);
	if (tmp.compare("true") == 0 || tmp.compare("TRUE") == 0 || tmp.compare("yes") == 0 || tmp.compare("YES") == 0)
		return true;
	else if (tmp.compare("false") == 0 || tmp.compare("FALSE") == 0 || tmp.compare("no") == 0 || tmp.compare("NO") == 0)
		return false;
	else
	{
		std::cerr<<" please select true or false for "<< name <<" (you have selected:"<< tmp << ")" <<std::endl;
		exit(0);
	}	      
}

