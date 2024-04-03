/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the ChequingAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
//*****************************************************************************
//  <assessment name example : Workshop - #8 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Mar 18th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"
#include "Account.h"
using namespace std;

namespace seneca {
  /* constructor receives a double holding the initial account balance, 
  a double holding the transaction fee to be applied to the balance 
  and a double holding the month-end fee to be applied to the account. 
  If the transaction fee received is positive-valued, 
  this function stores the fee. 
  If not, this function stores 0.0 as the fee to be applied. 
  If the monthly fee received is positive-valued, 
  this function stores the fee. 
  If not, this function stores 0.0 as the fee to be applied. */
  ChequingAccount::ChequingAccount(double balance, double transaction, double monthly)
   : Account(balance), m_transactionFee((transaction > 0) ? transaction : 0.0),
      m_monthlyFee((monthly > 0) ? monthly : 0.0) {}

  /* this modifier credits the balance by the amount received 
  and if successful debits the transaction fee from the balance. 
  This function returns true if the transaction succeeded; 
  false otherwise. */
  bool ChequingAccount::credit(double credit) {
    if (credit >= 0) {
      m_curBalance += credit;
      m_curBalance -= m_transactionFee;
      return true;
    } else {
      return false;
    }
  }

  /* this modifier debits the balance by the amount received 
  and if successful debits the transaction fee from the balance. 
  This function returns true if the transaction succeeded; 
  false otherwise. */
  bool ChequingAccount::debit(double debit) {
    if (debit >= 0) {
      m_curBalance -= debit;
      m_curBalance -= m_transactionFee;
      return true;
    } else {
      return false;
    }
  }

  /* this modifier debits the monthly fee from the balance, 
  but does not charge a transaction fee for this debit. */
  void ChequingAccount::monthEnd() {
    m_curBalance -= m_monthlyFee;
  }

  /* receives a reference to an ostream object 
  and inserts the following output on separate lines to the object. 
  The values marked in red are fixed format with 2 decimal places 
  and no fixed field width:
    Account type: Chequing
    Balance: $xxxx.xx
    Per Transaction Fee: x.xx
    Monthly Fee: x.xx */
  void ChequingAccount::display(std::ostream& os) const {
    os << "Account type: Chequing" << endl
       << "Balance: $" << fixed << setprecision(2) << m_curBalance << endl
       << "Per Transaction Fee: " << fixed << setprecision(2) << m_transactionFee << endl
       << "Monthly Fee: " << setprecision(2) << m_monthlyFee << endl;
  }
}