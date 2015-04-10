#include "BinaryOperand.h"


BinaryOperand::BinaryOperand()
{
	binops["+"] = [](double i, double j)->double{return i+j; };
	binops["-"] = [](double i, double j)->double{return i-j; };
	binops["*"] = [](double i, double j)->double{return i*j; };
	binops["/"] = [](double i, double j)->double{return i/j; };
	binops["^"] = [](double i, double j)->double{return pow(i, j); };
}


BinaryOperand::~BinaryOperand()
{
}


UnaryOperand::UnaryOperand()
{
	unops["sin"] = [](double i)->double{return sin(i); };
	unops["cos"] = [](double i)->double{return cos(i); };
	unops["tan"] = [](double i)->double{return tan(i); };
	unops["asin"] = [](double i)->double{return asin(i); };
	unops["acos"] = [](double i)->double{return acos(i); };
	unops["atan"] = [](double i)->double{return atan(i); };

	unops["sinh"] = [](double i)->double{return sinh(i); };
	unops["cosh"] = [](double i)->double{return cosh(i); };
	unops["tanh"] = [](double i)->double{return tanh(i); };
	unops["asinh"] = [](double i)->double{return asinh(i); };
	unops["acosh"] = [](double i)->double{return acosh(i); };
	unops["atanh"] = [](double i)->double{return atanh(i); };

	unops["sqrt"] = [](double i)->double{return sqrt(i); };
	unops["abs"] = [](double i)->double{return (i < 0) ? -i : i; };
	unops["exp"] = [](double i)->double{return exp(i); };
	unops["log"] = [](double i)->double{return log(i); };


}
UnaryOperand::~UnaryOperand()
{
}

void Constant::updateX(double x)
{
	this->x = x;
	constant["x"] = x;
}

Constant::Constant(double x)
{
	constant["x"] = x;
	constant["PI"] = 3.1415926535898;
}
Constant::~Constant()
{
}