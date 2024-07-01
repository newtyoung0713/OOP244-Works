/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: iAccount.h
// Version 1.0
// Date:
// Author: 
// Description
// This file defines the iAccount interface
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
#ifndef SENECA_I_ACCOUNT_H
#define SENECA_I_ACCOUNT_H
#include <iostream>

namespace seneca {
	class iAccount {
  public:
    // adds a positive amount to the account balance
    virtual bool credit(double) = 0;
    // subtracts a positive amount from the account balance
    virtual bool debit(double) = 0;
    // applies month-end transactions to the account
    virtual void monthEnd() = 0;
    // inserts account information into an ostream object
    virtual void display(std::ostream&) const = 0;
    // This interface also declares a public empty virtual destructor.
    virtual ~iAccount() = default;
  };
  /* This interface also declares the following helper function 
  (this global function is already coded 
  and is provided in the allocator module 
  and will be used at final submission)
  receives a C-style string identifying the type of account 
  and the initial account balance, 
  creates the account with the starting balance 
  and returns its address. */
  iAccount* CreateAccount(const char*, double);
}

#endif  //  ！SENECA_I_ACCOUNT_H