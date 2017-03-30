//Programmer: Madhura kulkarni
#include "Filter.h"




// do filter function actually performs filteration 
// it call function transform and depending upon the class transform function works differentely
void Filter::doFilter(ifstream & in, ofstream & out)
{
	char copyChar, ch;
	string inName, outName;
	cout << "\nEnter your input file name: ";
	//cin.ignore();
	getline(cin, inName);
	 
	setInputFileName(inName);                //setter to set file name 
	cout << "File name " << inName << endl;

	in.open(inFileName);                     // open the input file
	cout << "\nEnter your outputfile Name: ";
	//cin.ignore();
	getline(cin, outName);
	setOutputFileName(outName);          // setter for outputfile name
	cout << "File name " << outName << endl;

	
	out.open(outFileName);             //opening the out  put file
	
	if (in)
	{
		//get a character from file
		in.get(ch);
		// while the last read operation succesfull continue.
		while (in)
		{
			//cout << "i am in while loop.";
			copyChar = transform(ch);

			//cout display the last character read
			cout << copyChar;

			// writing this character into output file
			out << copyChar;

			// read the next character
			in.get(ch);
		}
	}
	// closing the file
	in.close();
	out.close();

}

void Filter::setOutputFileName(string outFile)
{
	ifstream input;
	char overwriteChoice = 'n';	// to get user choice to overwrite or not; initialize to no

	input.open(outFile);

	// Ask for another file name if file already exists and user doesn't wish to overwrite
	while (input && tolower(overwriteChoice) == 'n') 
	{
		cout << "The file " << outFile << " already exists. Overwrite? (yes or no) ";
		cin >> overwriteChoice; cin.ignore(80, '\n');

		while (!(tolower(overwriteChoice) == 'y' || tolower(overwriteChoice) == 'n'))
		{
			cout << "Enter either \"yes\" or \"no\": ";
			cin >> overwriteChoice;
			cin.ignore(80, '\n');
		}

		if (tolower(overwriteChoice) == 'y') 
		{
			// overwrite = true;
		}
		else {
			cout << "Enter another file name: ";
			cin >> ws;
			getline(cin, outFile);
		}
	}

	input.close();
	outFileName = outFile;
}

void Filter::setInputFileName(string inFile)
{
	ifstream input;
	inFileName = inFile;
	input.open(inFileName);
	while (!input)
	{
		cout << "The file " << inFileName << " cannot be opened. Enter another file name: ";
		cin >> ws;
		getline(cin, inFileName);
		
		input.open(inFileName);
	}

}


