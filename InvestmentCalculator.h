/*
CS-210
Project 2 : Airgead Banking Investment Calculator
InvestmentCalculator.h
2/7/2025
*/

#pragma once
#ifndef AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_BANKING_INVESTMENT_CALCULATOR_H_

#include <iostream>
#include <vector>
#include <iomanip>

// Defines a structure to hold interest details and year-end balance
struct YearEndData { 
	int year;
	double yearEndBalance;
	double yearEndInterest;

};

class InvestmentCalculator {
private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_years;
	std::vector<YearEndData> m_yearEndDataNoDeposits;
	std::vector<YearEndData> m_yearEndDataWithDeposits;

public:
	InvestmentCalculator() : m_initialInvestment(0), m_monthlyDeposit(0), m_annualInterest(0), m_years(0) {}
	
	void setInitialInvestment(double initialInvestment) { m_initialInvestment = initialInvestment; }
	void setMonthlyDeposit(double monthlyDeposit) { m_monthlyDeposit = monthlyDeposit; }
	void setAnnualInterest(double annualInterest) { m_annualInterest = annualInterest; }
	void setYears(int years) { m_years = years; }

	void calculateYearEndBalanceNoDeposits(); // Function call to calculate year-end balance WITHOUT additional monthly deposits
	void calculateYearEndBalanceWithDeposits(); // Function call to calculate year-end balance WITH additional monthly deposits
	void displayResults() const; // Funtion call to display results

};

#endif 
