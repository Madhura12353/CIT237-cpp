//Programmer: Madhura kulkarni
#pragma once

#ifndef UPPER_H
#define UPPER_H
# include "Filter.h"
#endif // !UPPER_H

class Upper : public Filter
{
public:
// virtual function to return the data that we have copied.
char transform(char ch);
//constructor for copy subclass which is accessing the constructor of parent class doFilter

Upper() :Filter()
{};
~Upper()
{};


};

