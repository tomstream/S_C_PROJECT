#include "InfixToPostfix.h"
#include <vector>

string infixToPostfix(string s)
{
	stack<string> charContainer;
	
	string postfixString;
	
	s = "(" + s + ")";

	handleNegativeAndPositiveSymbol(s);

	for (auto iter = s.begin(); iter != s.end();)
	{
		if (isdigit(*iter) || *iter == '.')//digit number
		{
			string stringTmp;
			for (; iter != s.end()&& (isdigit(*iter)||*iter=='.'); iter++)
				stringTmp += *iter;
			postfixString += stringTmp + ' ';
			if (charContainer.size() != 0&& isalpha(charContainer.top()[0]))
			{
				postfixString += charContainer.top() + ' ';
				charContainer.pop();
			}
			if (iter == s.end())
			{
				break;
			}
		}
		else if (isalpha(*iter))//alpha number
		{
			string stringTmp;
			for (; iter != s.end() && isalpha(*iter); iter++)
				stringTmp += *iter;
			charContainer.push(stringTmp);
			if (iter == s.end())break;
		}
		else
		{
			string iterString;
			iterString = *iter;
			if (typePriority(iterString) == 0)
				return "error!";
			else
			{
				if (*iter == '(')
				{
					charContainer.push(iterString);
				}
				else if (*iter == ')')
				{
					while (charContainer.top() != "("
						&&charContainer.size()!=0)
					{
						postfixString += charContainer.top() + ' ';
						charContainer.pop();
					}
					charContainer.pop();
					if (charContainer.size() != 0&&isalpha(charContainer.top()[0]))
					{
						postfixString += charContainer.top() + ' ';
						charContainer.pop();
					}
				}
				else if (charContainer.size() == 0
					|| typePriority(charContainer.top())
					< typePriority(iterString))
					charContainer.push(iterString);
				
				else 
				{	
					while (charContainer.size() != 0
						&&typePriority(charContainer.top())
						>= typePriority(iterString)
						)
					{
						postfixString += charContainer.top() + ' ';
						charContainer.pop();
					}
					charContainer.push(iterString);
				}
			}
			++iter;
		}
	}
	while (charContainer.size() != 0)
	{
		postfixString += charContainer.top() + ' ';
		charContainer.pop();
	}
	return postfixString;
}

int stringToInt(std::string s)
{
	int number(0);
	for (auto i : s)
		number = number * 10 + int(i)-int('0');
	return number;
}

int typePriority(std::string c)
{
	if (c == "+" || c == "-")
		return 2;
	else if (c == "*" || c == "/")
		return 3;
	else if (c == "(")return 1;
	else if (c == ")")return 10;

	
	return 0;
}
int typePriority(char c)
{
	if (c == '+' || c == '-')
		return 2;
	else if (c == '*' || c == '/')
		return 3;
	else if (c == '(')return 10;
	else if (c == ')')return 10;


	return 0;
}

void handleNegativeAndPositiveSymbol(string &s)
{
	for (auto iter = s.begin();; ++iter)
	{
		if (iter == s.end() || iter + 1 == s.end())break;
		if (*iter == '(' && (*(iter + 1) == '+' || *(iter + 1) == '-'))
		{
			s.insert(iter + 1, '0');
			iter++;
		}
	}
}
int checkString(string s)
{
	if (unknownCharacterCheck(s) == false)return 1;
	if (bracketCheck(s) == false)return 2;
	if (checkOperater(s) == false)return 3;
	return 0;
}

bool bracketCheck(string s)
{
	vector<char> bracketContainer;
	size_t numberOfLeftBracket(0);
	for (auto c : s)
	{
		if (c == '(')numberOfLeftBracket++;
		else if(c==')') {
			if (numberOfLeftBracket==0)return false;
			else{
				numberOfLeftBracket--;
			}
		}
	}
	return true;
}

bool checkOperater(string s)
{
	for (auto iter = s.begin();; ++iter)
	{
		if (iter == s.end() || iter + 1 == s.end())
			break;

		switch (*iter)
		{
		case '(':
			switch (*(iter + 1))
			{
			case ')':case '+':case '-':case '*':case '/':return false;
			default:break;
			}break;
		case ')':
			switch (*(iter + 1))
			{
			case '(':return false;
			default: break;
			}break;
		case '+':case '-':case '*':case '/':
			switch (*(iter + 1))
			{
			case '+':case '-':case '*':case '/':case ')':
				return false;
			default:break;
			}break;
		case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
			switch (*(iter + 1))
			{
			case '(':return false;
			default:break;
			}break;
		default: break;
		}
	}
	return true;
}

bool unknownCharacterCheck(string s)
{
	for (auto i : s)
	{
		switch (i)
		{
		case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
		case '+':case '-':case '*':case '/':
		case ')':case '(':break;
		default:return false;
		}
	}
	return true;
}