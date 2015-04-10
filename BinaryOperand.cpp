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
	unops["sqrt"] = [](double i)->double{return sqrt(i); };
	unops["abs"] = [](double i)->double{return (i < 0) ? -i : i; };

}
UnaryOperand::~UnaryOperand()
{

}