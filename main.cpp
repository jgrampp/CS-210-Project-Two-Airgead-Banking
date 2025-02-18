/* 
John Grampp
CS-210 - Project 2 : Airgead Banking Investment Calculator

*/

#include "InvestmentCalculator.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

double getValidDoubleInput(const string& prompt) {
	double value;
	cout << prompt;
	while (!(cin >> value) || value < 0) {
		cout << "Invalid input. Please enter a positive number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return value;
}

int getValidIntInput(const string& prompt) {
	int value;
	cout << prompt;
	while (!(cin >> value) || value <= 0) {
		cout << "Invalid input. Please enter a positive integer: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return value;
}

int main() {
	InvestmentCalculator calculator;
	char continueTesting = 'y';

	while (continueTesting == 'y' || continueTesting == 'Y') {
		/* Gather user input */
		cout << string(34, '*') << endl;
		cout << string(11, '*') << " Data Input " << string(11, '*') << endl;
		double initialInvestment = getValidDoubleInput("Initial Investment Amount: $");
		double monthlyDeposit = getValidDoubleInput("Monthly Deposit: $");
		double annualInterest = getValidDoubleInput("Annual Interest: %");
		int years = getValidIntInput("Number of years: ");
		cout << endl;
		cout << "Press <Enter> to Continue...";
		cin.get();
		cin.clear();
		cin.ignore();

		/* Sets values in calculator */
		calculator.setInitialInvestment(initialInvestment);
		calculator.setMonthlyDeposit(monthlyDeposit);
		calculator.setAnnualInterest(annualInterest);
		calculator.setYears(years);

		calculator.calculateYearEndBalanceNoDeposits();
		calculator.calculateYearEndBalanceWithDeposits();

		calculator.displayResults(); /* Display results */

        cout << endl;
		cout << "Would you like to try other values? (y/n): "; /* Ask user to test different values or exit program */
		cin >> continueTesting;
	}

	cout << "Thank you for using the Airgead Banking Investment Calculator! Goodbye!" << endl;

	return 0;
}