//============================================================================
// Name        : simpleif.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
  int a, b;

  cout << "Enter first number: ";
  cin >> a;
  cout << "Enter second number: ";
  cin >> b;

  if(a < b)
	  cout << "First number is less than second.\n";
  if(a > b)
	  cout << "First number is greater than second.\n";
  else if (a == b)
	 cout << "First number is equal to second.\n";

  return 0;

}
