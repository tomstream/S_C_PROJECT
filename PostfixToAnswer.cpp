#include "PostfixToAnswer.h"


double postfixToAnswer(string s)
{
	BinaryOperand binops;
	UnaryOperand unops;
	Constant constant(0);
	istringstream iss(s);
	stack<double> container;

	double number, answer;
	string word;

	while (iss >> word)
	{
		stringstream ss;
		ss << word;
		ss >> number;
		if (isdigit(word[0])||word[0]=='.')
		{
			container.push(number);
		}
		else
		{
			if (constant.constant.find(word) != constant.constant.end())
			{
				container.push(constant[word]);
			}
			else if (binops.binops.find(word)!=binops.binops.end())
			{ 
				double a = container.top();
				container.pop();
				double b = container.top();
				container.pop();

				answer = binops[word](b, a);
				container.push(answer);
			}
			else if (unops.unops.find(word) != unops.unops.end())
			{
				double a = container.top();
				container.pop();

				answer = unops[word](a);
				container.push(answer);
			}
		}
	}
	return answer;
}