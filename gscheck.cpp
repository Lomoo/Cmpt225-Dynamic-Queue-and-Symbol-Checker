#include "char_stack.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>

using namespace std;
int main()

{
	//to do: print the line where error occured. swag swag 420 yolo also test on linux shit. 
	int currentLine = 1; //create index for current line
	int tempLine = 0;
	string line;
	string tempString;
	char_stack Stack; //create instance of a new stack
	int tabs = 0;
	while (getline(cin, line)) //while there is a line to process
	{
		for (int i = 0; i < line.size(); i++) //iterate through every chararacter in the line string
		{
			char inputChar = line[i];
			if (inputChar == '{' || inputChar == '(' || inputChar == '[') //check to see if open symbol
			{
				Stack.push(inputChar);
			}
			else if (inputChar == ')' || inputChar == '}' || inputChar == ']') //check to see if close symbol
			{
				if (Stack.empty()) //since we only push opening brackets onto the stack, check to see if we didn't take any opening brackets, if we did report the error
				{
					cout << "Error on line " << currentLine << ": Too many " << inputChar << endl; //print error of mismatched brackets
					cout << line.substr(0, i + 1) << endl; //print the line where error occured
					int n = i + 1;
					for (int j=0; j < line.substr(0, i + 1).size(); j++)//loop through string where error occured and count numbers of tabs
					{
						if (line.substr(0, i + 1)[j] == '\t')
						{
							tabs = tabs + 1;
						}

					}
					while (n--) //iterate through size of error line and print that many spaces or tabs
					{
						if (tabs>0) //deal with tabs
						{
							while (tabs--)
							{
									cout << "\t";
							}

						}
						else
						{
							cout << " ";
						}

					}
					cout << line.substr(i + 1, line.size()) << endl; //print remainder of the line
					return 0;
				}
				char poppedChar = Stack.pop(); //since we know the input character must be either a ) or } or ] we have to check if it correctly matches it's corresponding opening symbol
				if (poppedChar == '(' && inputChar == '}') // check to see if the previous symbol on the stack doesn't match with the symbol the program is currently processing
				{
					cout << "Error on line " << currentLine << ": Read " << inputChar << ", expected )" << endl;
					cout << line.substr(0, i + 1) << endl;
					int n = i + 1;
					for (int j=0; j < line.substr(0, i + 1).size(); j++)
					{
						if (line.substr(0, i + 1)[j] == '\t')
						{
							tabs = tabs + 1;
						}

					}
					while (n--)
					{
						if (tabs>0)
						{
							while (tabs--)
							{
									cout << "\t";
							}

						}
						else
						{
							cout << " ";
						}

					}
					cout << line.substr(i + 1, line.size()) << endl;
					return 0;
				}
				else if (poppedChar == '{' && inputChar == ')')
				{
					cout << "Error on line " << currentLine << ": Read " << inputChar << ", expected } " << endl;
					cout << line.substr(0, i + 1) << endl; 
					int n = i + 1;
					for (int j=0; j < line.substr(0, i + 1).size(); j++)
					{
						if (line.substr(0, i + 1)[j] == '\t')
						{
							tabs = tabs + 1;
						}

					}
					while (n--)
					{
						if (tabs>0)
						{
							while (tabs--)
							{
									cout << "\t";
							}

						}
						else
						{
							cout << " ";
						}

					}
					cout << line.substr(i + 1, line.size()) << endl;
					return 0;
				}
				else if (poppedChar == '(' && inputChar == ']')
				{
					cout << "Error on line " << currentLine << ": Read " << inputChar << ", expected ) " << endl;
					cout << line.substr(0, i + 1) << endl;
					int n = i + 1;
					for (int j=0; j < line.substr(0, i + 1).size(); j++)
					{
						if (line.substr(0, i + 1)[j] == '\t')
						{
							tabs = tabs + 1;
						}

					}
					while (n--)
					{
						if (tabs>0)
						{
							while (tabs--)
							{
									cout << "\t";
							}

						}
						else
						{
							cout << " ";
						}

					}
					cout << line.substr(i + 1, line.size()) << endl;
					return 0;
				}
				else if (poppedChar == '[' && inputChar == ')')
				{
					cout << "Error on line " << currentLine << ": Read " << inputChar << ", expected ]" << endl;
					cout << line.substr(0, i + 1) << endl;
					int n = i + 1;
					for (int j=0; j < line.substr(0, i + 1).size(); j++)
					{
						if (line.substr(0, i + 1)[j] == '\t')
						{
							tabs = tabs + 1;
						}

					}
					while (n--)
					{
						if (tabs>0)
						{
							while (tabs--)
							{
									cout << "\t";
							}

						}
						else
						{
							cout << " ";
						}

					}
					cout << line.substr(i + 1, line.size()) << endl;
					return 0;
				}
				else if (poppedChar == '{' && inputChar == ']')
				{
					cout << "Error on line " << currentLine << ": Read " << inputChar << ", expected } " << endl;
					cout << line.substr(0, i + 1) << endl;
					int n = i + 1;
					for (int j=0; j < line.substr(0, i + 1).size(); j++)
					{
						if (line.substr(0, i + 1)[j] == '\t')
						{
							tabs = tabs + 1;
						}

					}
					while (n--)
					{
						if (tabs>0)
						{
							while (tabs--)
							{
									cout << "\t";
							}

						}
						else
						{
							cout << " ";
						}

					}
					cout << line.substr(i + 1, line.size()) << endl;
					return 0;
				}
				else if (poppedChar == '[' && inputChar == '}')
				{
					cout << "Error on line " << currentLine << ": Read " << inputChar << ", expected ]" << endl;
					cout << line.substr(0, i + 1) << endl;
					int n = i + 1;
					while (n--)
					{
						cout << " ";
					}
					cout << line.substr(i + 1, line.size()) << endl;
					return 0;
				}
			}

		}

		currentLine = currentLine + 1; //make sure we know what line we are on
		tempString = line;
	}
	if (!Stack.empty()) // if we didn't find a matching closing bracket the stack must have something in it and thus a mismatched bracket.. report error
	{
		char inputChar = Stack.pop();
		cout << "Error on line " << currentLine - 1 << ": Too many " << inputChar << endl; //subtract 1 from currentline because for loop added an extra at the end and we are out of the loop
		cout << tempString << endl;
		return 0;
	}


	cout << "No errors found" << endl; //no errors have occured, all brackets are matched



	return 0;


}
