/*
John Grampp
CS-210
Project 2 : Airgead Banking Investment Calculator
InvestmentCalculator.cpp
2/7/2025
*/

#include "InvestmentCalculator.h" // call to header file
#include <iomanip>

// Function to calculate year-end balance WITHOUT additional monthly deposits
void InvestmentCalculator::calculateYearEndBalanceNoDeposits() { 
	double balance = m_initialInvestment;
	m_yearEndDataNoDeposits.clear();

	for (int year = 1; year <= m_years; ++year) {
		double yearlyInterest = (balance * (m_annualInterest / 100));
		balance += yearlyInterest;
		m_yearEndDataNoDeposits.push_back({ year, balance, yearlyInterest });
	}
}

// Function to calculate year-end balance with additional monthly deposits
void InvestmentCalculator::calculateYearEndBalanceWithDeposits() { 
	double balance = m_initialInvestment;
	m_yearEndDataWithDeposits.clear();

	for (int year = 1; year <= m_years; ++year) {
		double yearlyInterest = 0;
		for (int month = 1; month <= 12; ++month) {
			balance += m_monthlyDeposit;
			double monthlyInterest = balance * (m_annualInterest / 100 / 12);
			balance += monthlyInterest;
			yearlyInterest += monthlyInterest;
		}
		m_yearEndDataWithDeposits.push_back({ year, balance, yearlyInterest});
		}
	}

// Function to display results
void InvestmentCalculator::displayResults() const { 
	std::cout << std::fixed << std::setprecision(2);


	std::cout << std::endl << "Balance and Interest Without Additional Monthly Deposits" << std::endl;
	std::cout << std::string(64, '=') << std::endl;
	std::cout << "Year          Year End Balance          Year End Earned Interest" << std::endl;
	std::cout << std::string(64, '-') << std::endl;

	for (const auto & data : m_yearEndDataNoDeposits) {
		std::cout << std::setw(4) << data.year << std::right << std::setw(26) << data.yearEndBalance << std::setw(34) << data.yearEndInterest << std::endl;
	}

	std::cout << std::endl << "Balance and Interest With Additional Monthly Deposits" << std::endl;
	std::cout << std::string(64, '=') << std::endl;
	std::cout << "Year          Year End Balance          Year End Earned Interest" << std::endl;
	std::cout << std::string(64, '-') << std::endl;

	for (const auto & data : m_yearEndDataWithDeposits) {
		std::cout << std::setw(4) << data.year << std::right << std::setw(26) << data.yearEndBalance << std::setw(34) << data.yearEndInterest << std::endl;
	}

}