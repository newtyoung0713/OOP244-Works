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
#include "SavingsAccount.h"

using namespace std;

namespace seneca {
    /* A query that inserts into out interest rate (m_interest) formatted so 
		that the precision is 3 and a '%' sign follows. 
		For example, if m_interest is 0.12, 0.120% is written to out. */
		void SavingsAccount::writeInterest(ostream& out) const {
      out << fixed << setprecision(3) << m_interest<< '%';
    }
		/* A constructor that updates all data members of the object. 
		It must call the constructor of the base class and pass the required data. 
		Assume all data is valid. */
		SavingsAccount::SavingsAccount(const char* name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate)
    : BankAccount(name, openDate, depInfo, balance), m_interest(interest), m_interestDate(interestDate) {
    }
		/* A mutator that increases the account balance by the amount of interest; 
		updates the date interest was last applied; 
		and outputs a message to cout. 
		The method will use writeCurrency() to output the account balances 
		and writeInterest() to output the interest rate. 
		There are three spaces at the front.
		[Original Balance] + [Interest Amount] ([Interest Rate]) = [New Balance] | [Original Interest Date] => [New Interest Date] */
		void SavingsAccount::applyInterest(Date& dt) {
      double new_balance = BankAccount::getBalance() * m_interest;
			cout << "   ";
      writeCurrency(cout, BankAccount::getBalance());
      cout << " + ";
      writeCurrency(cout, new_balance);
      cout << " (";
			writeInterest(cout);
			cout << ") = ";
      setBalance(BankAccount::getBalance() + new_balance);
      writeCurrency(cout, BankAccount::getBalance());
      cout << " | " << m_interestDate << " => " << dt << endl;
      m_interestDate = dt;
    }
		/* A query that inserts into out the content of the object as formatted below. 
		The method must call the write() function of the base class. 
		It will call writeInterest() to output the interest rate 
		and the insertion operator to output the interest date.
		>> [Name] | [Balance] | [Date Opened] | [Deposit Info] | [Interest Rate] | [Interest Date] */
		ostream& SavingsAccount::write(ostream& out) const {
      BankAccount::write(out);
      out << " | ";
      writeInterest(out);
      out << " | " << m_interestDate;
      return out;
    }
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
		istream& SavingsAccount::read(istream& in) {
      BankAccount::read(in);
      cout << "Interest Date ";
      in >> m_interestDate;
      cout << "Interest Rate: ";
      in >> m_interest;
      return in;
    }
		/* Overload the extraction operator to extract a SavingsAccount from a stream. 
		The extraction operator will call the read member function in the class SavingsAccount. */
		istream& operator>>(istream& in, SavingsAccount& acct) {
      acct.read(in);
      return in;
    }
		/* Overload the insertion operator to insert a SavingsAccount into a stream. 
		The insertion operator will call the write member function in the class SavingsAccount. */
		ostream& operator<<(ostream& out, const SavingsAccount& acct) {
      acct.write(out);
      return out;
    }
}