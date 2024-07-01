//*****************************************************************************
//  <assessment name example : Workshop - #7 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Mar , 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include <iostream>
#include "BankAccount.h"
#include "DepositUtility.h"

namespace seneca {

	class SavingsAccount : public BankAccount{
		double m_interest{};
		Date m_interestDate;
		/* A query that inserts into out interest rate (m_interest) formatted so 
		that the precision is 3 and a '%' sign follows. 
		For example, if m_interest is 0.12, 0.120% is written to out. */
		void writeInterest(std::ostream& out) const;
	public:
		/* A constructor that updates all data members of the object. 
		It must call the constructor of the base class and pass the required data. 
		Assume all data is valid. */
		SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
		virtual ~SavingsAccount() = default;
		/* A mutator that increases the account balance by the amount of interest; 
		updates the date interest was last applied; 
		and outputs a message to cout. 
		The method will use writeCurrency() to output the account balances 
		and writeInterest() to output the interest rate. 
		There are three spaces at the front.
		[Original Balance] + [Interest Amount] ([Interest Rate]) = [New Balance] | [Original Interest Date] => [New Interest Date] */
		void applyInterest(Date& dt);
		/* A query that inserts into out the content of the object as formatted below. 
		The method must call the write() function of the base class. 
		It will call writeInterest() to output the interest rate 
		and the insertion operator to output the interest date.
		>> [Name] | [Balance] | [Date Opened] | [Deposit Info] | [Interest Rate] | [Interest Date] */
		std::ostream& write(std::ostream& out) const;
		/* A mutator that reads from the stream in the data for the current object. 
		It must call the read() function of the base class.
		Name: [USER TYPES HERE]
		Opening Balance: [USER TYPES HERE]
		Date Opened (year month day): [USER TYPES HERE]
		Transit #: [USER TYPES HERE]
		Institution #: [USER TYPES HERE]
		Account #: [USER TYPES HERE]
		Interest Date (year month day): [USER TYPES HERE]
		Interest Rate: [USER TYPES HERE] */
		std::istream& read(std::istream& in);
	};
	/* Overload the extraction operator to extract a SavingsAccount from a stream. 
	The extraction operator will call the read member function in the class SavingsAccount. */
	std::istream& operator>>(std::istream& in, SavingsAccount& acct);
	/* Overload the insertion operator to insert a SavingsAccount into a stream. 
	The insertion operator will call the write member function in the class SavingsAccount. */
	std::ostream& operator<<(std::ostream& out, const SavingsAccount& acct);
}

#endif  //  ！SENECA_SAVINGSACCOUNT_H