//Programmer: Madhura kulkarni
#pragma once
#ifndef FILTER_H
#define FILTER_H




# include <iostream>
# include <fstream>
# include <string>
using namespace std;
// This is a super class nameed Filter
class Filter
{

protected:
	string inFileName;     //  input file name
	string outFileName;    //  output file name

public:
	Filter()              // default constructor 
	{};
	//Filter(string , string);
	void doFilter(ifstream &in, ofstream &out); 
	
	//Filter(string &inFileName, string &outFileName);
	~Filter()
	{};
	void setInputFileName(string);    // setter to set filename
	void setOutputFileName(string);   //setter to set file names
	virtual char transform(char ch) = 0; // pure virtual function it behaves differentely depending upon their subclasses
	;
};








#endif // !FILTER_H

