/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingAccount.h
// Version 1.0
// Date:
// Author:  
// Description
// This file defines the SavingsAccount class
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
#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H
#include <iostream>
#include "Account.h"

namespace seneca {
  /* The SavingsAccount class derives from the Account class 
  and holds the interest rate that applies to the account. 
  This class includes the following public member functions: */
	class SavingsAccount : public Account {
    double m_rate;
  public:
    /* constructor receives a double holding the initial account balance 
    and a double holding the interest rate to be applied to the balance. 
    If the interest rate received is positive-valued, 
    this function stores the rate. 
    If not, 
    this function stores 0.0 as the rate to be applied. */
    SavingsAccount(double, double);
    /* this modifier calculates the interest earned on the current balance 
    and credits the account with that interest. */
    void monthEnd();
    /* receives a reference to an ostream object 
    and inserts the following output on separate lines to the object. 
    The values marked in red are fixed format with 2 decimal places 
    and no fixed field width:
      Account type: Savings
      Balance: $xxxx.xx
      Interest Rate (%): x.xx */
    void display(std::ostream&) const;
  };
}

#endif  //  ！SENECA_SAVINGS_ACCOUNT_H