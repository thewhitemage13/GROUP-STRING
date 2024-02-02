#pragma once
#include "Date.h"
#include "Group.h"
#include <iostream>
#include <chrono>
using namespace std; 

class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction();

	Fraction(int numerator, int denominator);

	Fraction(int value);

	double GetDecimal() const;

	void Print() const;

	void PrintDecimal() const;


	int GetNumerator() const
	{
		return numerator;
	}

	int GetDenominator() const
	{
		return denominator;
	}

	void SetNumerator(int numerator) {
		this->numerator = numerator;
	}

	void SetDenominator(int denominator) {
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	bool GreaterThan(const Fraction& another) const;
	bool LessThan(const Fraction& another) const;
	bool IsEquals(const Fraction& another) const;



};