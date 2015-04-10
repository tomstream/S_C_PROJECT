#pragma once

#include <map>
#include <string>
#include <functional>
#include <cmath>
using namespace std;


class BinaryOperand
{
public:
	function<double(double, double)> operator[](string s){ return binops.at(s); }
	BinaryOperand();
	~BinaryOperand();
	map<string, function<double(double, double)> > binops;
};

class UnaryOperand
{
public:
	function<double(double)> operator[](string s){ return unops.at(s); }
	UnaryOperand();
	~UnaryOperand();
	map<string, function<double(double)>> unops;
};