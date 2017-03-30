#include "Encrypt.h"

// This class extends File class and is responsible to encrypt the file contents
char Encrypt::transform(char ch)
{
	return int(ch) + key;
}

void Encrypt::setEncryptionKey(int k)
{
	key = k;
}

Encrypt::Encrypt(int k)
{
	setEncryptionKey(k);
	
}

char Decrypt::transform(char ch)
{
	return int(ch) - key;
}

Decrypt::Decrypt(int k)
{
	key = k;
}
