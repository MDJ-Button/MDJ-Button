#include <iostream>
#include <string>
#include <limits>
#include <ctype.h>
#include <sstream>
#include <time.h>
#include <cstring>
#include <cctype>

using namespace std;

//Global Code Start
	std::string num1;
	std::string op;
	std::string num2;
//Global Code End
	
int main()
{//Main Code Start

	int inputop();
	
//Main Code Input, Check and Return

	cout << endl;
	cout << "Enter your frist number";
	cout << endl;
	cin >> num1;
	cout << endl;
	if (isdigit(num1[0]))
{
	cout << num1 <<" is a number." << endl;
	cout << endl;
	inputop();
}
	else
{
	cout << num1 << " is not a number!" << endl;
	cout << endl;
	return main();
}
}//Main Code End

int inputop()
{//Operator Code Start

	int input2();
	
//Operator Code Input, Check and Return

	cout << "Enter a operator." << endl;
	cout << endl;
	cin >> op;
	cout << endl;
	if (op == "+")
{
	cout << num1 << op << endl;
	cout << endl;
	input2();
	
}
	else if (op == "-")
{
	cout << num1 << op << endl;
	cout << endl;
	input2();
}
	else if (op == "/")
{
	cout << num1 << op << endl;
	cout << endl;
	input2();
}
	else if (op == "*")
{
	cout << num1 << op << endl;
	cout << endl;
	input2();
}
	else if (op == "%")
{
	cout << num1 << op << endl;
	cout << endl;
	input2();
}
	else
{
	cout << op << " is a invalid operator! (Arithmetic operators are /, *, +, - and %" << endl;
	cout << endl;
	return inputop();
}
}//Operator Code End

int input2()
{//Input 2 Code Start

	int calcu();
	
//Input 2 Code Input, Check and Return

	cout << "Enter your second number" << endl;
	cout << endl;
	cin >> num2;
	cout << endl;
	if (isdigit(num2[0]))
{
	cout << num2 << " is a number." << endl;
	cout << endl;
	calcu();
}
	else
{
	cout << num2 << " is not a number!" << endl;
	cout << endl;
	return input2();
}
}//Input 2 Code End

int calcu()
{//Clacu Code Start
	
//Calcu Code Input, Check and Return

int numA;
istringstream ( num1 ) >> numA;

int numB;
istringstream ( num2 ) >> numB;

char choice;


if (op == "+")
{
	cout << num1 << op << num2 << "=" << numA+numB;
	cout << endl;
	return main();
}
else if (op == "-")
{
	cout << num1 << op << num2 << "=" << numA-numB;
	cout << endl;
	return main();
}
else if (op == "/")
{
	cout << num1 << op << num2 << "=" << numA/numB;
	cout << endl;
	return main();
}
else if (op == "*")
{
	cout << num1 << op << num2 << "=" << numA*numB;
	cout << endl;
	return main();
}
else if (op == "%")
{
	cout << num1 << op << num2 << "=" << numA%numB;
	cout << endl;
	return main();
}
}//Clacu Code End
