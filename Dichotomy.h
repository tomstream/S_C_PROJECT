#pragma once

#include<iostream>
#include<utility>
#include<functional>

using namespace std;
class Dichotomy{
public:
	Dichotomy() = default;
	Dichotomy(double mininum, double maxinum, double prec, std::function<double(double)> function);
	Dichotomy(Dichotomy& item) :min(item.min), max(item.max), precision(item.precision), f(item.f), iterateTime(item.iterateTime), rootRange(item.rootRange)
	{}
	~Dichotomy() = default;
	friend ostream &operator<<(ostream &os, const Dichotomy&item);

private:
	void calculateTheRoot();

	double min;
	double max;
	double precision;
	function<double(double)> f;
	size_t iterateTime;
	pair<double, double> rootRange;
};
ostream &operator<<(ostream &os, const Dichotomy&item);

