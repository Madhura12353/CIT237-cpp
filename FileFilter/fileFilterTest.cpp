//Program:
//File filter reads an input file, transform it in some way and writes the result into output file
//Creating one abstract class that defines pure vertual function
//and create another derived class to perform encryption ,copy and upper case transformation
//Programmer: Madhura kulkarni
//Last modified: 3/30/2017
//
//

# include <iostream>
# include "Filter.h"
#include "Copy.h"
# include "Encrypt.h"
#include "Upper.h"
# include <string>
# include <fstream>
using namespace std;

void printFilterOptions();
int getIntInRange(int min, int max);

int main()
{

	string inputFileName, outputFileName;
	ifstream inputFile;
	ofstream outputFile;
	int key=0, option;

	cout << "\n		*** Welcome to the File filter program ***		\n\n";
	cout << "Which filter do you want to use from following options? \n";
	cout << "\nEnter your choice: \n";
	printFilterOptions();                //printing opetions
	 option = getIntInRange(1,5);
	
	//cin.ignore();
	while (option != 5)
	{
		switch (option)
		{
		case 1: 
		{
			Copy toCopy;
			toCopy.doFilter(inputFile, outputFile); break; 
		}
		case 2:
		{
			Upper toUpper;
			toUpper.doFilter(inputFile, outputFile); break; 
		}

		case 3: 
		{
			cout << "What is your Incryption key?: ";
			cin >> key; cin.ignore();
			Encrypt toEncrypt(key);
			toEncrypt.doFilter(inputFile, outputFile); break;
		}
		case 4:
		{
			cout << "What is your Incryption key?: ";
			cin >> key; cin.ignore();
			Decrypt toDecrypt(key);
			toDecrypt.doFilter(inputFile, outputFile); break;
		}
		
		case 5: cout << "press enter to exit: "; cin.get(); break;


		}

		cout << "\nEnter your choice: \n";
		printFilterOptions();
		option = getIntInRange(1, 4);

	}

	

	}
//printiong the available opetions
void printFilterOptions()
{
	cout << "	1) Copy\n"
		<< "	2) Upper case\n"
		<< "	3) Encrypt\n"
		<< "	4) Decrypt\n"
		<< "	5) Exit\n";
}
// Getting integer in range

int getIntInRange(int min, int max) 
{
	int num;
	cin >> num;
	cin.ignore(80, '\n');
	while (num < min || num > max) 
	{
		cout << "Enter a number between " << min << " and " << max << ": ";
		cin >> num;
		cin.ignore(80, '\n');
	}
	return num;
}

