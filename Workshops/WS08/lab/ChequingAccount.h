/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.h
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
#ifndef SENECA_CHEQUING_ACCOUNT_H
#define SENECA_CHEQUING_ACCOUNT_H
#include <iostream>
#include "Account.h"

namespace seneca {
  /* The ChequingAccount class derives from the Account class 
  and holds the transaction fee 
  and month-end fee to be applied to the account. */
	class ChequingAccount : public Account {
    double m_transactionFee;
    double m_monthlyFee;
  public:
    /* constructor receives a double holding the initial account balance, 
    a double holding the transaction fee to be applied to the balance 
    and a double holding the month-end fee to be applied to the account. 
    If the transaction fee received is positive-valued, 
    this function stores the fee. 
    If not, this function stores 0.0 as the fee to be applied. 
    If the monthly fee received is positive-valued, 
    this function stores the fee. 
    If not, this function stores 0.0 as the fee to be applied. */
    ChequingAccount(double, double, double);
    /* this modifier credits the balance by the amount received 
    and if successful debits the transaction fee from the balance. 
    This function returns true if the transaction succeeded; 
    false otherwise. */
    bool credit(double);
    /* this modifier debits the balance by the amount received 
    and if successful debits the transaction fee from the balance. 
    This function returns true if the transaction succeeded; 
    false otherwise. */
    bool debit(double);
    /* this modifier debits the monthly fee from the balance, 
    but does not charge a transaction fee for this debit. */
    void monthEnd();
    /* receives a reference to an ostream object 
    and inserts the following output on separate lines to the object. 
    The values marked in red are fixed format with 2 decimal places 
    and no fixed field width:
      Account type: Chequing
      Balance: $xxxx.xx
      Per Transaction Fee: x.xx
      Monthly Fee: x.xx */
    void display(std::ostream&) const;
  };
}

#endif  //  ！SENECA_CHEQUING_ACCOUNT_H