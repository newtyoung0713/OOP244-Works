/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the Account class
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
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include <iostream>
#include "iAccount.h"

namespace seneca {
	class Account : public iAccount {
  protected:
    double m_curBalance;
    // returns the current balance of the account.
    double balance() const;
  public:
    /* constructor receives either a double holding the initial account balance or nothing. 
    If the amount received is not positive-valued 
    or no amount is received, 
    this function initializes the current balance to 0.0. 
    If the amount received is positive-valued, 
    this function initializes the current account balance to the received amount. */
    Account(double);
    /* receives an amount to be credited (added) to the account balance 
    and returns the success of the transaction. 
    If the amount received is positive-valued, 
    the transaction succeeds 
    and this function adds the amount received to the current balance. 
    If the amount is not positive-valued, 
    the transaction fails 
    and this function does not add the amount received. */
    bool credit(double);
    /* receives an amount to be debited (subtracted) from the account balance 
    and returns the success of the transaction. 
    If the amount received is positive-valued, 
    the transaction succeeds 
    and this function subtracts the amount received from the current balance. 
    If the amount is not positive-valued, 
    the transaction fails 
    and this function does not subtract the amount received. */
    bool debit(double);
  };
}

#endif  //  ！SENECA_ACCOUNT_H