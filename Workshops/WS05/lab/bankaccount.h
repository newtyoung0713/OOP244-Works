/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
//*****************************************************************************
//  <assessment name example : Workshop - #5 (Part - 1)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 16th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_



namespace seneca
{
   const int	 ACCT_MAXLEN_USER = 16;					// Max Length of user name
   const double CHE_TRAN_FEE = 1.25;
   const double SAV_TRAN_FEE = 3.50;
   const double CHE_INT_RATE = 0.005;
   const double SAV_INT_RATE = 0.025;
   
   // Class Definition
   class bankAccount
   {

   private:
      // Data Members
      char	m_userName[ACCT_MAXLEN_USER];
      double	m_funds;
      bool	m_checking;
      int		m_monthlyTransactions;

      bool isOpen() const;
   public:
      bankAccount(const char* name = nullptr, bool checking = false);
      bool setup(const char* name, bool checking);

      // ADD: Type Conversion, Unary, Binary Operators & Additional Methods

      operator bool() const;

      operator double() const;

      bankAccount& operator++();

      bankAccount& operator--();

      bool operator+= (double);

      bool operator-= (double);

      bool operator== (const bankAccount&) const;

      bool operator> (double) const;

      bool operator<= (double) const;

      bool operator<<(bankAccount&);

      void display (void) const;
      // ...
   };

   // ADD: Global helpers

   bool operator> (double lhs, const bankAccount& rhs);

   bool operator<= (double lhs, const bankAccount& rhs);
   // ...
}
#endif

