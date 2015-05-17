#include <iostream>
#include "InfixToPostfix.h"
#include "PostfixToAnswer.h"
#include <functional>
#include "Dichotomy.h"
using namespace std::placeholders;

int main()
{

	string s("sin(6+10*(5/2))-5^2/4");
	string s1= infixToPostfix(s);
	cout << postfixToAnswer(s1, 2) << endl;;
	
	//	//cout << s1 << endl;
	//auto g = bind(postfixToAnswer, s1, _1);

	//Dichotomy D1(1.5, 2, 1e-5, g);
	//Dichotomy D2(1.5, 2, 1e-5, [](double x){return sin(x) - x*x / 4; });

	//cout << D1<<D2;
	getchar();
	return 0;
}