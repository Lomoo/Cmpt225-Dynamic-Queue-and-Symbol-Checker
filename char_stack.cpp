/* File: char_stack.cpp

Implementation of functions for basic simple array-based implementation of a stack.

*/
#include "char_stack.h"// contains the declarations of the variables and functions.

char_stack::char_stack() //default constructor 
{
	topIndex = -1; //initialize topindex to -1 to make it empty
}

void char_stack::push(char item)
{
	topIndex = topIndex + 1;
	A[topIndex] = item; 

}

char char_stack::pop()
{
	topIndex = topIndex - 1;
	return A[topIndex + 1];
}

char char_stack::top()
{
	return A[topIndex];

}

int char_stack::size()
{
	return topIndex;
}

bool char_stack::empty()
{
	return topIndex == -1;
}