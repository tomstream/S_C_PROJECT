#include <iostream>
#include "InfixToPostfix.h"
#include "PostfixToAnswer.h"

int main()
{
	string s("-(3.2+1)+3*(1+2)+1*(2*sin(3+4))");

	string s1= infixToPostfix(s);
	cout << s1 << endl;
	cout << postfixToAnswer(s1);

	cout << endl << sin(7);
	getchar();
	return 0;
}