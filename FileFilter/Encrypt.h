//Programmer: Madhura kulkarni
#pragma once
#ifndef ENCRYPT_H
#define ENCRYPT_H
# include "Filter.h"
#endif // !INCRYPT_H

class Encrypt : public Filter
{
protected:
	int key;
public:

//constructor for copy subclass 
Encrypt(int k);
// virtual function to return the data that we have copied.
char transform(char ch);
void setEncryptionKey(int);


~Encrypt()
{};


};

class Decrypt : public Filter
{

protected:
	int key;
public:
	// virtual function to return the data that we have copied.
	char transform(char ch);
	//constructor for copy subclass which is accessing the constructor of parent class doFilter
	Decrypt(int k);


	~Decrypt()
	{};


};