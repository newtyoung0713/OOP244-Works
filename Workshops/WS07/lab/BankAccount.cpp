//*****************************************************************************
//  <assessment name example : Workshop - #7 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Mar 12th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "BankAccount.h"

using namespace std;

namespace seneca {
		// A query method to return the current balance of the account (m_balance).
		double BankAccount::getBalance() const {
      return m_balance;
    }
		// A mutator that sets the current balance of the account (m_balance).
		void BankAccount::setBalance(double balance) {
      m_balance = balance;
    }
		/* A utility method that inserts into out a formatted dollar amount. 
		The amount is written with a leading '$' sign and a precision of 2. 
		For example, if amount is 1.2, $1.20 is written to out. */
		void BankAccount::writeCurrency(ostream& out, double amount) const {
      out << '$' << fixed << setprecision(2) << amount;
    }
		/* A constructor that updates all of the data members of the object. 
		Assume all data is valid. */
		BankAccount::BankAccount(const char* name, Date openDate, DepositInfo depInfo, double balance)
     : m_openDate(openDate), m_depInfo(depInfo), m_balance(balance) {
      strncpy(m_name, name, NAME_LEN);
    }
		/* A query that inserts into out the content of the object as formatted below. 
		The method will use writeCurrency() to output the account balance.
		>> [Name] | [Balance] | [Date Opened] | [Deposit Info] */
		ostream& BankAccount::write(ostream& out) const {
      out << ">> " << m_name << " | ";
      writeCurrency(out, m_balance);
      out << " | " << m_openDate << " | " << m_depInfo;
      return out;
    }
		/* A mutator that reads from the stream in the data for the current object.
		Name: [USER TYPES HERE]
		Opening Balance: [USER TYPES HERE]
		Date Opened (year month day): [USER TYPES HERE]
		Transit #: [USER TYPES HERE]
		Institution #: [USER TYPES HERE]
		Account #: [USER TYPES HERE] */
		istream& BankAccount::read(istream& in) {
      cout << "Name: ";
      // Checking if there is '\n' before the second getline
      // then ignore that '\n'
      // If did not check, then the first getline will ignore the first char
      if (in.peek() == '\n') in.ignore();
      in.getline(m_name, NAME_LEN);
      cout << "Opening Balance: ";
      in >> m_balance;
      cout << "Date Opened ";
      in >> m_openDate;
      m_depInfo.read(in);
      return in;
    }
		/* Overload the extraction operator to extract a BankAccount from a stream. 
		The extraction operator will call the read member function in the class BankAccount. */
		istream& operator>>(istream& in, BankAccount& acct) {
      acct.read(in);
      return in;
    }
		/* Overload the insertion operator to insert a BankAccount into a stream. 
		The insertion operator will call the write member function in the class BankAccount. */
		ostream& operator<<(ostream& out, const BankAccount& acct) {
      acct.write(out);
      return out;
    }
}