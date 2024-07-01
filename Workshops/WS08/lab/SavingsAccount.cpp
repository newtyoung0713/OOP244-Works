/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date:
// Author: 
// Description
// This file implements the SavingsAccount class
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
#include "SavingsAccount.h"
// #include "iAccount.h"
using namespace std;

namespace seneca {
  /* constructor receives a double holding the initial account balance 
  and a double holding the interest rate to be applied to the balance. 
  If the interest rate received is positive-valued, 
  this function stores the rate. 
  If not, 
  this function stores 0.0 as the rate to be applied. */
  SavingsAccount::SavingsAccount(double balance, double rate)
   : Account(balance), m_rate((rate >= 0) ? rate : 0.0) {}

  /* this modifier calculates the interest earned on the current balance 
  and credits the account with that interest. */
  void SavingsAccount::monthEnd() {
    m_curBalance += m_curBalance * m_rate;
  }

  /* receives a reference to an ostream object 
  and inserts the following output on separate lines to the object. 
  The values marked in red are fixed format with 2 decimal places 
  and no fixed field width:
    Account type: Savings
    Balance: $xxxx.xx
    Interest Rate (%): x.xx */
  void SavingsAccount::display(std::ostream& os) const {
    os << "Account type: Savings" << endl
       << "Balance: $" << fixed << setprecision(2) << m_curBalance << endl
       << "Interest Rate (%): " << setprecision(2) << m_rate * 100 << endl;
  }
}