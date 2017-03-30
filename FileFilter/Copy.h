//Programmer: Madhura kulkarni
#pragma once
#ifndef COPY_H
#define COPY_H
# include "Filter.h"
#endif // !COPY_H



// subclass for copy
class Copy : public Filter
{
public:
// virtual function to return the data that we have copied.
char transform(char ch);
//constructor for copy subclass 

Copy() :Filter()
{};
~Copy()
{};


};
