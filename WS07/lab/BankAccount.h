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
#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include <iostream>
#include "DepositUtility.h"

namespace seneca {
	const int NAME_LEN(50);

	class BankAccount {
		char m_name[NAME_LEN + 1];
		Date m_openDate;
		DepositInfo m_depInfo;
		double m_balance{};
	protected:
		// A query method to return the current balance of the account (m_balance).
		double getBalance() const;
		// A mutator that sets the current balance of the account (m_balance).
		void setBalance(double balance);
		/* A utility method that inserts into out a formatted dollar amount. 
		The amount is written with a leading '$' sign and a precision of 2. 
		For example, if amount is 1.2, $1.20 is written to out. */
		void writeCurrency(std::ostream& out, double amount) const;
	public:
		BankAccount() = default;
		/* A constructor that updates all of the data members of the object. 
		Assume all data is valid. */
		BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance);
		virtual ~BankAccount() = default;
		/* A query that inserts into out the content of the object as formatted below. 
		The method will use writeCurrency() to output the account balance.
		>> [Name] | [Balance] | [Date Opened] | [Deposit Info] */
		std::ostream& write(std::ostream& out) const;
		/* A mutator that reads from the stream in the data for the current object.
		Name: [USER TYPES HERE]
		Opening Balance: [USER TYPES HERE]
		Date Opened (year month day): [USER TYPES HERE]
		Transit #: [USER TYPES HERE]
		Institution #: [USER TYPES HERE]
		Account #: [USER TYPES HERE] */
		std::istream& read(std::istream& in);
	};
	/* Overload the extraction operator to extract a BankAccount from a stream. 
	The extraction operator will call the read member function in the class BankAccount. */
	std::istream& operator>>(std::istream& in, BankAccount& acct);
	/* Overload the insertion operator to insert a BankAccount into a stream. 
	The insertion operator will call the write member function in the class BankAccount. */
	std::ostream& operator<<(std::ostream& out, const BankAccount& acct);
}

#endif  //  ！SENECA_BANKACCOUNT_H