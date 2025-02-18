


#include "InvestmentCalculator.h"
#include <iomanip>

void InvestmentCalculator::calculateYearEndBalanceNoDeposits() { /* Function to claculate year-end balance WITHOUT additional monthly deposits */
	double balance = m_initialInvestment;
	m_yearEndDataNoDeposits.clear();

	for (int year = 1; year <= m_years; ++year) {
		double yearlyInterest = balance * (m_annualInterest / 100);
		balance += yearlyInterest;
		m_yearEndDataNoDeposits.push_back({ year, balance, yearlyInterest });
	}
}

void InvestmentCalculator::calculateYearEndBalanceWithDeposits() { /* Function to calculate year-end balance with additional monthly deposits */
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

void InvestmentCalculator::displayResults() const { /* Function to display results */
	std::cout << std::fixed << std::setprecision(2);

	std::cout << "\nBalance and Interest Without Additional Monthly Deposits" << std::endl;
	std::cout << std::string(64, '=') << std::endl;
	std::cout << "Year          Year End Balance          Year End Earned Interest" << std::endl;
	std::cout << std::string(64, '-') << std::endl;

	for (const auto & data : m_yearEndDataNoDeposits) {
		std::cout << std::setw(4) << data.year << std::right << std::setw(26) << data.yearEndBalance << std::setw(34) << data.yearEndInterest << std::endl;
	}

	std::cout << "\nBalance and Interest With Additional Monthly Deposits" << std::endl;
	std::cout << std::string(64, '=') << std::endl;
	std::cout << "Year          Year End Balance          Year End Earned Interest" << std::endl;
	std::cout << std::string(64, '-') << std::endl;

	for (const auto & data : m_yearEndDataWithDeposits) {
		std::cout << std::setw(4) << data.year << std::right << std::setw(26) << data.yearEndBalance << std::setw(34) << data.yearEndInterest << std::endl;
	}

}