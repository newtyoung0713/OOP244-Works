//*****************************************************************************
//  <assessment name example : Workshop - #3 (Part - 2)>
//  Full Name   : Sheng-Lin Yang
//  Student ID# : 160443222
//	Email       : syang153@myseneca.ca
//	Section     : OOP244 NAA
//	Date        : Feb 07th, 2024
//	Authenticity Declaration :
//  I have done all the coding by myself and only copied the code 
//  that my professor provided to complete my workshops and assignments.
//*****************************************************************************

#include <iostream>
#include <iomanip>
#include "Vendor.h"
using namespace std;

namespace seneca {
  void Vendor::setEmpty() {
    delete m_cusOfIcecream;
    m_cusOfIcecream = nullptr;
    m_numOfIcecream = 0;
  }

  void Vendor::takeOrders() {
    setEmpty();
    cout << "Seneca Icecream shop\n"
         << "          @\n"
         << "        (' .)\n"
         << "       (*.`. )\n"
         << "        \\###/\n"
         << "         \\#/\n"
         << "          V" << endl;

    cout << "How many Icecreams?\n> ";
    cin >> m_numOfIcecream;
    m_cusOfIcecream = new Icecream[m_numOfIcecream];
    for (int i = 0; i < m_numOfIcecream; i++) {
      cout << "Order number " << (i + 1) << ":" << endl;
      m_cusOfIcecream[i].getOrder();
    }
  }

  void Vendor::displayOrders() {
    cout << "\n********** Order Summary **********";
    for (int i = 0; i < m_numOfIcecream; i++) {
      cout << "\nOrder No: " << (i + 1) << ":" << endl;
      m_cusOfIcecream[i].printOrder();
      m_subTotal += m_cusOfIcecream[i].summaryPrice();
    }

    m_afterTax = m_subTotal * m_tax;
    m_total = m_subTotal + m_afterTax;
    m_cusOfIcecream->line(35);
    cout << "\nPrice:";
    cout.width(29);
    cout << fixed << setprecision(2) << m_subTotal << endl;
    cout << "Tax:";
    cout.width(31);
    cout << fixed << setprecision(2) << m_afterTax << endl;
    cout << "Total Price ($):";
    cout.width(19);
    cout << fixed << setprecision(2) << m_total << endl;
  }
  
  void Vendor::clearData() {
    setEmpty();
  }
}